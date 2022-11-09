/*************************************************************************
  Module
    Settings for spectrums' trend in time
  File
     Mc_SpectrTrendSettings.cpp
  Comment

  Modified
    Date      Person		        Comment
  ----------------------------------------------------------------------
    15-Aug-19 Abasov E.         Apply !=NULL changes
    28-Nov-16 Larionov V.       Changes
    11-Aug-15 Larionov V.       Changes
    05-Sep-13 Larionov V.       Total changes
    21-Jul-13 Larionov V.       Fixes
    26-Oct-12 Larionov V.       Changes
    08-Feb-12 Abasov E.         DFM changes
    05-May-10 Bellucci D.       Translations added/checked
    17-Mar-10 Yurovskiy         First tab page made active !!Please don't modify
    23-Nov-09 Bellucci D.       Translations added/checked
    11-Mar-08 Yurovskiy         First page in tab list is set to be default
    22-May-07 Yurovakiy         Fixes
    17-May-07 Bellucci D.       Italian and English translations.
    19-Feb-07 Yurovskiy         Cosmetics & fixes; TrLineCMBX fixed
    27-Jan-07 Yurovskiy         Displaying of trend higher than SEF made optional
    17-Jan-07 Yurovskiy         AR trend disabling fixed
    09-Dec-06 Yurovskiy         flag in .ini for enabling/disabling AR trend
    03-Nov-06 Yurovskiy         averaging of spectrums modified, new controls added
    27-Oct-06 Yurovskiy         new controls for SEF added
    16-Oct-06 Yurovskiy         parameters for amplitude trend added
    28-Jun-06 Bellucci D.       Italian translation
    21-Jun-06 Yurovskiy         Settings for spectrum time segment made dependant upon
                                max. possible trend length & ext. information
     < .................................... >
    31-Aug-05 Chernyavskiy A.   Changes
*************************************************************************/


//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <mmsystem.h>  // timer functions (timeSetEvent(), ...)
#include <stdio.h>     // sprintf()

#include "Cw_appl.hpp"
#include "Cw_util.hpp"
#include "utllist.h"

#include "Mc_CfgEnergyRatioTrend.h"
#include "Mc_ScaleRulers.h"
#include "Mc_SpectrTrendProc.h" // for MC_STP_MIN_SPC_PNT
#include "Mc_SpectrTrendSettings.h"

#include "Mc_FreqBandsForm.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MLMultiLangMain"
#pragma resource "*.dfm"

// Defines ------------------------------------------------------------------
const short LINE_TYPE_THIN   = 0;
const short LINE_TYPE_MEDIUM = 1;
const short LINE_TYPE_THICK  = 2;
const short LINES_NMB        = 3;
#define RINT_P( a)     (int) ( (a) + 0.5 )
#define BVAL( a, m, M )  ((a > M) ? M : (a < m) ? m : (a));

//---------------------------------------------------------------------------
//  TrLineCMBX
//---------------------------------------------------------------------------
TrLineCMBX::TrLineCMBX() : nType(LINE_TYPE_THIN), pComboBox(0), OnTypeChange(0)
{
  pImageList    = 0;
  BackColor     = (TColor) RGB(160, 160, 160);
  LineBackColor = clWhite;
  LineForeColor = clBlack;
}

//---------------------------------------------------------------------------
TrLineCMBX::~TrLineCMBX()  { Free(); }

//---------------------------------------------------------------------------
void TrLineCMBX::Free()
{
  if (pImageList)
    pImageList->Free();
}

//---------------------------------------------------------------------------
void TrLineCMBX::Alloc(const TRect &rRect)
{
  if (!pImageList)
  {
    pImageList               = new TImageList(pComboBox->Owner);
    pImageList->ImageType    = itImage;
    pImageList->DrawingStyle = TDrawingStyle::dsNormal;
    pImageList->Height       = rRect.Height();
    pImageList->Width        = rRect.Width();
    pImageList->BkColor      = Graphics::clNone;
    pImageList->BlendColor   = Graphics::clNone;
    pImageList->ShareImages  = false;
  }

  pImageList->Clear();

  for (short i = 0; i < LINES_NMB; ++i)
  {
    Graphics::TBitmap *pBMP = new Graphics::TBitmap();
    pBMP->HandleType        = bmDIB;
    pBMP->PixelFormat       = pf16bit;
    pBMP->Width             = rRect.Width();
    pBMP->Height            = rRect.Height();

    DrawLine(pBMP->Canvas, i, pBMP->Width, pBMP->Height);
    pImageList->Add(pBMP, 0);
    delete pBMP;
  }
}

//---------------------------------------------------------------------------
void TrLineCMBX::DrawLine(TCanvas *prC, short nAType, long nWidth, long nHeight)
{
  long nOW      = prC->Pen->Width;
  TPenStyle psO = prC->Pen->Style;
  TColor cBO    = prC->Brush->Color;
  TColor cPC    = prC->Pen->Color;
  TPenMode pmO  = prC->Pen->Mode;

  prC->Pen->Mode = pmCopy;
  prC->Brush->Color = BackColor;
  prC->FillRect( Rect(0, 0, nWidth, nHeight) );

  TPoint aPoints[2];
  aPoints[0] = Point(0, nHeight/2);
  aPoints[1] = Point(nWidth, nHeight/2);

  if( nAType != LINE_TYPE_THIN )
  {
    prC->Brush->Color = LineBackColor;
    long nI = nAType == LINE_TYPE_MEDIUM ? 0 : 1;
    prC->FillRect( Rect(0, nHeight/2 - nI, nWidth, nHeight/2 + nI + 1) );
  }

  int oldbk = SetBkMode(prC->Handle, TRANSPARENT);

  prC->Pen->Width = 1;
  prC->Pen->Style = psDot;

  prC->Pen->Color = (nAType == LINE_TYPE_THIN) ? LineBackColor : LineForeColor;
  prC->Polyline( aPoints, 1 );

  SetBkMode(prC->Handle, oldbk);

  prC->Pen->Width   = nOW;
  prC->Pen->Style   = psO;
  prC->Brush->Color = cBO;
  prC->Pen->Color   = cPC;
  prC->Pen->Mode    = pmO;
}

//---------------------------------------------------------------------------
void TrLineCMBX::Init(TComboBox *pAComboBox)
{
  Free();

  pComboBox             = pAComboBox;
  OldOnDrawItem         = pComboBox->OnDrawItem;
  pComboBox->OnDrawItem = ComboBoxDrawItem;

  pComboBox->Items->Clear();

  for (short i = 0; i < LINES_NMB; ++i)
    pComboBox->Items->Add("");

  OldWndProc = pComboBox->Parent->WindowProc;
  pComboBox->Parent->WindowProc = WndProc;
}

//---------------------------------------------------------------------------
void __fastcall TrLineCMBX::WndProc(Messages::TMessage &Message)
{
  if ( (Message.Msg == WM_COMMAND) && (HIWORD(Message.WParam)/*Message.WParamHi*/ == CBN_SELENDOK))
    if (OnTypeChange)
      OnTypeChange(pComboBox, pComboBox->ItemIndex);

  OldWndProc(Message);
}

//---------------------------------------------------------------------------
void TrLineCMBX::SetType(short nAType)  { pComboBox->ItemIndex = nAType; nType = nAType; }

//---------------------------------------------------------------------------
void __fastcall TrLineCMBX::ComboBoxDrawItem(TWinControl *Control, int Index,
  const TRect &Rect, TOwnerDrawState State)
{
  if (!pImageList)
    Alloc(TRect(0, 0, pComboBox->Width, Rect.Height()));

  nType = Index;

  pComboBox->Canvas->FillRect(Rect);
  pImageList->Draw(pComboBox->Canvas, Rect.Left, Rect.Top, nType, pComboBox->Enabled);

  if (OldOnDrawItem)
    OldOnDrawItem(Control, Index, Rect, State);
}

// Locals (declarations) ----------------------------------------------------
//---------------------------------------------------------------------------
static anScaleGrades[MC_STD_MAX_NMB_COLORS]; // possible values of scale grades (filled by the form's constructor)
static nScaleGrades;                         // number of values in anScaleGrades[]

static trMcSpectrTrendSettings rSettings;    // default constructors
static bool bInitialized = false;
static bool bEnableARTrend = false;          // !!! tmp: Enable setting parameters for the AR trend if it is set in .ini

static void ReadFromIniFile( void );         // read rSettings from .ini
static void WriteToIniFile( void );          // write rSettings to .ini

static void DrawRuler( TCanvas *prC, TRect rR ); // draw ruler in given rectangle
static void DrawBandBar( TCanvas *prC, TRect rR, trMcSTBPrmRA* prRA ); // draw colored bar


//  Source of globals -------------------------------------------------------
//---------------------------------------------------------------------------

// External | Get config. structure -----------------------------------------
trMcSpectrTrendSettings *BrGetSpcTrendSettings( trMcSpectrTrendSettings *prSettings )
{
  if( !bInitialized )
    ReadFromIniFile();

  bInitialized = true;

  rSettings.rPI.bDisplayARTrend = rSettings.rPI.bDisplayARTrend && bEnableARTrend; // !!!tmp

  if ( prSettings )
    *prSettings = rSettings;

  return prSettings ? prSettings : &rSettings;
} // ***

//---------------------------------------------------------------------------
void BrSetSpcTrendSettings( trMcSpectrTrendSettings *prSettings )
{
  rSettings = *prSettings;
  WriteToIniFile();
} // ***

// External | main proc. ----------------------------------------------------
bool McEditSpectrTrendSettings(trMcSpectrTrendSettings  *prC,
							   trMcSpectrTrendBoards *prB, trMcApplyObj *prAP, bool* pbShowViewPage, bool* pbMGA)
{
  TFormSpectrTrendSettings *prF = NULL;

  try
  {
	prF = new TFormSpectrTrendSettings( Application, 0, prB, prC, prAP, pbMGA );
	if (pbShowViewPage && !*pbShowViewPage)
	  prF->TabSheetView->TabVisible = false;
    prF->ShowModal();
    bool bResult = (prF->ModalResult == mrOk);
    prF->Release();
    return bResult;
  }
  catch(...)
  {
    if( prF )
      prF->Release();
    return false;
  }
} // ***

TFormSpectrTrendSettings *FormSpectrTrendSettings;

