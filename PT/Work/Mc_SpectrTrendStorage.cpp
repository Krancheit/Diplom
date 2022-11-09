/*************************************************************************
  Module
	Save and export ST
  File
	 Mc_SpectrTrendStorage.cpp

  Modified
	Date      Person		Comment
	----------------------------------------------------------------------
	16-Oct-12 Larionov V.   Original
*************************************************************************/

//---------------------------------------------------------------------------
// Includes -----------------------------------------------------------------
//---------------------------------------------------------------------------

#pragma hdrstop

#include <math.h>
#include <mem.h>

#include "Cb_defs.h"
#include "Cw_res.hpp"
#include "Cw_dlg.hpp"

#include "Wi_Utils.h"

#include "Mc_res.h"
#include "Mc_SpectrTrendStorage.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

//---------------------------------------------------------------------------
// Defines ------------------------------------------------------------------
//---------------------------------------------------------------------------

#ifndef CDELETEA
  #define CDELETEA( a )    { delete[] a;  a = NULL; }
#endif

#ifndef MAX
  #define MAX( a, b )       ((a) > (b) ? (a) : (b) )
#endif

#ifndef MIN
  #define MIN( a, b )       ((a) < (b) ? (a) : (b) )
#endif

#define STS_MAX_CHANNELS    8   // max. number of channels for spectr. trend
#define STS_MAX_CHN_LEN     12  // max. length of channel's name

//------------------------------------------------------------------------------
// Types -----------------------------------------------------------------------
//------------------------------------------------------------------------------

// Copy of struct trMcSpcTrendPrmTA (to prevent different alignment) -----------
struct trMcSpcTrendPrmTA2
{
  bool bAveragedMode;
  bool bSymmAvr;
  short nK;
  short nWinType;
  double fThr;
  double fTMax;

  trMcSpcTrendPrmTA2() { memset(this, 0, sizeof(trMcSpcTrendPrmTA2)); }
  trMcSpcTrendPrmTA2(trMcSpcTrendPrmTA rPrm);  // setting defaults to all parameters (see defines)
  trMcSpcTrendPrmTA GetData();
};

//------------------------------------------------------------------------------
// main object
struct trMcSTBufferR: trMcSTBuffer
{
  trMcSTBufferR() { pfBuffer = NULL; nFile = INVALID_HANDLE_VALUE; bInit = false; }

  virtual ~trMcSTBufferR()
  {
	CDELETEA(pfBuffer);
	if (nFile != INVALID_HANDLE_VALUE)
	  ::CloseHandle(nFile);
  }

  virtual bool Init(            // initialize object
	TrMcExamine* prExam,        // (In) examine object
	trMcSpcTrendProc * prSTP,   // (In) trend spectrums' processor
	char** ppcChanNames,        // (In) channel names
	long nSpcInBuf              // (In) max. number of multi-channel spectrums saved in buffer
				   );           // returns false if failed

  virtual bool Save(            // save spectrum
	long nSize,                 // (In) signal size
	trMcSTProgressCallback* prCallback = NULL // (In/Opt) callback for showing progress
	);                          // returns false if failed

  virtual bool IsSaved(         // check if file contains proper spectrum
	bool bUpdate = false        // (In/Opt) flag, if update parameters from spectrum DS
	);                          // returns true iff file contains proper spectrum

  virtual bool GetLimits(       // get limits of stored spectrum
	long* plFrom, long* plTo    // (Out) limits
	);                          // returns false if failed

  virtual bool GetSpectrum(     // get spectrum
	long nFrom, long nTo,       // (In) interval
	float** ppfS                // (Out) spectrum data
	);                          // returns false if failed

  virtual bool Export();        // export ST to external util

  // interface for saving all ST buffers

  #ifdef MC_ST_SAVE_ALL_BUFFERS

	virtual bool SaveAllBuffers(        // save all ST data
	  trMcSTBPrmGen *prPG,              // (In) general parameters for all trend
	  trMcSTBPrmCSA *prPCSA,            // (In) parameters for CSA
	  trMcSTBPrmRA  *prPRA,             // (In) parameters for relative amplitudes
	  trMcSTBPrmAR  *prPAR,             // (In) parameters for the AR trend
	  trCashedBufferN* prSpcBuffer,     // (In) spectrum buffer
	  trCashedBufferN* prSpcStatBuffer, // (In) spectrum stat buffer
	  trCashedBufferN* prPixBuffer,     // (In) pix buffer
	  long nSize,                       // (In) total length of spectrum signal
	  short nChannels,                  // (In) number of channels
	  trMcSTProgressCallback* prCallback // (In/Opt) callback for showing progress
					   );               // returns false if failed

