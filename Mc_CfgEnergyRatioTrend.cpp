/*************************************************************************
  Module
     Form for energy ratio trend (ER trend) config
  File
     Mc_CfgEnergyRatioTrend.cpp
*************************************************************************/

//---------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Includes -----------------------------------------------------------------
// --------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Cw_appl.hpp"
#include "Cw_util.hpp"

#include "utllist.h"
#include "utldefs.h"

#include "Mc_CfgEnergyRatioTrend.h"
#include "Mc_SpectrTrendHi.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MLMultiLangMain"
#pragma resource "*.dfm"

// --------------------------------------------------------------------------
// Defines ------------------------------------------------------------------
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Locals -------------------------------------------------------------------
// --------------------------------------------------------------------------

char* acBandsLabels[] = {"δ", "θ", "α", "β", "U1", "U2", "U3", "U4"};

// --------------------------------------------------------------------------
// Code for TFormERTrendBands -----------------------------------------------
// --------------------------------------------------------------------------

__fastcall TFormERTrendBands::TFormERTrendBands(TComponent* Owner, trMcSTBPrmRA* prPrm)
  : TForm(Owner)
{
  rPrm = *prPrm;

  arCheckBoxes1[0] = CheckBox1;
  arCheckBoxes1[1] = CheckBox2;
  arCheckBoxes1[2] = CheckBox3;
  arCheckBoxes1[3] = CheckBox4;
  arCheckBoxes1[4] = CheckBox5;
  arCheckBoxes1[5] = CheckBox6;
  arCheckBoxes1[6] = CheckBox7;
  arCheckBoxes1[7] = CheckBox8;

  arCheckBoxes2[0] = CheckBox9;
  arCheckBoxes2[1] = CheckBox10;
  arCheckBoxes2[2] = CheckBox11;
  arCheckBoxes2[3] = CheckBox12;
  arCheckBoxes2[4] = CheckBox13;
  arCheckBoxes2[5] = CheckBox14;
  arCheckBoxes2[6] = CheckBox15;
  arCheckBoxes2[7] = CheckBox16;

  for (short nB = 0; nB < MC_ER_TREND_BANDS_NUM; nB++)
    arLabels[nB] = arCheckBoxes1[nB]->Caption;

  MultiLang1->CurrentLang = CwApplGetLanguage(CwApplGetProfile(), "");

  OutputFreqBands();
  LoadToControls();
  UpdateLabels();
}

//---------------------------------------------------------------------------

void TFormERTrendBands::GetBandsConfig(trMcSTBPrmRA* prPrm)
{
  *prPrm = rPrm;
}

//---------------------------------------------------------------------------

void TFormERTrendBands::OutputFreqBands( void )
{
  trMcSpcTrendPrmE rP;

  for (short nB = 0; nB < 4; nB++)
  {
    AnsiString rStr = (AnsiString) " [" + FloatToStrF(rP.pBands[nB].fFrom, ffFixed, 10, 1) +
                      " ... " + FloatToStrF(rP.pBands[nB].fTo, ffFixed, 10, 1) + "]";
    arCheckBoxes1[nB]->Caption = arCheckBoxes1[nB]->Caption + rStr;
    arCheckBoxes2[nB]->Caption = arCheckBoxes2[nB]->Caption + rStr;
  }

  for (short nB = 0; nB < 4; nB++)
  {
    AnsiString rStr = (AnsiString) " [" + FloatToStrF(rPrm.rB.afF[nB], ffFixed, 10, 1) +
                      " ... " + FloatToStrF(rPrm.rB.afT[nB], ffFixed, 10, 1) + "]";
    arCheckBoxes1[nB + 4]->Caption = arCheckBoxes1[nB + 4]->Caption + rStr;
    arCheckBoxes2[nB + 4]->Caption = arCheckBoxes2[nB + 4]->Caption + rStr;
  }
}

//---------------------------------------------------------------------------

void TFormERTrendBands::LoadToControls( void )
{
  for (short nB = 0; nB < MC_ER_TREND_BANDS_NUM; nB++)
  {
    arCheckBoxes1[nB]->Checked = rPrm.abDividentBands[nB];
    arCheckBoxes2[nB]->Checked = rPrm.abDivisorBands[nB];
  }
}

//---------------------------------------------------------------------------

void TFormERTrendBands::UpdateLabels( void )
{
  UnicodeString rStr1 = "(",
                rStr2 = "(";
  bool bF1 = false,
       bF2 = false;
  for (short nB = 0; nB < MC_ER_TREND_BANDS_NUM; nB++)
  {
    if (arCheckBoxes1[nB]->Checked)
    {
      if (bF1)
        rStr1 += "+";
      rStr1 += arLabels[nB];
      bF1 = true;
    }

    if (arCheckBoxes2[nB]->Checked)
    {
      if (bF2)
        rStr2 += "+";
      rStr2 += arLabels[nB];
      bF2 = true;
    }
  }

  Label1->Caption = rStr1 + ")";
  Label4->Caption = rStr2 + ")";
}

//---------------------------------------------------------------------------

void __fastcall TFormERTrendBands::OnBandsChange(TObject *Sender)
{
  UpdateLabels();
}

//---------------------------------------------------------------------------

void TFormERTrendBands::LoadFromControls( void )
{
  for (short nB = 0; nB < MC_ER_TREND_BANDS_NUM; nB++)
  {
    rPrm.abDividentBands[nB] = arCheckBoxes1[nB]->Checked;
    rPrm.abDivisorBands[nB]  = arCheckBoxes2[nB]->Checked;
  }
}

//---------------------------------------------------------------------------

void __fastcall TFormERTrendBands::OnOKClick(TObject *Sender)
{
  LoadFromControls();
}

//---------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Externals ----------------------------------------------------------------
// --------------------------------------------------------------------------

// get ER trend bands config
bool McGetERTrendBandsConfig(trMcSTBPrmRA* prPrm)
{
  TFormERTrendBands* prF = new TFormERTrendBands(Application, prPrm);
  int nRez = prF->ShowModal();
  if (nRez == mrOk)
    prF->GetBandsConfig(prPrm);
  prF->Free();
  return nRez == mrOk;
}
