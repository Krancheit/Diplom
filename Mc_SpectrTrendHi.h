/*************************************************************************
 Module
 Spectrums' trend in time
 File
 Mc_SpectrTrendHi.h
 Comment
 Main module for displaying of spectrums' trend
 Modified
 Date      Person		Comment
 ----------------------------------------------------------------------
 10-Feb-20 Abasov E.         Cosmetics
 28-Nov-16 Larionov V.       Changes
 26-Oct-16 Abasov E.         Color scale changes
 16-Jul-15 Larionov V.       Changes
 05-Sep-13 Larionov V.       Total changes
 26-Oct-12 Larionov V.       Changes
 16-Oct-12 Larionov V.       Spectrum trend saving
 20-Mar-12 Larionov V.       Cursor and scrolling changes
 30-Nov-11 Abasov E.         Embarcadero color fixes
 26-Nov-07 Yurovskiy         Cosmetics
 09-Jun-07 Yurovskiy         comments added
 22-May-07 Yurovskiy         1st & 2nd amplitudes to trMcSpcTrendDta
 22-May-07 Yurovskiy         Cosmetics
 30-Mar-07 Yurovskiy         GetInfo() modified, GetProssessedData() added, 2 new structures
 18-Jan-07 Yurovskiy         Cosmetics
 05-Dec-06 Yurovskiy         Modifications for the trend of AR ratio
 27-Oct-06 Yurovskiy         new fields for SEF added to trMcSpcTrendPrmI
 16-Oct-06 Yurovskiy         dfm changes, defines added
 10-Oct-06 Yurovskiy         new version of trend closed
 02-Sep-06 Yurovskiy         parameters for the scale for RA trend added
 24-Jun-06 Yurovskiy         bShowScalePanel added
 21-Jun-06 Yurovskiy         Max. possible value of trend is included in initialization
 28-Apr-06 Yurovskiy         MC_STD_MAX_FRQ is set to 30, fSEFFrqBand field added
 28-Mar-06 Yurovskiy         Data transformation for diff. scaling added
 07-Mar-06 Yurovksiy         width of trends added; other modifications in trMcSpcTrendPrmI
 23-Feb-06 Yurovskiy         new fields added to trMcSpcTrendPrmI
 21-Feb-06 Yurovskiy         Cosmetics
 07-Feb-06 Abasov E.         SEF2 defines added
 07-Feb-05 Yurovskiy         trend of second SEF added
 04-Feb-05 Yurovskiy         2 SEF's instead of one
 03-Feb-05 Yurovskiy         MC_STD_MAX_FRQ added
 02-Feb-05 Yurovskiy         SEF trend added
 23-Jan-05 Yurovskiy         bShowScreenPanel added
 17-Jan-05 Yurovskiy         panel for screen border added
 17-Dec-05 Yurovskiy         params for max. and 2-nd peks of spectrums included
 02-Dec-05 Yurovskiy         DFM cosmetics
 21-Nov-05 Yurovskiy         Interface structrues modified
 19-Nov-05 Yurovskiy         channels' names added
 06-Oct-05 Yurovskiy         Cosmetics
 28-Sep-05 Chernyavskiy A.   Changes for color updates
 27-Sep-05 Chernyavskiy A.   Control() changed
 21-Sep-05 Chernyavskiy A.   Changes in dfm
 16-Sep-05 Chernyavskiy A.   Changes in dfm
 15-Sep-05 Chernyavskiy A.   New fields added to trMcSpcTrendPrmI - again
 14-Sep-05 Chernyavskiy A.   New fields added to trMcSpcTrendPrmI
 12-Sep-05 Chernyavskiy A.   DFM changed
 08-Sep-05 Chernyavskiy A.   Vertical ruler added
 07-Sep-05 Chernyavskiy A.   Mouse-related functions removed
 30-Aug-05 Chernyavskiy A.   Modifications
 19-Jul-05 Yurovskiy         Original
 *************************************************************************/

#ifndef Mc_SpectrTrendHiH
#define Mc_SpectrTrendHiH

// ---------------------------------------------------------------------------
// Includes -----------------------------------------------------------------
// ---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <AsPanelEx.hpp>

#include <Menus.hpp>
#include <MLMultiLangMain.hpp>

