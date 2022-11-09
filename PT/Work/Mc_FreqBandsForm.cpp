/*************************************************************************
  Module
     Form for bands setting
  File
     Mc_FreqBandsForm.cpp

*************************************************************************/
//---------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Includes -----------------------------------------------------------------
// --------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "math.h"

#include "Cw_appl.hpp"
#include "Cw_util.hpp"

#include "utllist.h"
#include "utldefs.h"

#include "Mc_FreqBandsForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MLMultiLangMain"
#pragma resource "*.dfm"

// --------------------------------------------------------------------------
// Defines ------------------------------------------------------------------
// --------------------------------------------------------------------------

#define MC_FB_VERT_SPACE         2       // Vertical space
#define MC_FB_QUANT              0.25    // Frequency quant
#define MC_FB_MIN_BAND_WIDTH     0.5     // Min band width (Hz)
#define MC_FB_FRQ_FORMAT         "%5.2f" // Frequency value format

// --------------------------------------------------------------------------
// Code for TFormFreqBands --------------------------------------------------
// --------------------------------------------------------------------------

__fastcall TFormFreqBands::TFormFreqBands(TComponent* Owner, trMcFreqBandsPrm* prPrm)
  : TForm(Owner)
{
  if (prPrm)
    rParams = *prPrm;

  for (int i = 0; i < MC_MAX_FREQ_BANDS; i++)
    Bands[i] = NULL;

  bBlockCallbacks = false;

  arCheckBoxes[0] = CheckBox1;
  arCheckBoxes[1] = CheckBox2;
  arCheckBoxes[2] = CheckBox3;
  arCheckBoxes[3] = CheckBox4;

  MultiLang1->CurrentLang = CwApplGetLanguage(CwApplGetProfile(), "");

  InsertBandsFrames();
}

//---------------------------------------------------------------------------

void __fastcall TFormFreqBands::InsertBandsFrames( void )
{
  // create frames
  for (int i = 0; i < MC_MAX_FREQ_BANDS; i++)
    if (Bands[i] == NULL)
    {
      Bands[i] = new TFreqBandFrame(NULL);
      Bands[i]->Name = "";
      Bands[i]->Parent = PanelBands;
      PanelBands->InsertComponent(Bands[i]);
    }

  // place frames
  int BandWidth  = Bands[0]->Width;
  int BandHeight = Bands[0]->Height;
  int nHSpace = (Width - BandWidth) / 2;
  for (int i = 0; i < MC_MAX_FREQ_BANDS; i++)
  {
    Bands[i]->Top  = MC_FB_VERT_SPACE + (BandHeight + MC_FB_VERT_SPACE) * i;
    Bands[i]->Left = nHSpace;
    arCheckBoxes[i]->Left = 10;
    arCheckBoxes[i]->Top = Bands[i]->Top + 15;
  }

  // adjust frames
  for (int i = 0; i < MC_MAX_FREQ_BANDS; i++)
  {
    Bands[i]->FreqSlider->Tag      = i;
    Bands[i]->FreqSlider->Min      = rParams.fMin;
    Bands[i]->FreqSlider->Max      = rParams.fMax;
    Bands[i]->FreqSlider->Quant    = MC_FB_QUANT;
    Bands[i]->FreqSlider->MinDist  = MC_FB_MIN_BAND_WIDTH;
    Bands[i]->FreqSlider->StepSize = MC_FB_QUANT;
    Bands[i]->FreqSlider->PageSize = 1;

    Bands[i]->FreqSlider->LeftPos  = rParams.afFrom[i];
    Bands[i]->FreqSlider->RightPos = rParams.afTo[i];
    Bands[i]->FreqSlider->OnChange = OnBandsChanged;
    Bands[i]->FreqSlider->Format   = MC_FB_FRQ_FORMAT;

    AnsiString rBandName           = LabelBand->Caption + " " + IntToStr(i + 1) + " (U" + IntToStr(i + 1) + ")";
    Bands[i]->Label->Caption       = rBandName;
    Bands[i]->LabelEdit->Text      = rBandName;

    arCheckBoxes[i]->Checked       = rParams.bOn[i];
    OnSwitchBand(arCheckBoxes[i]);
  }
}

//---------------------------------------------------------------------------

