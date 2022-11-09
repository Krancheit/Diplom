/*************************************************************************
  Module
     Form for energy ratio trend (ER trend) config
  File
     Mc_CfgEnergyRatioTrend.h

*************************************************************************/

//---------------------------------------------------------------------------

#ifndef Mc_CfgEnergyRatioTrendH
#define Mc_CfgEnergyRatioTrendH

// --------------------------------------------------------------------------
// Includes -----------------------------------------------------------------
// --------------------------------------------------------------------------

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>

#include <Mc_SpectrTrendBuffers.h>
#include "MLMultiLangMain.hpp"

// --------------------------------------------------------------------------
// Types --------------------------------------------------------------------
// --------------------------------------------------------------------------

// form
class TFormERTrendBands : public TForm
{
__published:	// IDE-managed Components
  TGroupBox *GroupBox1;
  TPanel *Panel1;
  TLabel *Label1;
  TLabel *Label2;
  TPanel *Panel2;
  TCheckBox *CheckBox1;
  TCheckBox *CheckBox2;
  TCheckBox *CheckBox3;
  TCheckBox *CheckBox4;
  TCheckBox *CheckBox5;
  TCheckBox *CheckBox6;
  TCheckBox *CheckBox7;
  TCheckBox *CheckBox8;
  TLabel *Label3;
  TLabel *Label4;
  TCheckBox *CheckBox9;
  TCheckBox *CheckBox10;
  TCheckBox *CheckBox11;
  TCheckBox *CheckBox12;
  TCheckBox *CheckBox13;
  TCheckBox *CheckBox14;
  TCheckBox *CheckBox15;
  TCheckBox *CheckBox16;
  TButton *ButtonOK;
  TButton *ButtonCancel;
  TMultiLang *MultiLang1;
  void __fastcall OnBandsChange(TObject *Sender);
  void __fastcall OnOKClick(TObject *Sender);
private:	// User declarations

  trMcSTBPrmRA rPrm;
  UnicodeString arLabels[MC_ER_TREND_BANDS_NUM];

  TCheckBox* arCheckBoxes1[MC_ER_TREND_BANDS_NUM];
  TCheckBox* arCheckBoxes2[MC_ER_TREND_BANDS_NUM];

  void OutputFreqBands( void );
  void LoadToControls( void );
  void LoadFromControls( void );
  void UpdateLabels( void );

public:		// User declarations
  __fastcall TFormERTrendBands(TComponent* Owner, trMcSTBPrmRA* prPrm);
  void GetBandsConfig(trMcSTBPrmRA* prPrm);
};

// --------------------------------------------------------------------------
// Externals ----------------------------------------------------------------
// --------------------------------------------------------------------------

// get ER trend bands config
bool McGetERTrendBandsConfig(trMcSTBPrmRA* prPrm);

#endif