//---------------------------------------------------------------------------
__fastcall TFormSpectrTrendSettings::TFormSpectrTrendSettings(
     TComponent* Owner, short nMode, trMcSpectrTrendBoards * prAB,
     trMcSpectrTrendSettings * prC, trMcApplyObj *prAAP, bool* pbMGA)
        : TForm(Owner)
{
  if( !bInitialized )
    ReadFromIniFile();  // for bEnableARTrend - tmp !!!
  //GroupBoxARTrend->Visible = bEnableARTrend;

  MultiLang1->CurrentLang = CwApplGetLanguage(CwApplGetProfile(), "");
  prCIn = prC;
  rCIn = rCApplied = rCOut = *prC;

  prAP = prAAP;
  prB = prAB;

  fFrqTime = prC->rPP.rSC.GetMaxFrqTime( prC->rPP.rFC );
  fFrqBand = prC->rPP.rSC.GetMaxFrqTime( prC->rPP.rFC, true );
  TimerApply->Interval = 250;

  // Set array of grades for scales:
  short nP = 0; anScaleGrades[0] = MC_STD_MIN_NMB_COLORS;
  while( anScaleGrades[nP++] < MC_STD_MAX_NMB_COLORS )
  {
    short nPrv = anScaleGrades[nP-1],
          nInc = (nPrv < MC_STD_DEF_NMB_COLORS) ? 1  :
                 (nPrv < 40                  ) ?  2  :
                 (nPrv < 100                 ) ?  10 : MC_STD_MAX_NMB_COLORS - nPrv;
    anScaleGrades[nP] = nPrv + nInc;
  }
  nScaleGrades = nP;

  // Set ranges:
  bBlockChangings = true;

  ButtonApply->Enabled = false;
  TimerApply->Enabled = false;

  TrackBarFreqFrom->Min = 0; // 20;
  TrackBarFreqFrom->Max = MC_STD_MAX_FRQ; // 40;
  TrackBarFreqFrom->Frequency = 1; // One step is one Hz
  TrackBarFreqFrom->LineSize = TrackBarFreqFrom->Frequency;
  TrackBarFreqFrom->PageSize = 5*TrackBarFreqFrom->Frequency;

  UpDownFrom->Min = 0; // 20;
  UpDownFrom->Max = MC_STD_MAX_FRQ; // 40;
  UpDownFrom->Increment = 1; // One step is one Hz

  TrackBarFreqTo->Min = 0; // 20;
  TrackBarFreqTo->Max = MC_STD_MAX_FRQ; // 40;
  TrackBarFreqTo->Frequency = 1; // One step is one Hz
  TrackBarFreqTo->LineSize = TrackBarFreqTo->Frequency;
  TrackBarFreqTo->PageSize = 5*TrackBarFreqTo->Frequency;

  UpDownTo->Min = 0; // 20;
  UpDownTo->Max = MC_STD_MAX_FRQ; // 40;
  UpDownTo->Increment = 1; // One step is one Hz

  UpDownScaleGrades->Min = 0;
  UpDownScaleGrades->Max = nScaleGrades - 1;
  UpDownScaleGrades->Increment = 1;

  UpDownAmpScaleMin->Min = MC_STD_MIN_MIN_AMP;
  UpDownAmpScaleMin->Max = 100; //MC_STD_MAX_MIN_AMP;
  UpDownAmpScaleMin->Position = MC_STD_DEF_MIN_AMP;

  UpDownAmpScaleMax->Min = MC_STD_MIN_MAX_AMP;
  UpDownAmpScaleMax->Max = MC_STD_MAX_MAX_AMP;
  UpDownAmpScaleMax->Position = MC_STD_DEF_MAX_AMP;

  UpDownAmpScaleGrades->Min = 0;
  UpDownAmpScaleGrades->Max = nScaleGrades - 1;
  UpDownAmpScaleGrades->Increment = 1;

  UpDownSEFPercent1->Min       = MC_MIN_CEF_PERCENT_1;
  UpDownSEFPercent1->Max       = MC_MAX_CEF_PERCENT_1;
  UpDownSEFPercent1->Increment = 1;

  UpDownSEFPercent2->Min       = MC_MIN_CEF_PERCENT_2;
  UpDownSEFPercent2->Max       = MC_MAX_CEF_PERCENT_2;
  UpDownSEFPercent2->Increment = 1;

  UpDownSEFFrom->Min = 0;
  UpDownSEFFrom->Max = 4*MC_STD_MAX_MIN_SEF_FRQ;   // step 0.25Hz, up to MC_STD_MAX_MIN_SEF_FRQ Hz
  UpDownSEFFrom->Increment = 1;

  UpDownSEFTo->Min = 0;
  UpDownSEFTo->Max = (MC_STD_MAX_FRQ - MC_STD_MIN_MAX_SEF_FRQ) * 2; // step 0.5 Hz
  UpDownSEFTo->Increment = 1;

  UpDownBandOf->Min = 1;
  UpDownBandOf->Max = MC_STD_MAX_SEF_SMT*4;  // step 0.25Hz, from 0.25Hz to MC_STD_MAX_SEF_SMT
  UpDownBandOf->Increment = 1;

  UpDownEntSmoothing->Min = 0;
  UpDownEntSmoothing->Max = MC_STD_MAX_SEF_SMT * 4;
  UpDownEntSmoothing->Increment = 1;

  UpDownAlpha->Max = 99;
  UpDownAlpha->Min = 0;
  UpDownAlpha->Increment = 1;

  TrackBarCorrWindow->Min = 0;
  TrackBarCorrWindow->Max = 100;
  TrackBarCorrWindow->Frequency = 10;

  TrackBarAROrder->Min = 0;
  TrackBarAROrder->Max = 100;
  TrackBarAROrder->Frequency = 10;

  UpDownNSp->Min = 0;
  UpDownNSp->Max = rCIn.rPA.bSymmAvr ? MC_STP_TIMEAVR_MAX/2 : MC_STP_TIMEAVR_MAX - 1;
  UpDownNSp->Increment = 1;

  TrackBarRAAmp->Min = 1;
  TrackBarRAAmp->Max = 100;
  TrackBarRAAmp->Frequency = 10;

  UpDownRAAmp->Min = 1;
  UpDownRAAmp->Max = 100;
  UpDownRAAmp->Increment = 1;

  bBlockChangings = false;

  bAdjustMaxAmp = false;

  bMGA = false;
  if (pbMGA && *pbMGA == true)
    bMGA = true;

  prBMRuler = new Graphics::TBitmap;
  prBMColorBar = new Graphics::TBitmap;
}

//---------------------------------------------------------------------------
__fastcall TFormSpectrTrendSettings::~TFormSpectrTrendSettings()
{
  CDELETE(prBMRuler);
  CDELETE(prBMColorBar);
}

//---------------------------------------------------------------------------
void __fastcall TFormSpectrTrendSettings::FormShow(TObject *Sender)
{
  PageControl1->ActivePage = TabSheet1;

  rLineCMBX[0].Init(ComboBoxLineSEF1);
  rLineCMBX[1].Init(ComboBoxLineSEF2);
  rLineCMBX[2].Init(ComboBoxLinePeakMain);
  rLineCMBX[3].Init(ComboBoxLinePeakSecondary);
  rLineCMBX[4].Init(ComboBoxLineEntropy);
  rLineCMBX[5].Init(ComboBoxERStyle1);
  rLineCMBX[6].Init(ComboBoxERStyle2);
  rLineCMBX[7].Init(ComboBoxERStyle3);

  for (long i = 0; i < 8; ++i)
    rLineCMBX[i].OnTypeChange = OnTypeChange;

  RestoreOptions( prCIn );      // set interface controls and update rCOut inside RestoreOptions

  OldFromWndProc = TrackBarFreqFrom->WindowProc;
  TrackBarFreqFrom->WindowProc = FromWndProc;
  OldToWndProc = TrackBarFreqTo->WindowProc;
  TrackBarFreqTo->WindowProc = ToWndProc;
  OldTimeWndProc = TrackBarTime->WindowProc;
  TrackBarTime->WindowProc = TimeWndProc;

  TimerApply->Enabled = true;

  // ruler
  prBMRuler->Width = PaintBoxBands->Width;
  prBMRuler->Height = PaintBoxBands->Height;
  DrawRuler( prBMRuler->Canvas, TRect(0, 0, prBMRuler->Width, prBMRuler->Height) );
  OnDrawRuler(PaintBoxBands);

  // color bar
  prBMColorBar->Width = PaintBoxColorBar->Width;
  prBMColorBar->Height = PaintBoxColorBar->Height;
  DrawBandBar( prBMColorBar->Canvas, TRect(0, 0, prBMColorBar->Width, prBMColorBar->Height), &rCOut.rRA );
  OnDrawColorBar(PaintBoxColorBar);

  if (bMGA)
  {
    TrackBarTime->Enabled = false;
    UpDownTime->Enabled = false;
    TabSheetRA->TabVisible = false;
    TrackBarRelHeight->Enabled = false;
    CheckBoxScaleLeft->Enabled = false;
    CheckBoxScaleRight->Enabled = false;
    CheckBoxRARulerLeft->Enabled = false;
    CheckBoxRARulerRight->Enabled = false;
    CheckBoxBandLeft->Enabled = false;
    CheckBoxBandRight->Enabled = false;
    CheckBoxScalePanel->Enabled = false;
    ButtonDefault->Visible = false;
  }

} // ***

