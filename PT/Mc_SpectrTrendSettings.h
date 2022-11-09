/*************************************************************************
  Module
    Settings for spectrums' trend in time
  File
     Mc_SpectrTrendSettings.h
  Comment
*************************************************************************/

#ifndef Mc_SpectrTrendSettingsH
#define Mc_SpectrTrendSettingsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <MLMultiLangMain.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>

#include <Mc_SpectrTrendProc.h>
#include <Mc_SpectrTrendHi.h>


//---------------------------------------------------------------------------
//  Defines -----------------------------------------------------------------
//---------------------------------------------------------------------------
// Defines for settings controls:

// Time segment
#define BRSTREND_MIN_TIME 1
#define BRSTREND_MAX_TIME 20
#define BRSTREND_DEF_TIME 2

// Frequency from/to
#define BRSTREND_X_MINLEN  5   // min. length of X-scale (Hz)
#define BRSTREND_XBEG_MAX  (MC_STD_MAX_FRQ-BRSTREND_X_MINLEN) // max. value of the beginning of X-scale
#define BRSTREND_XEND_MIN  BRSTREND_X_MINLEN                  // min. value of the end of X-scale

#define SPTREND_SECTION  "Spectral Trend"

// Types --------------------------------------------------------------------
//---------------------------------------------------------------------------

// Struct with paremeters set in UI & saved in .ini -------------------------
struct trMcSpectrTrendSettings
{
  trMcSpcTrendPrmP 		rPP;     // parameters for "primary" spectrums
  trMcSpcTrendPrmTA 	rPA;     // parameters for time-averaged spectrums
  trMcARVarPrm1 		rPAR1;   // base parameters for AR trend
  trMcARVarPrm2 		rPAR2;   // settable parameters for AR trend
  trMcSpcTrendPrmI 		rPI;     // trend parameters (int. set)
  trMcSTBPrmRA 			rRA;     // parameters for amp rel trend
  bool operator == ( const trMcSpectrTrendSettings & rS ) const
  { return (rPP == rS.rPP) && (rPA == rS.rPA) && (rPAR1 == rS.rPAR1) &&
		   (rPAR2 == rS.rPAR2) && (rPI == rS.rPI) && (rRA == rS.rRA); }
};

// Struct determining possible boards for trend; is used to set boards to select -
// trend length and to set restrictions to the length of spectrums' segments ---
struct trMcSpectrTrendBoards
{
  long lTMin, lTMax; // Min time of trend / max. time of trend (Sec.)...
  int nPixLen;         // ... for this trend length in pixels
  virtual int CurrWindowWidth( void ) = 0;  // Width of curr. window with trend (to display real time of trend only)
};

// Template for the object implementing "auto applly" function --------------
struct trMcApplyObj
{
  virtual void Apply( void * ) = 0; // Proc. to be called if "auto apply" function is active. If yes, this proc.
                                    // will be called regulary with current value of *prC

  virtual double GetERTrendMax() = 0;  // get max amplitude of energy ratio trend
};

typedef void (__closure *TpOnTypeChange)(void *pSender, long nType);
// line draw object
class TrLineCMBX
{
private:
  TComboBox *pComboBox;
  TImageList *pImageList;
  TColor BackColor, LineBackColor, LineForeColor;
  short nType;
  void __fastcall ComboBoxDrawItem(TWinControl *Control, int Index,
    const TRect &Rect, TOwnerDrawState State);

  TDrawItemEvent OldOnDrawItem;

  void Alloc(const TRect &rRect);
  void Free();
  void DrawLine(TCanvas *pCanvas, short nType, long nWidth, long nHeight);

  void __fastcall (__closure *OldWndProc)(Messages::TMessage &Message);
  virtual void __fastcall WndProc(Messages::TMessage &Message);

public:
  TrLineCMBX();
  ~TrLineCMBX();
  void Init(TComboBox *pAComboBox);
  void SetType(short nType);
  short GetType() { return nType; };

