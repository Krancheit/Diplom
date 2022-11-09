//---------------------------------------------------------------------------
/************************************************************************
 Main window of project
 	file
 SpektDraw.cpp
************************************************************************/

#include <vcl.h>
#pragma hdrstop
#include <Windows.h>
#include <string>
#include <stdlib.h>


#include <stdio.h>      // sprintf
#include "SpektDraw.h"
#include "Mc_SpectrTrendSettings.h"
#include "Mc_Freque.h"

#ifndef CFREE
  #define CFREE( p )  { if(p) { free(p); p = NULL; } }
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Mc_SpectrTrendHi"
#pragma resource "*.dfm"
TFormSpectrTrend *FormSpectrTrend;


//---------------------------------------------------------------------------
/*
#define FRQ_MI     5.     // freq. of sinusoid (Hz) for the first channel
#define FRQ_MA     15.    // freq. of sinusoid for the last channel
#define FRQ_DLT    4      // curr. freq of sinusoid varies in +-FRQ_DLT Hz
#define TIME_DLT   10.   */ // trend of frq. is periodic with this period (Sec)

#define S_RATE     500.   // sample rate (Hz)
#define N_CHANNELS 3      // number of channels

#ifndef MAX
  #define MAX( A, B )  (( (A) > (B) ) ? (A) : (B))
#endif
/*
struct trMcSpcTrendDataSourceR : trMcSpcTrendDataSource
{
  trMcSpcTrendDataSourceR()
  {
	pData = NULL;
	fCFrq = 2*M_PI/S_RATE;
	nChn  =  N_CHANNELS;
	fFrqStep = (nChn > 1) ? (FRQ_MA - FRQ_MI)/(nChn - 1.) : 0.;
	lT = TIME_DLT * S_RATE;
  }

#else
	for (long i = 0; i < lHowMany; i++)
	{
	  long lK = ((i+lFrom) / lT) % 3;
	  double fDF = (lK == 1) ? 0 : (lK == 2) ? FRQ_DLT : -FRQ_DLT;

	  for( short nCh = 0; nCh < nChn; nCh++ )
	  {
#define FRQ_STEP

#ifdef FRQ_STEP
		double fFrq = (FRQ_MI + fFrqStep*nCh) + fDF;
#else
		double fFrq = (FRQ_MI + fFrqStep*nCh);

*/



struct trMcSpcTrendDataSourceR : trMcSpcTrendDataSource
{
  trMcSpcTrendDataSourceR(McSpectrDataFreq * prfreq)
  {

	prFreq = prfreq;
	pData = NULL;
	fCFrq = 2*M_PI/S_RATE;
	nChn  =  N_CHANNELS;
	fFrqStep = (nChn > 1) ? ((prFreq ->frqmax) -
	(prFreq ->frqmin ))/(nChn - 1.) : 0.;
	lT = (prFreq ->timeper) * S_RATE;
  }

  virtual void CheckBoards( long *plF, long *plT )  // check if there is signal in [*plF, *plT]
  {
	 *plF = MAX(*plF, 0);
	 if( *plT >= *plF )
	   return;

	 *plF = *plT = - 1;
   }

  virtual short* Get( long lFrom, long lHowMany, long *plHowMany )
  {

	if( lFrom < 0 )
	  return NULL;

	CFREE( pData );

	if( !(bool)(pData = (short*) calloc(lHowMany, nChn*sizeof(short))) )
	{ *plHowMany = 0;  return NULL; }

	for (long i = 0; i < lHowMany; i++)
	{
	  long lK = ((i+lFrom) / lT) % 3;
	  double fDF = (lK == 1) ? 0 : (lK == 2) ? (prFreq ->frqdelta)
	  : -(prFreq ->frqdelta);

	  for( short nCh = 0; nCh < nChn; nCh++ )
	  {
		double fFrq = ((prFreq ->frqmin) + fFrqStep*nCh) + fDF;
		long lI = i * nChn;
		pData[lI + nCh] = (short) 100*sin(fCFrq*fFrq*(i+lFrom));
	  }
	}


	*plHowMany = lHowMany;

	return pData;
  }