void __fastcall TFormFreqBands::OnSwitchBand(TObject *Sender)
{
  int nBandNumber = -1;
  for (int nB = 0; nB < MC_MAX_FREQ_BANDS; nB++)
    if (Sender == arCheckBoxes[nB])
    {
      nBandNumber = nB;
      break;
    }

  if (nBandNumber == -1)
    return;

  bool bOn = arCheckBoxes[nBandNumber]->Checked;
  Bands[nBandNumber]->Enabled = bOn;
  Bands[nBandNumber]->FreqSlider->Enabled = bOn;
  Bands[nBandNumber]->Panel->Enabled = bOn;
  Bands[nBandNumber]->LabelEdit->Enabled = bOn;
  Bands[nBandNumber]->Panel->Font->Color = bOn ? clWindowText : clInactiveCaptionText;

  if (bOn)
  {
    for (int nB = 0; nB < MC_MAX_FREQ_BANDS; nB++)
      arCheckBoxes[nB]->Enabled = true;

    float fLeft = -1, fRight = -1;
    int nBL = nBandNumber;
    while(nBL > 0 && !Bands[nBL - 1]->Enabled)
      nBL--;
    if (nBL > 0)
      fLeft = Bands[nBL - 1]->FreqSlider->RightPos;
    int nBR = nBandNumber;
    while(nBR < MC_MAX_FREQ_BANDS - 1 && !Bands[nBR + 1]->Enabled)
      nBR++;
    if (nBR < MC_MAX_FREQ_BANDS - 1)
      fRight = Bands[nBR + 1]->FreqSlider->LeftPos;

    if (fabs(fLeft - fRight) < 0.01)
    {
       Bands[nBL - 1]->FreqSlider->UpdatePos(Bands[nBL - 1]->FreqSlider->LeftPos, fLeft - 0.5);
       Bands[nBR + 1]->FreqSlider->UpdatePos(fRight + 0.5, Bands[nBR + 1]->FreqSlider->RightPos);
       Bands[nBandNumber]->FreqSlider->UpdatePos(fLeft - 0.5, fRight + 0.5);
    }
    else
    {
      Bands[nBandNumber]->FreqSlider->UpdatePos(MAX(Bands[nBandNumber]->FreqSlider->LeftPos, fLeft),
                                                MIN(Bands[nBandNumber]->FreqSlider->RightPos, fRight));
    }
  }
  else
  {
    int nSelectedBands = 0;
    int nBand = -1;
    for (int nB = 0; nB < MC_MAX_FREQ_BANDS; nB++)
      if (arCheckBoxes[nB]->Checked)
      {
        nBand = nB;
        nSelectedBands++;
      }

    if (nSelectedBands == 1)
      arCheckBoxes[nBand]->Enabled = false;
  }
}

//---------------------------------------------------------------------------

void __fastcall TFormFreqBands::OnBandsChanged(System::TObject* Sender, double LeftPos, double RightPos)
{
  if( bBlockCallbacks )
    return;

  TDoubleSlider *pDs = (TDoubleSlider *) Sender;
  int nB1 = pDs->Tag;

  int nB = nB1;
  while(nB > 0 && !Bands[nB - 1]->Enabled)
    nB--;

  if (nB > 0)
  {
    if (LeftPos < Bands[nB - 1]->FreqSlider->RightPos)
    {
      LeftPos = MAX(LeftPos, Bands[nB - 1]->FreqSlider->LeftPos + 0.5);
      Bands[nB - 1]->FreqSlider->RightPos = LeftPos;

      bBlockCallbacks = true;
      Bands[nB - 1]->FreqSlider->UpdatePos(Bands[nB - 1]->FreqSlider->LeftPos, LeftPos);
      Bands[nB1]->FreqSlider->UpdatePos(LeftPos, Bands[nB1]->FreqSlider->RightPos);
      bBlockCallbacks = false;
    }
  }

  nB = nB1;
  while(nB < MC_MAX_FREQ_BANDS - 1 && !Bands[nB + 1]->Enabled)
    nB++;

  if (nB < MC_MAX_FREQ_BANDS - 1)
  {
    if (RightPos > Bands[nB + 1]->FreqSlider->LeftPos)
    {
      bBlockCallbacks = true;
      RightPos = MIN(RightPos, Bands[nB + 1]->FreqSlider->RightPos - 0.5);
      Bands[nB + 1]->FreqSlider->LeftPos = RightPos;
      Bands[nB + 1]->FreqSlider->UpdatePos(RightPos, Bands[nB + 1]->FreqSlider->RightPos);
      Bands[nB1]->FreqSlider->UpdatePos(Bands[nB1]->FreqSlider->LeftPos, RightPos);
      bBlockCallbacks = false;
    }
  }
}

//---------------------------------------------------------------------------

void __fastcall TFormFreqBands::OnOKClick(TObject *Sender)
{
  LoadFromControls();
}

//---------------------------------------------------------------------------

void TFormFreqBands::LoadFromControls( void )
{
  for (int i = 0; i < MC_MAX_FREQ_BANDS; i++)
  {
    rParams.afFrom[i] = Bands[i]->FreqSlider->LeftPos;
    rParams.afTo[i]   = Bands[i]->FreqSlider->RightPos;
    rParams.bOn[i]    = arCheckBoxes[i]->Checked;
  }
}

//---------------------------------------------------------------------------

void TFormFreqBands::GetBandsConfig(trMcFreqBandsPrm* prPrm)
{
  *prPrm = rParams;
}

//---------------------------------------------------------------------------
// Externals ----------------------------------------------------------------
//---------------------------------------------------------------------------

bool McSetFrequencyBands(trMcFreqBandsPrm* prPrm)
{
  TFormFreqBands* prF = new TFormFreqBands(Application, prPrm);
  int nRez = prF->ShowModal();
  if (nRez == mrOk)
    prF->GetBandsConfig(prPrm);
  prF->Free();
  return nRez == mrOk;
}