#include <Mc_Objects.h>
#include <Mc_SpectrTrendProc.h>    // trMcSpcTrendData
#include <Mc_SpectrTrendBuffers.h>
#include "JvExComCtrls.hpp"
#include "JvProgressBar.hpp"
#include <ComCtrls.hpp>  // trMcSTBPrmExtInd

#include <Mc_Freque.h>


// ---------------------------------------------------------------------------
// Defines -----------------------------------------------------------------
// ---------------------------------------------------------------------------

// Default freq. interval for displaying trend
#define MC_STD_FRQBAND_MIN     0   // from this point (Hz)
#define MC_STD_FRQBAND_MAX     20  // to this point (Hz)

// Defines for the max. length of trend (assuming the trend is drawn on total screen, from left to right)
// The max. possible length is set on initialization; it specifies restrictions for the
// min. possible segments for both computation of spectrums & intersection of spectrums
#define MC_STD_MIN_MAX_LENGTH   (10*60)  // min. for the max. length of trend (Sec.)
#define MC_STD_MAX_MAX_LENGTH   (120*60) // max. for the max length of trend (Sec.)
#define MC_STD_DEF_MAX_LENGTH   (30*60)  // default for the max. length of trend (Sec.)

#define MC_STD_DEF_LENGTH       MC_STD_MIN_MAX_LENGTH  // default for the length of trend (Sec.)

#define MC_STD_MIN_LENGTH       (3*60)   // min. possible length of trend
// So, the possible segment of selection the trend length is [MC_STD_MIN_LENGTH, M],
// where M is value in [MC_STD_MIN_MAX_LENGTH, MC_STD_MAX_MAX_LENGTH], with which trend
// was initialized

#define MC_STD_DEF_CSA_HPERCENT 50 // default relative height occupied by CSA trend in total stripe of trends (%)

#define MC_STD_MAX_CHANNELS    8   // max. number of channels for spectr. trend

#define MC_STD_MAX_NMB_COLORS  256 // max. number of colors in array for the color scale (scale's grades)
#define MC_STD_MIN_NMB_COLORS  3   // min. number of colors in array for the color scale
#define MC_STD_DEF_NMB_COLORS  30  // default number of colors in array for the color scale

#define MC_MIN_CEF_PERCENT_1   75  // min. percent for SEF (spectrum edge frequency) value (%)
#define MC_MAX_CEF_PERCENT_1   99  // max. percent for SEF value (%)
#define MC_MIN_CEF_PERCENT_2   40  // min. percent for SEF (spectrum edge frequency) value (%)
#define MC_MAX_CEF_PERCENT_2   70  // max. percent for SEF value (%)
#define MC_DEF_CEF_PERCENT_1   90  // default percent for the first SEF value
#define MC_DEF_CEF_PERCENT_2   50  // default percent for the second SEF value

#define MC_STD_MAX_FRQ         30. // (MC_STP_FRQ_BAND/2)  // max. frq. band is [0..MC_STD_MAX_FRQ] Hz
// (spectrum gives more, but we don't use it)

#define MC_STD_MIN_MAX_SEF_FRQ 12. // min. value of upper limit for frq. band for SEF (SEF is calculated
// in segment [f..F]Hz, where F must be in [MC_STD_MIN_MAX_SEF_FRQ..MC_STD_MAX_FRQ])
#define MC_STD_DEF_MAX_SEF_FRQ 20. // default value of upper limit for frq. band for SEF
#define MC_STD_MAX_MIN_SEF_FRQ 2.  // max. value of lower limit for frq. band for SEF
#define MC_STD_DEF_MIN_SEF_FRQ 0.5 // default value of lower limit for frq. band for SEF

#define MC_STD_MAX_SEF_SMT     4.  // max. value of frq. band used for smoothing spectrum before calculating SEF (Hz) (min. is 0 - no smoothing)
#define MC_STD_DEF_SEF_SMT     2.  // defailt value of frq. band used for smoothing spectrum before calculating SEF (Hz)