	virtual bool LoadFile(              // read file with ST
	  trMcSTBPrmGen *prPG,              // (Out) general parameters for all trend
	  trMcSTBPrmCSA *prPCSA,            // (Out) parameters for CSA
	  trMcSTBPrmRA  *prPRA,             // (Out) parameters for relative amplitudes
	  trMcSTBPrmAR  *prPAR,             // (Out) parameters for the AR trend
	  short* pnChannels                 // (Out) number of channels
	  );                                // returns false if failed

	virtual bool GetBufferLimits(       // get limits of stored signal
	  long* plFrom, long* plTo,         // (Out) limits
	  short nType                       // (In) type of buffer (see defines)
					   );               // returns false if failed

	virtual char* GetBufferData(        // get data
	  long nFrom,                       // (In) left border
	  long nSize,
	  long nChan,                       // (In) channel number
	  short nType                       // (In) type of buffer (see defines)
					   );      // returns pointer to giving data or NULL if failed

  #endif

  private:

  // common
  bool bInit;
  TrMcExamine* prExamine;
  trMcSpcTrendProc * prSTProcessor;
  char aasChNames[STS_MAX_CHANNELS][STS_MAX_CHN_LEN + 1];
  long nSpcMaxLength;

  bool bProperFile;
  HANDLE nFile;
  AnsiString rFilename;
  float* pfBuffer;

  // limits of stored signal
  long nSigFrom;
  long nSigTo;

  // for all buffers
  #ifdef MC_ST_SAVE_ALL_BUFFERS
	#define BUF_SIZE 1000000
	short nChanNumber;
	trMcSTBPrmGen rPG;
	long nSpcBufSize;
	long nSpcStatBufSize;
	long nPixBufSize;
	char acBuffer[BUF_SIZE];
  #endif

  // methods
  void SaveToFile(void);
  bool CheckFile(HANDLE nFile);
  HANDLE GetFile(bool bExists);
  bool WriteSpectrumHeader(HANDLE nFile);
};

//------------------------------------------------------------------------------
// Code for trMcSTBufferR ------------------------------------------------------
//------------------------------------------------------------------------------

bool trMcSTBufferR::Init(TrMcExamine* prExam, trMcSpcTrendProc * prSTP,
                         char** ppcChanNames, long nSpcInBuf)

{
  CDELETEA(pfBuffer);
  prExamine  = prExam;
  prSTProcessor = prSTP;
  nSpcMaxLength = nSpcInBuf;
  bProperFile = false;
  if (nFile != INVALID_HANDLE_VALUE)
    ::CloseHandle(nFile);
  nFile = INVALID_HANDLE_VALUE;

  if (ppcChanNames)
  {
	trMcSpcTrendData* prD;
	prSTProcessor->Get(&prD);
	for(short nCh = 0; nCh < prD->nNmbChOut; nCh++)
	  if(ppcChanNames[nCh] && strlen(ppcChanNames[nCh]))
		strncpy(aasChNames[nCh], ppcChanNames[nCh], STS_MAX_CHN_LEN );
  }

  #ifdef MC_ST_SAVE_ALL_BUFFERS
	nSpcBufSize = 0;
	nSpcStatBufSize = 0;
	nPixBufSize = 0;
  #endif

  bInit = true;
  return true;
}

//------------------------------------------------------------------------------