//---------------------------------------------------------------------------
void TFormSpectrTrendSettings::RestoreOptions(trMcSpectrTrendSettings * prC)
{
  bBlockChangings = true;
  char s[80];

  if( prC->rPP.rSC.nEstType != BSP_SMOOTHED_PERIODOGRAM_EST && prC->rPP.rSC.nEstType != BSP_AR_LEVDURB_EST )
    rCOut.rPP.rSC.nEstType = BSP_SMOOTHED_PERIODOGRAM_EST;

  // Set interface elements in correspondence to the input struct:
  TrackBarFreqFrom->Position = MIN( rCOut.rPI.fFrqF, BRSTREND_XBEG_MAX );
  UpDownFrom->Position = TrackBarFreqFrom->Position;
  PanelFreqFrom->Caption = TrackBarFreqFrom->Position;
  TrackBarFreqTo->Position = MAX( rCOut.rPI.fFrqT, BRSTREND_XEND_MIN );
  UpDownTo->Position = TrackBarFreqTo->Position;
  PanelFreqTo->Caption = TrackBarFreqTo->Position;

  // Track bar & updown for trend's length:
  TrackBarTime->Max = prB->lTMax;   // boards and position corr. to prB->nPixLen; text corr. to prB->WindowWidth()
  TrackBarTime->Min = prB->lTMin;
  int nR = (TrackBarTime->Max - TrackBarTime->Min + 1);
  TrackBarTime->Frequency = nR < 500 ? 10  : nR < 1000 ? 25 :
                            nR < 2000 ? 50 : nR < 4000 ? 100 : 200;
  TrackBarTime->LineSize = TrackBarTime->Frequency;
  TrackBarTime->PageSize = 5*TrackBarTime->Frequency;
  TrackBarTime->Position = (int) (prB->nPixLen / rCOut.rPI.fPixPerSec);
  nTrackBarTimePos = TrackBarTime->Position;
  UpDownTime->Max = TrackBarTime->Max;
  UpDownTime->Min = TrackBarTime->Min;
  UpDownTime->Increment = 1;
  UpDownTime->Position = TrackBarTime->Position;
  SetPanelTimeValue(); // text corr. to prB->WindowWidth()
  //CheckBoxARTrend->Checked = bEnableARTrend && rCOut.rPI.bDisplayARTrend; // !!! tmp
  ComboBoxWindow->ItemIndex = (rCOut.rPA.nWinType == 3) ? 0 : 1;  // triangular is itemindex=0; else (Blackman) = 1

  // Track bar, updown for the length of time segment for the primary spectrum
  // and control for intersection
  double fDTM = (prB->lTMax / (double)prB->nPixLen) * 1.0001,  // min. possible segment for spectrum
         fDT  = MAX(MC_STP_SPC_SEGM_MIN, fDTM );
  fDT = (fDT - ((int)(fDT*10))/10.) < 1e-8 ? fDT :  ((int)((fDT*10) + 1))/10.;

  TrackBarPrimTime->Max = 10 * MC_STP_SPC_SEGM_MAX;
  TrackBarPrimTime->Min = 10 * fDT;
  TrackBarPrimTime->Position = (int)(rCOut.rPP.fDT * 10);  // assuming that the parameters are legal
  TrackBarPrimTime->Frequency = (TrackBarPrimTime->Max - TrackBarPrimTime->Min)/10;
  TrackBarPrimTime->PageSize = TrackBarPrimTime->Frequency;
  TrackBarPrimTime->LineSize = 1;

  UpDownPrimTime->Max = TrackBarPrimTime->Max;
  UpDownPrimTime->Min = TrackBarPrimTime->Min;
  UpDownPrimTime->Increment = 1;
  UpDownPrimTime->Position = TrackBarPrimTime->Position;

  UpDownAlpha->Position = (int) (100*rCOut.rPP.fAl + 0.5); // assuming correct parameters``
  nAlphaValue = UpDownAlpha->Position;
  CheckUpDownAlpha();

  SetSpcTimeLabels();

  RadioButtonPeriodogram->Checked =
                        (rCOut.rPP.rSC.nEstType == BSP_SMOOTHED_PERIODOGRAM_EST) ||
                        (rCOut.rPP.rSC.nEstType == BSP_PERIODOGRAM_EST);

  RadioButtonAutoregressive->Checked = !RadioButtonPeriodogram->Checked;

  rCOut.rPP.rSC.fWWidthT = MIN(rCOut.rPP.rSC.fWWidthT, 1.);
  TrackBarCorrWindow->Enabled = RadioButtonPeriodogram->Checked;

  double fWWT = rCOut.rPP.rSC.fWWidthT;
  if( rCOut.rPP.rSC.nEstType == BSP_PERIODOGRAM_EST )
  {
    double fF = 2*rCOut.rPP.rSC.fWWidthF*fFrqBand,
           fT = 1.5 / MAX(fF, 0.000001);
    fWWT = MIN(fT/fFrqTime, 1.);
  }

  TrackBarCorrWindow->Position = TrackBarCorrWindow->Max*fWWT;

  sprintf( s, "%.2f", fWWT*fFrqTime );
  PanelCorrWindow->Caption = s;

  rCOut.rPP.rSC.fAROrder = MIN(rCOut.rPP.rSC.fAROrder, 0.5);
  TrackBarAROrder->Enabled = !TrackBarCorrWindow->Enabled || bEnableARTrend;
  TrackBarAROrder->Position = 2*TrackBarAROrder->Max*rCOut.rPP.rSC.fAROrder;
  sprintf( s, "%.2f", rCOut.rPP.rSC.fAROrder*fFrqTime );
  PanelAROrder->Caption = s;

  bool AllowChange = true;
  if( ScaleMaximumUpDown->Position == rCOut.rPI.fScaleMax )
    ScaleMaximumUpDownChangingEx(ScaleMaximumUpDown, AllowChange, rCOut.rPI.fScaleMax, updUp );
  else
  {
    ScaleMaximumUpDown->Position = rCOut.rPI.fScaleMax;
    ScaleMaximumUpDown->Tag = ScaleMaximumUpDown->Position;
  }

  if( SensitivityUpDown->Position  == rCOut.rPI.fScaleSens )
    SensitivityUpDownChangingEx(SensitivityUpDown,  AllowChange, rCOut.rPI.fScaleSens,  updUp );
  else
  {
    SensitivityUpDown->Position = rCOut.rPI.fScaleSens;
    SensitivityUpDown->Tag      = SensitivityUpDown->Position;
  }

  for( short nP = 0; nP < nScaleGrades; nP++ )
  if( anScaleGrades[nP] == rCOut.rPI.nSGrades )
  {
    UpDownScaleGrades->Position = nP;
    EditScaleGrades->Text = IntToStr(rCOut.rPI.nSGrades);
    break;
  }

  if( UpDownAmpScaleMin->Position == RINT_P(2.*rCOut.rPI.fScaleSensR) )
    UpDownAmpScaleMinChangingEx(UpDownAmpScaleMin, AllowChange, RINT_P(2.*rCOut.rPI.fScaleSensR), updUp );
  else
  {
    UpDownAmpScaleMin->Position = RINT_P(2.*rCOut.rPI.fScaleSensR);
    UpDownAmpScaleMin->Tag = UpDownAmpScaleMin->Position;
  }

  /*
  if( UpDownAmpScaleMin->Position == RINT_P(2.*rCOut.rPI.fScaleSensMinR) )
    UpDownAmpScaleMinChangingEx(UpDownAmpScaleMin, AllowChange, RINT_P(2.*rCOut.rPI.fScaleSensMinR), updUp );
  else
  {
    UpDownAmpScaleMin->Position = RINT_P(2.*rCOut.rPI.fScaleSensMinR);
    UpDownAmpScaleMin->Tag = UpDownAmpScaleMin->Position;
  }
  */

  if( UpDownAmpScaleMax->Position == RINT_P(2.*rCOut.rPI.fScaleSensMaxR) )
    UpDownAmpScaleMaxChangingEx(UpDownAmpScaleMax, AllowChange, RINT_P(2.*rCOut.rPI.fScaleSensMaxR), updUp );
  else
  {
    UpDownAmpScaleMax->Position = RINT_P(2.*rCOut.rPI.fScaleSensMaxR);
    UpDownAmpScaleMax->Tag = UpDownAmpScaleMax->Position;
  }

  for( short nP = 0; nP < nScaleGrades; nP++ )
  if( anScaleGrades[nP] == rCOut.rPI.nSGradesR )
  {
    UpDownAmpScaleGrades->Position = nP;
    EditAmpScaleGrades->Text = IntToStr(rCOut.rPI.nSGradesR);
    break;
  }

  RadioGroupTransform->ItemIndex = (int) rCOut.rPI.nTransform;

  CheckBoxScaleLeft->Checked     = rCOut.rPI.bRulerLeft;
  CheckBoxScaleRight->Checked    = rCOut.rPI.bRulerRight;
  CheckBoxBandLeft->Checked      = rCOut.rPI.bBandLeft;
  CheckBoxBandRight->Checked     = rCOut.rPI.bBandRight;

  CheckBoxRARulerLeft->Checked   = rCOut.rPI.bRARulerLeft;
  CheckBoxRARulerRight->Checked  = rCOut.rPI.bRARulerRight;

  CheckBoxSEF1->Checked          = rCOut.rPI.abTrends[trMcSpcTrendPrmI::SEFHi];
  CheckBoxSEF2->Checked          = rCOut.rPI.abTrends[trMcSpcTrendPrmI::SEFLo];
  CheckBoxPeakMain->Checked      = rCOut.rPI.abTrends[trMcSpcTrendPrmI::Max];
  CheckBoxPeakSecondary->Checked = rCOut.rPI.abTrends[trMcSpcTrendPrmI::Peak2];
  CheckBoxEntropy->Checked       = rCOut.rPI.abTrends[trMcSpcTrendPrmI::Entropy];

  TrackBarRelHeight->Position    = rCOut.rPI.nCSAHeightPerCent;
  CheckBoxScalePanel->Checked    = rCOut.rPI.bShowScalePanel;
  CheckBoxHigherSEF->Checked     = !rCOut.rPI.bShowSpectrHigherSEF;

  RadioButtonWholeBand->Checked     = rCOut.rRA.nBandScheme == MCSTB_BAND_WHOLE;
  RadioButtonStandartBands->Checked = rCOut.rRA.nBandScheme == MCSTB_BAND_STANDART;
  RadioButtonManual->Checked        = rCOut.rRA.nBandScheme == MCSTB_BAND_MANUAL;
  CheckBoxCutAmpTrend->Checked      = rCOut.rRA.bCutAmpTrend;

  ButtonAdjustBands->Enabled = RadioButtonManual->Checked;

  CheckBoxERTrend1->Checked    = rCOut.rRA.abShowERTrend[0];
  CheckBoxERTrend2->Checked    = rCOut.rRA.abShowERTrend[1];
  CheckBoxERTrend3->Checked    = rCOut.rRA.abShowERTrend[2];

  UpDownRAAmp->Position        = rCOut.rRA.fMaxAmp;
  TrackBarRAAmp->Position      = rCOut.rRA.fMaxAmp;
  PanelRAAmp->Caption          = IntToStr(UpDownRAAmp->Position);
  CheckBoxMaxAmpAutoAdjust->Checked = rCOut.rRA.bMaxAmpAutoAdjust;

  UpDownEntSmoothing->Position = (int) ((rCOut.rPI.fEntSmoothing / 0.25) + 0.5);
  PanelEntSmoothing->Caption = FloatToStr(rCOut.rPI.fEntSmoothing);

  if( UpDownNSp->Position == rCOut.rPA.nK )
    UpDownNSp->Position = (rCOut.rPA.nK == 0) ? MC_STP_TIMEAVR_MAX/2 : 0; // to force painting
  UpDownNSp->Position = rCOut.rPA.nK;

  ComboBoxWindow->Visible = rCOut.rPA.nK;             // if nK>0 then we may choose the window
  LabelNoAveraging->Visible = (rCOut.rPA.nK == 0);    // if nK == 0, then there is no averaging
  LabelWindow->Visible = !LabelNoAveraging->Visible;

  UpDownSEFPercent1->Position  = rCOut.rPI.anSEFPercent[0];
  EditSEFPercent1->Text        = IntToStr(UpDownSEFPercent1->Position);

  UpDownSEFPercent2->Position  = rCOut.rPI.anSEFPercent[1];
  EditSEFPercent2->Text        = IntToStr(UpDownSEFPercent2->Position);

  UpDownSEFFrom->Position = (int)((rCOut.rPI.fFrqFS / 0.25) + 0.5);
  PanelSEFFrom->Caption = FloatToStr(rCOut.rPI.fFrqFS);

  UpDownSEFTo->Position = (int)(((rCOut.rPI.fFrqToS - MC_STD_MIN_MAX_SEF_FRQ) / 0.5) + 0.5);
  PanelSEFTo->Caption = FloatToStr(rCOut.rPI.fFrqToS);

  CheckBoxSmoothing->Checked = rCOut.rPI.fSSB > 0.00001;
  LabelInBand->Visible = CheckBoxSmoothing->Checked;
  PanelBandOf->Visible = CheckBoxSmoothing->Checked;
  UpDownBandOf->Visible = CheckBoxSmoothing->Checked;
  LabelHz4->Visible = CheckBoxSmoothing->Checked;

  if( CheckBoxSmoothing->Checked )
  {
    UpDownBandOf->Position = (int)((rCOut.rPI.fSSB / 0.25) + 0.5);
    PanelBandOf->Caption = FloatToStr(rCOut.rPI.fSSB);
  }

  CheckBoxIndicators->Checked = rCOut.rPI.bShowIndicatorsPanel;
  CheckBoxDSEF1->Checked = rCOut.rPI.abDigitalIndicator[0];
  CheckBoxDSEF2->Checked = rCOut.rPI.abDigitalIndicator[1];
  CheckBoxDMax->Checked = rCOut.rPI.abDigitalIndicator[2];
  CheckBoxDEntropy->Checked = rCOut.rPI.abDigitalIndicator[3];
  CheckBoxDTotalAmp->Checked = rCOut.rPI.abDigitalIndicator[4];
  CheckBoxDDeltaIndex->Checked = rCOut.rPI.abDigitalIndicator[5];

  CheckBoxDSEF1->Enabled = CheckBoxIndicators->Checked;
  CheckBoxDSEF2->Enabled = CheckBoxIndicators->Checked;
  CheckBoxDMax->Enabled  = CheckBoxIndicators->Checked;
  CheckBoxDEntropy->Enabled = CheckBoxIndicators->Checked;
  CheckBoxDTotalAmp->Enabled = CheckBoxIndicators->Checked;
  CheckBoxDDeltaIndex->Enabled = CheckBoxIndicators->Checked;

  for (long i = 0; i < 5; ++i)
    rLineCMBX[i].SetType(rCOut.rPI.arTW[i]);

  for (long i = 0; i < 3; ++i)
    rLineCMBX[5 + i].SetType(rCOut.rRA.anERTrendStyle[i]);

  bBlockChangings = false;
} // ***