#define MC_STD_MIN_MIN_AMP     3   // min. value of min. amplitude for amplitude trend (mkV, peak-peak)
#define MC_STD_MAX_MIN_AMP     10  // max. value of min. amplitude for amplitude trend (mkV, peak-peak)
#define MC_STD_DEF_MIN_AMP     5   // default value of min. amplitude for amplitude trend (mkV, peak-peak)

#define MC_STD_MIN_MAX_AMP     20  // min. value of max. amplitude for amplitude trend (mkV, peak-peak)
#define MC_STD_MAX_MAX_AMP     150 // max. value of max. amplitude for amplitude trend (mkV, peak-peak)
#define MC_STD_DEF_MAX_AMP     80  // default value of max. amplitude for amplitude trend (mkV)

#define MC_STD_MAX_CHN_LEN     12  // max. length of channel's name

// Error codes --------------------------------------------------------------
#define MC_STD_NO_ERROR       0    // OK
#define MC_STD_NOT_INIT       1    // Object is not initialized yet
#define MC_STD_BAD_PRM        2    // Bad input parameters
#define MC_STD_NO_MEMORY      3    // Out of memory
#define MC_STD_GENERIC_ERR    99   // Any other error

#ifndef CDELETE
#define CDELETE( a )    { delete a;  a = NULL; }
#endif

// ---------------------------------------------------------------------------
// Types -------------------------------------------------------------------
// ---------------------------------------------------------------------------

// Frame with controls used for displaying ----------------------------------
class TFrameSpectrTrend : public TFrame {
__published: // IDE-managed Components

  TPopupMenu *PopupMenu1;
  TMultiLang *MultiLang1;
  TMenuItem *MenuItemSettings;
  TPanel *PanelBorder;
  TPanel *PanelSpectrTrend;
  TPanel *PanelHorSpTrendRuler;
  TPaintBox *PaintBoxHorRuler;
  TPanel *PanelHorBorder;
  TPanelEx *PanelTrends;
  TPaintBox *PaintBoxTrends;
  TPanel *PanelInPoint;
  TLabel *LabelHz;
  TLabel *LabelMkvHz;
  TLabel *LabelChName;
  TPanel *PanelFreq;
  TPanel *PanelValue;
  TPanel *PanelTime;
  TPanelEx *PanelFreqInd;
  TPaintBox *PaintBoxFreqInd;
  TPanel *Panel1;
  TPanel *PanelScreenBorder;
  TLabel *LabelCursor;
  TPanel *PanelViewDigits;
  TPanel *PanelViewDigitsLowBorder;
  TPanel *PanelVertBorderS;
  TLabel *LabelTotalAmpP;
  TLabel *LabelSelectedAmpP;
  TLabel *LabelRelEnergyP;
  TTimer *TimerCursor;
  TPanel *PanelProgress;
  TJvProgressBar *JvProgressBar1;
  TPanel *PanelButtons;
  TLabel *Label1;
  TBitBtn *ButtonSTSave;
  TBitBtn *ButtonSTExport;
  TPanel *PanelCSAData;
  TLabel *LabelSEFHi;
  TLabel *LabelSEFLo;
  TPanel *PanelCEFPerCentHi;
  TPanel *PanelCEFPerCentLo;
  TPanel *PanelSEFFrqHi;
  TPanel *PanelSEFFrqLo;
  TLabel *LabelHz2;
  TLabel *LabelHz3;
  TLabel *LabelTotallAmp;
  TPanel *PanelTotAmp;
  TLabel *LabelMkv;
  TLabel *LabelMax;
  TPanel *PanelMaxFrq;
  TLabel *LabelHz1;
  TPanel *PanelMaxValue;
  TLabel *LabelMkvHz1;
  TLabel *Label2;
  TPanel *PanelEntropy;
  TPanel *PanelRAData;
  TGroupBox *GroupBoxEnergiesInBands;
  TPanel *Panel2;
  TLabel *Label3;
  TPanel *Panel3;
  TLabel *LabelPerCent;
  TPanel *Panel4;
  TLabel *Label5;
  TPanel *Panel5;
  TLabel *Label6;
  TPanel *Panel6;
  TLabel *Label7;
  TPanel *Panel7;
  TLabel *Label8;
  TPanel *Panel8;
  TLabel *Label9;
  TPanel *Panel9;
  TLabel *Label10;
  TGroupBox *GroupBoxEnergyRatio;
  TPanel *Panel10;
  TPanel *Panel11;
  TPanel *Panel12;
  TLabel *Label11;
  TLabel *Label12;
  TLabel *Label13;
  TLabel *Label4;
  TLabel *Label14;
  TLabel *Label15;
    TPanel *PanelR;
    TPanel *PanelIndicatorsDef;
    TPanel *PanelBars;
    TMenuItem *MenuItemFreq;
    void __fastcall MenuItemFreqClick(TObject *Sender);

public: // User declarations