  TpOnTypeChange OnTypeChange;
};

//---------------------------------------------------------------------------
class TFormSpectrTrendSettings : public TForm
{
__published:	// IDE-managed Components
		TMultiLang *MultiLang1;
        TTimer *TimerApply;
        TButton *ButtonDefault;
        TButton *ButtonOK;
        TButton *ButtonCancel;
		TGroupBox *GroupBox7;
		TPageControl *PageControl1;
		TTabSheet *TabSheet1;
		TLabel *LabelScaleUnits;
		TLabel *LabelMkv;
		TGroupBox *GroupBoxCSA;
		TGroupBox *GroupBox3;
    	TLabel *Label6;
    TLabel *Label8;
    TPanel *PanelEntSmoothing;
    TUpDown *UpDownEntSmoothing;
    TGroupBox *GroupBoxTime;
    TTrackBar *TrackBarTime;
    TUpDown *UpDownTime;
    TPanel *PanelTime;
    TGroupBox *GroupBoxFreq;
    TLabel *LabelHz;
    TLabel *LabelTo;
    TLabel *LabelFrom;
    TLabel *LabelHz1;
    TTrackBar *TrackBarFreqTo;
    TPanel *PanelFreqTo;
    TTrackBar *TrackBarFreqFrom;
    TPanel *PanelFreqFrom;
    TUpDown *UpDownFrom;
    TUpDown *UpDownTo;
    TGroupBox *GroupBoxColorScale;
    TLabel *LabelScaleMaximum;
    TLabel *LabelScaleSensitivity;
    TLabel *LabelScaleGrades;
    TEdit *EditScaleMaximum;
    TUpDown *ScaleMaximumUpDown;
    TEdit *SensitivityEdit;
    TUpDown *SensitivityUpDown;
    TEdit *EditScaleGrades;
    TUpDown *UpDownScaleGrades;
    TRadioGroup *RadioGroupTransform;
    TGroupBox *GroupBoxSEF;
    TLabel *LabelSEFHi;
    TLabel *Label7;
    TLabel *Label9;
    TLabel *LabelSEFLo;
    TLabel *LabelSEFFrqBand;
    TLabel *LabelFrom1;
    TLabel *LabelHz2;
    TLabel *LabelTo1;
    TLabel *LabelHz3;
    TLabel *LabelInBand;
    TLabel *LabelHz4;
    TEdit *EditSEFPercent1;
    TUpDown *UpDownSEFPercent1;
    TUpDown *UpDownSEFPercent2;
    TEdit *EditSEFPercent2;
    TPanel *PanelSEFFrom;
    TUpDown *UpDownSEFFrom;
    TPanel *PanelSEFTo;
    TUpDown *UpDownSEFTo;
    TCheckBox *CheckBoxSmoothing;
    TPanel *PanelBandOf;
    TUpDown *UpDownBandOf;
    TGroupBox *GroupBoxRelHeigh;
    TLabel *LabelCSA;
    TLabel *LabelAmpTrend;
    TTrackBar *TrackBarRelHeight;
    TTabSheet *TabSheetRA;
    TGroupBox *GroupBox5;
    TGroupBox *GroupBox10;
    TPaintBox *PaintBoxBands;
    TPaintBox *PaintBoxColorBar;
    TRadioButton *RadioButtonWholeBand;
    TRadioButton *RadioButtonStandartBands;
    TRadioButton *RadioButtonManual;
    TButton *ButtonAdjustBands;
    TGroupBox *GroupBoxAmp;
    TLabel *LabelMinScaleAmp;
    TLabel *LabelMaxScaleAmp;
    TLabel *LabelScaleAmpGrades;
    TEdit *EditAmpScaleMin;
    TUpDown *UpDownAmpScaleMin;
    TEdit *EditAmpScaleMax;
    TUpDown *UpDownAmpScaleMax;
    TEdit *EditAmpScaleGrades;
    TUpDown *UpDownAmpScaleGrades;
    TGroupBox *GroupBox6;
    TGroupBox *GroupBox4;
    TTrackBar *TrackBarRAAmp;
    TPanel *PanelRAAmp;
    TUpDown *UpDownRAAmp;
    TCheckBox *CheckBoxMaxAmpAutoAdjust;
    TCheckBox *CheckBoxERTrend1;
    TComboBox *ComboBoxERStyle1;
    TButton *ButtonRatioSettings;
    TCheckBox *CheckBoxERTrend2;
    TComboBox *ComboBoxERStyle2;
    TCheckBox *CheckBoxERTrend3;
    TComboBox *ComboBoxERStyle3;
    TTabSheet *TabSheetView;
    TGroupBox *GroupBoxHigherSEF;
    TCheckBox *CheckBoxHigherSEF;
    TCheckBox *CheckBoxCutAmpTrend;
    TGroupBox *GroupBoxSEFTrends;
    TCheckBox *CheckBoxSEF1;
    TCheckBox *CheckBoxSEF2;
    TComboBox *ComboBoxLineSEF1;
    TComboBox *ComboBoxLineSEF2;
    TGroupBox *GroupBoxPeaks;
    TCheckBox *CheckBoxPeakMain;
    TCheckBox *CheckBoxPeakSecondary;
    TComboBox *ComboBoxLinePeakMain;
    TComboBox *ComboBoxLinePeakSecondary;
    TGroupBox *GroupBoxIndicators;
    TCheckBox *CheckBoxIndicators;
    TGroupBox *GroupBoxDigits;
    TCheckBox *CheckBoxDSEF1;
    TCheckBox *CheckBoxDSEF2;
    TCheckBox *CheckBoxDMax;
    TCheckBox *CheckBoxDEntropy;
    TCheckBox *CheckBoxDTotalAmp;
    TCheckBox *CheckBoxDDeltaIndex;
    TGroupBox *GroupBoxRulers;
    TLabel *LabelRuler;
    TLabel *LabelBand;
    TLabel *Label1;
    TLabel *Label4;
    TCheckBox *CheckBoxScaleLeft;
    TCheckBox *CheckBoxBandLeft;
    TCheckBox *CheckBoxScaleRight;
    TCheckBox *CheckBoxBandRight;
    TCheckBox *CheckBoxRARulerLeft;
    TCheckBox *CheckBoxRARulerRight;
    TCheckBox *CheckBoxScalePanel;
    TGroupBox *GroupBox8;
    TCheckBox *CheckBoxEntropy;
    TComboBox *ComboBoxLineEntropy;
    TTabSheet *TabSheetSpectra;
    TLabel *LabelUseInterval;
    TGroupBox *GroupBox1;
    TLabel *Label3;
    TLabel *Label2;
    TLabel *LabelAlphaSec;
    TLabel *LabelSecP;
    TLabel *LabelRecalc;
    TTrackBar *TrackBarPrimTime;
    TUpDown *UpDownPrimTime;
    TPanel *PanelPrimTime;
    TEdit *EditAlpha;
    TUpDown *UpDownAlpha;
    TGroupBox *GroupBox2;
    TLabel *LabelWindow;
    TLabel *Label5;
    TLabel *LabelNoAveraging;
    TLabel *LabelSegmentValue;
    TLabel *LabelSec3;
    TLabel *LabelSegment;
    TComboBox *ComboBoxWindow;
    TPanel *PanelNSp;
    TUpDown *UpDownNSp;
    TGroupBox *GroupBoxSpectrumEstimator;
    TLabel *LabelAROrder;
    TLabel *LabelSec;
    TLabel *LabelCorrWindow;
    TLabel *LabelSec1;
    TRadioButton *RadioButtonPeriodogram;
    TRadioButton *RadioButtonAutoregressive;
    TTrackBar *TrackBarAROrder;
    TPanel *PanelAROrder;
    TTrackBar *TrackBarCorrWindow;
    TPanel *PanelCorrWindow;
    TButton *ButtonApply;
        void __fastcall TrackBarFreqFromChange(TObject *Sender);
        void __fastcall TrackBarCorrWindowChange(TObject *Sender);
        void __fastcall RadioButtonPeriodogramClick(TObject *Sender);
        void __fastcall TimerApplyTimer(TObject *Sender);
        void __fastcall ButtonDefaultClick(TObject *Sender);
        void __fastcall ScaleMaximumUpDownChangingEx(TObject *Sender,
          bool &AllowChange, short NewValue, TUpDownDirection Direction);
        void __fastcall SensitivityUpDownChangingEx(TObject *Sender,
          bool &AllowChange, short NewValue, TUpDownDirection Direction);
        void __fastcall UpDownScaleGradesChangingEx(TObject *Sender,
          bool &AllowChange, short NewValue, TUpDownDirection Direction);
        void __fastcall ButtonOKClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall TrackBarPrimTimeChange(TObject *Sender);
        void __fastcall ComboBoxWindowChange(TObject *Sender);
        void __fastcall TrackBarTimeChange(TObject *Sender);
        void __fastcall UpDownPrimTimeChangingEx(TObject *Sender,
          bool &AllowChange, short NewValue, TUpDownDirection Direction);
        void __fastcall UpDownTimeChangingEx(TObject *Sender,
          bool &AllowChange, short NewValue, TUpDownDirection Direction);
        void __fastcall CheckBoxClick(TObject *Sender);
        void __fastcall UpDownNSpChangingEx(TObject *Sender,
          bool &AllowChange, short NewValue, TUpDownDirection Direction);
        void __fastcall UpDownFromChangingEx(TObject *Sender,
          bool &AllowChange, short NewValue, TUpDownDirection Direction);
        void __fastcall UpDownToChangingEx(TObject *Sender,
          bool &AllowChange, short NewValue, TUpDownDirection Direction);
        void __fastcall TrackBarFreqToChange(TObject *Sender);
        void __fastcall CheckBoxIndicatorsClick(TObject *Sender);
        void __fastcall RadioGroupTransformClick(TObject *Sender);
        void __fastcall TrackBarRelHeightChange(TObject *Sender);
        void __fastcall UpDownAmpScaleMinChangingEx(TObject *Sender,
          bool &AllowChange, short NewValue, TUpDownDirection Direction);
        void __fastcall UpDownAmpScaleMaxChangingEx(TObject *Sender,
          bool &AllowChange, short NewValue, TUpDownDirection Direction);
        void __fastcall UpDownAmpScaleGradesChangingEx(TObject *Sender,
          bool &AllowChange, short NewValue, TUpDownDirection Direction);
        void __fastcall CheckBoxSmoothingClick(TObject *Sender);
		void __fastcall OnRAParamsChange(TObject *Sender);
		void __fastcall TrackBarMaxAmpChange(TObject *Sender);
		void __fastcall UpDownRAAmpChangeEx(TObject *Sender, bool &AllowChange, short NewValue,
          TUpDownDirection Direction);
		void __fastcall OnBandsClick(TObject *Sender);
		void __fastcall OnDrawRuler(TObject *Sender);
		void __fastcall OnDrawColorBar(TObject *Sender);
		void __fastcall OnBandsSchemeChange(TObject *Sender);
		void __fastcall OnERTrendBandsClick(TObject *Sender);
		void __fastcall UpDownEntropySmoothingChangingEx(TObject *Sender, bool &AllowChange,
          short NewValue, TUpDownDirection Direction);
		void __fastcall UpDownAlphaChangingEx(TObject *Sender, bool &AllowChange, short NewValue,
          TUpDownDirection Direction);
		void __fastcall UpDownSEFPercent1ChangingEx(TObject *Sender, bool &AllowChange,
          short NewValue, TUpDownDirection Direction);
		void __fastcall UpDownSEFFromChangingEx(TObject *Sender, bool &AllowChange, short NewValue,
          TUpDownDirection Direction);
		void __fastcall UpDownSEFToChangingEx(TObject *Sender, bool &AllowChange, short NewValue,
          TUpDownDirection Direction);
		void __fastcall UpDownBandOfChangingEx(TObject *Sender, bool &AllowChange, short NewValue,
          TUpDownDirection Direction);
		void __fastcall OnAutoAdjustClick(TObject *Sender);

private:	// User declarations
        trMcSpectrTrendSettings rCIn, rCOut, rCApplied;    // original, current, applied
        trMcSpectrTrendSettings *prCIn;                    // pointer to input structure
        bool bBlockChangings;
        trMcApplyObj *prAP;
        double fFrqTime;
        double fFrqBand;
        trMcSpectrTrendBoards * prB; // used to compute pixels per second
        TrLineCMBX rLineCMBX[8];
        Graphics::TBitmap *prBMRuler;
        Graphics::TBitmap *prBMColorBar;
        int nAlphaValue;
        bool bAdjustMaxAmp;          // if adjust ER trend max amplitude value when config apply next time
        bool bMGA;