//---------------------------------------------------------------------------
void TFormSpectrTrendSettings::ReadParam(trMcSpectrTrendSettings *prConfig, TrReadParamType enReadType)
{
  Application->ProcessMessages();       // allow all trackbars, etc. to be redrawn in the new positions

  if ( enReadType == rpSpectr )
  {
    rCOut.rPP.fAl = (UpDownAlpha->Position) / 100.0;
    rCOut.rPP.fDT = TrackBarPrimTime->Position / 10.0;
    rCOut.rPP.rSC.nEstType = RadioButtonPeriodogram->Checked ?
                      BSP_SMOOTHED_PERIODOGRAM_EST : BSP_AR_LEVDURB_EST;
    double fWWT = TrackBarCorrWindow->Position/(double)TrackBarCorrWindow->Max;
    double fFrq = MIN( 1.5/MAX(fWWT*fFrqTime, 0.000001), fFrqBand/2. );
    rCOut.rPP.rSC.fWWidthF = 0.5 * (fFrq / fFrqBand);
    rCOut.rPP.rSC.fWWidthT = fWWT;

    double fARO = 0.5*TrackBarAROrder->Position/(double)TrackBarAROrder->Max;
    rCOut.rPP.rSC.fAROrder = MIN(MAX(fARO, MC_STP_MIN_AR_ORDER/fFrqTime), MC_STP_MAX_AR_ORDER/fFrqTime);

    rCOut.rPA.nK = UpDownNSp->Position;
    rCOut.rPA.nWinType = ComboBoxWindow->ItemIndex ? 1 : 3;    // if itemindex = 1 then Blackman, else Triangular

    // !!! Set parameters to AR trend same as for spectral estimators:
    rCOut.rPAR1.fTEst    = rCOut.rPP.fDT;
    rCOut.rPAR1.fAROrder = rCOut.rPP.rSC.fAROrder * fFrqTime;
    rCOut.rPAR1.fTClc    = rCOut.rPP.fDT * (1. - rCOut.rPP.fAl);
    rCOut.rPAR2.fTAvr    = rCOut.rPA.nK * rCOut.rPAR1.fTClc;
    rCOut.rPAR2.nWinType = rCOut.rPA.nWinType;
    return;
  }

  // All but spectrums:
  rCOut.rPI.fPixPerSec = (TrackBarTime->Position == nTrackBarTimePos) ?
    rCIn.rPI.fPixPerSec : prB->nPixLen / (double) TrackBarTime->Position;

  rCOut.rPI.fFrqF = TrackBarFreqFrom->Position;
  rCOut.rPI.fFrqT = TrackBarFreqTo->Position;
  rCOut.rPI.fScaleMax = ScaleMaximumUpDown->Tag;//Position; //(EditScaleMaximum->Text).ToDouble();
  rCOut.rPI.fScaleSens = SensitivityUpDown->Tag;//Position; //(SensitivityEdit->Text).ToDouble();
  rCOut.rPI.nSGrades = (EditScaleGrades->Text).ToInt();
  for (long i = 0; i < 5; ++i)
    rCOut.rPI.arTW[i] =
      rLineCMBX[i].GetType() == LINE_TYPE_MEDIUM ? trMcSpcTrendPrmI::Medium :
      rLineCMBX[i].GetType() == LINE_TYPE_THICK  ? trMcSpcTrendPrmI::Thick :
                                                   trMcSpcTrendPrmI::Thin;

  rCOut.rPI.fScaleSensR = UpDownAmpScaleMin->Tag * 0.5;
  //rCOut.rPI.fScaleSensMinR = UpDownAmpScaleMin->Tag * 0.5;
  rCOut.rPI.fScaleSensMaxR = UpDownAmpScaleMax->Tag * 0.5;
  rCOut.rPI.nSGradesR = (EditAmpScaleGrades->Text).ToInt();

  rCOut.rPI.nTransform = (trMcSpcTrendPrmI::TransType)RadioGroupTransform->ItemIndex;

  rCOut.rPI.bRulerLeft = CheckBoxScaleLeft->Checked;
  rCOut.rPI.bRulerRight = CheckBoxScaleRight->Checked;
  rCOut.rPI.bRARulerLeft = CheckBoxRARulerLeft->Checked;
  rCOut.rPI.bRARulerRight = CheckBoxRARulerRight->Checked;
  rCOut.rPI.bBandLeft = CheckBoxBandLeft->Checked;
  rCOut.rPI.bBandRight = CheckBoxBandRight->Checked;

  rCOut.rPI.abTrends[trMcSpcTrendPrmI::SEFHi]   = CheckBoxSEF1->Checked;
  rCOut.rPI.abTrends[trMcSpcTrendPrmI::SEFLo]   = CheckBoxSEF2->Checked;
  rCOut.rPI.abTrends[trMcSpcTrendPrmI::Max]     = CheckBoxPeakMain->Checked;
  rCOut.rPI.abTrends[trMcSpcTrendPrmI::Peak2]   = CheckBoxPeakSecondary->Checked;
  rCOut.rPI.abTrends[trMcSpcTrendPrmI::Entropy] = CheckBoxEntropy->Checked;

  rCOut.rPI.nCSAHeightPerCent = TrackBarRelHeight->Position;
  rCOut.rPI.bShowScalePanel  = CheckBoxScalePanel->Checked;
  rCOut.rPI.bShowSpectrHigherSEF = !CheckBoxHigherSEF->Checked;

  rCOut.rPI.anSEFPercent[0] = UpDownSEFPercent1->Position;
  rCOut.rPI.anSEFPercent[1] = UpDownSEFPercent2->Position;

  rCOut.rPI.fFrqFS = UpDownSEFFrom->Position * 0.25;
  rCOut.rPI.fFrqToS = (UpDownSEFTo->Position * 0.5)  + MC_STD_MIN_MAX_SEF_FRQ;

  rCOut.rPI.fSSB = (CheckBoxSmoothing->Checked) ? UpDownBandOf->Position * 0.25 : 0.;

  // rpChegoIzvolite
  rCOut.rPI.bShowIndicatorsPanel  = CheckBoxIndicators->Checked;

  rCOut.rPI.abDigitalIndicator[0] = CheckBoxDSEF1->Checked;
  rCOut.rPI.abDigitalIndicator[1] = CheckBoxDSEF2->Checked;
  rCOut.rPI.abDigitalIndicator[2] = CheckBoxDMax->Checked;
  rCOut.rPI.abDigitalIndicator[3] = CheckBoxDEntropy->Checked;
  rCOut.rPI.abDigitalIndicator[4] = CheckBoxDTotalAmp->Checked;
  rCOut.rPI.abDigitalIndicator[5] = CheckBoxDDeltaIndex->Checked;

  //rCOut.rPI.bDisplayARTrend = CheckBoxARTrend->Checked;

  if ( RadioButtonWholeBand->Checked )
    rCOut.rRA.nBandScheme = MCSTB_BAND_WHOLE;
  else if (RadioButtonStandartBands->Checked)
    rCOut.rRA.nBandScheme = MCSTB_BAND_STANDART;
  else
    rCOut.rRA.nBandScheme = MCSTB_BAND_MANUAL;

  rCOut.rRA.bCutAmpTrend      = CheckBoxCutAmpTrend->Checked;

  for (long i = 0; i < 3; ++i)
    rCOut.rRA.anERTrendStyle[i] =
      rLineCMBX[5 + i].GetType() == LINE_TYPE_MEDIUM ? trMcSpcTrendPrmI::Medium :
      rLineCMBX[5 + i].GetType() == LINE_TYPE_THICK  ? trMcSpcTrendPrmI::Thick :
                                                       trMcSpcTrendPrmI::Thin;

  rCOut.rRA.abShowERTrend[0]  = CheckBoxERTrend1->Checked;
  rCOut.rRA.abShowERTrend[1]  = CheckBoxERTrend2->Checked;
  rCOut.rRA.abShowERTrend[2]  = CheckBoxERTrend3->Checked;
  rCOut.rRA.fMaxAmp           = UpDownRAAmp->Position;
  rCOut.rRA.bMaxAmpAutoAdjust = CheckBoxMaxAmpAutoAdjust->Checked;
  rCOut.rPI.fEntSmoothing     = UpDownEntSmoothing->Position * 0.25;
} // ***

//---------------------------------------------------------------------------
void TFormSpectrTrendSettings::SetPanelTimeValue( void ) // set caption of panel time corr. to current trend's window width
{
  char s[32];
	long nTSec = (int)(0.5 + TrackBarTime->Position * (prB->CurrWindowWidth()/(double)prB->nPixLen)),
       nHour = nTSec / 3600,
       nMin  = (nTSec % 3600) / 60,
       nSec  = nTSec % 60;
  sprintf(s, "%1d:%02d:%02d", nHour, nMin, nSec);
  PanelTime->Caption = s;
} // ***

// Set caption of panel with length of prim. spectrums & check validity of intersection value
void TFormSpectrTrendSettings::SetSpcTimeLabels( void )
{
  double fD =  TrackBarPrimTime->Position/10.,
         fAl = nAlphaValue / 100.,
         fT = fD + (fD*(1.-fAl))*((rCOut.rPA.bSymmAvr ? 2:1) * UpDownNSp->Position);

  char s[32];
  sprintf( s, "%.2f", fD );             PanelPrimTime->Caption = s;
  sprintf( s, "%.2f", fAl );            EditAlpha->Text = s;
  sprintf( s, "%.2f", (1.-fAl) * fD );  LabelAlphaSec->Caption = s;
  sprintf( s, "%.2f", fT );             LabelSegmentValue->Caption = s;
} // ***

//---------------------------------------------------------------------------
void __fastcall TFormSpectrTrendSettings::TrackBarFreqFromChange(
      TObject *Sender)
{
  if( bBlockChangings)
    return;

  if (TrackBarFreqFrom->Tag==0)
  {
    PanelFreqFrom->Caption = TrackBarFreqFrom->Position;
    return;
  }

  bBlockChangings = true;
  TrackBarFreqFrom->Position = MIN(TrackBarFreqFrom->Position,
                                                               BRSTREND_XBEG_MAX);
  TrackBarFreqTo->Position = MAX(TrackBarFreqTo->Position,
                               TrackBarFreqFrom->Position+BRSTREND_X_MINLEN);

  float alpha = float(TrackBarFreqFrom->Position - TrackBarFreqFrom->Min) / (TrackBarFreqFrom->Max - TrackBarFreqFrom->Min);
  UpDownFrom->Position = RINT(UpDownFrom->Min + alpha*(UpDownFrom->Max - UpDownFrom->Min));

  alpha = float(TrackBarFreqTo->Position - TrackBarFreqTo->Min) / (TrackBarFreqTo->Max - TrackBarFreqTo->Min);
  UpDownTo->Position = RINT(UpDownTo->Min + alpha*(UpDownTo->Max - UpDownTo->Min));

  ReadParam( &rCOut );  // update the configuration
  ReadParam( &rCOut );    // update the configuration

  bBlockChangings = false;

  PanelFreqFrom->Caption = TrackBarFreqFrom->Position;
  PanelFreqTo->Caption = TrackBarFreqTo->Position;
}

//---------------------------------------------------------------------------
void __fastcall TFormSpectrTrendSettings::TrackBarFreqToChange(
      TObject *Sender)
{
  if( bBlockChangings)
    return;

  if (TrackBarFreqTo->Tag==0)
  {
    PanelFreqTo->Caption = TrackBarFreqTo->Position;
    return;
  }

  bBlockChangings = true;
  TrackBarFreqTo->Position = MAX(TrackBarFreqTo->Position,
                                                               BRSTREND_XEND_MIN);
  TrackBarFreqFrom->Position = MIN(TrackBarFreqFrom->Position,
                               TrackBarFreqTo->Position-BRSTREND_X_MINLEN);

  float alpha = float(TrackBarFreqFrom->Position - TrackBarFreqFrom->Min) / (TrackBarFreqFrom->Max - TrackBarFreqFrom->Min);
  UpDownFrom->Position = RINT(UpDownFrom->Min + alpha*(UpDownFrom->Max - UpDownFrom->Min));

  alpha = float(TrackBarFreqTo->Position - TrackBarFreqTo->Min) / (TrackBarFreqTo->Max - TrackBarFreqTo->Min);
  UpDownTo->Position = RINT(UpDownTo->Min + alpha*(UpDownTo->Max - UpDownTo->Min));

  ReadParam( &rCOut );  // update the configuration
  ReadParam( &rCOut );   // update the configuration

  bBlockChangings = false;

  PanelFreqFrom->Caption = TrackBarFreqFrom->Position;
  PanelFreqTo->Caption = TrackBarFreqTo->Position;
}
//---------------------------------------------------------------------------
void __fastcall TFormSpectrTrendSettings::TrackBarCorrWindowChange(
      TObject *Sender)
{
  if( bBlockChangings )
    return;

  ButtonApply->Enabled = true;
  char s[32];

  if( Sender == TrackBarCorrWindow )
  {
    double fWWT = TrackBarCorrWindow->Position/(double)TrackBarCorrWindow->Max;

    sprintf( s, "%.2f", fWWT*fFrqTime );
    PanelCorrWindow->Caption = s;
    return;
  }

  if( Sender == TrackBarAROrder )
  {
    double fARO = 0.5*fFrqTime*(TrackBarAROrder->Position/(double)TrackBarAROrder->Max);
    fARO = MIN( MAX(fARO, MC_STP_MIN_AR_ORDER), MC_STP_MAX_AR_ORDER );
    sprintf( s, "%.2f", fARO );
    PanelAROrder->Caption = s;
  }
} // ***

//---------------------------------------------------------------------------
void __fastcall TFormSpectrTrendSettings::RadioButtonPeriodogramClick(
      TObject *Sender)
{
  if( bBlockChangings )
    return;

  ButtonApply->Enabled = true;
//  ReadParam(&rCOut, (Sender==RadioButtonPeriodogram) ? rpPeriod : rpAutoRegr);

  TrackBarCorrWindow->Enabled = RadioButtonPeriodogram->Checked;
  TrackBarAROrder->Enabled = !TrackBarCorrWindow->Enabled || bEnableARTrend;
} // ***

//---------------------------------------------------------------------------
void __fastcall TFormSpectrTrendSettings::TimerApplyTimer(TObject *Sender)
{
  if( rCOut == rCApplied )
    return;

  TCursor nCrs = Screen->Cursor;
  Screen->Cursor = crHourGlass;

  rCApplied = rCOut;
  if (prAP)
    prAP->Apply( &rCApplied );

  if (bAdjustMaxAmp)
  {
    ApplyMaxAmpAutoAdjust();
    bAdjustMaxAmp = false;
  }

  if( !(rCOut == rCApplied) )   // ? rCApplied modified inside Apply() ?
    RestoreOptions(&rCApplied); // update rCOut inside RestoreOptions

  // Spectrum parameters are corrected from outside:
  SetPanelTimeValue();          // needed if window boards modified in Apply()
  Screen->Cursor = nCrs;
} // ***

//---------------------------------------------------------------------------
void __fastcall TFormSpectrTrendSettings::ButtonDefaultClick(
      TObject *Sender)
{
  trMcSpectrTrendSettings rSTS;
  trMcSpectrTrendSettings rC = rCOut;
  rCOut = rSTS;
  RestoreOptions(&rSTS);
} // ***

//---------------------------------------------------------------------------
void __fastcall TFormSpectrTrendSettings::ScaleMaximumUpDownChangingEx(
      TObject *Sender, bool &AllowChange, short NewValue,
      TUpDownDirection Direction)
{
  AllowChange = (Direction != updNone) && (rCOut.rPI.fScaleSens <= NewValue);

  if( !AllowChange )
    return;

  char s[32];

  sprintf(s, " %3d", NewValue);
  EditScaleMaximum->Text  = (AnsiString)s + LabelScaleUnits->Caption;
  SensitivityUpDown->Max  = NewValue;

  ScaleMaximumUpDown->Tag = NewValue;

  if( !bBlockChangings )          // !!!
    ReadParam( &rCOut );
} // ***

//---------------------------------------------------------------------------
void __fastcall TFormSpectrTrendSettings::SensitivityUpDownChangingEx(
      TObject *Sender, bool &AllowChange, short NewValue,
      TUpDownDirection Direction)
{
  AllowChange = (Direction != updNone) && (rCOut.rPI.fScaleMax >= NewValue);
  if( !AllowChange )
    return;

  char s[80];

  sprintf(s, " %3d", NewValue);
  SensitivityEdit->Text  = s + LabelScaleUnits->Caption;
  SensitivityUpDown->Tag = NewValue;

  if( !bBlockChangings )          // !!!
    ReadParam( &rCOut );
} // ***