  __fastcall TFrameSpectrTrend(TComponent* Owner) : TFrame(Owner) {}
};
// ---------------------------------------------------------------------------

// Forwards -----------------------------------------------------------------
struct trMcSpcTrendPrmE; // Parameters for spectrum trend set externally
struct trMcSpcTrendPrmI; // Parameters that trMcSpectrTrend normally sets itself
// (there is also possibility to set them externally but normally it is not used)
struct trMcSpcTrendDta; // Calculated data (SEF, ...) in a time point
struct trMcSpcTrendDCfg;
// Configuration of processed data (number of channel, sample rate, ...)

// Template for the main object ---------------------------------------------
struct trMcSpectrTrend : TFrameSpectrTrend {
  __fastcall trMcSpectrTrend(TComponent* Owner) : TFrameSpectrTrend(Owner) {}

  __fastcall virtual ~trMcSpectrTrend() {}

  virtual bool Init( // Initialize object
	trMcSpcTrendData *prD, // (In) data source
	trMcSpcTrendPrmE *prP, // (In) parameters for spectrum trend
	char **ppsChNames = NULL,
    // (In/Opt) names of channel; array of strings of length
	// not longer than MC_STD_MAX_CHN_LEN (truncated if longer)
    long lTMax = MC_STD_DEF_MAX_LENGTH,
    // (In) Max. length of trend if drawn on the total screen
    // from left to right (Sec.); this setting may modify parameters
    // for the calculation of spectrums (min. length of interval for
    // calculating spectrums & min. length of spectrums' intersection)
    trMcSTBPrmExtInd *prPEI = NULL,
    // (In/Opt) source of external indexes (to be displayed on amp. trend's field)
    bool* pbEnableExport = NULL,
    // (In/Opt) flag, if enable ST export
    bool* pbLightMode = NULL,
    // (In/Opt) flag, if MGA ver
    bool* pbMGA = NULL
    // (In/Opt) flag, if show ST in small window (for navigator bar)
    ) = 0; // return: true if OK, false for bad parameters or system error

  virtual bool Control( // modify trend
    trMcSpcTrendPrmE *prP, // (In) parameters for spectrum trend
    trMcSpcTrendPrmI *prPI =
    NULL // (In/Opt) parameters which are usually set by trend itself
    ) = 0;

  virtual bool GetInfo( // get curr. information
    trMcSpcTrendPrmE *prPE, // (Out) curr. parameters (ext.)
    trMcSpcTrendPrmI *prPI = NULL, // (Out/opt) curr. parameters (loc.)
    trMcSpcTrendDCfg *prSDC =
    NULL // (Out/Opt) configuration of processed data (number of channels, sample rate, ...)
    ) = 0;

  virtual bool GetProcessedData( // Get processed signal data
    double fT,
    // (In) time point for processed data (sec.; value <0 means that the rightmost time point is used)
    int nCh, // (In) number of channel for processed data
    trMcSpcTrendDta *prSD
    // (Out) calculated data in time point prPE->fTR (or earlier point, if there is no data)
    ) = 0; // true if OK, false if bad parameters or other error; also if fT is >= 0 and out of data time range

  virtual void SetAcqMode(bool bAcqMode) = 0; // set acquisition mode

  virtual short GetErrorCode(void) = 0;
  // error code for the last performed call
};

// Structure for colored bar indicating frequencies -------------------------
struct trBand {
  double fFrom; // start of band in some units (for example, Hz)
  double fTo; // end of bar
  TColor cColor; // color used for drawing this band

  // default constructor
  trBand()
  {
    fFrom = fTo = 0.;
    cColor = clYellow;
  }
};