bool trMcSTBufferR::Save(long nSize, trMcSTProgressCallback* prCallback)
{
  if (!bInit) return false;

  float fProgress = 0;
  if (prCallback) prCallback->ShowProgress(0);

  // file
  if (nFile != INVALID_HANDLE_VALUE)
	::CloseHandle(nFile);
  nFile = GetFile(false);
  WriteSpectrumHeader(nFile);

  trMcSpcTrendData* prD;
  trMcSpcTrendPrmP rPP;
  trMcSpcTrendPrmTA rPA;
  trMcSpcTrendCfg rCfg;
  prSTProcessor->Get(&prD, &rPP, &rPA, &rCfg);
  int nRecordSize = prD->nNmbChOut * rCfg.nP;

  // buffer
  long nBlockSize = 100;
  float* pfBuf;

  long nL = 0, nR = 0;
  bool bLast = false;
  float fPart = MIN((float) nBlockSize / nSize, 1.);
  DWORD nBytes;
  nSigFrom = -1;
  while(nR < nSize)
  {
	nR = MIN(nL + nBlockSize, nSize - 1);
	bLast = nR == nSize - 1;

	// calculate
	prSTProcessor->GetSpectrums(&nL, &nR, &pfBuf);

	// correct borders
	if (nSigFrom == -1) nSigFrom = nL;
	if (nR >= 0 ) nSigTo = nR;
	if (nL >= nR)
	{
	  break;
	}

	// write to file
	::WriteFile(nFile, (void*) pfBuf, (nR - nL + 1) * nRecordSize * sizeof(float),
	  &nBytes, NULL);

	// show progress
	fProgress += fPart * 100;
	if (prCallback) prCallback->ShowProgress(fProgress);

	nL = nR + 1;
  }

  // write borders
  ::SetFilePointer(nFile, 0, NULL, FILE_BEGIN);
  ::WriteFile(nFile, (void*) &nSigFrom, sizeof(long), &nBytes, NULL);
  ::WriteFile(nFile, (void*) &nSigTo, sizeof(long), &nBytes, NULL);

  ::CloseHandle(nFile);
  nFile = INVALID_HANDLE_VALUE;
  bProperFile = true;
  if (prCallback) prCallback->ShowProgress(100);

  return bLast;
}

//------------------------------------------------------------------------------

bool trMcSTBufferR::IsSaved(bool bUpdate)
{
  if (!bInit) return false;

  if (bUpdate)
  {
	if (nFile != INVALID_HANDLE_VALUE)
	  ::CloseHandle(nFile);
	nFile = GetFile(true);
	if (nFile == INVALID_HANDLE_VALUE) bProperFile = false;
	else bProperFile = CheckFile(nFile);
  }

  return bProperFile;
}

//------------------------------------------------------------------------------

bool trMcSTBufferR::GetLimits(long* plFrom, long* plTo)
{
  if (!bInit || !bProperFile) return false;

  if (plFrom) *plFrom = nSigFrom;
  if (plTo) *plTo = nSigTo;
}

//------------------------------------------------------------------------------

bool trMcSTBufferR::GetSpectrum(long nFrom, long nTo, float** ppfS)
{
  if (!bInit || !bProperFile) return false;

  trMcSpcTrendData* prD;
  trMcSpcTrendPrmP rPP;
  trMcSpcTrendPrmTA rPA;
  trMcSpcTrendCfg rCfg;
  prSTProcessor->Get(&prD, &rPP, &rPA, &rCfg);
  int nRecordSize = prD->nNmbChOut * rCfg.nP;
  int nHeaderSize = 2 * sizeof(long) + sizeof(short) + sizeof(trMcSpcTrendPrmP) +
					sizeof(trMcSpcTrendPrmTA2) + sizeof(trMcSpcTrendCfg) +
					prD->nNmbChOut * STS_MAX_CHN_LEN * sizeof(char);

  if (!pfBuffer)
  {
	// alloc memory
	pfBuffer = new float[nSpcMaxLength * nRecordSize];
  }

  DWORD nBytes;
  ::SetFilePointer(nFile, nHeaderSize + (nFrom - nSigFrom) * nRecordSize * sizeof(float),
	NULL, FILE_BEGIN);
  ::ReadFile(nFile, (void*) pfBuffer, (nTo - nFrom + 1) * nRecordSize * sizeof(float),
	&nBytes, NULL);

  *ppfS = pfBuffer;
  return true;
}

//------------------------------------------------------------------------------