//---------------------------------------------------------------------------
void __fastcall TFormSpectrTrendSettings::UpDownScaleGradesChangingEx(
      TObject *Sender, bool &AllowChange, short NewValue,
      TUpDownDirection Direction)
{
  AllowChange = true;
  short nNV = NewValue < UpDownScaleGrades->Min ? UpDownScaleGrades->Max :
              NewValue > UpDownScaleGrades->Max ? UpDownScaleGrades->Min :
                                                  NewValue;

  EditScaleGrades->Text = IntToStr(anScaleGrades[nNV]);

  if( !bBlockChangings )
    ReadParam( &rCOut );
}

//---------------------------------------------------------------------------
void __fastcall TFormSpectrTrendSettings::UpDownAmpScaleMinChangingEx(
      TObject *Sender, bool &AllowChange, short NewValue,
      TUpDownDirection Direction)
{
  AllowChange = (Direction != updNone) && (2 * rCOut.rPI.fScaleSensMaxR >= NewValue);
  if( !AllowChange )
    return;

  char s[80];  sprintf(s, " %3d", NewValue);
  EditAmpScaleMin->Text  = s + LabelMkv->Caption;
  UpDownAmpScaleMin->Tag = NewValue;

  if( !bBlockChangings )          // !!!
    ReadParam(&rCOut);
}

//---------------------------------------------------------------------------
void __fastcall TFormSpectrTrendSettings::UpDownAmpScaleMaxChangingEx(
      TObject *Sender, bool &AllowChange, short NewValue,
      TUpDownDirection Direction)
{
  AllowChange = (Direction != updNone) && (2 * rCOut.rPI.fScaleSensR <= NewValue);
  if( !AllowChange )
    return;

  char s[80];  sprintf(s, " %3d", NewValue);
  EditAmpScaleMax->Text  = s + LabelMkv->Caption;
  UpDownAmpScaleMax->Tag = NewValue;

  UpDownAmpScaleMin->Max = NewValue;

  if( !bBlockChangings )          // !!!
    ReadParam(&rCOut);
}

//---------------------------------------------------------------------------
void __fastcall TFormSpectrTrendSettings::UpDownAmpScaleGradesChangingEx(
      TObject *Sender, bool &AllowChange, short NewValue,
      TUpDownDirection Direction)
{
  AllowChange = true;
  short nNV = NewValue < UpDownAmpScaleGrades->Min ? UpDownAmpScaleGrades->Max :
              NewValue > UpDownAmpScaleGrades->Max ? UpDownAmpScaleGrades->Min :
                                                  NewValue;

  EditAmpScaleGrades->Text = IntToStr(anScaleGrades[nNV]);

  if( !bBlockChangings )
    ReadParam(&rCOut);
}

//---------------------------------------------------------------------------
void __fastcall TFormSpectrTrendSettings::ButtonOKClick(TObject *Sender)
{
  TimerApply->Enabled = false;

  if( Sender == ButtonApply || Sender == ButtonOK )
    // set parameters which are not "autoapplied"
    ReadParam(&rCOut, rpSpectr);

  bool bToBeApplied = (Sender == ButtonApply) ||
                      ((Sender == ButtonOK) && (!(rCOut == rCApplied)));

  if( (Sender == ButtonCancel) && !(rCIn == rCApplied) )
  {
    rCOut = rCIn;
    bToBeApplied = true;
  }

  if ( bToBeApplied )
  {
    TimerApplyTimer( Sender );

    if( Sender == ButtonApply )
    {
      ButtonApply->Enabled = false;
      TimerApply->Enabled = true;
      return;
    }
  }

  if( Sender == ButtonCancel )
    return;

  if( Sender == ButtonCancel || (rCIn == rCOut && rCOut == rCApplied) )
  {
    ModalResult = mrCancel;
    return;
  }

  *prCIn = rCOut;      // set output structure
  ModalResult = mrOk;

  // save to ini file
  BrSetSpcTrendSettings(prCIn);
}

//---------------------------------------------------------------------------
void __fastcall TFormSpectrTrendSettings::TrackBarPrimTimeChange( TObject *Sender)
{
  if (bBlockChangings)          // if this function has been called as a result of UpDown change
    return;

  bBlockChangings = true;
  UpDownPrimTime->Position = TrackBarPrimTime->Position;
  CheckUpDownAlpha();
  SetSpcTimeLabels();
  bBlockChangings = false;

  ButtonApply->Enabled = true;
//  ReadParam(&rCOut, rpPrimTime);
}

//---------------------------------------------------------------------------
void __fastcall TFormSpectrTrendSettings::ComboBoxWindowChange(
      TObject *Sender)  { ButtonApply->Enabled = true; }

//---------------------------------------------------------------------------
void __fastcall TFormSpectrTrendSettings::UpDownPrimTimeChangingEx(
      TObject *Sender, bool &AllowChange, short NewValue,
      TUpDownDirection Direction)
{
  if (bBlockChangings)          // if this function has been called as a result of TrackBar change
    return;

  if (NewValue > UpDownPrimTime->Max || NewValue < UpDownPrimTime->Min)
    return;

  bBlockChangings = true;

  TrackBarPrimTime->Position = NewValue;
  CheckUpDownAlpha();

  SetSpcTimeLabels();

  bBlockChangings = false;
  ButtonApply->Enabled = true;
//  ReadParam(&rCOut, rpPrimTime);
}

//---------------------------------------------------------------------------
void TFormSpectrTrendSettings::CheckUpDownAlpha( void )
{
  bool bBC = bBlockChangings;
  bBlockChangings = true;

	double fDTM = (prB->lTMax / (double)prB->nPixLen) * 1.0001;     // min. possible segment for spectrum
  int nAlMax = 100*(1 - fDTM/((TrackBarPrimTime->Position/10.))); // max. possible intersection (%)

  UpDownAlpha->Position = MIN(UpDownAlpha->Position, nAlMax);
  nAlphaValue = UpDownAlpha->Position;
  UpDownAlpha->Max = MAX( nAlMax, 0 );
  bBlockChangings = bBC;
} // ***

//---------------------------------------------------------------------------// ***

//---------------------------------------------------------------------------
void __fastcall TFormSpectrTrendSettings::UpDownTimeChangingEx(
      TObject *Sender, bool &AllowChange, short NewValue,
      TUpDownDirection Direction)
{
  if (bBlockChangings)
    return;

  if (NewValue > UpDownTime->Max || NewValue < UpDownTime->Min)
    return;

  bBlockChangings = true;

  TrackBarTime->Position = NewValue;
  SetPanelTimeValue();

  bBlockChangings = false;
  ReadParam(&rCOut);
}

//---------------------------------------------------------------------------
void __fastcall TFormSpectrTrendSettings::TrackBarTimeChange(
      TObject *Sender)
{
  if (bBlockChangings)
    return;

  SetPanelTimeValue();

  if (TrackBarTime->Tag==0)
    return;

  bBlockChangings = true;
  UpDownTime->Position = TrackBarTime->Position;
  bBlockChangings = false;

  ReadParam(&rCOut);
}

//---------------------------------------------------------------------------
void __fastcall TFormSpectrTrendSettings::UpDownNSpChangingEx(
      TObject *Sender, bool &AllowChange, short NewValue,
      TUpDownDirection Direction)
{
  if (NewValue > UpDownNSp->Max || NewValue < UpDownNSp->Min)
    return;

  if (!bBlockChangings)
    ButtonApply->Enabled = true;

  int nSpc = 1 + NewValue*(rCOut.rPA.bSymmAvr ? 2:1);
  char s[32];
  sprintf( s, "%d", nSpc );  PanelNSp->Caption = s;

  ComboBoxWindow->Visible = (bool) NewValue;
  LabelNoAveraging->Visible = !ComboBoxWindow->Visible;
  LabelWindow->Visible = !LabelNoAveraging->Visible;

  double fD =  TrackBarPrimTime->Position/10.,
         fAl = UpDownAlpha->Position/100.,
         fT = fD + (fD*(1.-fAl))*((rCOut.rPA.bSymmAvr ? 2:1) * NewValue);

  sprintf( s, "%.2f", fT );  LabelSegmentValue->Caption = s;
} // ***

void __fastcall TFormSpectrTrendSettings::UpDownFromChangingEx(
      TObject *Sender, bool &AllowChange, short NewValue,
      TUpDownDirection Direction)
{
  if (bBlockChangings)
    return;

  if (NewValue > UpDownFrom->Max || NewValue < UpDownFrom->Min)
    return;

  float alpha = float(NewValue - UpDownFrom->Min) / (UpDownFrom->Max - UpDownFrom->Min);
  bBlockChangings = true;

  int nNewPos = RINT(TrackBarFreqFrom->Min + alpha*(TrackBarFreqFrom->Max - TrackBarFreqFrom->Min));
  if (nNewPos + BRSTREND_X_MINLEN > TrackBarFreqTo->Position)
  {
    if (TrackBarFreqTo->Position + 1 > TrackBarFreqTo->Max)
    {
      AllowChange     = false;
      bBlockChangings = false;
      return;
    }
    else
    {
      TrackBarFreqTo->Position = TrackBarFreqTo->Position + 1;
      PanelFreqTo->Caption     = TrackBarFreqTo->Position;
      UpDownTo->Position       = TrackBarFreqTo->Position;
      ReadParam( &rCOut );  // update the configuration
    }
  }

  TrackBarFreqFrom->Position = nNewPos;

  ReadParam( &rCOut );  // update the configuration

  PanelFreqFrom->Caption = TrackBarFreqFrom->Position;

  bBlockChangings = false;
}
//---------------------------------------------------------------------------
void __fastcall TFormSpectrTrendSettings::UpDownToChangingEx(
      TObject *Sender, bool &AllowChange, short NewValue,
      TUpDownDirection Direction)
{
  if (bBlockChangings)
    return;

  if (NewValue > UpDownTo->Max || NewValue < UpDownTo->Min)
    return;

  float alpha = float(NewValue - UpDownTo->Min) / (UpDownTo->Max - UpDownTo->Min);
  bBlockChangings = true;

  int nNewPos = RINT(TrackBarFreqTo->Min + alpha*(TrackBarFreqTo->Max - TrackBarFreqTo->Min));

  if (nNewPos - BRSTREND_X_MINLEN < TrackBarFreqFrom->Position)
  {
    if (TrackBarFreqFrom->Position - 1 < TrackBarFreqFrom->Min)
    {
      AllowChange     = false;
      bBlockChangings = false;
      return;
    }
    else
    {
      TrackBarFreqFrom->Position = TrackBarFreqFrom->Position - 1;
      PanelFreqFrom->Caption     = TrackBarFreqFrom->Position;
      UpDownFrom->Position       = TrackBarFreqFrom->Position;
      ReadParam( &rCOut );  // update the configuration
    }
  }
  TrackBarFreqTo->Position = nNewPos;

  ReadParam( &rCOut );  // update the configuration

  PanelFreqTo->Caption = TrackBarFreqTo->Position;

  bBlockChangings = false;
}

//---------------------------------------------------------------------------
void __fastcall TFormSpectrTrendSettings::FromWndProc(Messages::TMessage &Message)
{
  if (Message.Msg == WM_LBUTTONUP)
  {
    TrackBarFreqFrom->Tag=1;
    TrackBarFreqFromChange(TrackBarFreqFrom);
    TrackBarFreqFrom->Tag=0;
  }

  OldFromWndProc(Message);
}

//---------------------------------------------------------------------------
void __fastcall TFormSpectrTrendSettings::ToWndProc(Messages::TMessage &Message)
{
  if (Message.Msg == WM_LBUTTONUP)
  {
    TrackBarFreqTo->Tag=1;
    TrackBarFreqToChange(TrackBarFreqTo);
    TrackBarFreqTo->Tag=0;
  }

  OldToWndProc(Message);
}

//---------------------------------------------------------------------------
void __fastcall TFormSpectrTrendSettings::TimeWndProc(Messages::TMessage &Message)
{
  if (Message.Msg == WM_LBUTTONUP)
  {
    TrackBarTime->Tag=1;
    TrackBarTimeChange(TrackBarTime);
    TrackBarTime->Tag=0;
  }

  OldTimeWndProc(Message);
}

//---------------------------------------------------------------------------
void __fastcall TFormSpectrTrendSettings::CheckBoxClick(
      TObject *Sender)
{
  if (!bBlockChangings)
    ReadParam(&rCOut);
}

//---------------------------------------------------------------------------
void __fastcall TFormSpectrTrendSettings::RadioGroupTransformClick(
      TObject *Sender)
{
  if (!bBlockChangings)
    ReadParam(&rCOut);
}