// Structure for callback ---------------------------------------------------
struct trMcSpcTrendCallback {
  // tells that current screen position was changed
  virtual void SetPosition(double fPos // (In) new position (secs)
    ) = 0;

  // gets right border of available signal
  virtual long GetRightBorder() = 0;

  // gets examine object ptr
  virtual TrMcExamine* GetExamine() = 0;
};

// Parameters for spectrum trend (set from outside) ------------------------
struct trMcSpcTrendPrmE {
  double fTR; // Right time point (sec.) (same for signal on screen & trend)
  double fTScr;
  // length of time segment of signal on screen ([fTR-fTScr, fTR])

  // Colors & colored vert.panel with freq. bands
  TColor nBK1; // color for background (not computed spectrums)
  TColor nBK2; // color for background (zone between spectrums)

  TColor nSC1, nSC2, nSC3; // 3 colors to combine array for scale grades

  // Colors for trends; the dotted line of these colors are drawn on background of nTrendsBKC color;
  // for no background the dotted line of background color is drawn
  TColor nSpMaxC1, nSpMaxC2;
  // color for the max. peak of spectrums & second peak of spectrums
  TColor nSEFColor;  // color for SEF (spectrum edge freq.) trend
  TColor nTrendsBKC; // color of background line for trends
  TColor nEntropyC;  // color of spectral entropy trend

  TColor nRulerFont;     // ruler colors
  TColor nRulerBack;

  // color scale
  TColor nCSForeC;       // color for labels (i.e., freq. diapasone)
  TColor nCSActC;        // active color of ruler & scale border
  TColor nCSNActC;       // non active color of ruler & scale border

  trBand pBands[4];
  // params for bands (alpha-, beta-, etc.) frequencies and colors
  TColor nSpcNormColor; // color for band outside of specific bands

  trMcSpcTrendCallback* prCallback; // callback

  void SetBandsColors( // all parameters are input
    TColor nASpcNormColor, // color of bands outside specified bands
    short nABands, // number of frq. bands
    TColor * pnColors, // colors for curves in frq. bands
    float * pfFrqs // frq. bands
    );

  trMcSpcTrendPrmE(void); // set defaults
  void SetColorScheme(TColor nASC1, TColor nASC2, TColor nASC3);
  // set three colors to combine for scale grades
  bool operator == (const trMcSpcTrendPrmE &) const ;
};

// Parameters for spectrum trend (by object itself by calling settings) ----
struct trMcSpcTrendPrmI {
  double fPixPerSec; // pixels per sec. (determines length of trend on screen)
  short nCSAHeightPerCent;
  // % of height of CSA in stripe with trends. If less then 10,
  // then only amplitudes/indexies trend is displayed; if more then 90,
  // then only CSA is displayed
  // 1. *** CSA
  float fFrqF, fFrqT; // freq. band to be displayed

  double fFrqFS, fFrqToS;
  // Frq. band to calculate SEF values (should be a subset of frq. band in spectral processor)
  double fSSB;
  // SEF smoothing band: if fSSB > 0 then the values of spectrum are smoothed
  // with rect. window with fSSB width
  double fEntSmoothing;
  // Entropy smoothing band (same as for SEF)
  short anSEFPercent[2];
  // percent for two computed SEF values (in [MC_MIN_CEF_PERCENT, MC_MAX_CEF_PERCENT])

  enum TransType {
    Linear = 0, SqrRoot = 1, Logarythm = 2
  }

  nTransform; // data transform for CSA (from spectrum to scale values)
  bool bShowSpectrHigherSEF;
  // ? display colored spectrum for frq. higher than high SEF frq.(if not, background is displayed)

  // Scale for CSA (compressed spectrum analysis) trend:
  double fScaleMax; // Global max. (range) of scale (in units of spc.)
  double fScaleSens; // Curr. value of scale max. (in units of spc.)
  short nSGrades;
  // number of scale grades for CSA (i.e., number of colors in colors'array)
  // must be inside [MC_STD_MIN_NMB_COLORS, MC_STD_MAX_NMB_COLORS]

  // Vert. rulers & colored bars with EEG freq. bands:
  bool bRulerLeft, bRulerRight;
  // ? draw vertical ruler for frequencies on the left/right side of the screen
  bool bBandLeft, bBandRight; // ? draw colorbar for bands

