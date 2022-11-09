/*************************************************************************
  Module
     Form for bands setting
  File
     Mc_FreqBandsForm.h
*************************************************************************/
//---------------------------------------------------------------------------

#ifndef Mc_FreqBandsFormH
#define Mc_FreqBandsFormH

// --------------------------------------------------------------------------
// Includes -----------------------------------------------------------------
// --------------------------------------------------------------------------

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include <ExtCtrls.hpp>
#include "MLMultiLangMain.hpp"

#include "Mc_FreqBandFrame.h"

// --------------------------------------------------------------------------
// Defines ------------------------------------------------------------------
// --------------------------------------------------------------------------

#define MC_MAX_FREQ_BANDS 4

// --------------------------------------------------------------------------
// Types --------------------------------------------------------------------
// --------------------------------------------------------------------------

// parameters
struct trMcFreqBandsPrm
{
  float fMin;
  float fMax;
  float afFrom[MC_MAX_FREQ_BANDS];
  float afTo[MC_MAX_FREQ_BANDS];
  bool bOn[MC_MAX_FREQ_BANDS];

  trMcFreqBandsPrm( float fAMin = 0., float fAMax = 30. )
  { memset( this, 0, sizeof(trMcFreqBandsPrm) ); fMin = fAMin, fMax = fAMax;}
};

// --------------------------------------------------------------------------
// form
class TFormFreqBands : public TForm
{
__published:	// IDE-managed Components
  TPanel *BasePanel;
  TPanel *PanelBands;
  TCheckBox *CheckBox1;
  TCheckBox *CheckBox2;
  TCheckBox *CheckBox3;
  TCheckBox *CheckBox4;
  TButton *ButtonOK;
  TButton *Button1;
  TLabel *LabelBand;
  TMultiLang *MultiLang1;
  void __fastcall OnSwitchBand(TObject *Sender);
  void __fastcall OnBandsChanged(System::TObject* Sender, double LeftPos, double RightPos);
  void __fastcall OnOKClick(TObject *Sender);
private:	// User declarations

  trMcFreqBandsPrm rParams;

  TFreqBandFrame *Bands[MC_MAX_FREQ_BANDS];
  TCheckBox* arCheckBoxes[MC_MAX_FREQ_BANDS];

  bool bBlockCallbacks;

  void __fastcall InsertBandsFrames( void );
  void LoadFromControls( void );

public:		// User declarations
  __fastcall TFormFreqBands(TComponent* Owner, trMcFreqBandsPrm* prPrm);
  void GetBandsConfig(trMcFreqBandsPrm* prPrm);
};

//---------------------------------------------------------------------------
// Externals ----------------------------------------------------------------
//---------------------------------------------------------------------------

bool McSetFrequencyBands(trMcFreqBandsPrm* prPrm);

#endif