bool trMcSTBufferR::Export()
{
  if (!bInit || !bProperFile) return false;

  // running utility
  AnsiString sExe = "STUtil.exe";
  PROCESS_INFORMATION piDecarto;

  if (!WiIsProcessRunning(C_TO_ANSI_CSTR(sExe)))
  {
	DWORD dwCreationFlag = NORMAL_PRIORITY_CLASS;
	STARTUPINFO si;
	memset(&si, 0, sizeof(STARTUPINFO));
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = SW_SHOWDEFAULT;
	si.cb = sizeof(si);
	char sCommand[256];

	sprintf(sCommand, "%s %s", sExe.c_str(), rFilename.c_str());

	if (!FileExists(sExe) || !CreateProcess(NULL, sCommand, NULL, NULL,
											false, dwCreationFlag, NULL, NULL, &si, &piDecarto))
	{
	  AnsiString s;
	  s.sprintf(C_TO_ANSI_CSTR(CwLoadStr(STR_INFO_EXAM_DOESNT_EXISTS)), C_TO_ANSI_CSTR(sExe));
	  CwShowWarning(s);
	  return false;
	}

	CloseHandle(piDecarto.hThread);
	CloseHandle(piDecarto.hProcess);
  }
  else
	piDecarto.dwProcessId = 0;

  return true;
}

//------------------------------------------------------------------------------

HANDLE trMcSTBufferR::GetFile(bool bRead)
{
  char* pcFilename = prExamine->GetFile();
  rFilename = pcFilename;
  if (rFilename.IsEmpty() || ExtractFileName(rFilename).IsEmpty())
	return INVALID_HANDLE_VALUE;
  rFilename = ChangeFileExt(rFilename, ".csa");

  if (bRead)
	return ::CreateFile(rFilename.c_str(), GENERIC_READ, FILE_SHARE_READ,
						NULL, OPEN_EXISTING, 0, NULL);
  else
	return ::CreateFile(rFilename.c_str(), GENERIC_WRITE, FILE_SHARE_READ,
						NULL, OPEN_ALWAYS, 0, NULL);
}

//------------------------------------------------------------------------------

bool trMcSTBufferR::WriteSpectrumHeader(HANDLE nFile)
{
  if (nFile == INVALID_HANDLE_VALUE || !prSTProcessor)
	return false;

  trMcSpcTrendData* prD;
  trMcSpcTrendPrmP rPP;
  trMcSpcTrendPrmTA rPA;
  trMcSpcTrendCfg rCfg;
  prSTProcessor->Get(&prD, &rPP, &rPA, &rCfg);
  trMcSpcTrendPrmTA2 rPA2(rPA);

  DWORD nBytes;

  // borders
  ::WriteFile(nFile, (void*) &nSigFrom, sizeof(long), &nBytes, NULL);
  ::WriteFile(nFile, (void*) &nSigTo, sizeof(long), &nBytes, NULL);

  // channels
  ::WriteFile(nFile, (void*) &prD->nNmbChOut, sizeof(short), &nBytes, NULL);

  // ST data
  ::WriteFile(nFile, (void*) &rPP, sizeof(trMcSpcTrendPrmP), &nBytes, NULL);
  ::WriteFile(nFile, (void*) &rPA2, sizeof(trMcSpcTrendPrmTA2), &nBytes, NULL);
  ::WriteFile(nFile, (void*) &rCfg, sizeof(trMcSpcTrendCfg), &nBytes, NULL);

  // channel names
  for(short nCh = 0; nCh < prD->nNmbChOut; nCh++)
	::WriteFile(nFile, (void*) aasChNames[nCh], STS_MAX_CHN_LEN * sizeof(char), &nBytes, NULL);

  return true;
}

//------------------------------------------------------------------------------