  virtual ~trMcSpcTrendDataSourceR() { CFREE( pData ); }

  //McSpectrDataFreq *prfreq;
private:
  short *pData;
  double fCFrq;     // frq. constant
  double fFrqStep;  // step for frequency incrementing frq. for channels with higher numbers
  long lT;          // period of time (in signal points) for freq. trend
  short nChn;       // number of channels
  McSpectrDataFreq *prFreq;
};

//---------------------------------------------------------------------------
__fastcall TFormSpectrTrend::TFormSpectrTrend(TComponent* Owner)
		: TForm(Owner)
{
  SpTr = McCreateSpectrTrend( this->Panel1, this, this );
  prDS = (trMcSpcTrendDataSource*) (new trMcSpcTrendDataSourceR(&rDataFreq));



  rD.prDS = prDS;
  rD.nNmbCh = N_CHANNELS;
  rD.nNmbChOut = rD.nNmbCh;
  rD.nSampRate = S_RATE;
  rD.fUPT = 6;
  static bool abChn[100];
  for( short nCh = 0; nCh < rD.nNmbCh; nCh++ )
    abChn[nCh] = true;

  rP.fTR = 100;         // Right time point (sec.) (same for signal on screen & trend)   !!!
  rP.fTScr = 10;        // length of time segment of signal on screen ([fTR-fTScr, fTR])
}
//---------------------------------------------------------------------------
__fastcall TFormSpectrTrend::~TFormSpectrTrend()
{
  delete (prDS);
}

//---------------------------------------------------------------------------

void __fastcall TFormSpectrTrend::FormShow(TObject *Sender)
{
  char aasChNames[N_CHANNELS][8];
  char * apsCN[N_CHANNELS];
  for( short nCh = 0; nCh < N_CHANNELS; nCh++ )
  {
    apsCN[nCh] = aasChNames[nCh];
    strcpy( aasChNames[nCh], ((AnsiString)IntToStr(nCh)).c_str() );
  }

  rP.prCallback = &rSTCallback;
  SpTr->Init(&rD, &rP, apsCN );
  EditTime->Text = "1";

  trMcSpectrTrendSettings* prSpTrend = BrGetSpcTrendSettings( NULL );
  float fStartTime = rP.fTR - ((SpTr->PaintBoxTrends->Width)/(prSpTrend->rPI.fPixPerSec));
  LabelToTime->Caption = AnsiString(rP.fTR);
  char s[32];
  sprintf(s, "%.1f", fStartTime);
  LabelFromTime->Caption = s;
}
//---------------------------------------------------------------------------

void __fastcall TFormSpectrTrend::ButtonFwdClick(TObject *Sender)
{
  float fSec = (EditTime->Text).ToDouble();
  // (for debug purposes?) we change the right time boundary
  // using 4 buttons

  if (Sender == ButtonFwd)
  rP.fTR += fSec;
  else
  if (Sender == ButtonRew)
    rP.fTR -= fSec;
  else
  if (Sender == ButtonFastFwd)
    rP.fTR += 4*fSec;
  else
  if (Sender == ButtonFastRew)
    rP.fTR -= 4*fSec;
 /* else
  if (Sender == ButtonAuto)
     rP.fTR += fSec;
  else
         */
  SpTr->Control(&rP);

  trMcSpectrTrendSettings* prSpTrend = BrGetSpcTrendSettings( NULL );
  LabelToTime->Caption = AnsiString(rP.fTR);
  float fStartTime = rP.fTR - (SpTr->PaintBoxTrends->Width)/(prSpTrend->rPI.fPixPerSec);
  char s[32];
  sprintf(s, "%.1f", fStartTime);
  LabelFromTime->Caption = s;
}
//---------------------------------------------------------------------------