  // Rulers for RA trend
  bool bRARulerLeft, bRARulerRight;

  // 2. *** Trend of amplitudes & indexies of anaesthesy's depth
  // Scale for RA (rel. amplitudes) trend:
  double fScaleSensR;

  double fScaleSensMaxR;
  // Curr max. of scale (in units of amplitude) (values higher then this are marked with special color)
  double fScaleSensMinR;
  // Curr min. of scale (in units of amplitude.) (values lower then this are marked with special color)
  short nSGradesR;
  // number of scale grades for rel. ampl. (i.e., number of colors in colors'array)
  // must be inside [MC_STD_MIN_NMB_COLORS, MC_STD_MAX_NMB_COLORS]
  // the values lying in [fScaleMinR, fScaleMaxR] are codificated with "nSGradesR" grades of colors
  bool bDisplayARTrend;
  // ? display trend of AR residuals (is displayed in the same zone than rel. amplitudes trend

  // 3. *** One - dimentional trends (SEF (high & low), max & second peak,...)
  enum IndType {
    SEFHi = 0, SEFLo = 1, Max = 2, Peak2 = 3, Entropy = 4
  }; // parameters for trends & digital indicators

  bool abTrends[5]; // ? trends (in order of IndType) are enabled

  enum {
    Thin, Medium, Thick
  }

  arTW[5]; // widht of trends (if enabled)
  // (dotted line with transparent background / dotted line with 1-pixel background line / same with 3-pixes backgr.

  // 4. *** Other view options
  bool bShowScalePanel; // ? show panel with colored scale
  bool bShowIndicatorsPanel;
  // ? show panel with indicators for curr. values of SEF, ... (vertical colored bars)
  // and panel with corr. digital values (optional)
  bool abDigitalIndicator[6];
  // ? show digital values of parameters on indicators' panel (valid only if bShowIndicatorsPanel is true)
  // values corr. to: 0 - SEFHi, 1 - SEFLo, 2 - Max, 3 - second peak
  // (indicators with colored bars are always shown if bShowIndicatorsPanel is true)

  // Digitl indicators back color
  TColor nDigitalIndicatorBackColor;

  bool bShowScreenPanel;
  // ? show vertical panel at the beginning of segment corr. to signal on screen

  trMcSpcTrendPrmI(void); // set defaults (some are in defines above)
  bool operator == (const trMcSpcTrendPrmI &) const ;

  bool AnyTrend();
};

// Calculated data (SEF, ...) in a time point ---------------------------------
struct trMcSpcTrendDta {
  double fSEFHi; // SEF frequency (high)
  int nHiSEFPercent; // percent for high SEF (e.g. 90)

  double fSEFLo; // SEF frequency (high)
  int nLoSEFPercent; // percent for low SEF (e.g. 50)

  double fAmp1, // 1st peak (max of spectrum) mkV^2/Hz
    fFrq1, // Frequency on which 1st peak is reached (Hz)
    fAmp2, // 2nd peak of spectrum mkV^2/Hz (negative if does not exist)
    fFrq2; // Frequency on which 2nd peak is reached (Hz) (negative if does not exist)
};

// Configuration of processed data (number of channel, sample rate, ...) -------
struct trMcSpcTrendDCfg {
  trMcSpcTrendData *prD; // pointer to data source
  char *apsChNames[MC_STD_MAX_CHANNELS];
  // names of channels ("prD->nNmbChOut" strings)
  double fTRecalc;
  // period of calculation of each spectrum (and all other parameters)
  // it is calculated based on parameters set for spectrums (those are set
  // internally inside project via user interface)
  // !! this parameter is unique that may be changed after Init() is called
  // (by calling trend settings)
};

// External | create object for EP graphs' displaying -----------------------
trMcSpectrTrend *McCreateSpectrTrend(TWinControl * Parent,
  // (In) parent for the TFrameSpectrTrend's child
  TWinControl * ButtonsPanel, // (In) panel for buttons
  TComponent * Owner,
  TWinControl *pPanelIndicators = NULL); // (In) owner for the TFrameSpectrTrend's child

// ---------------------------------------------------------------------------
#endif