bool trMcSTBufferR::CheckFile(HANDLE nFile)
{
  DWORD nBytes;

  short nChannels;
  trMcSpcTrendPrmP rPP1;
  trMcSpcTrendPrmTA2 rPA12;
  trMcSpcTrendCfg rCfg1;
  char aasChNames1[STS_MAX_CHANNELS][STS_MAX_CHN_LEN + 1];

  try
  {
	// borders
	if (!::ReadFile(nFile, (void*) &nSigFrom, sizeof(long), &nBytes, NULL))
	  throw 0;
	if (!::ReadFile(nFile, (void*) &nSigTo, sizeof(long), &nBytes, NULL))
	  throw 0;

	// channels
	if (!::ReadFile(nFile, (void*) &nChannels, sizeof(short), &nBytes, NULL))
	  throw 0;

	// ST data
	if (!::ReadFile(nFile, (void*) &rPP1, sizeof(trMcSpcTrendPrmP), &nBytes, NULL))
	  throw 0;
	if (!::ReadFile(nFile, (void*) &rPA12, sizeof(trMcSpcTrendPrmTA2), &nBytes, NULL))
	  throw 0;
	if (!::ReadFile(nFile, (void*) &rCfg1, sizeof(trMcSpcTrendCfg), &nBytes, NULL))
	  throw 0;

    // channel names
	for(short nCh = 0; nCh < nChannels; nCh++)
	  if (!::ReadFile(nFile, (void*) aasChNames1[nCh], STS_MAX_CHN_LEN * sizeof(char), &nBytes, NULL))
		throw 0;
  }
  catch(...)
  {
    if (nFile != INVALID_HANDLE_VALUE)
	  ::CloseHandle(nFile);
	return false;
  }

  trMcSpcTrendPrmTA rPA1 = rPA12.GetData();

  trMcSpcTrendData* prD;
  trMcSpcTrendPrmP rPP2;
  trMcSpcTrendPrmTA rPA2;
  trMcSpcTrendCfg rCfg2;
  prSTProcessor->Get(&prD, &rPP2, &rPA2, &rCfg2);

  bool bChannels = nChannels == prD->nNmbChOut;
  if (bChannels)
  {
    for(short nCh = 0; nCh < nChannels; nCh++)
	  if (strcmp(aasChNames[nCh], aasChNames1[nCh]))
	  {
		bChannels = false;
		break;
	  }
  }

  return bChannels &&
		 rPP1      == rPP2 &&
		 rPA1      == rPA2 &&
		 rCfg1.nP  == rCfg2.nP &&
		 fabs(rCfg1.fMaxFrq - rCfg2.fMaxFrq) < 0.0000001 &&
		 rCfg1.lT  == rCfg2.lT;
}