//---------------------------------------------------------------------------
void __fastcall TFormSpectrTrendSettings::CheckBoxIndicatorsClick(
      TObject *Sender)
{
  if (bBlockChangings)
    return;

  CheckBoxDSEF1->Enabled = CheckBoxIndicators->Checked;
  CheckBoxDSEF2->Enabled = CheckBoxIndicators->Checked;
  CheckBoxDMax->Enabled = CheckBoxIndicators->Checked;
  CheckBoxDEntropy->Enabled = CheckBoxIndicators->Checked;
  CheckBoxDTotalAmp->Enabled = CheckBoxIndicators->Checked;
  CheckBoxDDeltaIndex->Enabled = CheckBoxIndicators->Checked;

  ReadParam( &rCOut );
}

//---------------------------------------------------------------------------
void __fastcall TFormSpectrTrendSettings::CheckBoxSmoothingClick( TObject *Sender)
{
  if (bBlockChangings)
    return;

  LabelInBand->Visible = CheckBoxSmoothing->Checked;
  PanelBandOf->Visible = CheckBoxSmoothing->Checked;
  UpDownBandOf->Visible = CheckBoxSmoothing->Checked;
  LabelHz4->Visible = CheckBoxSmoothing->Checked;

  ReadParam(&rCOut);
} // ***

//---------------------------------------------------------------------------
void TFormSpectrTrendSettings::OnTypeChange(void *pSender, long nType)
{
  if (!bBlockChangings)
    ReadParam(&rCOut);
}

//---------------------------------------------------------------------------
void __fastcall TFormSpectrTrendSettings::TrackBarRelHeightChange(
      TObject *Sender)
{
  if (!bBlockChangings)
    ReadParam(&rCOut);
}

//---------------------------------------------------------------------------

void __fastcall TFormSpectrTrendSettings::OnRAParamsChange(TObject *Sender)
{
  if (bBlockChangings)
    return;

  if ( CheckBoxMaxAmpAutoAdjust->Checked &&
       (Sender == CheckBoxERTrend1 ||
        Sender == CheckBoxERTrend2 ||
        Sender == CheckBoxERTrend3))
    bAdjustMaxAmp = true;

  ReadParam(&rCOut);
}

//---------------------------------------------------------------------------

void __fastcall TFormSpectrTrendSettings::TrackBarMaxAmpChange(TObject *Sender)
{
  if (bBlockChangings)
    return;

  bBlockChangings = true;
  UpDownRAAmp->Position = TrackBarRAAmp->Position;
  PanelRAAmp->Caption = IntToStr(UpDownRAAmp->Position);
  bBlockChangings = false;

  ReadParam(&rCOut);
}

//---------------------------------------------------------------------------

void __fastcall TFormSpectrTrendSettings::UpDownRAAmpChangeEx(TObject *Sender, bool &AllowChange,
          short NewValue, TUpDownDirection Direction)
{
  if (Direction == updNone || bBlockChangings)          // if this function has been called as a result of TrackBar change
    return;

  bBlockChangings = true;
  PanelRAAmp->Caption = IntToStr(NewValue);
  TrackBarRAAmp->Position = NewValue;
  bBlockChangings = false;

  ReadParam(&rCOut);
}

//---------------------------------------------------------------------------

void __fastcall TFormSpectrTrendSettings::OnBandsClick(TObject *Sender)
{
  trMcFreqBandsPrm rParams(0, MC_STD_MAX_FRQ);

  for (int nB = 0; nB < MC_MAX_FREQ_BANDS; nB++)
  {
    rParams.afFrom[nB] = rCOut.rRA.rB.afF[nB];
    rParams.afTo[nB]   = rCOut.rRA.rB.afT[nB];
    rParams.bOn[nB]    = rCOut.rRA.rBG.abBG[nB][nB];
  }

  // bands config window
  McSetFrequencyBands(&rParams);

  int nBands = 0;
  for (int nB = 0; nB < MC_MAX_FREQ_BANDS; nB++)
  {
    rCOut.rRA.rB.afF[nB] = rParams.afFrom[nB];
    rCOut.rRA.rB.afT[nB] = rParams.afTo[nB];
    rCOut.rRA.rBG.abBG[nB][nB] = rParams.bOn[nB];
    if (rParams.bOn[nB])
      nBands++;
  }

  rCOut.rRA.rB.nNB = MC_MAX_FREQ_BANDS;
  rCOut.rRA.rBG.nNG = nBands;

  // redraw
  DrawBandBar( prBMColorBar->Canvas, TRect(0, 0, prBMColorBar->Width, prBMColorBar->Height), &rCOut.rRA );
  OnDrawColorBar(PaintBoxColorBar);
}
//---------------------------------------------------------------------------

void __fastcall TFormSpectrTrendSettings::OnDrawRuler(TObject *Sender)
{
  TRect rRectSrc (0, 0, prBMRuler->Width, prBMRuler->Height);
  TRect rRectDest(0, 0, PaintBoxBands->Width, PaintBoxBands->Height);
  PaintBoxBands->Canvas->CopyRect( rRectDest, prBMRuler->Canvas, rRectSrc );
}
//---------------------------------------------------------------------------

void __fastcall TFormSpectrTrendSettings::OnDrawColorBar(TObject *Sender)
{
  TRect rRectSrc (0, 0, prBMColorBar->Width, prBMColorBar->Height);
  TRect rRectDest(0, 0, PaintBoxColorBar->Width, PaintBoxColorBar->Height);
  PaintBoxColorBar->Canvas->CopyRect( rRectDest, prBMColorBar->Canvas, rRectSrc );
}
//---------------------------------------------------------------------------