        enum TrReadParamType { rpSpectr, rpChegoIzvolite }; //chegoizvolite :)

        void ReadParam(trMcSpectrTrendSettings *prConfig, TrReadParamType enReadType = rpChegoIzvolite);
        void SetPanelTimeValue( void );   // set caption of panel time corr. to current trend's window width
        void SetSpcTimeLabels( void );    // set captions for panels/labels for prim. spectrums
                                          // validity of intersection value
        void CheckUpDownAlpha( void );    // check if intersection is correct and correct it if needed
        void OnTypeChange(void *pSender, long nType);
        void ApplyMaxAmpAutoAdjust();     // apply max ER trend amplitude auto adjust

protected:
       void __fastcall (__closure *OldFromWndProc)(Messages::TMessage &Message);
       virtual void __fastcall FromWndProc(Messages::TMessage &Message);
       void __fastcall (__closure *OldToWndProc)(Messages::TMessage &Message);
       virtual void __fastcall ToWndProc(Messages::TMessage &Message);
       void __fastcall (__closure *OldTimeWndProc)(Messages::TMessage &Message);
       virtual void __fastcall TimeWndProc(Messages::TMessage &Message);

public:		// User declarations
        __fastcall TFormSpectrTrendSettings( TComponent* Owner,
                                             short nMode,
                                             trMcSpectrTrendBoards * prB,
                                             trMcSpectrTrendSettings * prC,
                                             trMcApplyObj * prAAP = NULL,
                                             bool* pbMGA = NULL);