//------------------------------------------------------------------------------
// code for saving all ST buffers
#ifdef MC_ST_SAVE_ALL_BUFFERS
  bool trMcSTBufferR::SaveAllBuffers(trMcSTBPrmGen *prPG, trMcSTBPrmCSA *prPCSA,
						trMcSTBPrmRA  *prPRA, trMcSTBPrmAR  *prPAR,
						trCashedBufferN* prSpcBuffer, trCashedBufferN* prSpcStatBuffer,
						trCashedBufferN* prPixBuffer, long nSize, short nChannels,
						trMcSTProgressCallback* prCallback)

  {
	int nProgress = 0;
	if (prCallback) prCallback->ShowProgress(0);

	nSpcBufSize = nSize * (prPG->nH + 3) * sizeof(float);
	nSpcStatBufSize = nSize * (2 + prPRA->rB.nNB) * sizeof(float);
	nPixBufSize = nSize * (prPG->nH + 2) * sizeof(short);

	HANDLE nFile = GetFile(false);

	DWORD nBytes;

	// size
	::WriteFile(nFile, (void*) &nSize, sizeof(long), &nBytes, NULL);

	// borders
	::SetFilePointer(nFile, 3 * sizeof(long), NULL, FILE_BEGIN);

	// channels
	::WriteFile(nFile, (void*) &nChannels, sizeof(short), &nBytes, NULL);

	// trMcSTBPrmGen
	::WriteFile(nFile, (void*) prPG, sizeof(trMcSTBPrmGen), &nBytes, NULL);

	// trMcSTBPrmCSA
	::WriteFile(nFile, (void*) prPCSA, sizeof(trMcSTBPrmCSA), &nBytes, NULL);

	// trMcSTBPrmRA
	::WriteFile(nFile, (void*) prPRA, sizeof(trMcSTBPrmRA), &nBytes, NULL);

	// trMcSTBPrmAR
	::WriteFile(nFile, (void*) prPAR, sizeof(trMcSTBPrmAR), &nBytes, NULL);


	int nHeaderOffset = 3 * sizeof(long) + sizeof(short) + sizeof(trMcSTBPrmGen) +
						sizeof(trMcSTBPrmCSA) + sizeof(trMcSTBPrmRA) + sizeof(trMcSTBPrmAR);

	long nSrcBufSize = MIN(prSpcBuffer->N(), MIN(prSpcStatBuffer->N(), prPixBuffer->N()));

	long nL = 0, nR = 0;
	bool bLast = false;
	float fPart = MIN( (float) nSrcBufSize / nSize, 1.);
	nSigFrom = -1;
	while(nR < nSize)
	{
	  nR = MIN(nL + nSrcBufSize, nSize - 1);
	  bLast = nR == nSize - 1;

	  // calculate

	  long nSL = nL * prPG->fhH,
		   nSR = nR * prPG->fhH + 1;
	  prSpcBuffer->Update(&nSL, &nSR);
	  if (prCallback) prCallback->ShowProgress(nProgress + fPart * 33);
	  prSpcStatBuffer->Update(&nL, &nR);
	  if (prCallback) prCallback->ShowProgress(nProgress + fPart * 66);
	  prPixBuffer->Update(&nL, &nR);
	  if (prCallback) prCallback->ShowProgress(nProgress + fPart * 100);

	  if (nSigFrom == -1) nSigFrom = nL;
	  if (nR >= 0 ) nSigTo = nR;
	  if (nR <= nL) break;

	  for( short ng = 0; ng < nChannels; ng++ )
	  {
		// signal
		::SetFilePointer(nFile,
		  nHeaderOffset + ng * nSpcBufSize + nSL * prSpcBuffer->M(), NULL, FILE_BEGIN);
		::WriteFile(nFile, (void*) prSpcBuffer->Pos(0, ng),
		  (nSR - nSL + 1) * prSpcBuffer->M(), &nBytes, NULL);

		::SetFilePointer(nFile,
		  nHeaderOffset + nSpcBufSize * nChannels + ng * nSpcStatBufSize + nL * prSpcStatBuffer->M(), NULL, FILE_BEGIN);
		::WriteFile(nFile, (void*) prSpcStatBuffer->Pos(0, ng),
		  (nR - nL + 1) * prSpcStatBuffer->M(), &nBytes, NULL);

		::SetFilePointer(nFile,
		  nHeaderOffset + nSpcBufSize * nChannels + nSpcStatBufSize * nChannels +
		  ng * nPixBufSize + nL * prPixBuffer->M(), NULL, FILE_BEGIN);
		::WriteFile(nFile, (void*) prPixBuffer->Pos(0, ng),
		  (nR - nL + 1) * prPixBuffer->M(), &nBytes, NULL);
	  }

	  nProgress += fPart * 100;
	  nL = nR + 1;
	}

	// write borders
	::SetFilePointer(nFile, sizeof(long), NULL, FILE_BEGIN);
	::WriteFile(nFile, (void*) &nSigFrom, sizeof(long), &nBytes, NULL);
	::WriteFile(nFile, (void*) &nSigTo, sizeof(long), &nBytes, NULL);

	::CloseHandle(nFile);

	if (prCallback) prCallback->ShowProgress(100);

	return bLast;
  }

//------------------------------------------------------------------------------

  bool trMcSTBufferR::LoadFile(trMcSTBPrmGen *prPG, trMcSTBPrmCSA *prPCSA,
							   trMcSTBPrmRA  *prPRA, trMcSTBPrmAR  *prPAR, short* pnChannels)
  {
    if (!bInit) return false;

	if (nFile != INVALID_HANDLE_VALUE)
	  ::CloseHandle(nFile);
	nFile = GetFile(true);

	if (nFile == INVALID_HANDLE_VALUE) return false;

	DWORD nBytes;

	// size
	long nSize;
	::WriteFile(nFile, (void*) &nSize, sizeof(long), &nBytes, NULL);

	// borders
	::WriteFile(nFile, (void*) &nSigFrom, sizeof(long), &nBytes, NULL);
	::WriteFile(nFile, (void*) &nSigTo, sizeof(long), &nBytes, NULL);

	// channels
	::WriteFile(nFile, (void*) &nChanNumber, sizeof(short), &nBytes, NULL);
	if (pnChannels) *pnChannels = nChanNumber;

	// trMcSTBPrmGen
	::WriteFile(nFile, (void*) prPG, sizeof(trMcSTBPrmGen), &nBytes, NULL);

	// trMcSTBPrmCSA
	::WriteFile(nFile, (void*) prPCSA, sizeof(trMcSTBPrmCSA), &nBytes, NULL);

	// trMcSTBPrmRA
	::WriteFile(nFile, (void*) prPRA, sizeof(trMcSTBPrmRA), &nBytes, NULL);

	// trMcSTBPrmAR
	::WriteFile(nFile, (void*) prPAR, sizeof(trMcSTBPrmAR), &nBytes, NULL);

	nSpcBufSize = nSize * (prPG->nH + 3) * sizeof(float);
	nSpcStatBufSize = nSize * (2 + prPRA->rB.nNB) * sizeof(float);
	nPixBufSize = nSize * (prPG->nH + 2) * sizeof(short);

    return true;
  }

