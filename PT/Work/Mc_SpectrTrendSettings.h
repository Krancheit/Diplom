/*************************************************************************
  Module
    Settings for spectrums' trend in time
  File
     Mc_SpectrTrendSettings.h
  Comment

  Modified
    Date      Person		Comment
  ----------------------------------------------------------------------
    28-Nov-16 Larionov V.       Changes
    05-Sep-13 Larionov V.       Total changes
    26-Oct-12 Larionov V.       Changes
    09-Feb-07 Yurovskiy         Cosmetics
    21-Nov-06 Yurovskiy         parameters for the AR trend added to trMcSpectrTrendSettings
    03-Nov-06 Yurovskiy         averaging of spectrums modified, new controls added
    27-Oct-06 Yurovskiy         new controls for SEF added
    16-Oct-06 Yurovskiy         parameters for amplitude trend added
    21-Jun-06 Yurovskiy         Settings for spectrum time segment made dependant upon
                                max. possible trend length & ext. information
    28-Mar-06 Yurovskiy         Scale transformations added
    10-Mar-06 Abasov E.         Line combobox processing changed
    09-Mar-06 Abasov E.         Line types added
    28-Feb-06 Yurovskiy         parameters for the panel of indicators added
                                Many modifications in designer
    03-Feb-06 Yurovsky          BRSTREND_X_MAX is substited for MC_STD_MAX_FRQ
    23-Jan-06 Abasov E.         Screen panel added
    02-Dec-05 Yurovskiy         <mc_map.h> excluded; defines for colors included (BRSTREND_MIN_NMB_COLORSá ...)
    21-Nov-05 Abasov E.         Changes
    19-Nov-05 Yurovskiy         Scale units; hour cursor for timer; fixes
    17-Nov-05 Abasov E.         Wndprocs added
    16-Nov-05 Yurovskiy         prCIn added
    07-Oct-05 Chernyavskiy A.   Memorize TrackBarTime position
    15-Sep-05 Chernyavskiy A.   New controls added
    14-Sep-05 Chernyavskiy A.   New controls added for rulers and bands
    13-Sep-05 Chernyavskiy A.   Defines moved here from ".cpp"
    08-Sep-05 Chernyavskiy A.   Changes
    06-Sep-05 Chernyavskiy A.   Cosmetic dfm changes; nWindowWidth added
    31-Aug-05 Chernyavskiy A.   Loading/saving from/to .ini file added
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
  trMcSpcTrendPrmP rPP;      // parameters for "primary" spectrums
  trMcSpcTrendPrmTA rPA;     // parameters for time-averaged spectrums
  trMcARVarPrm1 rPAR1;       // base parameters for AR trend
  trMcARVarPrm2 rPAR2;       // settable parameters for AR trend
  trMcSpcTrendPrmI rPI;      // trend parameters (int. set)
  trMcSTBPrmRA rRA;          // parameters for amp rel trend
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
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
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
  TTabSheet *TabSheetView;
        TUpDown *UpDownFrom;
        TUpDown *UpDownTo;
        TLabel *LabelScaleUnits;
  TTabSheet *TabSheetRA;
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
        TGroupBox *GroupBoxSEF;
        TLabel *LabelSEFHi;
        TEdit *EditSEFPercent1;
        TUpDown *UpDownSEFPercent1;
        TLabel *Label7;
        TLabel *Label9;
        TUpDown *UpDownSEFPercent2;
        TEdit *EditSEFPercent2;
        TLabel *LabelSEFLo;
        TRadioGroup *RadioGroupTransform;
        TGroupBox *GroupBoxCSA;
        TLabel *LabelMkv;
        TLabel *LabelSEFFrqBand;
        TLabel *LabelFrom1;
        TPanel *PanelSEFFrom;
        TUpDown *UpDownSEFFrom;
        TLabel *LabelHz2;
        TLabel *LabelTo1;
        TPanel *PanelSEFTo;
        TUpDown *UpDownSEFTo;
        TLabel *LabelHz3;
        TCheckBox *CheckBoxSmoothing;
        TLabel *LabelInBand;
        TPanel *PanelBandOf;
        TUpDown *UpDownBandOf;
        TLabel *LabelHz4;
  TTabSheet *TabSheetSpectra;
  TLabel *LabelUseInterval;
  TGroupBox *GroupBox5;
  TGroupBox *GroupBox10;
  TPaintBox *PaintBoxBands;
  TPaintBox *PaintBoxColorBar;
  TRadioButton *RadioButtonWholeBand;
  TRadioButton *RadioButtonStandartBands;
  TRadioButton *RadioButtonManual;
  TButton *ButtonAdjustBands;
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
  TGroupBox *GroupBoxHigherSEF;
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
  TGroupBox *GroupBoxRulers;
  TLabel *LabelRuler;
  TLabel *LabelBand;
  TCheckBox *CheckBoxScaleLeft;
  TCheckBox *CheckBoxBandLeft;
  TCheckBox *CheckBoxScaleRight;
  TCheckBox *CheckBoxBandRight;
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
  TGroupBox *GroupBoxRelHeigh;
  TLabel *LabelCSA;
  TLabel *LabelAmpTrend;
  TTrackBar *TrackBarRelHeight;
  TCheckBox *CheckBoxRARulerLeft;
  TCheckBox *CheckBoxRARulerRight;
  TLabel *Label1;
  TCheckBox *CheckBoxScalePanel;
  TLabel *Label4;
  TGroupBox *GroupBox8;
  TCheckBox *CheckBoxEntropy;
  TComboBox *ComboBoxLineEntropy;
  TCheckBox *CheckBoxHigherSEF;
  TCheckBox *CheckBoxCutAmpTrend;
  TGroupBox *GroupBox3;
  TLabel *Label6;
  TPanel *PanelEntSmoothing;
  TUpDown *UpDownEntSmoothing;
  TLabel *Label8;
  TCheckBox *CheckBoxDTotalAmp;
  TCheckBox *CheckBoxDDeltaIndex;
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

        enum TrReadParamType { rpSpectr, rpChegoIzvolite };

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
        trMcSpectrTrendSettings *prC,     // (In/Out) struct to be edited
        trMcSpectrTrendBoards   *prB,     // (In) time boards for trend / curr. width of window (depends upon settings)
        // !!!    int nAWidth,                       // (In) width (in pixels) of the spectral trends area
        trMcApplyObj *prAP = NULL,        // (In/Opt) (if NULL - no "auto apply" is performed)
        bool* pbShowViewPage = NULL,      // (In/Opt) flag if show second page ("view")
        bool* pbMGA = NULL                // (In/Opt) flag if MGA ver.
                            ); // return: ? struct modified

//---------------------------------------------------------------------------
extern PACKAGE TFormSpectrTrendSettings *FormSpectrTrendSettings;
//---------------------------------------------------------------------------
#endif