        __fastcall ~TFormSpectrTrendSettings();

        void RestoreOptions(trMcSpectrTrendSettings * prC);
        int nTrackBarTimePos;

};

// Get config. structure; if !prSettings - pointer to static structure returned
trMcSpectrTrendSettings *BrGetSpcTrendSettings( trMcSpectrTrendSettings *prSettings=NULL );

// Set config. structure, write to .ini file
void BrSetSpcTrendSettings( trMcSpectrTrendSettings *prSettings=NULL );

// Setting parameters for multichannel spectrums (open modal window) --------
bool McEditSpectrTrendSettings(
		trMcSpectrTrendSettings *prC,     // (In/Out) struct to be edited         				 			   +
		trMcSpectrTrendBoards   *prB,     // (In) time boards for trend / curr. width of window (depends upon settings)
		// !!!    int nAWidth,                       // (In) width (in pixels) of the spectral trends area     -
		trMcApplyObj *prAP = NULL,        // (In/Opt) (if NULL - no "auto apply" is performed)   			   +
		bool* pbShowViewPage = NULL,      // (In/Opt) flag if show second page ("view")  		 			   -
		bool* pbMGA = NULL                // (In/Opt) flag if MGA ver.                  		 			   -
                            ); // return: ? struct modified

//---------------------------------------------------------------------------
extern PACKAGE TFormSpectrTrendSettings *FormSpectrTrendSettings;
//---------------------------------------------------------------------------
#endif