void __fastcall TFormSpectrTrendSettings::OnBandsSchemeChange(TObject *Sender)
{
  if (bBlockChangings)
    return;

  ReadParam( &rCOut );
  DrawBandBar( prBMColorBar->Canvas, TRect(0, 0, prBMColorBar->Width, prBMColorBar->Height), &rCOut.rRA );
  OnDrawColorBar(PaintBoxColorBar);

  ButtonAdjustBands->Enabled = RadioButtonManual->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TFormSpectrTrendSettings::OnERTrendBandsClick(TObject *Sender)
{
  if (!McGetERTrendBandsConfig(&rCOut.rRA))
    return;

  if (CheckBoxMaxAmpAutoAdjust->Checked && CheckBoxERTrend3->Checked)
    bAdjustMaxAmp = true;
}

//---------------------------------------------------------------------------

void __fastcall TFormSpectrTrendSettings::UpDownEntropySmoothingChangingEx(TObject *Sender,
          bool &AllowChange, short NewValue, TUpDownDirection Direction)
{
  if (Direction == updNone || bBlockChangings)
    return;
  PanelEntSmoothing->Caption = FloatToStr(NewValue * 0.25);
  ReadParam(&rCOut);
}

//---------------------------------------------------------------------------

void __fastcall TFormSpectrTrendSettings::UpDownAlphaChangingEx(TObject *Sender, bool &AllowChange,
          short NewValue, TUpDownDirection Direction)
{
  if (Direction == updNone || bBlockChangings)
    return;

  nAlphaValue = NewValue;
  SetSpcTimeLabels();
  ButtonApply->Enabled = true;
//  ReadParam(&rCOut, rpAlpha);
}

//---------------------------------------------------------------------------

void __fastcall TFormSpectrTrendSettings::UpDownSEFPercent1ChangingEx(TObject *Sender,
          bool &AllowChange, short NewValue, TUpDownDirection Direction)
{
  if (bBlockChangings)
    return;

  if( Sender == UpDownSEFPercent1 )
    EditSEFPercent1->Text = IntToStr( NewValue );
  else
    EditSEFPercent2->Text = IntToStr( NewValue );

  ReadParam(&rCOut);
}

//---------------------------------------------------------------------------

void __fastcall TFormSpectrTrendSettings::UpDownSEFFromChangingEx(TObject *Sender,
          bool &AllowChange, short NewValue, TUpDownDirection Direction)
{
  if ( bBlockChangings)
    return;
  PanelSEFFrom->Caption = FloatToStr(NewValue * 0.25);
  ReadParam(&rCOut);
}

//---------------------------------------------------------------------------

void __fastcall TFormSpectrTrendSettings::UpDownSEFToChangingEx(TObject *Sender, bool &AllowChange,
          short NewValue, TUpDownDirection Direction)
{
  if ( bBlockChangings)
    return;

  PanelSEFTo->Caption = FloatToStr(NewValue * 0.5 + MC_STD_MIN_MAX_SEF_FRQ);
  ReadParam(&rCOut);
}

//---------------------------------------------------------------------------

void __fastcall TFormSpectrTrendSettings::UpDownBandOfChangingEx(TObject *Sender,
          bool &AllowChange, short NewValue, TUpDownDirection Direction)
{
  if (bBlockChangings)
    return;
  PanelBandOf->Caption = FloatToStr(NewValue * 0.25);
  ReadParam(&rCOut);
}

//---------------------------------------------------------------------------

void __fastcall TFormSpectrTrendSettings::OnAutoAdjustClick(TObject *Sender)
{
  if (bBlockChangings)
    return;

  if (CheckBoxMaxAmpAutoAdjust->Checked)
    ApplyMaxAmpAutoAdjust();

  ReadParam(&rCOut);
}

//---------------------------------------------------------------------------

void TFormSpectrTrendSettings::ApplyMaxAmpAutoAdjust()
{
  bBlockChangings = true;
  double fMaxERTrendVal = prAP->GetERTrendMax();

  if (fMaxERTrendVal <= 0)
  {
    bBlockChangings = false;
    return;
  }

  double fNewMaxAmp = fMaxERTrendVal > 1. ? fMaxERTrendVal * 1.2 : 1.;

  UpDownRAAmp->Position        = fNewMaxAmp;
  TrackBarRAAmp->Position      = fNewMaxAmp;
  PanelRAAmp->Caption          = IntToStr(UpDownRAAmp->Position);
  bBlockChangings = false;

  ReadParam(&rCOut);
}

//---------------------------------------------------------------------------
// Code of locals -----------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
static void ReadFromIniFile( void )       // read rSettings from .ini
{
  AnsiString sFN = CwApplGetProfile();

  rSettings.rPP.fDT = CwGetPrivateProfileFloat(sFN, SPTREND_SECTION, "Time interval primary spectrum", rSettings.rPP.fDT);
  rSettings.rPP.fAl = CwGetPrivateProfileFloat(sFN, SPTREND_SECTION, "Primary spectrum intersection", rSettings.rPP.fAl);
  rSettings.rPA.nWinType = CwGetPrivateProfileInt(sFN, SPTREND_SECTION, "Primary spectrum averaging window", rSettings.rPA.nWinType);
  rSettings.rPA.nK = CwGetPrivateProfileInt(sFN, SPTREND_SECTION, "Number of averaged spectrums", rSettings.rPA.nK);

  rSettings.rPI.fPixPerSec = CwGetPrivateProfileFloat(sFN, SPTREND_SECTION, "Pixels per second", rSettings.rPI.fPixPerSec);
  rSettings.rPI.fFrqF = CwGetPrivateProfileFloat(sFN, SPTREND_SECTION, "From frequency", rSettings.rPI.fFrqF);
  rSettings.rPI.fFrqT = CwGetPrivateProfileFloat(sFN, SPTREND_SECTION, "To frequency", rSettings.rPI.fFrqT);

  rSettings.rPI.fFrqFS = CwGetPrivateProfileFloat(sFN, SPTREND_SECTION, "Lower SEF frequency", rSettings.rPI.fFrqFS);
  rSettings.rPI.fFrqFS = BVAL(rSettings.rPI.fFrqFS, 0., MC_STD_MAX_MIN_SEF_FRQ);
  rSettings.rPI.fFrqToS = CwGetPrivateProfileFloat(sFN, SPTREND_SECTION, "Upper SEF frequency", rSettings.rPI.fFrqToS);
  rSettings.rPI.fFrqToS = BVAL(rSettings.rPI.fFrqToS, MC_STD_MIN_MAX_SEF_FRQ, MC_STD_MAX_FRQ);
  rSettings.rPI.fSSB = CwGetPrivateProfileFloat(sFN, SPTREND_SECTION, "Smoothing SEF band", rSettings.rPI.fSSB);
  rSettings.rPI.fSSB = BVAL( rSettings.rPI.fSSB, 0., MC_STD_MAX_SEF_SMT );

  // probably get colors from elsewhere ... like in maps
/*    rSettings.rPI.nSC1 = CwGetPrivateProfileInt(sFN, SPTREND_SECTION, "Color1", rSettings.rPI.nSC1);
  rSettings.rPI.nSC2 = CwGetPrivateProfileInt(sFN, SPTREND_SECTION, "Color2", rSettings.rPI.nSC2);
  rSettings.rPI.nSC3 = CwGetPrivateProfileInt(sFN, SPTREND_SECTION, "Color3", rSettings.rPI.nSC3);*/

  rSettings.rPI.fScaleMax = CwGetPrivateProfileFloat(sFN, SPTREND_SECTION, "Scale maximum", rSettings.rPI.fScaleMax);
  rSettings.rPI.fScaleSens = CwGetPrivateProfileFloat(sFN, SPTREND_SECTION, "Scale sensitivity", rSettings.rPI.fScaleSens);
  rSettings.rPI.nSGrades = CwGetPrivateProfileInt(sFN, SPTREND_SECTION, "Scale grades", rSettings.rPI.nSGrades);

  rSettings.rPI.fScaleSensR = CwGetPrivateProfileFloat(sFN, SPTREND_SECTION, "Scale amp", rSettings.rPI.fScaleSensR);
  rSettings.rPI.fScaleSensMinR = CwGetPrivateProfileFloat(sFN, SPTREND_SECTION, "Scale amp min", rSettings.rPI.fScaleSensMinR);
  rSettings.rPI.fScaleSensMaxR = CwGetPrivateProfileFloat(sFN, SPTREND_SECTION, "Scale amp max", rSettings.rPI.fScaleSensMaxR);
  rSettings.rPI.nSGradesR = CwGetPrivateProfileInt(sFN, SPTREND_SECTION, "Scale amp grades", rSettings.rPI.nSGradesR);

  int nT = CwGetPrivateProfileInt(sFN, SPTREND_SECTION, "Scale transform", rSettings.rPI.nTransform);
  rSettings.rPI.nTransform = (trMcSpcTrendPrmI::TransType) MIN( 2, MAX(nT, 0) );

  rSettings.rPI.bRulerLeft = CwGetPrivateProfileBool(sFN, SPTREND_SECTION, "Draw ruler on left", rSettings.rPI.bRulerLeft);
  rSettings.rPI.bRulerRight = CwGetPrivateProfileBool(sFN, SPTREND_SECTION, "Draw ruler on right", rSettings.rPI.bRulerRight);
  rSettings.rPI.bBandLeft = CwGetPrivateProfileBool(sFN, SPTREND_SECTION, "Draw bands on left", rSettings.rPI.bBandLeft);
  rSettings.rPI.bBandRight = CwGetPrivateProfileBool(sFN, SPTREND_SECTION, "Draw bands on right", rSettings.rPI.bBandRight);
  rSettings.rPI.bRARulerLeft = CwGetPrivateProfileBool(sFN, SPTREND_SECTION, "Draw RA trend ruler on left", rSettings.rPI.bRARulerLeft);
  rSettings.rPI.bRARulerRight = CwGetPrivateProfileBool(sFN, SPTREND_SECTION, "Draw RA trend ruler on right", rSettings.rPI.bRARulerRight);

  rSettings.rPP.rSC.nEstType = CwGetPrivateProfileInt(sFN, SPTREND_SECTION, "Estimator", rSettings.rPP.rSC.nEstType);
  rSettings.rPP.rSC.fWWidthF = CwGetPrivateProfileFloat(sFN, SPTREND_SECTION, "Width F", rSettings.rPP.rSC.fWWidthF);
  rSettings.rPP.rSC.fWWidthT = CwGetPrivateProfileFloat(sFN, SPTREND_SECTION, "Width T", rSettings.rPP.rSC.fWWidthT);
  rSettings.rPP.rSC.fAROrder = CwGetPrivateProfileFloat(sFN, SPTREND_SECTION, "Autoregr. order", rSettings.rPP.rSC.fAROrder);

  rSettings.rPI.abTrends[trMcSpcTrendPrmI::SEFHi]   =
     CwGetPrivateProfileBool(sFN, SPTREND_SECTION, "SEF1", rSettings.rPI.abTrends[trMcSpcTrendPrmI::SEFHi] );
  rSettings.rPI.abTrends[trMcSpcTrendPrmI::SEFLo]   =
     CwGetPrivateProfileBool(sFN, SPTREND_SECTION, "SEF2", rSettings.rPI.abTrends[trMcSpcTrendPrmI::SEFLo]);
  rSettings.rPI.abTrends[trMcSpcTrendPrmI::Max]     =
     CwGetPrivateProfileBool(sFN, SPTREND_SECTION, "Main peak", rSettings.rPI.abTrends[trMcSpcTrendPrmI::Max]);
  rSettings.rPI.abTrends[trMcSpcTrendPrmI::Peak2]   =
     CwGetPrivateProfileBool(sFN, SPTREND_SECTION, "Secondary peak", rSettings.rPI.abTrends[trMcSpcTrendPrmI::Peak2]);
  rSettings.rPI.abTrends[trMcSpcTrendPrmI::Entropy] =
     CwGetPrivateProfileBool(sFN, SPTREND_SECTION, "Entropy", rSettings.rPI.abTrends[trMcSpcTrendPrmI::Entropy]);

  rSettings.rPI.nCSAHeightPerCent = CwGetPrivateProfileInt(sFN, SPTREND_SECTION, "Relative CSA height", rSettings.rPI.nCSAHeightPerCent);
  rSettings.rPI.bShowScalePanel = CwGetPrivateProfileBool(sFN, SPTREND_SECTION, "Scale Panel", rSettings.rPI.bShowScalePanel);
  rSettings.rPI.bShowSpectrHigherSEF = CwGetPrivateProfileBool(sFN, SPTREND_SECTION, "CSA higher SEF", rSettings.rPI.bShowSpectrHigherSEF);
  rSettings.rPI.bShowScreenPanel = true; //CwGetPrivateProfileBool(sFN, SPTREND_SECTION, "Screen Panel", rSettings.rPI.bShowScreenPanel);
  rSettings.rPI.bDisplayARTrend = CwGetPrivateProfileBool(sFN, SPTREND_SECTION, "AR trend", rSettings.rPI.bDisplayARTrend);

  rSettings.rPI.fEntSmoothing = CwGetPrivateProfileFloat(sFN, SPTREND_SECTION, "Smoothing entropy band", rSettings.rPI.fEntSmoothing);
  rSettings.rPI.fEntSmoothing = BVAL( rSettings.rPI.fEntSmoothing, 0., MC_STD_MAX_SEF_SMT );

  rSettings.rPI.anSEFPercent[0] = CwGetPrivateProfileInt(sFN, SPTREND_SECTION, "SEF1 Percent", rSettings.rPI.anSEFPercent[0]);

  rSettings.rPI.anSEFPercent[1] = CwGetPrivateProfileInt(sFN, SPTREND_SECTION, "SEF2 Percent", rSettings.rPI.anSEFPercent[1]);

  rSettings.rPI.bShowIndicatorsPanel = CwGetPrivateProfileBool(sFN, SPTREND_SECTION, "Indicators panel", rSettings.rPI.bShowIndicatorsPanel);
  rSettings.rPI.abDigitalIndicator[0] =
           CwGetPrivateProfileBool(sFN, SPTREND_SECTION, "SEF1 indicator", rSettings.rPI.abDigitalIndicator[0] );
  rSettings.rPI.abDigitalIndicator[1] =
           CwGetPrivateProfileBool(sFN, SPTREND_SECTION, "SEF2 indicator", rSettings.rPI.abDigitalIndicator[1] );
  rSettings.rPI.abDigitalIndicator[2] =
           CwGetPrivateProfileBool(sFN, SPTREND_SECTION, "MAX indicator", rSettings.rPI.abDigitalIndicator[2] );
  rSettings.rPI.abDigitalIndicator[3] =
           CwGetPrivateProfileBool(sFN, SPTREND_SECTION, "Entropy indicator", rSettings.rPI.abDigitalIndicator[3] );
  rSettings.rPI.abDigitalIndicator[4] =
           CwGetPrivateProfileBool(sFN, SPTREND_SECTION, "Total amplitude indicator", rSettings.rPI.abDigitalIndicator[4] );
  rSettings.rPI.abDigitalIndicator[5] =
           CwGetPrivateProfileBool(sFN, SPTREND_SECTION, "Delta index indicator", rSettings.rPI.abDigitalIndicator[5] );

  rSettings.rRA.rB.nNB = CwGetPrivateProfileInt(sFN, SPTREND_SECTION, "Bands number", rSettings.rRA.rB.nNB);

  rSettings.rRA.rB.nNB = MC_MAX_FREQ_BANDS;
  rSettings.rRA.rBG.nNG = 0;
  for (int nB = 0; nB < MC_MAX_FREQ_BANDS; nB++)
  {
    rSettings.rRA.rB.afF[nB] = CwGetPrivateProfileFloat(sFN, SPTREND_SECTION,
                               "Band " + IntToStr(nB + 1) + " from", rSettings.rRA.rB.afF[nB]);
    rSettings.rRA.rB.afT[nB] = CwGetPrivateProfileFloat(sFN, SPTREND_SECTION,
                               "Band " + IntToStr(nB + 1) + " to", rSettings.rRA.rB.afT[nB]);

    rSettings.rRA.rBG.abBG[nB][nB] = CwGetPrivateProfileBool(sFN, SPTREND_SECTION,
                                     "Band " + IntToStr(nB + 1) + " enabled", rSettings.rRA.rBG.abBG[nB][nB]);

    if (rSettings.rRA.rBG.abBG[nB][nB])
      rSettings.rRA.rBG.nNG++;
  }

  for (short nB = 0; nB < MC_ER_TREND_BANDS_NUM; nB++)
  {
    rSettings.rRA.abDividentBands[nB] = CwGetPrivateProfileFloat(sFN, SPTREND_SECTION,
      "RA divident band " + IntToStr(nB), rSettings.rRA.abDividentBands[nB]);
    rSettings.rRA.abDivisorBands[nB] = CwGetPrivateProfileFloat(sFN, SPTREND_SECTION,
      "RA divisor band " + IntToStr(nB), rSettings.rRA.abDivisorBands[nB]);
  }

  for (short nT = 0; nT < MC_ER_MAX_TRENDS_NUMBER; nT++)
  {
    rSettings.rRA.abShowERTrend[nT]  = CwGetPrivateProfileBool(sFN, SPTREND_SECTION,
      "Show ER trend " + IntToStr(nT), rSettings.rRA.abShowERTrend[nT]);
    rSettings.rRA.anERTrendStyle[nT] = CwGetPrivateProfileInt(sFN, SPTREND_SECTION,
      "ER trend " + IntToStr(nT) + " style", rSettings.rRA.anERTrendStyle[nT]);
  }

  rSettings.rRA.anTrendColors[0] = CwGetPrivateProfileInt(sFN, SPTREND_SECTION, "ER trend foreground color", rSettings.rRA.anTrendColors[0]);
  rSettings.rRA.anTrendColors[1] = CwGetPrivateProfileInt(sFN, SPTREND_SECTION, "ER trend background color", rSettings.rRA.anTrendColors[1]);
  rSettings.rRA.fMaxAmp = CwGetPrivateProfileFloat(sFN, SPTREND_SECTION, "RA maximal amplitude", rSettings.rRA.fMaxAmp);
  rSettings.rRA.bMaxAmpAutoAdjust =
           CwGetPrivateProfileBool(sFN, SPTREND_SECTION, "RA maximal amplitude auto adjust", rSettings.rRA.bMaxAmpAutoAdjust);

  rSettings.rRA.nBandScheme =
           CwGetPrivateProfileInt(sFN, SPTREND_SECTION, "Bands scheme", rSettings.rRA.nBandScheme);
  rSettings.rRA.bCutAmpTrend =
           CwGetPrivateProfileBool(sFN, SPTREND_SECTION, "Cut RA trenf", rSettings.rRA.bCutAmpTrend);

  for (int i = 0; i < 5; ++i)
  {
    long nType = CwGetPrivateProfileInt(sFN, SPTREND_SECTION, "Line Type " + IntToStr(i+1),
      rSettings.rPI.arTW[i] );

    rSettings.rPI.arTW[i] =
        nType == LINE_TYPE_MEDIUM ? trMcSpcTrendPrmI::Medium :
        nType == LINE_TYPE_THICK  ? trMcSpcTrendPrmI::Thick :
                                    trMcSpcTrendPrmI::Thin;
  }

  bEnableARTrend = CwGetPrivateProfileBool(sFN, SPTREND_SECTION, "Enable AR trend", bEnableARTrend );

  // !!! Set parameters to AR trend same as for spectral estimators:
  double fFrqTime = rSettings.rPP.rSC.GetMaxFrqTime( rSettings.rPP.rFC );
  rSettings.rPAR1.fTEst    = rSettings.rPP.fDT;
  rSettings.rPAR1.fAROrder = rSettings.rPP.rSC.fAROrder * fFrqTime;
  rSettings.rPAR1.fTClc    = rSettings.rPP.fDT * (1. - rSettings.rPP.fAl);
  rSettings.rPAR2.fTAvr    = rSettings.rPA.nK * rSettings.rPAR1.fTClc;
  rSettings.rPAR2.nWinType = rSettings.rPA.nWinType;
} // ***

//---------------------------------------------------------------------------
static void WriteToIniFile( void )       // write rSettings to .ini
{
  AnsiString sFN = CwApplGetProfile();
  CwSetPrivateProfileFloat(sFN, SPTREND_SECTION, "Time interval primary spectrum", rSettings.rPP.fDT);
  CwSetPrivateProfileFloat(sFN, SPTREND_SECTION, "Primary spectrum intersection", rSettings.rPP.fAl);
  CwSetPrivateProfileFloat(sFN, SPTREND_SECTION, "Pixels per second", rSettings.rPI.fPixPerSec);
  CwSetPrivateProfileFloat(sFN, SPTREND_SECTION, "From frequency", rSettings.rPI.fFrqF);
  CwSetPrivateProfileFloat(sFN, SPTREND_SECTION, "To frequency", rSettings.rPI.fFrqT);

  CwSetPrivateProfileFloat(sFN, SPTREND_SECTION, "Lower SEF frequency", rSettings.rPI.fFrqFS);
  CwSetPrivateProfileFloat(sFN, SPTREND_SECTION, "Upper SEF frequency", rSettings.rPI.fFrqToS);
  CwSetPrivateProfileFloat(sFN, SPTREND_SECTION, "Smoothing SEF band", rSettings.rPI.fSSB);

  CwSetPrivateProfileInt(sFN, SPTREND_SECTION, "Primary spectrum averaging window", rSettings.rPA.nWinType);
  CwSetPrivateProfileInt(sFN, SPTREND_SECTION, "Number of averaged spectrums", rSettings.rPA.nK);

  CwSetPrivateProfileInt(sFN, SPTREND_SECTION, "Scale transform", rSettings.rPI.nTransform);

  CwSetPrivateProfileBool(sFN, SPTREND_SECTION, "Draw ruler on left", rSettings.rPI.bRulerLeft);
  CwSetPrivateProfileBool(sFN, SPTREND_SECTION, "Draw ruler on right", rSettings.rPI.bRulerRight);
  CwSetPrivateProfileBool(sFN, SPTREND_SECTION, "Draw bands on left", rSettings.rPI.bBandLeft);
  CwSetPrivateProfileBool(sFN, SPTREND_SECTION, "Draw bands on right", rSettings.rPI.bBandRight);
  CwSetPrivateProfileBool(sFN, SPTREND_SECTION, "Draw RA trend ruler on left", rSettings.rPI.bRARulerLeft);
  CwSetPrivateProfileBool(sFN, SPTREND_SECTION, "Draw RA trend ruler on right", rSettings.rPI.bRARulerRight);

  CwSetPrivateProfileFloat(sFN, SPTREND_SECTION, "Scale maximum", rSettings.rPI.fScaleMax);
  CwSetPrivateProfileFloat(sFN, SPTREND_SECTION, "Scale sensitivity", rSettings.rPI.fScaleSens);
  CwSetPrivateProfileInt(sFN, SPTREND_SECTION, "Scale grades", rSettings.rPI.nSGrades);

  CwSetPrivateProfileFloat(sFN, SPTREND_SECTION, "Scale amp", rSettings.rPI.fScaleSensR );
  CwSetPrivateProfileFloat(sFN, SPTREND_SECTION, "Scale amp min", rSettings.rPI.fScaleSensMinR );
  CwSetPrivateProfileFloat(sFN, SPTREND_SECTION, "Scale amp max", rSettings.rPI.fScaleSensMaxR );
  CwSetPrivateProfileInt(sFN, SPTREND_SECTION, "Scale amp grades", rSettings.rPI.nSGradesR);

  CwSetPrivateProfileInt(sFN, SPTREND_SECTION, "Estimator", rSettings.rPP.rSC.nEstType);
  CwSetPrivateProfileFloat(sFN, SPTREND_SECTION, "Width F", rSettings.rPP.rSC.fWWidthF);
  CwSetPrivateProfileFloat(sFN, SPTREND_SECTION, "Width T", rSettings.rPP.rSC.fWWidthT);
  CwSetPrivateProfileFloat(sFN, SPTREND_SECTION, "Autoregr. order", rSettings.rPP.rSC.fAROrder);

  CwSetPrivateProfileInt(sFN, SPTREND_SECTION, "SEF1 Percent", rSettings.rPI.anSEFPercent[0]);
  CwSetPrivateProfileInt(sFN, SPTREND_SECTION, "SEF2 Percent", rSettings.rPI.anSEFPercent[1]);

  CwSetPrivateProfileBool(sFN, SPTREND_SECTION, "SEF1", rSettings.rPI.abTrends[trMcSpcTrendPrmI::SEFHi] );
  CwSetPrivateProfileBool(sFN, SPTREND_SECTION, "SEF2", rSettings.rPI.abTrends[trMcSpcTrendPrmI::SEFLo]);
  CwSetPrivateProfileBool(sFN, SPTREND_SECTION, "Main peak", rSettings.rPI.abTrends[trMcSpcTrendPrmI::Max]);
  CwSetPrivateProfileBool(sFN, SPTREND_SECTION, "Secondary peak", rSettings.rPI.abTrends[trMcSpcTrendPrmI::Peak2]);
  CwSetPrivateProfileBool(sFN, SPTREND_SECTION, "Entropy", rSettings.rPI.abTrends[trMcSpcTrendPrmI::Entropy]);

  CwSetPrivateProfileInt(sFN, SPTREND_SECTION, "Relative CSA height", rSettings.rPI.nCSAHeightPerCent);
  CwSetPrivateProfileBool(sFN, SPTREND_SECTION, "Scale Panel", rSettings.rPI.bShowScalePanel);
  CwSetPrivateProfileBool(sFN, SPTREND_SECTION, "CSA higher SEF", rSettings.rPI.bShowSpectrHigherSEF);
  CwSetPrivateProfileBool(sFN, SPTREND_SECTION, "Screen Panel", rSettings.rPI.bShowScreenPanel);
  CwSetPrivateProfileBool(sFN, SPTREND_SECTION, "AR trend", rSettings.rPI.bDisplayARTrend);

  CwSetPrivateProfileBool(sFN, SPTREND_SECTION, "Indicators panel", rSettings.rPI.bShowIndicatorsPanel);
  CwSetPrivateProfileBool(sFN, SPTREND_SECTION, "SEF1 indicator", rSettings.rPI.abDigitalIndicator[0] );
  CwSetPrivateProfileBool(sFN, SPTREND_SECTION, "SEF2 indicator", rSettings.rPI.abDigitalIndicator[1] );
  CwSetPrivateProfileBool(sFN, SPTREND_SECTION, "MAX indicator", rSettings.rPI.abDigitalIndicator[2] );
  CwSetPrivateProfileBool(sFN, SPTREND_SECTION, "Entropy indicator", rSettings.rPI.abDigitalIndicator[3] );
  CwSetPrivateProfileBool(sFN, SPTREND_SECTION, "Total amplitude indicator", rSettings.rPI.abDigitalIndicator[4] );
  CwSetPrivateProfileBool(sFN, SPTREND_SECTION, "Delta index indicator", rSettings.rPI.abDigitalIndicator[5] );

  for (int i = 0; i < 5; ++i)
    CwSetPrivateProfileInt(sFN, SPTREND_SECTION, "Line Type " + IntToStr(i+1), rSettings.rPI.arTW[i] );
  CwSetPrivateProfileBool(sFN, SPTREND_SECTION, "Enable AR trend", bEnableARTrend );

  CwSetPrivateProfileInt(sFN, SPTREND_SECTION, "Bands number", rSettings.rRA.rB.nNB);

  for (int nB = 0; nB < MC_MAX_FREQ_BANDS; nB++)
  {
    CwSetPrivateProfileFloat(sFN, SPTREND_SECTION,
                             "Band " + IntToStr(nB + 1) + " from", rSettings.rRA.rB.afF[nB]);
    CwSetPrivateProfileFloat(sFN, SPTREND_SECTION,
                             "Band " + IntToStr(nB + 1) + " to", rSettings.rRA.rB.afT[nB]);

    CwSetPrivateProfileBool(sFN, SPTREND_SECTION,
                            "Band " + IntToStr(nB + 1) + " enabled", rSettings.rRA.rBG.abBG[nB][nB]);
  }

  for (short nB = 0; nB < MC_ER_TREND_BANDS_NUM; nB++)
  {
    CwSetPrivateProfileFloat(sFN, SPTREND_SECTION,
      "RA divident band " + IntToStr(nB), rSettings.rRA.abDividentBands[nB]);
    CwSetPrivateProfileFloat(sFN, SPTREND_SECTION,
      "RA divisor band " + IntToStr(nB), rSettings.rRA.abDivisorBands[nB]);
  }

  for (short nT = 0; nT < MC_ER_MAX_TRENDS_NUMBER; nT++)
  {
    CwSetPrivateProfileBool(sFN, SPTREND_SECTION,
      "Show ER trend " + IntToStr(nT), rSettings.rRA.abShowERTrend[nT]);
    CwSetPrivateProfileInt(sFN, SPTREND_SECTION,
      "ER trend " + IntToStr(nT) + " style", rSettings.rRA.anERTrendStyle[nT]);
  }

  CwSetPrivateProfileInt(sFN, SPTREND_SECTION, "ER trend foreground color", rSettings.rRA.anTrendColors[0]);
  CwSetPrivateProfileInt(sFN, SPTREND_SECTION, "ER trend background color", rSettings.rRA.anTrendColors[1]);
  CwSetPrivateProfileFloat(sFN, SPTREND_SECTION, "RA maximal amplitude", rSettings.rRA.fMaxAmp);
  CwSetPrivateProfileBool(sFN, SPTREND_SECTION, "RA maximal amplitude auto adjust", rSettings.rRA.bMaxAmpAutoAdjust);

  CwSetPrivateProfileInt(sFN, SPTREND_SECTION, "Bands scheme", rSettings.rRA.nBandScheme);
  CwSetPrivateProfileBool(sFN, SPTREND_SECTION, "Cut RA trenf", rSettings.rRA.bCutAmpTrend);

  CwSetPrivateProfileFloat(sFN, SPTREND_SECTION, "Smoothing entropy band", rSettings.rPI.fEntSmoothing);
} // ***

//---------------------------------------------------------------------------
void DrawRuler( TCanvas *prC, TRect rR ) // draw ruler in given rectangle
{
  // fill the canvas with black
  //prC->Brush->Color = clBtnFace;
  //prC->FillRect(rR);

  prC->Font->Name = "Arial";
  prC->Font->Size  = 8;
  prC->Font->Style = TFontStyles() << fsItalic; // << fsBold
  prC->Font->Color = clWindowText;

  int nLW = 1;
  short nTH = prC->TextHeight( "0" ) + 2*nLW;
  TRect rR1 = TRect( rR.left, rR.top, rR.right, rR.bottom - nTH );

  McDrawTRuler( prC, rR1, nTH, clWindowText, nLW, 0, MC_STD_MAX_FRQ, 1., 5, 5, false, true, NULL, false );
} // ***

//---------------------------------------------------------------------------
static void DrawBandBar( TCanvas *prC, TRect rR, trMcSTBPrmRA* prRA ) // draw colored bar
{
  trMcSpcTrendPrmE rPrm;
  float afFrom[4];
  float afTo[4];
  TColor anColor[4];

  for (int i = 0; i < 4; i++)
    anColor[i] = rPrm.pBands[i].cColor;

  int nBands = 0;

  if (prRA->nBandScheme == MCSTB_BAND_WHOLE)
  {
    nBands = 1;
    afFrom[0] = MC_STD_FRQBAND_MIN / MC_STD_MAX_FRQ;
    afTo[0]   = MC_STD_FRQBAND_MAX / MC_STD_MAX_FRQ;
  }
  else if (prRA->nBandScheme == MCSTB_BAND_STANDART)
  {
    nBands = 4;
    for (int i = 0; i < nBands; i++)
    {
      afFrom[i] = rPrm.pBands[i].fFrom / MC_STD_MAX_FRQ;
      afTo[i]   = rPrm.pBands[i].fTo / MC_STD_MAX_FRQ;
    }
  }
  else
  {
    nBands = prRA->rBG.nNG;
    short nBandIndex = 0;
    for (int i = 0; i < nBands; i++)
    {
      while (!prRA->rBG.abBG[nBandIndex][nBandIndex] && nBandIndex < MC_MAX_FREQ_BANDS)
        nBandIndex++;

      if (nBandIndex == MC_MAX_FREQ_BANDS)
        break;

      afFrom[i] = prRA->rB.afF[nBandIndex]   / MC_STD_MAX_FRQ;
      afTo[i]   = prRA->rB.afT[nBandIndex++] / MC_STD_MAX_FRQ;
    }
  }

  McDrawColoredBar( prC, rR, clBlack, 1, anColor, nBands, afFrom, afTo );
} // ***

//---------------------------------------------------------------------------