//------------------------------------------------------------------------------

  bool trMcSTBufferR::GetBufferLimits(long* plFrom, long* plTo, short nType)
  {
	if (!bInit) return false;

	if (plFrom) *plFrom = nSigFrom;
	if (plTo) *plTo = nSigTo;

	if (nType == MC_ST_SPC_BUF)
	{
	  if (plFrom) *plFrom = *plFrom * rPG.fhH;
	  if (plTo) *plTo = *plTo * rPG.fhH + 1;
	}

	return true;
  }

//------------------------------------------------------------------------------

  char* trMcSTBufferR::GetBufferData(long nFrom, long nSize, long nChan, short nType)
  {
	if (!bInit || nSpcBufSize <= 0) return NULL;

	int nHeaderOffset = 3 * sizeof(long) + sizeof(short) + sizeof(trMcSTBPrmGen) +
						sizeof(trMcSTBPrmCSA) + sizeof(trMcSTBPrmRA) + sizeof(trMcSTBPrmAR);
	DWORD nBytes;

	switch(nType)
	{
	  case MC_ST_SPC_BUF:
	  {
		::SetFilePointer(nFile,
		  nHeaderOffset + nChan * nSpcBufSize + nFrom - nSigFrom, NULL, FILE_BEGIN);
		::ReadFile(nFile, (void*) acBuffer, nSize, &nBytes, NULL);

		break;
	  }
	  case MC_ST_SPC_STAT_BUF:
	  {
		::SetFilePointer(nFile,
		  nHeaderOffset + nSpcBufSize * nChanNumber + nChan * nSpcStatBufSize + nFrom - nSigFrom,
		  NULL, FILE_BEGIN);
		::ReadFile(nFile, (void*) acBuffer, nSize, &nBytes, NULL);

		break;
	  }
	  case MC_ST_PIX_BUF:
	  {
		::SetFilePointer(nFile,
		  nHeaderOffset + nSpcBufSize * nChanNumber + nSpcStatBufSize * nChanNumber + nChan * nPixBufSize + nFrom - nSigFrom,
		  NULL, FILE_BEGIN);
		::ReadFile(nFile, (void*) acBuffer, nSize, &nBytes, NULL);

		break;
	  }
	}

	return acBuffer;
  }

#endif

//------------------------------------------------------------------------------
// Code for trMcSpcTrendPrmTA2 -------------------------------------------------
//------------------------------------------------------------------------------

trMcSpcTrendPrmTA2::trMcSpcTrendPrmTA2(trMcSpcTrendPrmTA rPrm)
{
  bAveragedMode = rPrm.nSpcMode == trMcSpcTrendPrmTA::Averaged;
  bSymmAvr = rPrm.bSymmAvr;
  nK = rPrm.nK;
  nWinType = rPrm.nWinType;
  fThr = rPrm.fThr;
  fTMax = rPrm.fTMax;
}

trMcSpcTrendPrmTA trMcSpcTrendPrmTA2::GetData()
{
  trMcSpcTrendPrmTA rPrm;
  rPrm.nSpcMode = bAveragedMode ? trMcSpcTrendPrmTA::Averaged : trMcSpcTrendPrmTA::Adaptive;
  rPrm.bSymmAvr = bSymmAvr;
  rPrm.nK = nK;
  rPrm.nWinType = nWinType;
  rPrm.fThr = fThr;
  rPrm.fTMax = fTMax;
  return rPrm;
}

//------------------------------------------------------------------------------
// Externals -------------------------------------------------------------------
//------------------------------------------------------------------------------

trMcSTBuffer* McCreateSTBuffer()
{
  return (trMcSTBuffer*) new trMcSTBufferR();
}
