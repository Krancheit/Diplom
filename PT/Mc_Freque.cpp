//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <mmsystem.h>  // timer functions (timeSetEvent(), ...)
#include <stdio.h>     // sprintf()

#include "Cw_appl.hpp"
#include "Cw_util.hpp"
#include "utllist.h"


#include "Mc_Freque.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MLMultiLangMain"
#pragma resource "*.dfm"

//Defines

 TFormParamSin *FormParamSin;


 static bool boolInitialized = false;   // not enable

 static double one = 1;                 // dont even need



 //---------------------------------------------------------------------------
 bool McEditSetFreq(void )
{
  TFormParamSin *rFreq = NULL;

  try
  {
	rFreq = new TFormParamSin( Application, &rDataFreq );
	/*if (pbShowViewPage && !*pbShowViewPage)
	  prF->TabSheetView->TabVisible = false;*/
	rFreq->ShowModal();
	bool bResult = (rFreq->ModalResult == mrOk);
	rFreq->Release();
	return bResult;
  }
  catch(...)
  {
	if( rFreq )
	  rFreq->Release();
	return false;
  }
}

//---------------------------------------------------------------------------
__fastcall TFormParamSin::TFormParamSin(
TComponent* Owner, McSpectrDataFreq * prFreq,McFreqApply *prFreqAAp)
	: TForm(Owner)
{
	prFreqIn = prFreq;
	rFreqIn = *prFreq;
	rFreqApplied = rFreqOut = *prFreq;

	prFreqAp = prFreqAAp;

	 BlockChangings = true;


	TrackBarMaxFreq   -> Min = 11;
	TrackBarMaxFreq   -> Max = 20;
	//TrackBarMaxFreq   -> Frequency = 1;
	TrackBarMaxFreq   -> Position = rFreqIn.frqmax;

	TrackBarMinFreq   -> Min = 5;
	TrackBarMinFreq   -> Max = 10;
	//TrackBarMinFreq   -> Frequency = 1;
	TrackBarMinFreq   -> Position = rFreqIn.frqmin;

	TrackBarDeltaFreq -> Min = 1;
	TrackBarDeltaFreq -> Max = 4;
	//TrackBarDeltaFreq -> Frequency = 1;
	TrackBarDeltaFreq -> Position = rFreqIn.frqdelta;

	TrackBarPeriod    -> Min = 2;
	TrackBarPeriod    -> Max = 20;
	//TrackBarPeriod    -> Frequency = 1;
	TrackBarPeriod    -> Position = rFreqIn.timeper;

	pnlMaxFreq   -> Caption = TrackBarMaxFreq   -> Position / 1.0;
	pnlMinFreq   -> Caption = TrackBarMinFreq   -> Position / 1.0;
	pnlDeltaFreq -> Caption = TrackBarDeltaFreq -> Position / 1.0;
	pnlPeriod    -> Caption = TrackBarPeriod    -> Position / 1.0;

	BlockChangings = false;

}

void TFormParamSin::RestoreFreqOptions(McSpectrDataFreq  * prFreq)
{
	BlockChangings = true;

	TrackBarMaxFreq   -> Position = rFreqIn.frqmax;
	pnlMaxFreq   -> Caption = TrackBarMaxFreq   -> Position;

	TrackBarMinFreq   -> Position = rFreqIn.frqmin;
	pnlMinFreq   -> Caption = TrackBarMinFreq   -> Position;

	TrackBarDeltaFreq -> Position = rFreqIn.frqdelta;
	pnlDeltaFreq -> Caption = TrackBarDeltaFreq -> Position;

	TrackBarPeriod    -> Position = rFreqIn.timeper;
	pnlPeriod    -> Caption = TrackBarPeriod    -> Position;

	BlockChangings = false;
}


void TFormParamSin::ReadParamFreq (McSpectrDataFreq *prFreqConfig)
{
	Application->ProcessMessages();
	rFreqOut.frqmax   = TrackBarMaxFreq  -> Position / 1.0;
	rFreqOut.frqmin   = TrackBarMinFreq  -> Position / 1.0;
	rFreqOut.frqdelta = TrackBarDeltaFreq-> Position / 1.0;
	rFreqOut.timeper  = TrackBarPeriod   -> Position / 1.0;
}
//---------------------------------------------------------------------------

void __fastcall TFormParamSin::btnDefaultClick(TObject *Sender)
{
	McSpectrDataFreq rDefault;
    McSpectrDataFreq rD = rDefault;
    rFreqOut = rDefault;
    RestoreFreqOptions(&rDefault);
}
//---------------------------------------------------------------------------
	  

void __fastcall TFormParamSin::TrackBarChange(TObject *Sender)
{
   BlockChangings = true;

	char s[32];

	if (Sender == TrackBarMaxFreq) {

	  double FMax = TrackBarMaxFreq -> Position;

	  sprintf(s,"%.2f",FMax);

      rFreqApplied.frqmax = FMax;

	  pnlMaxFreq -> Caption = s;

      return;

    }

    if (Sender == TrackBarMinFreq) {

	  double FMin = TrackBarMinFreq -> Position;

	  sprintf(s,"%.2f",FMin);
      rFreqApplied.frqmin = FMin;

      pnlMinFreq -> Caption = s;

      return;
	}

    if (Sender == TrackBarDeltaFreq) {

	  double FDelta = TrackBarDeltaFreq -> Position;

	  sprintf(s,"%.2f",FDelta);

      rFreqApplied.frqdelta = FDelta;

      pnlDeltaFreq -> Caption = s;
      return;
	}

	if (Sender == TrackBarPeriod) {

	  double FPeriod = TrackBarPeriod -> Position;

	  sprintf(s,"%.2f",FPeriod);

	  rFreqApplied.timeper = FPeriod;

      pnlPeriod -> Caption = s;
      return;
	}

	ReadParamFreq(&rFreqOut);
}


//---------------------------------------------------------------------------
 /*	void BrGetSpcTrendFreq(McSpectrDataFreq prDataFreq)
 {
	 if ( prDataFreq )
	*prDataFreq = rDataFreq;

  return prDataFreq ? prDataFreq : &rDataFreq;
 }


 void BrSetSpcTrendFreq(McSpectrDataFreq prDataFreq)
 {
	 rDataFreq = *prDataFreq;
 }        */
//---------------------------------------------------------------------------

void __fastcall TFormParamSin::btnOKClick(TObject *Sender)
{
	if(Sender == btnOK)
	{
		ReadParamFreq(&rFreqOut);
	}
	bool ToBeApplied = ((Sender == btnOK) && (!(rFreqOut == rFreqApplied)));

	if( (Sender == btnCancel) && !(rFreqIn == rFreqApplied) )
  {
	rFreqOut = rFreqIn;
	ToBeApplied = true;
  }

   if( Sender == btnCancel || (rFreqIn == rFreqOut && rFreqOut == rFreqApplied) )
  {
	ModalResult = mrCancel;
	return;
  }


  *prFreqIn = rFreqOut;

  //rDataFreq = rFreqOut;

  ModalResult = mrOk;
}
//---------------------------------------------------------------------------


/*void __fastcall TFormParamSin::FormShow(TObject *Sender)
{
	if (rFreqOut != rFreqIn) {
			rFreqIn = rFreqOut;
	}
	else
			return;
	RestoreFreqOptions(rFreqIn);
} */
//---------------------------------------------------------------------------

