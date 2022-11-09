/*************************************************************************
  Module
	Save and export ST
  File
	 Mc_SpectrTrendStorage.h
*************************************************************************/

//---------------------------------------------------------------------------

#ifndef Mc_SpectrTrendStorageH
#define Mc_SpectrTrendStorageH

//---------------------------------------------------------------------------
// Includes -----------------------------------------------------------------
//---------------------------------------------------------------------------

#include <Mc_Objects.h>
#include <Mc_SpectrTrendBuffers.h>

//---------------------------------------------------------------------------
// Defines ------------------------------------------------------------------
//---------------------------------------------------------------------------

// if save all buffers
//#define MC_ST_SAVE_ALL_BUFFERS

// defines for types of buffer
#ifdef MC_ST_SAVE_ALL_BUFFERS
  #define MC_ST_SPC_BUF 0
  #define MC_ST_SPC_STAT_BUF 1
  #define MC_ST_PIX_BUF 2
#endif

//------------------------------------------------------------------------------
// Types -----------------------------------------------------------------------
//------------------------------------------------------------------------------

struct trMcSTBuffer
{
  virtual ~trMcSTBuffer() {}

  virtual bool Init(            // initialize object
	TrMcExamine* prExam,        // (In) examine object
	trMcSpcTrendProc * prSTP,   // (In) trend spectrums' processor
	char** ppcChanNames,        // (In) channel names
	long nSpcInBuf              // (In) max. number of multi-channel spectrums saved in buffer
				   ) = 0;       // returns false if failed

  virtual bool Save(            // save spectrum
	long nSize,                 // (In) signal size
	trMcSTProgressCallback* prCallback = NULL // (In/Opt) callback for showing progress
	) = 0;                      // returns false if failed

  virtual bool IsSaved(         // check if file contains proper spectrum
	bool bUpdate = false        // (In/Opt) flag, if update parameters from spectrum DS
	) = 0;                      // returns true iff file contains proper spectrum

  virtual bool GetLimits(       // get limits of stored spectrum
	long* plFrom, long* plTo    // (Out) limits
	) = 0;                      // returns false if failed

  virtual bool GetSpectrum(     // get spectrum
	long nFrom, long nTo,       // (In) interval
	float** ppfS                // (Out) spectrum data
	) = 0;                      // returns false if failed

  virtual bool Export() = 0;    // export ST to external util



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
	  trMcSTProgressCallback* prCallback = NULL // (In/Opt) callback for showing progress
					   ) = 0;           // returns false if failed

	virtual bool LoadFile(              // read file with ST
	  trMcSTBPrmGen *prPG,              // (Out) general parameters for all trend
	  trMcSTBPrmCSA *prPCSA,            // (Out) parameters for CSA
	  trMcSTBPrmRA  *prPRA,             // (Out) parameters for relative amplitudes
	  trMcSTBPrmAR  *prPAR,             // (Out) parameters for the AR trend
	  short* pnChannels                 // (Out) number of channels
	  ) = 0;                            // returns false if failed

	virtual bool GetBufferLimits(       // get limits of stored signal
	  long* plFrom, long* plTo,         // (Out) limits
	  short nType                       // (In) type of buffer (see defines)
					   ) = 0;           // returns false if failed

	virtual char* GetBufferData(        // get data
	  long nFrom,                       // (In) left border
	  long nSize,
	  long nChan,                       // (In) channel number
	  short nType                       // (In) type of buffer (see defines)
					   ) = 0;  // returns pointer to giving data or NULL if failed

  #endif

};

//------------------------------------------------------------------------------
// Externals -------------------------------------------------------------------
//------------------------------------------------------------------------------

trMcSTBuffer* McCreateSTBuffer();

//---------------------------------------------------------------------------
#endif
