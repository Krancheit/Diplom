/*************************************************************************
  Module
    Spectrums' trend in time
  File
     Mc_SpectrTrendHi.cpp
  Comment
    Main module for displaying of spectrums' trend
  Modified
    Date      Person		        Comment
    ----------------------------------------------------------------------
    11-Aug-20 Abasov E.         MGA changes; NULL fixes
    10-Feb-20 Abasov E.         Cosmetics
    25-Apr-19 Yurovskiy         UpdateBitmapBuffer() made bool (to avoid an error)
    28-Nov-16 Larionov V.       Changes
    26-Oct-16 Abasov E.         Color scale changes
    04-Oct-16 Abasov E.         Bars width changes
    21-Sep-16 Abasov E.         New indicators added
    24-Sep-15 Larionov V.       Fixes
    11-Aug-15 Larionov V.       Changes
    16-Jul-15 Larionov V.       Changes
    17-Jun-14 Larionov V.       Changes
    05-Sep-13 Larionov V.       Total changes
    26-Oct-12 Larionov V.       Changes
    18-Oct-12 Larionov V.       Indicators panel fixes
    16-Oct-12 Larionov V.       Spectrum trend saving
    20-Mar-12 Larionov V.       Cursor and scrolling changes
    30-Nov-11 Abasov E.         Embarcadero color fixes
    05-May-10 Bellucci D.       Translations added/checked
    18-Mar-10 Yurovskiy         SetPositionsForDPanel() modified;  Digital panel's
                                viewing in case of small height of one of the trends fixed
    23-Nov-09 Bellucci D.       Translations added/checked
    15-Aug-08 Riabov A.         Proc names changed.
    12-Mar-08 Abasov E.         TrMcHorzSignalRuler <--> TrMcHorzSignalRulerTrend
    09-Jun-07 Yurovskiy         additional fields added to trMcSpcTrendDta are filled in GetProcessedData()
    22-May-07 Yurovskiy         Cosmetics
    17-May-07 Bellucci D.       Translations added/checked.
    30-Mar-07 Yurovskiy         GetInfo() modified, GetProcessedData() added, 2 new structures
    21-Feb-07 Yurovskiy         hing for zero signal fixed
    19-Feb-07 Yurovskiy         UpdateBitmapBuffer() added, cosmetics
    14-Feb-07 Yurovskiy         displaying of rulers fixed
    08-Feb-07 Yurovskiy         SEF calculations modified
    29-Jan-07 Yurovskiy         Cosmetics
    18-Jan-07 Yurovskiy         Set() modified
    08-Dec-06 Yurovskiy         Modifications for the trend of AR ratio; define SET_AR_TO_ARTREND
    27-Oct-06 Yurovskiy         new fields for SEF added to trMcSpcTrendPrmI
    16-Oct-06 Yurovskiy         dfm changes, defines added, Set() modified for amplitude trend
    12-Oct-06 Yurovskiy         Digital panels for rel. amplitude trend
    10-Oct-06 Yurovskiy         boards of arrays fixed; flags for only CSA & bands'selection; Done() fixed
    02-Sep-06 Yurovskiy         modifications for the new container of bmp buffers;
                                parameters for the scale for RA trend added
    02-Aug-06 Yurovskiy         Control of scale transformation modified
    28-Jun-06 Bellucci D.       Italian translation
    24-Jun-06 Yurovskiy         mean energy for bands calculated, scale panes visible/unvisible
    23-Jun-06 Yurovskiy         hor. ruler made dependant upon trend's density; interface with buffers modified
    28-Apr-06 Yurovskiy         MC_STD_MAX_FRQ is set to 30, fSEFFrqBand field added
    30-Mar-06 Yurovskiy         Data transformation for diff. scaling added
    24-Mar-06 Yurovskiy         Values under mouse cursor fixed
    20-Mar-06 Yurovskiy         Values of digital panel in revision fixed
    17-Mar-06 Yurovksiy         Width of indicators' bar modified
    10-Mar-06 Yurovskiy         Displaying of a channel modified; positions of
                                color bands & vertical rulers fixed; bitmap for displaying channel added;
                                setting SEF captions for digital pannels added
    07-Mar-06 Abasov E.         Panel resize fixed
    07-Mar-06 Yurovksiy         width of trends added; other modifications in trMcSpcTrendPrmI
    03-Mar-06 Yurovskiy         Fixes
    03-Mar-06 Abasov E.         Fixes
    02-Mar-06 Yurovskiy         modifications & fixes (... many)
    23-Feb-06 Yurovskiy         panel for indicators added
    19-Feb-06 Yurovskiy         Changes of the interface for cashed buffers
    16-Feb-06 Yurovskiy         Buffers moved to file Mc_SpectrTrendBuffers
    15-Feb-06 Yurovskiy         Vert. rulers modified
    13-Feb-06 Yurovskiy         Scale moved to mc_scalerulers.*
    09-Feb-06 Yurovskiy         Cosmetics for SEF displaying
    09-Feb-06 Abasov E.         DFM translate changes
    09-Feb-06 Abasov E.         Hint changes
    08-Feb-06 Yurovskiy         Fixes; panel on mouse cursor modified
    07-Feb-06 Abasov E.         Hint width/dfm changes
    07-Feb-05 Yurovskiy         trend of second SEF added
    06-Feb-05 Yurovskiy         SEF values at mouse cursor modified; 2 SEF's instead of one
    03-Feb-06 Abasov E.         Hint/cursor added added
    03-Feb-05 Yurovskiy         SEF trend added
    27-Jan-05 Yurovskiy         ComputeAveragedSpectrum() fixed
    24-Jan-05 Yurovskiy         CheckInput() for pix. buffer modified
    23-Jan-05 Yurovskiy         bShowScreenPanel added; buffers modified
    18-Jan-05 Yurovskiy         panel for screen border added
    12-Jan-05 Yurovskiy         fixes
    11-Jan-05 Yurovskiy         fixes & modifications for max. values; Set() for max & sec. peak
    17-Dec-05 Yurovskiy         max. and second peak of spectrums inmplemented
    15-Dec-05 Yurovskiy         params for max. and 2-nd peks of spectrums included
                                Max. of signal for colored scale fixed & modified; dfm cosmetics
    07-Dec-05 Yurovskiy         Modifications of scale
    02-Dec-05 Yurovskiy         Other DFM cosmetics + scale cosmetics
    02-Dec-05 Abasov E.         DFM cosmetics
    01-Dec-05 Abasov E.         Scale bounds changes; Screen cursor fixes
    01-Dec-05 Abasov E.         Scale back erase fixes
    21-Nov-05 Yurovskiy         Control condition fixed
    21-Nov-05 Yurovskiy         Interface structrues modified
    19-Nov-05 Yurovskiy         channels' names added
    16-Nov-05 Yurovskiy         Vertical rulers & bands fixed
    09-Nov-05 Faccioni E.       Dfm translation.
    10-Oct-05 Yurovskiy         Mouse time fixed
    10-Oct-05 Chernyavskiy A.   Fixes for changes of grades for color scales
    07-0ct-05 Yurovskiy         GetDataInPoint() modified; Display() fixed
    06-Oct-05 Yurovskiy         Many changes & fixes
    28-Sep-05 Chernyavskiy A.   Changes for color updates
    22-Sep-05 Chernyavskiy A.   Maximum for color scale changed
    21-Sep-05 Chernyavskiy A.   Cosmetic changes; maximum of spectrums is now used in scale;
                                TrMcCScalePrm renamed to TrMcSpTrScalePrm to avoid collisions with Mc_Map;
                                TrColorScale renamed to TrSpTrColorScale for the same goal
    20-Sep-05 Chernyavskiy A.   THorzSignalRuleer renamed to TrMcHorzSignalRuler;
                                + replaced nNmbCh by nNmbChOut
    16-Sep-05 Chernyavskiy A.   Changes
    15-Sep-05 Yurovskiy         Cycles in buffers modified to avoid code guard message
    15-Sep-05 Chernyavskiy A.   Changes related to colorbars for bands added
    14-Sep-05 Chernyavskiy A.   Colorbars for bands added
    13-Sep-05 Chernyavskiy A.   Vertical ruler changes
    12-Sep-05 Yurovskiy         fixes; define for debugging buffers
    12-Sep-05 Chernyavskiy A.   DFM changed; vertical ruler replaced
    09-Sep-05 Chernyavskiy A.   Panels for GetDataInPoint added
    08-Sep-05 Chernyavskiy A.   GetDataInPoint(), vertical ruler added
    07-Sep-05 Chernyavskiy A.   Mouse-related functions changed + some minor fixes;
                                +Yet another param for McEditSpectrTrendSettings
    06-Sep-05 Chernyavskiy A.   One more param for McEditSpectrTrendSettings
    05-Sep-05 Chernyavskiy A.   Changes related to ruler and scale
    02-Sep-05 Chernyavskiy A.   Changes related to ruler and scale
    01-Sep-05 Chernyavskiy A.   Changes for painting and resizing
    31-Aug-05 Yurovskiy         Modifications / fixes (see "!!!")
    30-Aug-05 Chernyavskiy A.   Changes
    25-Aug-05 Yurovskiy         Fixes
    06-Aug-05 Yurovskiy         Cashed buffers
    19-Jul-05 Yurovskiy         Original
*************************************************************************/

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Includes -----------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <math.h>         // fabs()
#include <JvJCLUtils.hpp> // for hours/minutes/seconds in ruler
#include <stdio.h>        // sprintf()     - !!! temporary, for debug

#include <JvgProgress.hpp>

#define NEW_INDICATORS
#ifdef NEW_INDICATORS
#include "AsIndicator.h"
#endif

#include "Cw_appl.hpp"
#include "Cw_util.hpp"

#include "utldttm.h"      // trTime
#include "utlstr.h"       // also for time labels on ruler
#include "Cb_Defs.h"
#include "Cb_Ruler.h"     // for ruler
#include "Cb_Util.h"      // for hint window

#include "Mc_CashedBuffers.h"      // trCashedBufferN, trCashedBufferT
#include "Mc_SpectrTrendSettings.h"
#include "Mc_ScaleRulers.h"        // TrSpTrColorScale
#include "Mc_SpectrTrendBuffers.h" // trSpcBuf, trPixBuf, trBtmBufCSA
#include "Mc_SpectrTrendStorage.h"
#include "Mc_DigitalPanel.h"       // trMcDigitalPanel

#include "Mc_SpectrTrendHi.h"

//------------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AsPanelEx"
#pragma link "MLMultiLangMain"
#pragma link "JvExComCtrls"
#pragma link "JvProgressBar"
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
//  Defines -----------------------------------------------------------------
//---------------------------------------------------------------------------
#define MP_COLOR_PWR        0.7  // power in interpolation from one color
                                 // to another in color scale (1. - linear int.)
#define CH_PIX_DIST_2       2    // 1/2 of min. vert. dist. between neighbour channels (pix.)
#define LR_PIX_DIST         0 //2*CH_PIX_DIST_2   // dist. from the beginning / end of spectrums' zone to displaying zone's edges
#define CLR_BK2             100  // intensity of gray (RGB(x,x,x)) for the background color no.2 (stripes between channels,...)

#define FLOAT_EQ( a, b )    (fabs((a)-(b)) < 1e-9)
#define BOOL_EQ(a,b)        ( ((a) && (b)) || (!(a) && !(b)) )

#define MALO                1E-5

#undef MP_DIRECT_BITMAP_MODE
#ifdef MP_DIRECT_BITMAP_MODE
  #define MAKE_RGB(a, b, c) RGB(a, b, c)
#else
  #define MAKE_RGB(a, b, c) RGB(c, b, a)
#endif

// defines for the control of the color scale
#define SCALE_MOVE_CURSOR   crSizeNS    // cursor for modification of scale

// Defines for color scale sizes:
#define MP_VERT_RULER_WDT    6.   // width of vertical ruler for trends, in mm
#define MP_VERT_RULER_LW     0.26 // line width of vertical ruler for trends, in mm
#define MP_VERT_BAND_WDT     1.2  // width of vertical column for bands, in mm

// *** Other defines:
#define MM_TO_PIX( mm, ppm )   (int)( (mm)*(ppm) + 0.5 )  // mm to pixels
#define MP_NEAR_MM           2.5  // distance ( MAX(DX, DY) ) between mouse cursor and a control (e.g., scale) cursor
                                 // when the control is possible to be modified (mm)
#define MP_MIN_IND_HEIGHT_MM 20. // min height of indicator's panel for one trend (mm)

#define MP_MIN_IND_TEXT_HEIGHT_MM 2.5 // min height of indicator's text panel for one trend (mm)

#define MP_NEAR_PIX( ptm )   MM_TO_PIX( MP_NEAR_MM, ptm ) // same in pixels

// float int. [F1,F2] to pixels [0,...,K-1]:
#define FLOAT_IND( F1, F2, K, x )   (long)( (x>=F2) ? (long)(K-1) : (long)( (K)*(x-F1)/(F2-F1) ) )
// float int. [F1,F2] to pixels [K-1,...,0]:
#define FLOAT_ANTIIND( F1, F2, K, x )   ( (K-1) - FLOAT_IND( F1, F2, K, x ) )

// pixels [0,...,K-1] to float int. [F1,F2] edge to edge:
#define IND_FLOAT_EDGES( K, F1, F2, l )    (double)( ((l)/(double)(K-1))*(F2-F1) + F1 )

// *** Sizes of objects in trend:
#define HINT_HIDE_PAUSE     3500 // hint show time
#define HINT_PAUSE          500  // time before hint
#define HINT_STR_LENGTH     25   // length of hint string (size is fixed)

#define LONG_SIGNAL_TIME    (60*5)  // period for which signal is long enought to display
                                    // progress bar for recalculating it (sec., one channal; is increased for many channels)
#define LONG_SIGNAL_TICKS   4       // number of steps of progress bar to display signal of LONG_SIGNAL_TIME length

#define BARS_GAP_FRACTION   0.33    // interval between bars (in %%)

// defines for configuration (temporarily - it should be settings...) ----------
    #undef ONLY_CSA         // display only CSA (otherwise - CSA & rel. amplitudes)
#define DELTA               // ampl. trend is displayed for delta band only
                            // (otherwise - delta and (alpha + betha) )

// cursors
#define ST_TREND_CURSOR 6
#define ST_HAND_CURSOR 7
#define ST_CAPTURED_CURSOR 8

#ifndef CDELETE_M
  #define CDELETE_M( a )    { delete[] a;  a = NULL; }
#endif
#ifndef CFREE
  #define CFREE( a )        { free( a );  a = NULL; }
#endif
#ifndef MAX
  #define MAX( a, b )       ((a) > (b) ? (a) : (b) )
#endif
#ifndef MIN
  #define MIN( a, b )       ((a) < (b) ? (a) : (b) )
#endif

#ifndef RED
  #define RED(c) (c & 0x000000FF)
#endif

#ifndef GREEN
  #define GREEN(c) ((c & 0x0000FF00) >> 8)
#endif

#ifndef BLUE
  #define BLUE(c) ((c & 0x00FF0000) >> 16)
#endif

//---------------------------------------------------------------------------
//  Locals' declarations ----------------------------------------------------
//---------------------------------------------------------------------------
static double fPixMM = (double)GetDeviceCaps(GetDC(NULL), LOGPIXELSX) / 25.4;

// Local | Hor. axes for a channel ------------------------------------------
static int HorAxes( int nH, short nNCh, short nCh, short nDT = CH_PIX_DIST_2 ) // (In) heigth of channels' area, number of channels, curr. channel
{  float fAx = ((nH-2*nDT) /(float)nNCh)*(nCh + 0.5);   return nDT + (int)(fAx + 0.5);  }

// Local | Height of a band for a channel -----------------------------------
static int ChHeight( int nH, short nNCh,   // (In) total height of displaying zone, number of channels, min
                          short nMinD = 2*CH_PIX_DIST_2 );   // (In) 1/2 of min. distance between the edges of the neightbour band (in pix.)

// Local | Create array with colors for map & color scale ------------------
static void SetColors( TColor nC1, TColor nC2, TColor nC3, // (In) base colors making scale
                       int nGrd,                           // (In) number of grades in scale
                       TColor *pnC,                        // (Out) array with colors for scale ("nGrd" values)
                       double fSmooth = MP_COLOR_PWR );    // (In/Opt) smoothing parameter for mixing colors nC1, nC2, nC3

// Local | draw vertical rulers, one is oriented towards left, another towards right
static void DrawVertRulers( TCanvas *prC1, // (In) canvas for left-oriented ruler
              TCanvas *prC2,               // (In) canvas for right-oriented ruler
              TRect rR,                    // (In) where to draw
              TColor nC,                   // (In) foreground color
              int nLW,                     // (In) line width (pixels)
              double fA, double fB,        // (In) min/max of the interval
              double fStep,                // (In) step (in [fA, fB]) for markers
              short nStep );               // (In) draw "big" marker every "nP" markers (others are small)

static void DrawBandColumn( TCanvas *prC,            // (In) where to draw
                            TRect rR,
                            TColor cBorder,          // (In) border color, also used to fill in gaps between bands
                            double fA, double fB,    // (In) min/max of the interval
                            trBand *pBands,          // (In) data about boundaries of bands
                            int nBands );            // (In) how many bands in pBands

static TRect ShiftRect( TRect rR, int nLeft, int nTop )
{ return TRect( rR.left+nLeft, rR.top+nTop,  rR.right+nLeft, rR.bottom+nTop ); }

static AnsiString GetTimeString(long nSeconds, short nTimeCoeff = 1);  // string "xx.xx.xx" (nTimeCoeff ==1) or "xx.xx", including negative values
static AnsiString PadString(AnsiString sStr, long nMaxLen);

// Update buffer-container for the spectrum trends; display progress bar for long calculations
static bool UpdateBitmapBuffer( long *plF, long *plT,      // (In) from time point, to time point (in pixels' coord.)
                                trMcBtmBufSpcTrend *prB,   // (In) buffer
                                double fUnitPerSec );      // (In) number of units (pixels) per second

// get object mouse coordinates
static void GetMouseCoord(TControl *pControl, int &X, int &Y);

//---------------------------------------------------------------------------
//  Types -------------------------------------------------------------------
//---------------------------------------------------------------------------

// Horizontal ruler ---------------------------------------------------------
class TrMcHorzSignalRulerTrend : public trCbRuler
{
public:
  __fastcall TrMcHorzSignalRulerTrend(TPaintBox *pADisplayBox, double fPPU ) :
  trCbRuler( pADisplayBox, fPPU, RL_HORIZONTAL_LEFT_TO_RIGHT, &rP ) { Update( fPPU ); }

  void Update( double fPPU )
  {
    double fST = Screen->Width / fPPU;  // time of trend if it occupied total screen
    nTK = fST < 600. ? 1 : fST < 1500. ? 2 : fST < 3000. ? 5 : fST < 5000. ? 10 : 20;

    TrCbRulerMarkersPar rP;
    rP.Set( nTK*30, nTK*6, nTK*3,   // rates of: time text markers, large line markers, small line markers
                         3,  1 );    // sizes of: large line markers, small line markers (pix.)
    Set( &rP, fPPU );
  }

  virtual __fastcall ~TrMcHorzSignalRulerTrend(void){}

protected:
  short nTK;  // curr. time coeff.

  virtual AnsiString ValueFunc( long n ) // in sec.
  { return (n) ? GetTimeString( n, nTK ) : (AnsiString) "0"; }
};


#ifdef NEW_INDICATORS
struct TrIndicatorHolder
{
  std::vector<TAsIndicator *> vAsIndicator;
  std::vector<TPanel *> vIndPanels;
  std::vector<TJvgProgress *> vProgressBars;
  std::vector<TPanel *> vBarPanels;

  TrIndicatorHolder()
  {
    vAsIndicator.resize(6, NULL);
    vIndPanels.resize(6, NULL); // 2/*CSA*/ + 4 /*ampl*/
    vProgressBars.resize(6, NULL);
    vBarPanels.resize(2, NULL); // 1/*CSA*/ + 1 /* ampl */
  }

  ~TrIndicatorHolder()
  {
    Free();
  }

  void Free()
  {
    for (int i = 0; i < vAsIndicator.size(); i++)
      CDELETE(vAsIndicator[i]);
  }
};

#endif
//---------------------------------------------------------------------------
// Real object for spectral trend (with code) -------------------------------
//---------------------------------------------------------------------------
struct trMcSpectrTrendR : trMcSpectrTrend
{
  __fastcall trMcSpectrTrendR(TComponent* Owner, TWinControl *pPanelIndicators);

  __fastcall virtual ~trMcSpectrTrendR()
  {
    Done(); CDELETE(pCurrValueHintW); CDELETE(prBBST); CDELETE(prSTBuffer);
#ifdef NEW_INDICATORS
    for (int nCh = 0; nCh < MC_STD_MAX_CHANNELS; ++nCh)
      arIndicatorHolder[nCh].Free();
#endif
  }

  virtual bool Init(  // Initialize object
                     trMcSpcTrendData *prD,    // (In) data source
                     trMcSpcTrendPrmE *prP,    // (In) parameters for spectrum trend
                     char **ppsChNames = NULL, // (In/Opt) names of channel; array of strings of length
                                               // not longer than MC_STD_MAX_CHN_LEN
                     long lTMax = MC_STD_DEF_MAX_LENGTH,  // (In) Max. length of trend if drawn on the total screen
                                               // from left to right (Sec.); this setting may modify parameters
                                               // for the calculation of spectrums (min. length of interval for
                                               // calculating spectrums & min. length of spectrums' intersection)
                     trMcSTBPrmExtInd *prPEI = NULL, // (In/Opt) source of external indexes (to be displayed on amp. trend's field)
                     bool* pbEnableExport = NULL, // (In/Opt) flag, if enable ST export
                     bool* pbLightMode = NULL, // (In/Opt) flag, if show ST in small window (for navigator bar)
                     bool* pbMGA = NULL     // (In/Opt) flag, if MGA ver
                     ); // return: true if OK, false for bad parameters or system error

  virtual bool Control( // modify trend
                     trMcSpcTrendPrmE *prP,         // (In) parameters for spectrum trend
                     trMcSpcTrendPrmI *prPI = NULL  // (In) color parameters
                      );

  virtual bool GetInfo( // get curr. information
                     trMcSpcTrendPrmE *prPE, // (Out) curr. parameters (ext.)
                     trMcSpcTrendPrmI *prPI = NULL, // (Out/opt) curr. parameters (loc.)
                     trMcSpcTrendDCfg *prSDC = NULL // (Out/Opt) configuration of processed data (number of channels, sample rate, ...)
                   );

  virtual bool GetProcessedData( // Get processed signal data
                     double fT,              // (In) time point for processed data (value <0 means that the rightmost time point is used)
                     int nCh,                // (In) number of channel for processed data
                     trMcSpcTrendDta *prSD   // (Out) calculated data in time point prPE->fTR (or earlier point, if there is no data)
                   ); // true if OK, false if bad parameters or other error; also if fT is >= 0 and out of data time range

  virtual void SetAcqMode(bool bAcqMode); // set acqusition mode

  double GetERTrendMax();

  virtual short GetErrorCode( void ) { return nErrorCode; }  // error code for the last performed call

  void __fastcall PanelTrendsResize(TObject *Sender);

  void __fastcall PaintBoxTrendsPaint(TObject *Sender)
  { if( bInitialized )  Display(); } // ***

  void __fastcall PaintBoxHorzRulerPaint(TObject *Sender)
  { if( bInitialized ) pHorzRuler->Display(lBR - (nBW - 1) - LO(), 0); } // ***

  void __fastcall PaintBoxFreqIndPaint(TObject *Sender)
  {
    if( !bInitialized )
      return;

    rScale.rP.nBackC = PaintBoxHorRuler->Color;
    rRAScale.rP.nBackC = PaintBoxHorRuler->Color;
    rRAScale.rP.nForeC = rPE.nCSForeC;
    rScale.rP.nForeC = rPE.nCSForeC;

    rRAScale.rP.nNActC = rPE.nCSNActC;
    rScale.rP.nNActC = rPE.nCSNActC;
    rRAScale.rP.nActC = rPE.nCSActC;
    rScale.rP.nActC = rPE.nCSActC;

    rScale.SetMinMax( 0., (double) rScale.rP.nScaleMax, 0, prBBST->GetCurrMax() );
    rScale.Paint( PaintBoxFreqInd->Canvas, 0, PaintBoxFreqInd->Height * (1. - (double) rSP.rPI.nCSAHeightPerCent / 100));

    rRAScale.SetMinMax( 0., (double) rRAScale.rP.nScaleMax, 0, 2 * rSP.rPI.fScaleSensMaxR );
    rRAScale.Paint( PaintBoxFreqInd->Canvas, 0, 0 );
  } // ***

  void __fastcall OnMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);

  void __fastcall OnMouseDown( TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);

  void __fastcall OnMouseUp( TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);

  void __fastcall LblWndProc(TMessage &Message);

  void __fastcall OnTrendMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);

  void __fastcall TrendMouseDown(TObject *Sender, TMouseButton Button,
                        TShiftState Shift, int X, int Y);

  void __fastcall TrendMouseUp(TObject *Sender, TMouseButton Button,
                        TShiftState Shift, int X, int Y);

  void __fastcall TrendDoubleClick(TObject *Sender);

  void __fastcall PanelViewDigitsOnCanResize( TObject* Sender,
                                   int &NewWidth, int &NewHeight, bool &Resize );

  void __fastcall PanelViewDigitsOnResize(TObject* Sender);
  void __fastcall PanelViewIndicatorsOnResize(TObject* Sender);
  void __fastcall PanelBarsOnResize(TObject* Sender);

  void __fastcall SettingsClick(TObject *Sender);

  void __fastcall MarkerMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);

  void __fastcall MarkerMouseDown(TObject *Sender, TMouseButton Button,
                        TShiftState Shift, int X, int Y);

  void __fastcall TimerCursorTimer(TObject *Sender);

  void __fastcall OnSTSave(TObject *Sender);

  void __fastcall OnSTExport(TObject *Sender);

private: // ---------------------------------------------------------------

  void Done( void ) {  bInitialized = false;
                      //if( bInitialized )
                      //  PanelViewDigits->Visible = false;
                      CDELETE( prBBST );      CDELETE( prSTP );
                      CDELETE( pHorzRuler );
                      CDELETE( prBMRulerR );  CDELETE( prBMRulerL );
                      CDELETE( prBMAmpRulerR );  CDELETE( prBMAmpRulerL );
                      CDELETE( prBMColumn );  CDELETE( prBMChannel );
                      memset( aasChNames, 0, sizeof(aasChNames) );
                      nMStatus = None;   }

  int RO( void ) // right horiz. offset for the part of PaintBoxTrends occupied by trends
  { // vert. line of vert. ruler (opt), vert. band + stripe of 2 ruler's line widht (opt), stripe of LR_PIX_DIST width
    return LR_PIX_DIST + (rSP.rPI.bBandRight ? prBMColumn->Width + 2*nVRLW : 0) +
                         (rSP.rPI.bRulerRight || rSP.rPI.bRARulerRight ? 2*nVRLW : 0);
  } // ***

  int LO( void ) // left horiz. offset for the part of PaintBoxTrends occupied by trends
  { // stripe of LR_PIX_DIST width, vert. band + stripe of 2 ruler's line widht (opt), vert. line of vert. ruler (opt)
    return LR_PIX_DIST + (rSP.rPI.bBandLeft ? prBMColumn->Width + 2*nVRLW : 0) +
                         (rSP.rPI.bRulerLeft || rSP.rPI.bRARulerLeft ? 2*nVRLW : 0);
  } // ***

  void SetBoards( bool bReinit = false );

  void SetBitmapScaleColors( void ); // set colors' set for bitmap & scale;

  void UpdateVertRulersAndBands( void );

  void SetScale( trMcSpcTrendPrmI *prAPI = NULL );

  // Set scale parameters corr. to the new value of a scale cursor for CSA
  void SetScaleCursorCSA( short nY );

  // Set scale parameters corr. to the new value of a scale cursor for RA
  void SetScaleCursorRA( short nY );

  void GetTrendsStyles( short *pnTS, trMcSpcTrendPrmI * prTP = NULL );

  void GetTrendsColors( TColor *pnC );

  bool SetBuffers( void ); // should be called on init or if modified: nBH, rSPC.lT

  void FillBufferStructs( trMcSTBPrmGen * prPG, trMcSTBPrmCSA * prPC,
         trMcSTBScale *prScC, trMcSTBPrmRA *prPR, trMcSTBScale *prScR, trMcSTBPrmAR *prPAR );

  trMcDigitalPanelCtl GetDPanelCtl( trMcSTBTrends nTT = CSA ); // fill struct for indicators' panel parameters with current values

  int GetDPanelWidth( void );

  void SetParametersForDPanel( bool bParameters = true, bool bCaptions = false );

  void SetValuesForDPanel( void ); // set values for panel with indicators (lat computed spectrum used)

  void SetPositionsForDPanel( void );

  void Set( trMcSpectrTrendSettings * prS ); // Set all parameters

  void Display( void );

  void DisplayOneChannel( TRect rRCh, TRect rRT, int nRSh, int nLSh, int nRBTop, short nCh );

  void DisplayTrendForChannel( TCanvas *prC, TRect rR, short nCh );

  void MoveMarker();

  void __fastcall GetDataInPoint(int X, int Y, bool bShowPanel);

  bool SetErrorCode( short nErr ) { return (nErrorCode = nErr) == MC_STD_NO_ERROR; }

  trMcSpcTrendData rD;         // data source
  trMcSpcTrendPrmE rPE;        // trend parameters (ext. set)
  trMcSpectrTrendSettings rSP; // parameters, modified in Settings()

  trMcSTBPrmExtInd *prPEI;     // source of external trend with an index
  trMcSpcTrendProc * prSTP;    // trend spectrums' processor
  trMcSpcTrendCfg rSPC;        // config. parameters got from spectr. processor

  trMcBtmBufSpcTrend *prBBST;// cashed buffer for all trends (CSA, RA, ...)

  trMcFIDT    rLinDT;        // transformation of spectrum to pixels for CSA (linear)
  trMcSqrFIDT rSqrDT;        // transformation of spectrum to pixels for CSA  (square root)
  trMcLogFIDT rLogDT;        // transformation of spectrum to pixels for CSA  (logarythm)
  trMcLinearFIDT rLinDTR;    // transformation of amplitude in band to pixels for rel. amplitudes

  int nBH;                   // height of band on bitmap for one channel, computed for given number of channels and current PaintBoxTrends->Height
                             // (top of band for a channel is nX - nH/2, where nX is the axis coord. HorAxes()
  int nBW;                   // same for width (normally is PaintBoxTrends->Width; is kept to control changings of width)
  long lBR;                  // right board for bitmap in time scale based on "pixels" spectrums (calculated boards are [rPB.lF, rPB.lT];
                             // for not computed spectrums displayed zone is filled with background color)
  long lScrPix;              // X-coord. of the screen marker (in time scale based on "pixels" spectrums)

  char aasChNames[MC_STD_MAX_CHANNELS][MC_STD_MAX_CHN_LEN+1]; // channels' names

  TColor anC[MC_STD_MAX_NMB_COLORS+3];    // array with colors for color scaling (CSA)
  float afB[MC_STD_MAX_NMB_COLORS+1];     // array with boards for segments in [0..1] determining transformation of color scale (CSA)
  TColor anCR[MC_STD_MAX_NMB_COLORS + 4]; // array with colors for color scaling (rel. amplitudes)
  float afBRA[MC_STD_MAX_NMB_COLORS+1];   // same as afB, but for RA trend

  Graphics::TBitmap *prBMRulerR;    // bitmap for right vertical ruler for spectral trends
  Graphics::TBitmap *prBMRulerL;    // bitmap for left vertical ruler for spectral trends
  Graphics::TBitmap *prBMAmpRulerR; // bitmap for right vertical ruler for spectral trends
  Graphics::TBitmap *prBMAmpRulerL; // bitmap for left vertical ruler for spectral trends
  Graphics::TBitmap *prBMColumn;    // bitmap for the vertical column for bands
  int nVRLW;                        // vertical ruler's line width
  Graphics::TBitmap *prBMChannel;   // bitmap for the stripe with one channel (including left/right boards)

  TrMcSpTrColorScale rScale;          // colored scale
  TrMcSpTrColorScale rRAScale;        // colored scale for RA trend
  TrMcHorzSignalRulerTrend *pHorzRuler;  // horizontal ruler
  trMcIndicatorsPanel * pprDP[MCSTB_MAX_TRENDS][MC_STD_MAX_CHANNELS];  // frames with indicators & digital values of SEF90, SEF50, Max, 2-nd max.

  TWinControl *PanelIndicators;
  TWinControl *pPanelIndicators;
#ifdef NEW_INDICATORS
  TrIndicatorHolder arIndicatorHolder[MC_STD_MAX_CHANNELS];
  void UpdateIndicators();
#endif
  TCbHintWindow *pCurrValueHintW;
  long nPX, nPY;                    // previous mouse position
  enum MouseStatus { Scale, None } nMStatus;
  short nMouseX, nMouseY;           // coordinates used to track the place where the mouse was clicked
  bool bSetupMouseLeaveTrack;
  TWndMethod pfnOldStaticText1Proc;

  long lMarkerPos;                  // position of screen marker (pixels)
  long lMarkerOldPos;               // old position of screen marker
  bool bCaptured;                   // flag, if dragging screen marker
  bool bHandCursor;                 // flag, if cursor is hand (near screen marker)

  bool bLightMode;                  // flag if light mode

  bool bMGA;                        // flag if MGA mode

  bool bAcq;                        // flag, if acquisition mode

  // buffer for storaging whole calculated ST
  trMcSTBuffer* prSTBuffer;

  // Real object for applying settings ----------------------------------------
  struct trMcSpcTrendApplyObj : trMcApplyObj
  {
    virtual void Apply( void * pP )
    { prST->Set( (trMcSpectrTrendSettings *) pP ); }

    virtual double GetERTrendMax()
    { return prST->GetERTrendMax(); }

    trMcSpectrTrendR * prST;
  } rAppSet;
  friend trMcSpcTrendApplyObj;  // for the possibility to call Set()

  // Struct determining possible boards for trend
  struct trTrendBoards : trMcSpectrTrendBoards
  {
    virtual int CurrWindowWidth( void ) { return prST->PaintBoxTrends->Width; }
    trMcSpectrTrendR * prST;
  } rTB;

  short nErrorCode;
  bool bInitialized;

  // callback for progress bar ---------------------------------------------------
  struct trMcSTProgressCallbackR: trMcSTProgressCallback
  {
    virtual void ShowProgress(int nProgress)
    {
      if (prFrame)
        prFrame->JvProgressBar1->Position = nProgress;
      Application->ProcessMessages();
    }

    TFrameSpectrTrend* prFrame;
  } rCallback;
};

//------------------------------------------------------------------------------
// Source of trMcSpectrTrendR --------------------------------------------------
//------------------------------------------------------------------------------

// Constructor of trMcSpectrTrend ----------------------------------------------
__fastcall trMcSpectrTrendR::trMcSpectrTrendR(TComponent* Owner,
  TWinControl *pPanelIndicators) : trMcSpectrTrend(Owner)
{
  Visible = false;        bInitialized = false;
  prSTP = NULL;           pHorzRuler = NULL;
  prBMRulerR = NULL;      prBMRulerL = NULL;
  prBMAmpRulerR = NULL;   prBMAmpRulerL = NULL;
  prBMColumn = NULL;      prBMChannel = NULL;
  prBBST = NULL;          prPEI = NULL;
  lMarkerPos = 0;         bCaptured = false;     bHandCursor = false;
  bAcq = false;

  PanelTrends->OnResize = PanelTrendsResize;
  rAppSet.prST = this,  rTB.prST = this;
  MenuItemSettings->OnClick   = SettingsClick;
  PaintBoxTrends->OnPaint     = PaintBoxTrendsPaint;
  PaintBoxTrends->OnMouseMove = OnTrendMouseMove;
  PaintBoxTrends->OnMouseDown = TrendMouseDown;
  PaintBoxTrends->OnMouseUp   = TrendMouseUp;
  PaintBoxTrends->OnDblClick  = TrendDoubleClick;
  PanelViewDigits->OnCanResize = PanelViewDigitsOnCanResize;
  PanelViewDigits->OnResize    = PanelViewDigitsOnResize;
  PanelScreenBorder->OnMouseMove = MarkerMouseMove;
  PanelScreenBorder->OnMouseDown = MarkerMouseDown;
  PanelScreenBorder->OnMouseUp = TrendMouseUp;
  ButtonSTSave->OnClick = OnSTSave;
  ButtonSTExport->OnClick = OnSTExport;

  // load cursors
  HCURSOR h = LoadCursor(HInstance, "TrendCursor");
  Screen->Cursors[ST_TREND_CURSOR] = h;
  PaintBoxTrends->Cursor = (TCursor) ST_TREND_CURSOR;
  h = LoadCursor(HInstance, "HandCursor");
  Screen->Cursors[ST_HAND_CURSOR] = h;
  PanelScreenBorder->Cursor = (TCursor) ST_HAND_CURSOR;
  h = LoadCursor(HInstance, "HandCaptCursor");
  Screen->Cursors[ST_CAPTURED_CURSOR] = h;
  TimerCursor->OnTimer = TimerCursorTimer;

  PaintBoxFreqInd->OnPaint = PaintBoxFreqIndPaint;
  PaintBoxFreqInd->OnMouseMove = OnMouseMove;
  PaintBoxFreqInd->OnMouseDown = OnMouseDown;
  PaintBoxFreqInd->OnMouseUp = OnMouseUp;

  PaintBoxHorRuler->Font->Name  = "Small Fonts";
  PaintBoxHorRuler->Font->Size  = 7;
  PaintBoxHorRuler->Color       = clInfoBk;
  PaintBoxHorRuler->OnPaint     = PaintBoxHorzRulerPaint;

  PanelInPoint->Visible = false;
  LabelChName->Caption = "";
  LabelChName->Visible = true;
  nMStatus = None;

  PanelViewDigitsLowBorder->Color = PaintBoxHorRuler->Color;
  rScale.rP.nBackC = PaintBoxHorRuler->Color;
  rRAScale.rP.nBackC = PaintBoxHorRuler->Color;

  pfnOldStaticText1Proc = PanelTrends->WindowProc;
  PanelTrends->WindowProc = LblWndProc;

  pCurrValueHintW = new TCbHintWindow(this);
  pCurrValueHintW->SetHintHidePause(HINT_HIDE_PAUSE);
  pCurrValueHintW->SetHintPause(HINT_PAUSE);

  PanelScreenBorder->Visible = false;

  PanelBars->Visible = false;
  PanelViewDigits->Visible = false;
  for( short nP = 0; nP < MC_STD_MAX_CHANNELS; nP++ )
    for( short nT = CSA; nT <= RelAmp; nT++ )
    {
      pprDP[nT][nP] = McCreateIndicatorsPanel( PanelViewDigits, this, nT + (nP*2) );
      pprDP[nT][nP]->Visible = false;
    }


  //PanelIndicators = pPanelIndicators ? pPanelIndicators : PanelIndicatorsDef;
  PanelIndicators = PanelIndicatorsDef;
  this->pPanelIndicators = pPanelIndicators;
  pPanelIndicators = pPanelIndicators ? pPanelIndicators : PanelR;
  if (pPanelIndicators)
  {
    PanelIndicators->Parent = pPanelIndicators;
    PanelBars->Parent = pPanelIndicators;
    PanelIndicators->Width = pPanelIndicators->Width / 2;
    PanelBars->Width = pPanelIndicators->Width / 2;
    ((TPanel*)pPanelIndicators/*PanelBars*/)->OnResize = PanelBarsOnResize;
  }

#ifndef NEW_INDICATORS
  PanelIndicators->Visible = false;
#endif

#ifdef NEW_INDICATORS
  trMcDigitalPanelPrm rDPP;
  int nBarWidth = PanelBars->Width / 4;
  PanelBars->Color = rSP.rPI.nDigitalIndicatorBackColor;
  PanelBars->Visible = false;
  for (int nCh = 0; nCh < MC_STD_MAX_CHANNELS; ++nCh)
  {
    TrIndicatorHolder *prIndicatorHolder = &arIndicatorHolder[nCh];

    int nI = 0;
    prIndicatorHolder->vBarPanels[nI] = new TPanel(PanelBars);
    prIndicatorHolder->vBarPanels[nI]->BevelInner = bvNone;
    prIndicatorHolder->vBarPanels[nI]->BevelOuter = bvNone;
    prIndicatorHolder->vBarPanels[nI]->Parent = PanelBars;
    prIndicatorHolder->vBarPanels[nI]->Width = 4*nBarWidth;

    ++nI;
    prIndicatorHolder->vBarPanels[nI] = new TPanel(PanelBars);
    prIndicatorHolder->vBarPanels[nI]->BevelInner = bvNone;
    prIndicatorHolder->vBarPanels[nI]->BevelOuter = bvNone;
    prIndicatorHolder->vBarPanels[nI]->Parent = PanelBars;
    prIndicatorHolder->vBarPanels[nI]->Width = 4*nBarWidth;

//    prIndicatorHolder->vBarPanels[nI]->Visible = false;
    for( short i = 0; i < prIndicatorHolder->vAsIndicator.size(); i++ )
    {
      prIndicatorHolder->vIndPanels[i] = new TPanel(PanelIndicators);
      prIndicatorHolder->vIndPanels[i]->BevelInner = bvNone;
      prIndicatorHolder->vIndPanels[i]->BevelOuter = bvNone;
      prIndicatorHolder->vIndPanels[i]->Parent = PanelIndicators;
      prIndicatorHolder->vIndPanels[i]->Padding->Left = 2;

      nI = i < 2 ? 1 /*CSA*/ : 0/*ampl*/;
      // progress bar
      TJvgProgress *pr = new TJvgProgress(prIndicatorHolder->vIndPanels[i]);
      pr->Parent = prIndicatorHolder->vBarPanels[nI];
      pr->Align = alNone;//Left;
      TAnchors anc;
      anc<<akTop;
      anc<<akBottom;
      pr->Anchors = anc;
      pr->Width = nBarWidth;
      pr->Percent = 100;
      pr->Caption = "%d%%";
      pr->CaptionStyle = fstPushed;
      pr->Colors->Background = rDPP.anC[i % 4];
      pr->Colors->Delineate = clBlue;
      pr->Colors->Shadow = clBlack;

      pr->Gradient->Active = true;
      pr->BevelInner = bvNone;
      pr->BevelOuter = bvSpace;//

      pr->Gradient->FromColor = PanelBars->Color;
      pr->Gradient->ToColor = PanelBars->Color;
      pr->Gradient->Orientation = fgdHorizontal;

      pr->GradientBack->Active = true;
      int r = RED(rDPP.anC[i % 4]);
      int g = GREEN(rDPP.anC[i % 4]);
      int b = BLUE(rDPP.anC[i % 4]);
      int k1 = -150, k = 100;
      pr->GradientBack->FromColor = RGB(MAX(0, k1 + r), MAX(0, k1 + g), MAX(0, k1 + b));
      pr->GradientBack->ToColor = RGB(MIN(255, k + r), MIN(255, k + g), MIN(255, k + b));
      pr->GradientBack->Orientation = fgdHorizontal;

//      pr->Interspace = 0;
      pr->Options = pr->Options<<fpoTransparent;
      pr->Step = nBarWidth / 2 - 2;
      pr->GradientBack->BrushStyle = bsHorizontal;
//      pr->Gradient->BrushStyle = bsHorizontal;

      prIndicatorHolder->vProgressBars[i] = pr;
    }
  }

  AnsiString asPNames[] =
  {
    LabelTotalAmpP->Caption,
    Label15->Caption,
    (LabelSEFHi->Caption + (AnsiString)rSP.rPI.anSEFPercent[0]),
    (LabelSEFLo->Caption + (AnsiString)rSP.rPI.anSEFPercent[1]),
    LabelMax->Caption,
    Label2->Caption
  };

  for (int nCh = 0; nCh < MC_STD_MAX_CHANNELS; ++nCh)
  {
    TrIndicatorHolder *prIndicatorHolder = &arIndicatorHolder[nCh];
    for( short i = 0; i < prIndicatorHolder->vAsIndicator.size(); i++ )
    {
      if (!prIndicatorHolder->vAsIndicator[i])
      {
        if (!prIndicatorHolder->vIndPanels[i])
          continue;
        prIndicatorHolder->vAsIndicator[i] = new TAsIndicator(prIndicatorHolder->vIndPanels[i]);
        TAsIndicator *prAsIndicator = prIndicatorHolder->vAsIndicator[i];
        prAsIndicator->Parent = prIndicatorHolder->vIndPanels[i];
        prAsIndicator->Align = alClient;

        prAsIndicator->Color = rSP.rPI.nDigitalIndicatorBackColor;
        prAsIndicator->CaptionAlignment = taCenter;
        prAsIndicator->TimeValue = asPNames[i];
        prAsIndicator->CaptionHeightPercent = 0;
        prAsIndicator->TimeHeightPercent = 40;
        prAsIndicator->ValueBackColor = rSP.rPI.nDigitalIndicatorBackColor;
        prAsIndicator->ValueTextColor = rDPP.anC[i % 4];
        prAsIndicator->TimeTextColor = rDPP.anC[i % 4];

        int r = RED(prAsIndicator->ValueBackColor);
        int g = GREEN(prAsIndicator->ValueBackColor);
        int b = BLUE(prAsIndicator->ValueBackColor);
        int k = 100;
        prAsIndicator->CaptionBackColor = RGB(MAX(0, k + r), MAX(0, k + g), MAX(0, k + b));

        prAsIndicator->Curvature = 20;
        prAsIndicator->Value = "--";
        prAsIndicator->BoundsRect = prIndicatorHolder->vIndPanels[i]->ClientRect;
      }
    }
  }
#endif
  MultiLang1->CurrentLang = CwApplGetLanguage(CwApplGetProfile(), "");

  strcpy( rScale.rP.asScaleLabel, C_TO_ANSI_CSTR(LabelMkvHz->Caption) );
  strcpy( rRAScale.rP.asScaleLabel, C_TO_ANSI_CSTR(LabelMkv->Caption) );
  LabelHz1->Caption   = LabelHz->Caption;  LabelHz2->Caption    = LabelHz->Caption;
  LabelHz3->Caption   = LabelHz->Caption;  LabelMkvHz1->Caption = LabelMkvHz->Caption;
  LabelSEFLo->Caption = LabelSEFHi->Caption;
  prBBST = McCreateSpectrTrendBuffer();
  rCallback.prFrame = this;
  prSTBuffer = McCreateSTBuffer();
  nErrorCode = MC_STD_NO_ERROR;
} // ***

// -----------------------------------------------------------------------------
void __fastcall trMcSpectrTrendR::PanelBarsOnResize(TObject* Sender)
{
  if (!PanelBars || PanelBars->Tag)
    return;

  TWinControl *pParent = PanelIndicators->Parent;
  if (!pParent)
    return;

  PanelBars->Tag = 1;

  PanelIndicators->Width = pParent->Width / 2;
  PanelBars->Width = pParent->Width / 2;

  int nGap = PanelBars->Width / 4 * BARS_GAP_FRACTION;
  int nBarWidth = PanelBars->Width / 4 - nGap;
  PanelBars->Color = rSP.rPI.nDigitalIndicatorBackColor;
  PanelBars->Visible = false;
  for (int nCh = 0; nCh < MC_STD_MAX_CHANNELS; ++nCh)
  {
    TrIndicatorHolder *prIndicatorHolder = &arIndicatorHolder[nCh];

    int nI = 0;
    prIndicatorHolder->vBarPanels[nI]->Width = 4*(nBarWidth + nGap);

    ++nI;
    prIndicatorHolder->vBarPanels[nI]->Width = 4*(nBarWidth + nGap);

    for( short i = 0; i < prIndicatorHolder->vAsIndicator.size(); i++ )
    {
      nI = i < 2 ? 1 /*CSA*/ : 0/*ampl*/;
      // progress bar
      TJvgProgress *pr = prIndicatorHolder->vProgressBars[i];
      TRect rB((nBarWidth + nGap) * (i - (nI == 0 ? 2 : 0)) + (!pPanelIndicators ? 3 : 0),
        0, nBarWidth, prIndicatorHolder->vBarPanels[nI]->Height);
      rB.Right = rB.Left + rB.Right;
      rB.Bottom = rB.Top + rB.Bottom;

      pr->BoundsRect = rB;
    }
  }
  if (Sender)
    PanelViewIndicatorsOnResize(NULL);
  PanelBars->Tag = 0;
}

// Initialization --------------------------------------------------------------
bool trMcSpectrTrendR::Init( trMcSpcTrendData *prD, trMcSpcTrendPrmE *prP,
             char **ppsChNames, long lTMax,  trMcSTBPrmExtInd *prAPEI,
             bool* pbEnableExport, bool* pbLightMode, bool* pbMGA)
{
  Done();

  if (0)  //pbEnableExport && *pbEnableExport)
    ButtonSTExport->Visible = true;
  else
    ButtonSTSave->Top = (PanelButtons->Height - ButtonSTSave->Height) / 2;

  prBMRulerR = new Graphics::TBitmap;    // bitmap for right CSA vertical ruler
  prBMRulerL = new Graphics::TBitmap;    // bitmap for left CSA vertical ruler
  prBMAmpRulerR = new Graphics::TBitmap; // bitmap for right RA vertical ruler
  prBMAmpRulerL = new Graphics::TBitmap; // bitmap for left RA vertical ruler
  prBMColumn = new Graphics::TBitmap;    // bitmap for vertical bands' indicator
  prBMChannel = new Graphics::TBitmap;   // bitmap stripe with single channel

  prBMRulerR->Width     = MM_TO_PIX(MP_VERT_RULER_WDT, fPixMM);
  prBMRulerL->Width     = prBMRulerR->Width;
  prBMAmpRulerR->Width  = prBMRulerR->Width;
  prBMAmpRulerL->Width  = prBMRulerR->Width;
  prBMColumn->Width  = MM_TO_PIX(MP_VERT_BAND_WDT, fPixMM);
  nVRLW = MM_TO_PIX(MP_VERT_RULER_LW, fPixMM);  // Vertical Ruler Line Width

  bool bOK = (prD && prP);

  bOK = bOK ? prD->prDS && (prD->nNmbChOut > 0) && (prD->nNmbChOut <= MC_STD_MAX_CHANNELS) &&
        (prD->nSampRate > 2) && (prD->fUPT > MALO) &&  // others in prTD are checked in prSTP->Init()
        (prP->fTR > MALO) && (prP->fTScr > MALO) &&
        (lTMax >= MC_STD_MIN_MAX_LENGTH) && (lTMax <= MC_STD_MAX_MAX_LENGTH) : false;

  if( !bOK )
    return SetErrorCode( MC_STD_BAD_PRM );

  lMarkerPos = 0;
  bCaptured = false;
  TimerCursor->Enabled = false;
  bAcq = false;

  rD = *prD;
  rPE = *prP;
  prPEI = prAPEI;
  rTB.lTMax = lTMax, rTB.lTMin = MC_STD_MIN_LENGTH;
  rTB.nPixLen = Screen->Width;

  BrGetSpcTrendSettings( &rSP );
  double fDT = 1.00001 * (rTB.lTMax / (double)rTB.nPixLen); // min. time segment for intersection (step in time) of spectrums
  if( rSP.rPP.fDT*(1 - rSP.rPP.fAl) < fDT )
  {
    double fDT1 = ((int)(fDT*10 + 1)) / 10.;  // nearest value not less than fDT that is rounded to 1/10 of second
    fDT1 = MAX( MC_STP_SPC_SEGM_MIN, fDT1 );
    rSP.rPP.fDT = MAX( fDT1, rSP.rPP.fDT );
    rSP.rPP.fAl = MIN( rSP.rPP.fAl, 1. - fDT / rSP.rPP.fDT ); // correct values for this max. length of trend
    BrSetSpcTrendSettings( &rSP ); // save corrected values
  }

  bLightMode = false;
  if (pbLightMode && *pbLightMode)
  {
    rSP.rPI.nCSAHeightPerCent    = 100;
    rSP.rPI.bShowScalePanel      = false;
    rSP.rPI.bShowSpectrHigherSEF = true;
    rSP.rPI.abTrends[trMcSpcTrendPrmI::SEFHi]   = true;
    rSP.rPI.abTrends[trMcSpcTrendPrmI::SEFLo]   = false;
    rSP.rPI.abTrends[trMcSpcTrendPrmI::Max]     = true;
    rSP.rPI.abTrends[trMcSpcTrendPrmI::Peak2]   = false;
    rSP.rPI.abTrends[trMcSpcTrendPrmI::Entropy] = true;
    rSP.rPI.arTW[0] = 0;
    rSP.rPI.arTW[1] = 1;
    rSP.rPI.arTW[2] = 0;
    rSP.rPI.arTW[3] = 0;
    rSP.rPI.arTW[4] = 0;
    rSP.rPI.bShowIndicatorsPanel = false;
    rSP.rPI.bRulerLeft           = false;
    rSP.rPI.bRulerRight          = false;
    rSP.rPI.bBandLeft            = false;
    rSP.rPI.bBandRight           = false;
    rSP.rPI.bRARulerLeft         = false;
    rSP.rPI.bRARulerRight        = false;
    rSP.rPI.bShowScreenPanel     = true;

    PopupMenu = NULL;
    PanelScreenBorder->Cursor = crDefault;
    PaintBoxTrends->Cursor = crDefault;

    bLightMode = true;

    double fSec = rPE.prCallback->GetRightBorder();
    if (fSec > 1.)
      rSP.rPI.fPixPerSec = (double) PaintBoxTrends->Width / MIN(30 * 60., fSec);
  }

  bMGA = false;
  if (pbMGA && *pbMGA)
  {
    rSP.rPI.nCSAHeightPerCent    = 100;
    rSP.rPI.bShowScalePanel      = false;
    rSP.rPI.bShowSpectrHigherSEF = true;
    rSP.rPI.abTrends[trMcSpcTrendPrmI::SEFHi]   = true;
    rSP.rPI.abTrends[trMcSpcTrendPrmI::SEFLo]   = false;
    rSP.rPI.abTrends[trMcSpcTrendPrmI::Max]     = true;
    rSP.rPI.abTrends[trMcSpcTrendPrmI::Peak2]   = false;
    rSP.rPI.abTrends[trMcSpcTrendPrmI::Entropy] = true;
    rSP.rPI.arTW[0] = 0;
    rSP.rPI.arTW[1] = 1;
    rSP.rPI.arTW[2] = 0;
    rSP.rPI.arTW[3] = 0;
    rSP.rPI.arTW[4] = 0;
    rSP.rPI.bRulerLeft           = true;
    rSP.rPI.bRulerRight          = false;
    rSP.rPI.bBandLeft            = false;
    rSP.rPI.bBandRight           = false;
    rSP.rPI.bRARulerLeft         = false;
    rSP.rPI.bRARulerRight        = false;
    rSP.rPI.bShowScreenPanel     = true;

    //PanelHorSpTrendRuler->Visible = false;  // ???

    PanelScreenBorder->Cursor = crDefault;
    PaintBoxTrends->Cursor = crDefault;

    rSP.rPI.fPixPerSec = (double) PaintBoxTrends->Width / (30 * 60);

    bMGA = true;
  }

  if (bAcq)
    rSP.rPP.nLag = 2 * rD.nSampRate;
  else
    rSP.rPP.nLag = 0;

  bOK = bOK ? (bool) (prSTP = McCreateSpcTrendProc()) : false;
  bOK = bOK ? prSTP->Init( &rD, &rSP.rPP, &rSP.rPA, rTB.nPixLen, &rSPC ) : false;
  bOK = bOK ? prSTBuffer->Init( rPE.prCallback->GetExamine(), prSTP, ppsChNames, rTB.nPixLen) : false;
  bOK = bOK ? (bool) (prBBST = McCreateSpectrTrendBuffer()) : false;
  bOK = bOK ? SetBuffers() : false; // SetBoards() called (nBH, nBW, nFFrq, nTFrq)
  bOK = bOK ? (bool) ( pHorzRuler = new TrMcHorzSignalRulerTrend(
                   PaintBoxHorRuler, rSP.rPI.fPixPerSec ) ) : false;

  if( !bOK )
  {
    Done();
    return SetErrorCode( MC_STD_GENERIC_ERR );
  }

  PanelFreqInd->Visible = rSP.rPI.bShowScalePanel;
  PanelViewDigits->Visible = false;
  PanelBars->Visible = false;

  trMcDigitalPanelCfg rDPCfgC;    rDPCfgC.nNmbPar = 4;  // configuration of digital indicators' panel for CSA
  strcpy( rDPCfgC.asPNames[0], C_TO_ANSI_CSTR((LabelSEFHi->Caption + (AnsiString)rSP.rPI.anSEFPercent[0])) );
  strcpy( rDPCfgC.asPNames[1], C_TO_ANSI_CSTR((LabelSEFLo->Caption + (AnsiString)rSP.rPI.anSEFPercent[1])) );
  strcpy( rDPCfgC.asPNames[2], C_TO_ANSI_CSTR(LabelMax->Caption) );
  strcpy( rDPCfgC.asPNames[3], C_TO_ANSI_CSTR((Label2->Caption)) );

  trMcDigitalPanelCfg rDPCfgA;    rDPCfgA.nNmbPar = 2;  // configuration of digital indicators' panel for rel. amplitudes
  strcpy( rDPCfgA.asPNames[0], C_TO_ANSI_CSTR(LabelTotalAmpP->Caption) );
  strcpy( rDPCfgA.asPNames[1], C_TO_ANSI_CSTR(Label15->Caption) );

  trMcDigitalPanelCtl rCtlC = GetDPanelCtl( CSA ),
                      rCtlA = GetDPanelCtl( RelAmp );

  rDPCfgC.nIndicatorWidth = 18, rDPCfgA.nIndicatorWidth = 18;

  for( short nP = 0; nP < rD.nNmbChOut; nP++ )
  {
    bOK = bOK ? pprDP[CSA][nP]->Init( &rDPCfgC, &rCtlC ) : false;   // values are set to 0 after Init()
    bOK = bOK ? pprDP[RelAmp][nP]->Init( &rDPCfgA, &rCtlA ) : false;
  }

  int nMIHP = MM_TO_PIX(MP_MIN_IND_HEIGHT_MM, fPixMM); // Min Indicator Height in Pixels
  bool bRelAmp = bOK ? (prBBST->GetVertCrd( RelAmp ) > nMIHP): false,
       bCSA    = bOK ? (prBBST->GetVertCrd( CSA ) > nMIHP) : false;

  for( short nP = 0; nP < MC_STD_MAX_CHANNELS; nP++ )
  {
    pprDP[CSA][nP]->Visible = bOK && (nP < rD.nNmbChOut) && bCSA;
    pprDP[RelAmp][nP]->Visible = bOK && (nP < rD.nNmbChOut) && bRelAmp;
#ifdef NEW_INDICATORS
    TrIndicatorHolder *prIndicatorHolder = &arIndicatorHolder[nP];
    prIndicatorHolder->vBarPanels[0]->Visible = bOK && (nP < rD.nNmbChOut) && bCSA;
    prIndicatorHolder->vBarPanels[1]->Visible = bOK && (nP < rD.nNmbChOut) && bRelAmp;
    for( short i = 2; i < prIndicatorHolder->vAsIndicator.size(); i++ )
      prIndicatorHolder->vIndPanels[i]->Visible = bOK && (nP < rD.nNmbChOut) && bCSA;

    for( short i = 0; i < 2; i++ )
      prIndicatorHolder->vIndPanels[i]->Visible = bOK && (nP < rD.nNmbChOut) && bRelAmp;
  }
  UpdateIndicators();
#endif

  PanelViewDigits->Width = GetDPanelWidth();
  SetPositionsForDPanel();

  // colors, scale & ruler
  SetBitmapScaleColors(); // set colors' set for bitmap & scale;
  SetScale();

  UpdateVertRulersAndBands();

  rPE.fTScr /= 2;  // forse Control() to calculate
  bInitialized = true;  // to pass Control()
  bInitialized = Control( prP );   // horizontal ruler is also updated

  // Set channels' names if any:
  if( bInitialized && ppsChNames )
    for( short nCh = 0; nCh < rD.nNmbChOut; nCh++ )
      if( ppsChNames[nCh] )
        if( strlen(ppsChNames[nCh]) )
          strncpy( aasChNames[nCh], ppsChNames[nCh], MC_STD_MAX_CHN_LEN );

//    long lR = lBR, lL = lBR - (nBW - 1);  // lBR & lBW is set in SetBoards()
//    rBB.Update( &lL, &lR );
//    rBBR.Update( &lL, &lR ); // !!!

//    SetValuesForDPanel();

  if( !bInitialized )
    Done();

  Visible = bInitialized;

  PanelBarsOnResize(NULL);

  return SetErrorCode( bInitialized ? MC_STD_NO_ERROR : MC_STD_GENERIC_ERR );
} // ***

//---------------------------------------------------------------------------
bool trMcSpectrTrendR::Control( trMcSpcTrendPrmE *prP, trMcSpcTrendPrmI *prPI )
{
  if( !bInitialized )
    return SetErrorCode( MC_STD_NOT_INIT );
  if( !prP || (prP && ((prP->fTR < MALO) || (prP->fTScr < MALO))) )
    return SetErrorCode( MC_STD_BAD_PRM );

  // if bounds did not change AND no new information given about colors - then exit
  if( ((*prP == rPE) && prPI) || !nBH)
    return SetErrorCode( MC_STD_NO_ERROR ); // already set or no pixels- do nothing

  if( prPI )  // should never happen in practice
  {
    trMcSpectrTrendSettings rSTmp = rSP;  rSTmp.rPI = *prPI;
    Set(&rSTmp);
  }

  bool bBoards = !FLOAT_EQ(rPE.fTR, prP->fTR) || !FLOAT_EQ(rPE.fTScr, prP->fTScr),
       bVertRulers = !BOOL_EQ(rPE.nSpcNormColor, prP->nSpcNormColor) ||
                     memcmp(rPE.pBands, prP->pBands, 4*sizeof(trBand)),
       bScale = (prP->nSC1 != rPE.nSC1) || (prP->nSC2 != rPE.nSC2) || (prP->nSC3 != rPE.nSC3);

  rPE = *prP;

  if( bBoards )
    SetBoards();

  if( bVertRulers )
    UpdateVertRulersAndBands();

  PaintBoxHorRuler->Color = rPE.nRulerBack;
  PaintBoxHorRuler->Canvas->Pen->Color = rPE.nRulerFont;
  PaintBoxHorRuler->Font->Color = rPE.nRulerFont;

  if( bScale )
  {
    prBBST->Reset();
    SetBitmapScaleColors(); // set colors' set for bitmap & scale;
    SetScale();
  }

  PaintBoxTrends->Invalidate();
  if( bBoards )
    PaintBoxHorRuler->Invalidate();
  if( bBoards || bScale )
    PaintBoxFreqInd->Invalidate();
#ifdef NEW_INDICATORS
  UpdateIndicators();
#endif
  return SetErrorCode( MC_STD_NO_ERROR );
} // ***

//---------------------------------------------------------------------------
bool trMcSpectrTrendR::GetInfo( trMcSpcTrendPrmE *prPE, trMcSpcTrendPrmI *prPI,
                                                       trMcSpcTrendDCfg *prSDC )
{
  if( !bInitialized )
    return SetErrorCode( MC_STD_NOT_INIT );
  if( !prPE )
    return SetErrorCode( MC_STD_BAD_PRM );

  *prPE = rPE;
  if( prPI )
    *prPI = rSP.rPI;
  if( prSDC )
  {
    prSDC->prD = &rD;
    for( short nCh = 0; nCh < rD.nNmbChOut; nCh++ )
      prSDC->apsChNames[nCh] = aasChNames[nCh];
    prSDC->fTRecalc = (1-rSP.rPP.fAl)*rSP.rPP.fDT;
  }
  return SetErrorCode( MC_STD_NO_ERROR );
} // ***

// Get processed signal data ---------------------------------------------------
bool trMcSpectrTrendR::GetProcessedData( double fT, int nCh, trMcSpcTrendDta *prTD )
{
  if( !bInitialized )
    return SetErrorCode( MC_STD_NOT_INIT );
  if( !prTD || nCh < 0 || nCh > rD.nNmbChOut )
    return SetErrorCode( MC_STD_BAD_PRM );

  long lX = (fT < 0.) ? -1. : fT*rSP.rPI.fPixPerSec;

  trMcSTBCurrState rS;
  if( !prBBST->GetStateInPoint( lX, 0, nCh, &rS ) )
    return SetErrorCode( MC_STD_GENERIC_ERR );

  prTD->fSEFHi = rS.fSEFHi;
  prTD->nHiSEFPercent = rSP.rPI.anSEFPercent[0];

  prTD->fSEFLo = rS.fSEFLo;
  prTD->nLoSEFPercent = rSP.rPI.anSEFPercent[1];

  prTD->fAmp1 = rS.fMax,   prTD->fAmp2 = rS.fSecPeak;

  int nBHH = prBBST->GetVertCrd( CSA );

  prTD->fFrq1 = (rS.nMax/ (float) (nBHH-1) ) * (rSP.rPI.fFrqT - rSP.rPI.fFrqF)  + rSP.rPI.fFrqF;
  prTD->fFrq2 = (prTD->fAmp2 > 0.) ?
        (rS.nSecPeak/ (float) (nBHH-1) ) * (rSP.rPI.fFrqT - rSP.rPI.fFrqF)  + rSP.rPI.fFrqF : -1;
  return true;
} //***

//---------------------------------------------------------------------------
// set acqusition mode
void trMcSpectrTrendR::SetAcqMode(bool bAcqMode)
{
  bAcq = bAcqMode;
  PanelScreenBorder->Cursor = bAcq ? crDefault :(TCursor) ST_HAND_CURSOR;
  ButtonSTSave->Enabled = !bAcqMode;
} //***

//---------------------------------------------------------------------------

double trMcSpectrTrendR::GetERTrendMax()
{
  return prBBST ? prBBST->GetERTrendMax() : -1;
} //***

//---------------------------------------------------------------------------
void __fastcall trMcSpectrTrendR::PanelTrendsResize(TObject *Sender)
{
  if( !bInitialized )
    return;

  SetScale();

  int nNBH = ChHeight( PaintBoxTrends->Height, rD.nNmbChOut );

  if( nNBH != nBH )
  {
    prBBST->Resize( nBH = nNBH );
    UpdateVertRulersAndBands();
  }

  if (bLightMode)
  {
    trMcSpectrTrendSettings rSPNew = rSP;
    double fSec = rPE.prCallback->GetRightBorder();
    if (fSec > 1.)
      rSPNew.rPI.fPixPerSec = (double) PaintBoxTrends->Width / MIN(30 * 60., fSec);
    Set(&rSPNew);
  }

  if (bMGA)
  {
    trMcSpectrTrendSettings rSPNew = rSP;
    rSPNew.rPI.fPixPerSec = (double) PaintBoxTrends->Width / (30 * 60.);
    Set(&rSPNew);
  }

  SetBoards(true);
} // ***

//------------------------------------------------------------------------------
void __fastcall trMcSpectrTrendR::OnMouseMove(TObject *Sender, TShiftState Shift, int X, int Y)
{
  if( !bInitialized )
    return;

  if (bLightMode)
    return;

  TCursor nCrs = SCALE_MOVE_CURSOR;
  if( PaintBoxFreqInd->Cursor != nCrs )
    PaintBoxFreqInd->Cursor = nCrs;

  if (nMStatus == Scale)
  {
    if (Y < PaintBoxFreqInd->Height * (1. - (double) rSP.rPI.nCSAHeightPerCent / 100))
      SetScaleCursorRA( Y );
    else
      SetScaleCursorCSA( Y );

    PaintBoxFreqIndPaint( this );
  }
} // ***

//------------------------------------------------------------------------------
void __fastcall trMcSpectrTrendR::OnMouseDown( TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
  if( !bInitialized )
    return;

  if (bLightMode)
    return;

  nMStatus = None;
  OnMouseMove(Sender, Shift, X, Y);
  nMStatus = Scale;
  OnMouseMove(Sender, Shift, X, Y);
} // ***

//------------------------------------------------------------------------------
void __fastcall trMcSpectrTrendR::OnMouseUp( TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
  if( !bInitialized )
    return;

  if (bLightMode)
    return;

  nMStatus = None;
  TCursor oldC   = Screen->Cursor;
  Screen->Cursor = crHourGlass;

  trMcSpectrTrendSettings rSTmp = rSP;
  rSTmp.rPI.fScaleSens  = (double) rScale.rP.nScaleSens;
  rSTmp.rPI.fScaleSensR = (double) rRAScale.rP.nScaleSens / 2;
  Set(&rSTmp);
  Application->ProcessMessages();

  trMcSpectrTrendSettings* prSettings = BrGetSpcTrendSettings();
  prSettings->rPI.fScaleSens  = rSTmp.rPI.fScaleSens;
  prSettings->rPI.fScaleSensR = rSTmp.rPI.fScaleSensR;
  BrSetSpcTrendSettings(prSettings);

  Screen->Cursor = oldC;
} // ***

//------------------------------------------------------------------------------
void __fastcall trMcSpectrTrendR::OnTrendMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y)
{
  if (bLightMode)
    return;

  if (bInitialized)
  {
    if (!bCaptured && !bAcq)
    {
      if (Y > 0 && Y < PaintBoxTrends->Height &&
        X > PanelScreenBorder->Left - 5 &&
        X < PanelScreenBorder->Left + PanelScreenBorder->Width + 5)
      {
        if (!bHandCursor)
        {
          Screen->Cursor = (TCursor) ST_HAND_CURSOR;
          bHandCursor = true;
        }
      }
      else if (bHandCursor)
      {
        Screen->Cursor = crDefault;
        bHandCursor = false;
      }
    }

    if (bCaptured && !bAcq)
      MoveMarker();
    else
    if (!bLightMode)
      GetDataInPoint(X, Y, Shift.Contains(ssLeft));
  }
}

//------------------------------------------------------------------------------
void __fastcall trMcSpectrTrendR::LblWndProc(TMessage &Message)
{
   if(Message.Msg == WM_MOUSEMOVE)
   {
      if( !bSetupMouseLeaveTrack )
      {
         TRACKMOUSEEVENT tme;

         tme.cbSize      = sizeof(TRACKMOUSEEVENT);
         tme.dwFlags     = TME_LEAVE;
         tme.hwndTrack   = PanelTrends->Handle;

         TrackMouseEvent(&tme);

         bSetupMouseLeaveTrack = true;
      }
   }
   else
   if( Message.Msg == WM_MOUSELEAVE )
   {
      PanelInPoint->Visible = false;
      bSetupMouseLeaveTrack = false;
      pCurrValueHintW->Hide();
   }

   pfnOldStaticText1Proc(Message);
} // ***

//------------------------------------------------------------------------------
void __fastcall trMcSpectrTrendR::MarkerMouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y)
{
  if (bLightMode)
    return;

  if (!bAcq)
    MoveMarker();
} //***

//------------------------------------------------------------------------------
void __fastcall trMcSpectrTrendR::TrendMouseDown(TObject *Sender, TMouseButton Button,
                        TShiftState Shift, int X, int Y)
{
  if (bLightMode)
    return;

  if( !bInitialized )
    return;
  pCurrValueHintW->Hide();
  if (Button == mbLeft)
  {
    if (bHandCursor && !bAcq)
    {
      bCaptured = true;
      lMarkerOldPos = lMarkerPos;
      Screen->Cursor = (TCursor) ST_CAPTURED_CURSOR;
      TimerCursor->Enabled = true;
    }
    else
    if (!bLightMode)
    {
      nPX = X-1;
      GetDataInPoint(X, Y, true);
    }
  }
} // ***

//------------------------------------------------------------------------------
void __fastcall trMcSpectrTrendR::TrendMouseUp(TObject *Sender, TMouseButton Button,
                                              TShiftState Shift, int X, int Y)
{
  if (bLightMode)
    return;

  if (bAcq)
    return;
  TimerCursor->Enabled = false;
  TimerCursorTimer(NULL);
  bCaptured = false;
  Screen->Cursor = crDefault;
}

//------------------------------------------------------------------------------
void __fastcall trMcSpectrTrendR::TrendDoubleClick(TObject *Sender)
{
  if (bLightMode)
    return;

  if (bAcq)
    return;

  PanelInPoint->Visible = false;

  if (rSP.rPI.bShowScreenPanel && lScrPix > 0)
  {
    double fh = 1. / rSP.rPI.fPixPerSec;   // step in time for pixels (in sec.)

    if (rPE.prCallback)
    {
      long nSigR = rPE.prCallback->GetRightBorder() / fh;
      if (nBW >= nSigR)
        return;
    }

    int X, Y;
    GetMouseCoord(PaintBoxTrends, X, Y);

    if (X > LO() && Y > 0 && X < PaintBoxTrends->Width - RO() &&
                 Y < PaintBoxTrends->Height)
    {
      lBR = lBR + X - lMarkerPos;

      if (lBR < nBW)
      {
        lMarkerPos = lMarkerPos - nBW + lBR;
        lBR = nBW;
      }

      if (rPE.prCallback)
      {
        long nSigR = rPE.prCallback->GetRightBorder() / fh;
        if (lBR > nSigR)
        {
          lMarkerPos = lMarkerPos - nSigR + lBR;
          lBR = nSigR;
        }

        long lCurPos = lBR - (PaintBoxTrends->Width - lMarkerPos - RO());
        rPE.prCallback->SetPosition(lCurPos * fh);
      }
    }
  }
} // ***

//------------------------------------------------------------------------------
void __fastcall trMcSpectrTrendR::PanelViewDigitsOnCanResize( TObject* Sender,
                 int &NewWidth, int &NewHeight, bool &Resize )
{
  if( !bInitialized )
  {
    Resize = false;
    return;
  }
  NewWidth = GetDPanelWidth();
} // ***

//------------------------------------------------------------------------------
void __fastcall trMcSpectrTrendR::PanelViewIndicatorsOnResize(TObject* Sender)
{
#ifdef NEW_INDICATORS
  if( !bInitialized )
    return;

  int nMIHP = MM_TO_PIX(MP_MIN_IND_HEIGHT_MM, fPixMM); // Min Indicator Height in Pixels
  int nMIHTP = MM_TO_PIX(MP_MIN_IND_TEXT_HEIGHT_MM, fPixMM); // Min Indicator Text Height in Pixels

  int nTC1, nTC2, nHC1 = prBBST ? prBBST->GetVertCrd( CSA, &nTC1 ) : 0;
  bool bCSAVisible = (nHC1 >= nMIHP);

  int nHC2 = prBBST->GetVertCrd( RelAmp, &nTC2 );
  bool bAmpVisible = (nHC2 >= nMIHP);

  int nAmplVisibles = 0, nCSAVisibles = 0;

  for( short nCh = 0; nCh < MC_STD_MAX_CHANNELS; ++nCh )
  {
    TrIndicatorHolder *prIndicatorHolder = &arIndicatorHolder[nCh];
    prIndicatorHolder->vBarPanels[0]->Visible = (nCh < rD.nNmbChOut) && bCSAVisible;
    for( short i = 2; i < prIndicatorHolder->vAsIndicator.size(); i++ )
    {
      prIndicatorHolder->vIndPanels[i]->Visible = (nCh < rD.nNmbChOut) && bCSAVisible &&
        rSP.rPI.abDigitalIndicator[i - 2];

      if (!nCh)
        nCSAVisibles += prIndicatorHolder->vIndPanels[i]->Visible;
    }

    prIndicatorHolder->vBarPanels[1]->Visible = (nCh < rD.nNmbChOut) && bAmpVisible;
    for( short i = 0; i < 2; i++ )
    {
      prIndicatorHolder->vIndPanels[i]->Visible = (nCh < rD.nNmbChOut) && bAmpVisible &&
        rSP.rPI.abDigitalIndicator[i + 4];

      if (!nCh)
        nAmplVisibles += prIndicatorHolder->vIndPanels[i]->Visible;
    }
  }

  int nVisibleInds = bCSAVisible * nCSAVisibles + bAmpVisible * nAmplVisibles,
    nT = PanelIndicators->Height;

  if (PanelIndicators->Visible != (bool)nVisibleInds)
  {
    PanelIndicators->Visible = nVisibleInds;
    PanelIndicators->Left = Width - 1;
  }
  if (PanelBars->Visible != (PanelIndicators->Visible && rSP.rPI.bShowIndicatorsPanel))
    PanelBars->Visible = PanelIndicators->Visible && rSP.rPI.bShowIndicatorsPanel;

  // ToDo: some offset ???
  int nDD = 2*(PanelIndicators->Top - 1); // ???
  nBH = ChHeight( PaintBoxTrends->Height, rD.nNmbChOut );
  nBH -= nDD;

  if (!bAmpVisible || !nAmplVisibles)
    nHC1 = nBH;

  if (!bCSAVisible || !nCSAVisibles)
    nHC2 = nBH;

  for (int nCh = 0; nCh < MC_STD_MAX_CHANNELS; ++nCh)
  {
    TrIndicatorHolder *prIndicatorHolder = &arIndicatorHolder[nCh];
    int nYcT = HorAxes( PaintBoxTrends->Height, rD.nNmbChOut, nCh ) - nBH/2;
    nT = nYcT + nBH;
    for (int i = prIndicatorHolder->vIndPanels.size()-1; i >= 2; --i)
      if (prIndicatorHolder->vIndPanels[i] && prIndicatorHolder->vIndPanels[i]->Visible)
      {
        prIndicatorHolder->vIndPanels[i]->Height = nHC1 / nCSAVisibles;
        nT -= prIndicatorHolder->vIndPanels[i]->Height + 1;
        prIndicatorHolder->vIndPanels[i]->Top = nT - nDD/2;
        prIndicatorHolder->vIndPanels[i]->Width = PanelIndicators->Width;
      }

    int nI = 0;
    // CSA
    prIndicatorHolder->vBarPanels[nI]->Visible = bCSAVisible && nCSAVisibles;
    if (prIndicatorHolder->vBarPanels[nI]->Top != nT)
      prIndicatorHolder->vBarPanels[nI]->Top = nT - nDD/2;
    if (prIndicatorHolder->vBarPanels[nI]->Height != nHC1)
      prIndicatorHolder->vBarPanels[nI]->Height = nHC1;
    int nBarsWidth = prIndicatorHolder->vBarPanels[nI]->Width;

    if (!bCSAVisible || !nCSAVisibles)
      nT -= nHC1;

    for (int i = 1; i >= 0; --i)
      if (prIndicatorHolder->vIndPanels[i] && prIndicatorHolder->vIndPanels[i]->Visible)
      {
        prIndicatorHolder->vIndPanels[i]->Height = nHC2 / nAmplVisibles;
        nT -= prIndicatorHolder->vIndPanels[i]->Height + 1;
        prIndicatorHolder->vIndPanels[i]->Top = nT - nDD/2;
        prIndicatorHolder->vIndPanels[i]->Width = PanelIndicators->Width;
      }

    for (int i = prIndicatorHolder->vIndPanels.size()-1; i >= 0; --i)
    {
      prIndicatorHolder->vAsIndicator[i]->TimeValueVisible = true;
      prIndicatorHolder->vAsIndicator[i]->TimeValueVisible =
        prIndicatorHolder->vAsIndicator[i]->ValueTimeBounds.Height() >= nMIHTP;
    }

    ++nI;
    // Ampl
    prIndicatorHolder->vBarPanels[nI]->Visible = bAmpVisible && nAmplVisibles;
    if (prIndicatorHolder->vBarPanels[nI]->Top != nT)
      prIndicatorHolder->vBarPanels[nI]->Top = nT - nDD/2;
    if (prIndicatorHolder->vBarPanels[nI]->Height != nHC2)
      prIndicatorHolder->vBarPanels[nI]->Height = nHC2;

    nBarsWidth = MAX(nBarsWidth, prIndicatorHolder->vBarPanels[nI]->Width);

    if (PanelBars->Width != nBarsWidth)
      PanelBars->Width = nBarsWidth;
  }

  if (!pPanelIndicators)
    PanelR->Visible = PanelBars->Visible || PanelIndicators->Visible;

  if (Sender)
    PanelBarsOnResize(NULL);

#endif
}

//------------------------------------------------------------------------------
void __fastcall trMcSpectrTrendR::PanelViewDigitsOnResize(TObject* Sender)
{
  if( bInitialized )
    SetPositionsForDPanel();
} // ***

//------------------------------------------------------------------------------
void __fastcall trMcSpectrTrendR::SettingsClick(TObject *Sender)
{
  if( bInitialized )
  {
    bool bShowView = !bLightMode;
    bool bShowMGA = bMGA;
    McEditSpectrTrendSettings(&rSP, &rTB, (trMcApplyObj *)(&rAppSet), &bShowView, &bShowMGA);  // sets everything by itself
  }
} // ***

//---------------------------------------------------------------------------
// save spectrum trend
void __fastcall trMcSpectrTrendR::OnSTSave(TObject *Sender)
{
  if (rPE.prCallback)
  {
    TCursor rTmpCursor = Screen->Cursor;
    Screen->Cursor = crHourGlass;
    JvProgressBar1->Position = 0;
    PanelProgress->Left = (Width - PanelProgress->Width) / 2;
    PanelProgress->Top  = (Height - PanelProgress->Height) / 2;
    PanelProgress->Visible = true;
    PanelProgress->BringToFront();
    Application->ProcessMessages();

    double fh = 1. / rSP.rPI.fPixPerSec;   // step in time for pixels (in sec.)
    long nSigR = rPE.prCallback->GetRightBorder() / fh;
    prBBST->SaveSpectrumTrend(0, nSigR);

    prSTBuffer->IsSaved(true);

    Screen->Cursor = rTmpCursor;
    PanelProgress->Visible = false;
    ButtonSTSave->Enabled = false;
    if (ButtonSTExport->Visible)
      ButtonSTExport->Enabled = true;
  }
} // ***

//---------------------------------------------------------------------------
// export spectrum trend
void __fastcall trMcSpectrTrendR::OnSTExport(TObject *Sender)
{
  if (!prSTBuffer->IsSaved(true))
    OnSTSave(ButtonSTSave);

  prSTBuffer->Export();
}

//------------------------------------------------------------------------------
void __fastcall trMcSpectrTrendR::MarkerMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y)
{
  if (bLightMode)
    return;

  if (bAcq) return;
  bCaptured = true;
  lMarkerOldPos = lMarkerPos;
  Screen->Cursor = (TCursor) ST_CAPTURED_CURSOR;
  TimerCursor->Enabled = true;
} // ***

//------------------------------------------------------------------------------
void __fastcall trMcSpectrTrendR::TimerCursorTimer(TObject *Sender)
{
  if (bAcq) return;
  if (lMarkerOldPos != lMarkerPos)
  {
    double fh = 1. / rSP.rPI.fPixPerSec;   // step in time for pixels (in sec.)
    lMarkerOldPos = lMarkerPos;
    if (rPE.prCallback)
    {
      long lCurPos = lBR - (PaintBoxTrends->Width - lMarkerPos - RO()); // current marker pos
      rPE.prCallback->SetPosition(lCurPos * fh);
      Application->ProcessMessages();
    }
  }
} // ***

//------------------------------------------------------------------------------
void trMcSpectrTrendR::SetBoards( bool bReinit )
{ // nBH, nBW (Set); lBR, lScrPix (Resize)
  nBH = ChHeight( PaintBoxTrends->Height, rD.nNmbChOut );
  nBW = PaintBoxTrends->Width - RO() - LO();

  double fh = 1. / rSP.rPI.fPixPerSec;   // step in time for pixels (in sec.)

  long lBC = rPE.fTR / fh;          // right board for bitmap; used in displaying
                  // closest right point to prP->fTR in pixels' index
  lScrPix = (rPE.fTScr / fh) + 0.5; // time point for the left of signal screen (in pixels' index)
  long lHalfScr = lScrPix / 2;    // size of half screen (in pixels' index)

  long lCurPos = lBR - (PaintBoxTrends->Width - lMarkerPos - RO());
                  // current position of screen center

  if (bReinit || lMarkerPos <= 0 || lCurPos < 0)
  {
    lMarkerPos = LO() + lHalfScr;
    lBR = lBC < nBW ? nBW : lBC + nBW - lHalfScr;
  }
  else
  {
    long nOffset = lBC - lCurPos;   // value on which screen is moved

    if (nOffset <= 0 && nOffset >= - (lMarkerPos - lHalfScr - LO()) ||
      nOffset >  0 && nOffset <= PaintBoxTrends->Width - lMarkerPos - lHalfScr - RO())
    {
      // just move marker
      lMarkerPos += nOffset;
    }
    else
    {
      // modify spectrum
      lBR = lBC + (nOffset > 0 ? lHalfScr : nBW - lHalfScr);
      lMarkerPos = nOffset > 0 ?
      PaintBoxTrends->Width - RO() - lHalfScr : LO() + lHalfScr;
    }
  }
} // ***

//------------------------------------------------------------------------------
void trMcSpectrTrendR::SetBitmapScaleColors( void ) // set colors' set for bitmap & scale;
{
  SetColors( rPE.nSC1, rPE.nSC2, rPE.nSC3, rSP.rPI.nSGrades, anC );
  rScale.rP.pnC = anC;    // assign new colors to scale (CSA)

  SetColors( rPE.nSC1, rPE.nSC2, rPE.nSC3, rSP.rPI.nSGradesR, anCR );
  rRAScale.rP.pnC = anCR;

  // text color
  rRAScale.rP.nForeC = rPE.nCSForeC;
  rScale.rP.nForeC = rPE.nCSForeC;

  rRAScale.rP.nNActC = rPE.nCSNActC;
  rScale.rP.nNActC = rPE.nCSNActC;
  rRAScale.rP.nActC = rPE.nCSActC;
  rScale.rP.nActC = rPE.nCSActC;

  #define CLT   200
  #define CLB   50
  #define CLMI  90
  #define CLMA  150
  // put add. colors at the end of color array:
  anC[rSP.rPI.nSGrades] = (TColor)RGB(CLB,CLB,CLB);         // color for the background (if displaying background higher than SEF)
  anC[rSP.rPI.nSGrades+1] = (TColor)RGB(CLMI,CLMI,CLMI);    // color for values lower than the scale minimum
  anC[rSP.rPI.nSGrades+2] = (TColor)RGB(CLMA,CLMA,CLMA);    // color for values upper than the scale maximum

  anCR[rSP.rPI.nSGradesR]   = (TColor)RGB(CLT,CLT,CLT);     // color for the borders (top) of stripes with relative amplitudes
  anCR[rSP.rPI.nSGradesR+1] = (TColor)RGB(CLB,CLB,CLB);     // color for the borders (bottom) of stripes with relative amplitudes
  anCR[rSP.rPI.nSGradesR+2] = (TColor)RGB(CLMI,CLMI,CLMI);  // color for values lower than the scale minimum
  anCR[rSP.rPI.nSGradesR+3] = (TColor)RGB(CLMA,CLMA,CLMA);  // color for values upper than the scale maximum
} // ***

//------------------------------------------------------------------------------
void trMcSpectrTrendR::UpdateVertRulersAndBands( void )
{
  int nCSAH = prBBST->GetVertCrd( CSA ) * (MC_STD_MAX_FRQ/(rSP.rPI.fFrqT - rSP.rPI.fFrqF)) + 0.5;
  int nRAH  = prBBST->GetVertCrd( RelAmp );// * (MC_STD_MAX_FRQ/(rSP.rPI.fFrqT - rSP.rPI.fFrqF)) + 0.5;
  prBMRulerR->Height = nCSAH;   prBMRulerL->Height = nCSAH;
  prBMAmpRulerR->Height = nRAH; prBMAmpRulerL->Height = nRAH;
  prBMColumn->Height = nCSAH;

  // draw vertical ruler in white on black background, values ranging from 0 to MC_STD_MAX_FRQ
  DrawVertRulers( prBMRulerR->Canvas, prBMRulerL->Canvas,
                  TRect(0, 0, prBMRulerR->Width, nCSAH),
                  clWhite, nVRLW, 0, MC_STD_MAX_FRQ, 1., 5 );    // 2., 5);

  double fStep;
  short nStep;
  if (rSP.rRA.fMaxAmp < 5)
  { fStep = 0.5; nStep = 2; }
  else if (rSP.rRA.fMaxAmp < 10)
  { fStep = 1; nStep = 2; }
  else if (rSP.rRA.fMaxAmp < 20)
  { fStep = 1; nStep = 5; }
  else if (rSP.rRA.fMaxAmp < 50)
  { fStep = 5; nStep = 2; }
  else
  { fStep = 10; nStep = 5; }

  DrawVertRulers( prBMAmpRulerR->Canvas, prBMAmpRulerL->Canvas,
                  TRect(0, 0, prBMAmpRulerR->Width, nRAH),
                  clWhite, nVRLW, 0, rSP.rRA.fMaxAmp, fStep, nStep );

  DrawBandColumn( prBMColumn->Canvas, TRect(0, 0, prBMColumn->Width, nCSAH),
                  rPE.nSpcNormColor, 0, MC_STD_MAX_FRQ, rPE.pBands, 4);
} // ***

//------------------------------------------------------------------------------
void trMcSpectrTrendR::SetScale( trMcSpcTrendPrmI *prAPI )
{
  trMcSpcTrendPrmI *prPI = prAPI ? prAPI : &(rSP.rPI);

  trMcFIDT *prDT = prPI->nTransform == trMcSpcTrendPrmI::Linear ?  (trMcFIDT *) &rLinDT :
                   prPI->nTransform == trMcSpcTrendPrmI::SqrRoot ? (trMcFIDT *) &rSqrDT :
                                                                   (trMcFIDT *) &rLogDT;
  for( short nG = 0; nG <= prPI->nSGrades; nG++ )
    afB[nG] = prDT->X( nG / (double) prPI->nSGrades );
  rScale.rP.pfB = afB;    // set scale transformation

  rScale.rP.Set( (short)prPI->fScaleMax, (short)prPI->fScaleSens, prPI->nSGrades );
  rScale.Set( PaintBoxFreqInd->Height * (double) rSP.rPI.nCSAHeightPerCent / 100,
              PaintBoxFreqInd->Width, rScale.rP );
  rScale.SetCursor( 0., (double)rScale.rP.nScaleMax, (double)rScale.rP.nScaleSens,
                    (double)rScale.rP.nScaleSens );

  for( short nG = 0; nG <= prPI->nSGradesR; nG++ )
    afBRA[nG] = rLinDTR.X( nG / (double) prPI->nSGradesR ) / prPI->fScaleSensMaxR;
  rRAScale.rP.pfB = afBRA;    // set scale transformation
  rRAScale.rP.Set( (short) (2 * prPI->fScaleSensMaxR), (short) (2 * prPI->fScaleSensR), prPI->nSGradesR );
  rRAScale.Set( PaintBoxFreqInd->Height * (1. - (double) rSP.rPI.nCSAHeightPerCent / 100),
                PaintBoxFreqInd->Width, rRAScale.rP );
  rRAScale.SetCursor( 0, (double) rRAScale.rP.nScaleMax,
                      (double) rRAScale.rP.nScaleSens, (double) rRAScale.rP.nScaleSens );
} // ***

// Set scale parameters corr. to the new value of a scale cursor for CSA ------
void trMcSpectrTrendR::SetScaleCursorCSA( short nY )
{
  nY -= PaintBoxFreqInd->Height * (1. - (double) rSP.rPI.nCSAHeightPerCent / 100);
  nY = MAX( 0, MIN(rScale.nH-1, nY) ); // inside scale

  double fB = (double)rScale.rP.nScaleMax,
         fV = IND_FLOAT_EDGES( rScale.nH, fB, 0., nY );
  fV = fabs(fV);
  rScale.rP.nScaleSens = MAX(fV + 0.5, 1);   // new value

  double fVP = (double)rScale.rP.nScaleSens;
  // set the cursor position on the screen
  rScale.SetCursor( 0., fB, fVP, fVP );
} // ***

// Set scale parameters corr. to the new value of a scale cursor for CSA ------
void trMcSpectrTrendR::SetScaleCursorRA( short nY )
{
  nY = MAX( 0, MIN(rRAScale.nH - 1, nY) ); // inside scale

  double fB = (double) rRAScale.rP.nScaleMax,
         fV = IND_FLOAT_EDGES( rRAScale.nH, fB, 0., nY );
  fV = fabs(fV);
  rRAScale.rP.nScaleSens = MAX(fV + 0.5, 1);   // new value

  double fVP = (double) rRAScale.rP.nScaleSens;
  // set the cursor position on the screen
  rRAScale.SetCursor( 0., fB, fVP, fVP );
} // ***

// -----------------------------------------------------------------------------
void trMcSpectrTrendR::GetTrendsStyles( short *pnTS, trMcSpcTrendPrmI * prTP  )
{
  trMcSpcTrendPrmI *prPI = prTP ? prTP : &rSP.rPI;
  for( short nT = 0; nT < 5; nT++ )
    pnTS[nT] = (prPI->arTW[nT] == trMcSpcTrendPrmI::Thin)   ? MCSTB_DOTTED_TRANSPARENT :
               (prPI->arTW[nT] == trMcSpcTrendPrmI::Medium) ? MCSTB_DOTTED_THINBK :
                                                              MCSTB_DOTTED_THICKBK;
} // ***

// -----------------------------------------------------------------------------
void trMcSpectrTrendR::GetTrendsColors( TColor *pnC )
{
  pnC[0] = pnC[1] = rPE.nSEFColor;
  pnC[2] = rPE.nSpMaxC1,  pnC[3] = rPE.nSpMaxC2,
  pnC[5] = rPE.nEntropyC, pnC[5] = rPE.nTrendsBKC;
} // ***

// should be called on init or if modified: nBH, rSPC.lT -----------------------
bool trMcSpectrTrendR::SetBuffers( void )
{ // rPE, rSPC, rD, rPI - should be already set
  SetBoards(); // nBW, nBH

  trMcSTBPrmGen rPG;   trMcSTBPrmCSA rPC;   trMcSTBPrmRA rPR;
  trMcSTBScale rScC, rScR;
  trMcSTBPrmAR rPAR;
  FillBufferStructs( &rPG, &rPC, &rScC, &rPR, &rScR, &rPAR );

  bool bEmpty = rPE.prCallback->GetRightBorder() <= 0;
  ButtonSTSave->Enabled = !bAcq && !bEmpty && !prSTBuffer->IsSaved(true);
  if (ButtonSTExport->Visible)
    ButtonSTExport->Enabled = !bEmpty && prSTBuffer->IsSaved(true);

  return prBBST->Init( prSTP, rTB.nPixLen, &rPG, &rPC, &rScC, &rPR, &rScR, &rPAR,
             prPEI, PanelButtons->Visible ? prSTBuffer : NULL, &rCallback );
} // ***

// -----------------------------------------------------------------------------
void trMcSpectrTrendR::FillBufferStructs( trMcSTBPrmGen * prPG, trMcSTBPrmCSA * prPC,
       trMcSTBScale *prScC, trMcSTBPrmRA *prPR, trMcSTBScale *prScR, trMcSTBPrmAR *prPAR )
{ // fill structs with parameters for the spectrum trends' buffer
  double fh = 1. / rSP.rPI.fPixPerSec,         // step in time 1 pixel (sec.)
         fH = rSPC.lT / (double)rD.nSampRate,  // step in time for 1 raw spectrun (sec.)
         fhH = fh / fH;

  prPG->fhH = fhH,  prPG->nH = nBH;

  bool bOnlyCSA = (rSP.rPI.nCSAHeightPerCent > 90),
       bOnlyAmp = (rSP.rPI.nCSAHeightPerCent < 10);

  prPG->rCP.nNBB = (bOnlyCSA || bOnlyAmp) ? 1 : 2;
  prPG->anT[0] = (bOnlyCSA) ? CSA : RelAmp,   prPG->anT[1] = CSA;

  prPG->rCP.afRH[0] = (bOnlyCSA || bOnlyAmp) ? 1. : (100 - rSP.rPI.nCSAHeightPerCent) /100.;
  prPG->rCP.afRH[1] = rSP.rPI.nCSAHeightPerCent /100.;

  prPG->rCP.ndH = 2;
  prPG->rCP.nDC = (TColor)RGB(CLR_BK2,CLR_BK2,CLR_BK2);

  prPC->fFrqF = rSP.rPI.fFrqF,    prPC->fFrqTo  = rSP.rPI.fFrqT;
  prPC->fFrqFS = rSP.rPI.fFrqFS,  prPC->fFrqToS = rSP.rPI.fFrqToS;
  prPC->fSSB = rSP.rPI.fSSB;
  prPC->fEntSmoothing = rSP.rPI.fEntSmoothing;

  prPC->fSLevHi = rSP.rPI.anSEFPercent[0]/100., prPC->fSLevLo = rSP.rPI.anSEFPercent[1]/100.;
  memcpy( prPC->abTrends, rSP.rPI.abTrends, sizeof(prPC->abTrends) );

  for( short nT = 0; nT < 5; nT++ )
    prPC->anTrendStyles[nT] =
       (rSP.rPI.arTW[nT] == trMcSpcTrendPrmI::Thin)   ? MCSTB_DOTTED_TRANSPARENT :
       (rSP.rPI.arTW[nT] == trMcSpcTrendPrmI::Medium) ? MCSTB_DOTTED_THINBK :
                                                        MCSTB_DOTTED_THICKBK;

  prPC->anTrendColors[0] = prPC->anTrendColors[1] = rPE.nSEFColor;
  prPC->anTrendColors[2] = rPE.nSpMaxC1,  prPC->anTrendColors[3] = rPE.nSpMaxC2,
  prPC->anTrendColors[4] = rPE.nEntropyC, prPC->anTrendColors[5] = rPE.nTrendsBKC;
  prPC->bShowSpectrHigherSEF = rSP.rPI.bShowSpectrHigherSEF;

  prScC->pnC = anC;
  trMcFIDT *prDT = rSP.rPI.nTransform == trMcSpcTrendPrmI::Linear ?  (trMcFIDT *) &rLinDT :
                   rSP.rPI.nTransform == trMcSpcTrendPrmI::SqrRoot ? (trMcFIDT *) &rSqrDT :
                                                                     (trMcFIDT *) &rLogDT;
  prDT->Set( 1./rSP.rPI.fScaleSens, rSP.rPI.nSGrades );
  prScC->prDT = prDT;

  *prPR = rSP.rRA;

  prPR->rB.fC = rSPC.fMaxFrq;

  /*
  prPR->rB.nNB = 4;
  for( short nB = 0; nB < 4; nB++ )
  {
    prPR->rB.afF[nB] = rPE.pBands[nB].fFrom/rSPC.fMaxFrq;
    prPR->rB.afT[nB] = rPE.pBands[nB].fTo/rSPC.fMaxFrq;
  }

  // rAB.afF[4] = rAB.afT[3],   rAB.afT[4] = 1.;

  memset( &prPR->rBG, 0, sizeof( prPR->rBG ) );  // all to false

  prPR->rBG.nNG = 4;  prPR->rBG.abBG[0][0] = prPR->rBG.abBG[1][1] =
                      prPR->rBG.abBG[2][2] = prPR->rBG.abBG[3][3] = true;   // delta, tetha, alpha, beta
  */

  prPR->anTrendColors[0] = clBlack;
  prPR->anTrendColors[1] = clWhite;

  prScR->pnC = anCR;
  rLinDTR.Set( /*rSP.rPI.fScaleSensMinR*/ 0, rSP.rPI.fScaleSensR, rSP.rPI.nSGradesR );
  prScR->prDT = &rLinDTR;

  trMcSTBPrmAR rPAR;

  rPAR.bDisplayed = rSP.rPI.bDisplayARTrend;
  rPAR.rP1 = rSP.rPAR1;   rPAR.rP2 = rSP.rPAR2;
  *prPAR = rPAR;
} // ***

// -----------------------------------------------------------------------------
trMcDigitalPanelCtl trMcSpectrTrendR::GetDPanelCtl( trMcSTBTrends nTT ) // fill struct for indicators' panel parameters with current values
{
  trMcDigitalPanelCtl rCtl;
  for( short nP = 0, nPM = (nTT==CSA) ? 4 : 2; nP < nPM ; nP++ )
  {
  #ifdef NEW_INDICATORS
    rCtl.abD[nP] = false;
#else
    rCtl.abD[nP] = (nTT==CSA) ? rSP.rPI.abDigitalIndicator[nP] : rSP.rPI.abDigitalIndicator[nP + 4];
#endif
    rCtl.arR[nP].fF = (nTT==CSA) ? (nP == 3 ? 0. : rSP.rPI.fFrqF) : 0.;
    rCtl.arR[nP].fT = (nTT==CSA) ? (nP == 3 ? 1. : rSP.rPI.fFrqT) :
                                   (nP == 1 ? 1. : 100.);
  }

  return rCtl;
} // ***

// -----------------------------------------------------------------------------
int trMcSpectrTrendR::GetDPanelWidth( void )
{
  int nHC = prBBST->GetVertCrd( CSA ),
      nHR = prBBST->GetVertCrd( RelAmp ),
      nH = MAX(nHC, nHR);
  trMcDigitalPanelCtl rCtlC = GetDPanelCtl( CSA ),
                      rCtlA = GetDPanelCtl( RelAmp );
  for( short nP = 0; nP < 3; nP++ )
    rCtlC.abD[nP] = rCtlC.abD[nP] || rCtlA.abD[nP];

  return McIndPanelWidth( nH, pprDP[CSA][0]->PanelBars->Width, rCtlC, 4);
} // ***

#ifdef NEW_INDICATORS
// -----------------------------------------------------------------------------
void trMcSpectrTrendR::UpdateIndicators()
{
  AnsiString asPNames[] =
  {
    LabelTotalAmpP->Caption,
    Label15->Caption,
    (LabelSEFHi->Caption + (AnsiString)rSP.rPI.anSEFPercent[0]),
    (LabelSEFLo->Caption + (AnsiString)rSP.rPI.anSEFPercent[1]),
    LabelMax->Caption,
    Label2->Caption
  };

  PanelBars->Color = rSP.rPI.nDigitalIndicatorBackColor;
  for (int nCh = 0; nCh < MC_STD_MAX_CHANNELS; ++nCh)
  {
    TrIndicatorHolder *prIndicatorHolder = &arIndicatorHolder[nCh];
    for( short i = 0; i < prIndicatorHolder->vAsIndicator.size(); i++ )
    {
      if (prIndicatorHolder->vAsIndicator[i])
      {
        if (!prIndicatorHolder->vIndPanels[i])
          continue;
        TAsIndicator *prAsIndicator = prIndicatorHolder->vAsIndicator[i];

        prAsIndicator->TimeValue = asPNames[i];

        prIndicatorHolder->vProgressBars[i]->Gradient->FromColor = PanelBars->Color;
        prIndicatorHolder->vProgressBars[i]->Gradient->ToColor = PanelBars->Color;

        prAsIndicator->ValueBackColor = rSP.rPI.nDigitalIndicatorBackColor;
        prAsIndicator->Color = rSP.rPI.nDigitalIndicatorBackColor;

        int r = RED(prAsIndicator->ValueBackColor);
        int g = GREEN(prAsIndicator->ValueBackColor);
        int b = BLUE(prAsIndicator->ValueBackColor);
        int k = 50;
        prAsIndicator->CaptionBackColor = RGB(MAX(0, k + r), MAX(0, k + g), MAX(0, k + b));

//        prAsIndicator->ValueBackColor = rDPP.nBkC;
//        prAsIndicator->ValueTextColor = rDPP.anC[i % 4];
      }
    }
  }
}
#endif
// -----------------------------------------------------------------------------
void trMcSpectrTrendR::SetParametersForDPanel( bool bParameters, bool bCaptions )
{
  trMcDigitalPanelCtl rCtlC = GetDPanelCtl( CSA ),
                      rCtlA = GetDPanelCtl( RelAmp );
  AnsiString sSEF1 = LabelSEFHi->Caption + (AnsiString)rSP.rPI.anSEFPercent[0],
             sSEF2 = LabelSEFHi->Caption + (AnsiString)rSP.rPI.anSEFPercent[1];

  for( short nCh = 0; nCh < rD.nNmbChOut; nCh++ )
  {
    if( bParameters )
      pprDP[CSA][nCh]->Set( &rCtlC ),
      pprDP[RelAmp][nCh]->Set( &rCtlA );

    if( !bCaptions )
      continue;
    pprDP[CSA][nCh]->SetCaption( 0, sSEF1.c_str() );
    pprDP[CSA][nCh]->SetCaption( 1, sSEF2.c_str() );
  }

#ifdef NEW_INDICATORS
  UpdateIndicators();
#endif
} // ***

// Set values for panel with indicators (lat computed spectrum used) -----------
void trMcSpectrTrendR::SetValuesForDPanel( void )
{
  for( short nCh = 0; nCh < rD.nNmbChOut; nCh++ )
  {
    float afV[4];    int nMP, nSMP;
    long lX = MIN( lBR, prBBST->T() );

    trMcSTBCurrState rS;
    bool bOK = (lX >= 0) ? prBBST->GetStateInPoint( lX, 0, nCh, &rS ) : false;

    afV[2] = rS.fMax,  nMP = rS.nMax,   afV[0] = rS.fSEFHi,  afV[1] = rS.fSEFLo;
    afV[3] = rS.fEntropy;

    trMcDigitalPanelPrm rDPP;

    if( !bOK )
      afV[0] = afV[1] = afV[2] = afV[3] = rDPP.fMissedValue;
    else
    {
      int nBHH = prBBST->GetVertCrd( CSA );
      afV[2] = (nMP/ (float) (nBHH - 1) ) * (rSP.rPI.fFrqT - rSP.rPI.fFrqF)  + rSP.rPI.fFrqF;
    }

    pprDP[CSA][nCh]->Control( afV );

#ifdef NEW_INDICATORS
//    for( short nP = 0, nPM = (nTT==CSA) ? 4 : 2; nP < nPM ; nP++ )
//    rCtl.arR[nP].fF = (nTT==CSA) ? (nP == 3 ? 0. : rSP.rPI.fFrqF) : 0.;
//    rCtl.arR[nP].fT = (nTT==CSA) ? (nP == 3 ? 1. : rSP.rPI.fFrqT) :
//                                   (nP == 1 ? 1. : 100.);

    TrIndicatorHolder *prIndicatorHolder = &arIndicatorHolder[nCh];
    for (int i = 2; i < prIndicatorHolder->vAsIndicator.size(); i++)
      if (prIndicatorHolder->vAsIndicator[i])
      {
        if (fabs(afV[i-2] - rDPP.fMissedValue) < 1e-6)
        {
          prIndicatorHolder->vAsIndicator[i]->Value = "--";
          prIndicatorHolder->vProgressBars[i]->Percent = 100;
          prIndicatorHolder->vProgressBars[i]->Caption = prIndicatorHolder->vAsIndicator[i]->Value;
        }
        else
        {
          prIndicatorHolder->vAsIndicator[i]->Value = FloatToStrF(afV[i-2], ffFixed, 15, 1);
          double fF = i-2 == 3 ? 0. : rSP.rPI.fFrqF;
          double fT = i-2 == 3 ? 1. : rSP.rPI.fFrqT;
          prIndicatorHolder->vProgressBars[i]->Percent = 100 - 100*afV[i-2] / (fT - fF);
          prIndicatorHolder->vProgressBars[i]->Caption = prIndicatorHolder->vAsIndicator[i]->Value;
        }
      }
#endif

    if ( bOK )
    {
      afV[0] = rS.fTotalEnergy;
      afV[1] = rS.afERTrend[0];
    }
    else
      afV[0] = afV[1] = afV[2] = rDPP.fMissedValue;

#ifdef NEW_INDICATORS
    for (int i = 0; i < 2; i++)
      if (prIndicatorHolder->vAsIndicator[i])
        if (fabs(afV[i] - rDPP.fMissedValue) < 1e-6)
        {
          prIndicatorHolder->vAsIndicator[i]->Value = "--";
          prIndicatorHolder->vProgressBars[i]->Percent = 100;
          prIndicatorHolder->vProgressBars[i]->Caption = prIndicatorHolder->vAsIndicator[i]->Value;
        }
        else
        {
          double fF = 0;
          double fT = i == 1 ? 1. : 100.;

          prIndicatorHolder->vAsIndicator[i]->Value = FloatToStrF(afV[i], ffFixed, 15, 1);

          prIndicatorHolder->vProgressBars[i]->Percent = 100 - 100*afV[i] / (fT - fF);
          prIndicatorHolder->vProgressBars[i]->Caption = prIndicatorHolder->vAsIndicator[i]->Value;

        }
#endif

    pprDP[RelAmp][nCh]->Control( afV );
  }


} // ***

// -----------------------------------------------------------------------------
void trMcSpectrTrendR::SetPositionsForDPanel( void )
{
  if (PanelViewDigits->Tag)
    return;

  PanelViewDigits->Tag = 1;
  int nMIHP = MM_TO_PIX(MP_MIN_IND_HEIGHT_MM, fPixMM); // Min Indicator Height in Pixels

  bool bPanelIndVisible = false;
  for( short nCh = 0; nCh < rD.nNmbChOut; nCh++ )
  {
    // top is same top on PanelViewDigits as for bitmap on PaintBoxTrends:
    int nYcT = HorAxes( PaintBoxTrends->Height, rD.nNmbChOut, nCh ) - nBH/2;

    // CSA bounds:
    int nTC, nHC = prBBST->GetVertCrd( CSA, &nTC ),
        nYT = nYcT + nTC;
    TRect rRCSA_O = pprDP[CSA][nCh]->BoundsRect,                      // Old bounds' rect for CSA
          rRCSA_N = Rect(0, nYT, PanelViewDigits->Width, nYT + nHC);  // New bounds' rect for CSA

    pprDP[CSA][nCh]->Visible = (nHC >= nMIHP);

    if (pprDP[CSA][nCh]->Visible)
      bPanelIndVisible = true;

    // RelAmp bounds:
    nHC = prBBST->GetVertCrd( RelAmp, &nTC );
    nYT = nYcT + nTC;
    TRect rRRA_O = pprDP[RelAmp][nCh]->BoundsRect,                   // Old bounds' rect for RelAmp
      rRRA_N = Rect(0, nYT, PanelViewDigits->Width, nYT + nHC);  // New bounds' rect for RelAmp

    pprDP[RelAmp][nCh]->Visible = (nHC >= nMIHP);

    if (pprDP[RelAmp][nCh]->Visible)
      bPanelIndVisible = true;

    // Set bounds to panels
    bool bCSA = pprDP[CSA][nCh]->Visible,
        bRA  = pprDP[RelAmp][nCh]->Visible;

    if( bCSA && !bRA )
      rRCSA_N.Top = nYcT;

    if( !bCSA && bRA )
      rRRA_N.Bottom = nYcT + nBH;

    if( bCSA && !(rRCSA_N == rRCSA_O) )
      pprDP[CSA][nCh]->BoundsRect = rRCSA_N;
    if( bRA && !(rRRA_N == rRRA_O) )
      pprDP[RelAmp][nCh]->BoundsRect = rRRA_N;
  }

//  PanelViewDigits->Visible = bPanelIndVisible && rSP.rPI.bShowIndicatorsPanel;
  PanelViewIndicatorsOnResize(NULL);
  PanelViewDigits->Tag = 0;
} // ***

// Set all parameters ----------------------------------------------------------
void trMcSpectrTrendR::Set( trMcSpectrTrendSettings * prS )
{
  if( !bInitialized || !prS )
    return;

  if( *prS == rSP )
    return;

  // todo
  if (prPEI->prD[0])
  {
    BrSetSpcTrendSettings(prS);
    prPEI->prD[0]->Reset();
  }

  bool bReInit = false, bScale = false, bHResize = false, bVResize = false, bVertRulers = false,
       bDPanel = false, bSefLevel = false, bTrends = false, bRA = false;

  bool bPrimSpc = !(rSP.rPP == prS->rPP);
  if( !(rSP.rPA == prS->rPA) || bPrimSpc )
  {
    prSTP->Set( &prS->rPA, bPrimSpc ? &prS->rPP : NULL, &rSPC );
    bReInit = true;
  }

  bool bAR = !(rSP.rPAR1 == prS->rPAR1) || !(rSP.rPAR2 == prS->rPAR2);

  if (!(rSP == *prS))
  {
    bRA = true;
    bVertRulers = bVertRulers || !FLOAT_EQ(rSP.rRA.fMaxAmp, prS->rRA.fMaxAmp);
  }

  if( !(rSP.rPI == prS->rPI) || bAR )
  {
    bHResize = !FLOAT_EQ(rSP.rPI.fPixPerSec, prS->rPI.fPixPerSec);
    bVResize = rSP.rPI.nCSAHeightPerCent != prS->rPI.nCSAHeightPerCent;
    bVertRulers = bVertRulers || bVResize || !FLOAT_EQ(rSP.rPI.fFrqF, prS->rPI.fFrqF) ||
                  !FLOAT_EQ(rSP.rPI.fFrqT, prS->rPI.fFrqT);
    bScale =
        !FLOAT_EQ(rSP.rPI.fScaleMax, prS->rPI.fScaleMax) ||
        !FLOAT_EQ(rSP.rPI.fScaleSens, prS->rPI.fScaleSens) ||
        (rSP.rPI.nSGrades != prS->rPI.nSGrades) ||
        !FLOAT_EQ(rSP.rPI.fScaleSensR, prS->rPI.fScaleSensR) ||
        !FLOAT_EQ(rSP.rPI.fScaleSensMaxR, prS->rPI.fScaleSensMaxR) ||
        !FLOAT_EQ(rSP.rPI.fScaleSensMinR, prS->rPI.fScaleSensMinR) ||
        (rSP.rPI.nSGradesR != prS->rPI.nSGradesR) ||
        (rSP.rPI.nTransform != prS->rPI.nTransform) ||
        !BOOL_EQ(rSP.rPI.bShowSpectrHigherSEF, prS->rPI.bShowSpectrHigherSEF);

    bSefLevel = (rSP.rPI.anSEFPercent[0] != prS->rPI.anSEFPercent[0]) ||
                (rSP.rPI.anSEFPercent[1] != prS->rPI.anSEFPercent[1]);

    for( short nT = 0; nT < 5;  nT++ )
      bTrends = bTrends || (rSP.rPI.arTW[nT] != prS->rPI.arTW[nT]) ||
                BOOL_EQ(rSP.rPI.abTrends[nT], prS->rPI.abTrends[nT]);

    bDPanel = !BOOL_EQ(rSP.rPI.bShowIndicatorsPanel, prS->rPI.bShowIndicatorsPanel) ||
              !BOOL_EQ(rSP.rPI.abDigitalIndicator[0], prS->rPI.abDigitalIndicator[0] ) ||
              !BOOL_EQ(rSP.rPI.abDigitalIndicator[1], prS->rPI.abDigitalIndicator[1] ) ||
              !BOOL_EQ(rSP.rPI.abDigitalIndicator[2], prS->rPI.abDigitalIndicator[2] ) ||
              !BOOL_EQ(rSP.rPI.abDigitalIndicator[3], prS->rPI.abDigitalIndicator[3] ) ||
              !BOOL_EQ(rSP.rPI.abDigitalIndicator[4], prS->rPI.abDigitalIndicator[4] ) ||
              !BOOL_EQ(rSP.rPI.abDigitalIndicator[5], prS->rPI.abDigitalIndicator[5] ) ||
              bSefLevel;

    rSP = *prS;
    SetPositionsForDPanel();
  }

  rSP = *prS;

  SetBoards();

  if( bReInit )
    SetBuffers();
  else
  {
    trMcSTBPrmGen rPG;   trMcSTBPrmCSA rPC;   trMcSTBPrmRA rPR;
    trMcSTBScale rScC, rScR;   trMcSTBPrmAR rPAR;
    FillBufferStructs( &rPG, &rPC, &rScC, &rPR, &rScR, &rPAR );
    if( bHResize || bVResize || bSefLevel || bTrends || bAR || bRA )
      prBBST->Set( &rPG, &rPC, &rPR, &rPAR );
    if( bScale )
      prBBST->SetScales( &rScC, &rScR );
  }

  if (bVResize)
  {
    SetScale();
    PaintBoxFreqIndPaint(PaintBoxFreqInd);
  }

  if( bVertRulers )
    UpdateVertRulersAndBands();

  if( bSefLevel )
    SetParametersForDPanel( false, true );

  if( bDPanel || bReInit )
  {
    if( PanelViewDigits->Visible )
    {
      PanelViewDigits->Width++; // to force resizing
      SetParametersForDPanel( true, false );
    }
  }

  PaintBoxTrends->Invalidate();

  if( bHResize )
  {
    pHorzRuler->Update( rSP.rPI.fPixPerSec );
    PaintBoxHorRuler->Invalidate();
  }

  if( bScale )
  {
    SetBitmapScaleColors(); // set colors' set for bitmap & scale;
    SetScale();
    PaintBoxFreqInd->Invalidate();
  }
} // ***

// -----------------------------------------------------------------------------
void trMcSpectrTrendR::Display( void )
{
  long lR = lBR, lL = lBR - (nBW - 1);

  float fOldMax = prBBST->GetCurrMax();

  if (!UpdateBitmapBuffer( &lL, &lR, prBBST, rSP.rPI.fPixPerSec ))
    return;

  if( (prBBST->GetCurrMax() != fOldMax) && (prBBST->GetCurrMax() >= 0) )
    PaintBoxFreqIndPaint(this);

  // Display digital panel (if switched on)
  if (rSP.rPI.bShowIndicatorsPanel || rSP.rPI.AnyTrend())
  {
    PanelViewDigits->Color = rPE.nBK2;
    SetPositionsForDPanel();
    SetValuesForDPanel();
  }

  int nRSh = RO(),  nLSh = LO(),
      nX1 = 0,           // left edge of displayed zone
      nX2 = nX1 + nLSh,  // beginning of bitmap(s) with color spectrums
      nX4 = PaintBoxTrends->Width - 1, // right edge of displayed zone
      nX3 = nX4 - nRSh,  // end of bitmap(s) with color spectrums
      nYT  = 0,                        // top of the displayed zone
      nYB  = PaintBoxTrends->Height - 1, // bottom of the displayed zone
      nYcT = HorAxes( PaintBoxTrends->Height, rD.nNmbChOut, 0 ) - nBH/2,                          // top line of the first bitmap
      nYcB = HorAxes( PaintBoxTrends->Height, rD.nNmbChOut, rD.nNmbChOut-1 ) - (nBH/2) + nBH - 1, // bottom line of the last bitmap
      nRBTop = FLOAT_ANTIIND(0, MC_STD_MAX_FRQ, prBMColumn->Height, rSP.rPI.fFrqT);  // top of displayed zone in vert. rulers & bands

  // Set screen panel:
  bool bScrPanel = rSP.rPI.bShowScreenPanel && (lScrPix > 0) && (lMarkerPos > 0);
  if( bScrPanel && !bCaptured)
  {
    PanelScreenBorder->Top = nYcT + LR_PIX_DIST;
    PanelScreenBorder->Height = nYcB - nYcT + 1 - 2 * LR_PIX_DIST;
    PanelScreenBorder->Left = lMarkerPos;
  }
  PanelScreenBorder->Visible = bScrPanel;

  PanelFreqInd->Visible = rSP.rPI.bShowScalePanel;

  PaintBoxTrends->Canvas->Brush->Color = rPE.nBK2;
  PaintBoxTrends->Canvas->FillRect( TRect( nX1,   nYT,    nX4+1, nYcT ) );      // stripe before the first bitmap
  PaintBoxTrends->Canvas->FillRect( TRect( nX1,   nYcB+1, nX4+1, nYB+1 ) );     // stripe after the last bitmap

  for( short nCh = 0; nCh < rD.nNmbChOut; nCh++ )
  {
    if( nCh  )
    { //  nYcB is bottom of the previous bitmap
      nYcT = HorAxes( PaintBoxTrends->Height, rD.nNmbChOut, nCh ) - nBH/2;    // top line of the curent bitmap
      PaintBoxTrends->Canvas->Brush->Color = rPE.nBK2;
      PaintBoxTrends->Canvas->FillRect( TRect( nX1, nYcB+1, nX4+1, nYcT ) );  // stripe between bitmaps
    }

    nYcB = nYcT + nBH - 1;      // bottom line of the current bitmap

    TRect rRCh = TRect( nX1, nYcT, nX4+1, nYcB+1 ), // rect. with channel (including boards)
          rRT  = TRect( nX2, nYcT, nX3+1, nYcB+1 ); // rect. with trend itself

    DisplayOneChannel( rRCh, rRT, nRSh - LR_PIX_DIST, nLSh - LR_PIX_DIST, nRBTop, nCh );
  }
} // ***

//------------------------------------------------------------------------------
void trMcSpectrTrendR::DisplayOneChannel( TRect rRCh, TRect rRT, int nRSh, int nLSh, int nRBTop, short nCh )
{ // rRCh is rect. with board, color panel(s) (if any), vert. rulers (if any)
  // rRT is rect. with trend itself (should be inside rRCh, height & top being equal for both)
  TRect rRT0  = ShiftRect(rRT, -rRCh.left, -rRT.top),
        rRCh0 = ShiftRect(rRCh, -rRCh.left, -rRCh.top);

  int nH = rRCh.Height();
  prBMChannel->Height = nH;
  prBMChannel->Width  = rRCh.Width();

  // Display trend itself:
  DisplayTrendForChannel( prBMChannel->Canvas, rRT0, nCh );

  // Display left/right boards:
  prBMChannel->Canvas->Brush->Color = rPE.nBK2;
  prBMChannel->Canvas->FillRect( TRect(0, 0, rRT0.left, nH ) );            // left vert. stripe before trend field
  prBMChannel->Canvas->FillRect( TRect(rRT0.right, 0, rRCh0.right, nH ) ); // right vert. stripe after tremd field

  // Display vert. bands:
  int nW = prBMColumn->Width,
      nTC, nHC = prBBST->GetVertCrd( CSA, &nTC );

  TRect rRL = TRect(rRT.left - nLSh, nTC, rRT.left - nLSh + nW, nTC + nHC ),
        rRR = TRect(rRT.right + nRSh - nW, nTC, rRT.right + nRSh, nTC + nHC ),
        rRC = TRect(0, nRBTop, nW, nRBTop + nHC );

  if (rSP.rPI.bBandRight)
    prBMChannel->Canvas->CopyRect( rRR, prBMColumn->Canvas, rRC );
  if (rSP.rPI.bBandLeft)
    prBMChannel->Canvas->CopyRect( rRL, prBMColumn->Canvas, rRC );

  // Display CSA vert. rulers:
  prBMChannel->Canvas->CopyMode = cmSrcPaint;   // set copy mode in such way that the target image is (itself OR vertical ruler)
  nW = prBMRulerR->Width;
  int nSh = 2*nVRLW;

  rRL = TRect(rRT.left - nSh, nTC, rRT.left - nSh + nW, nTC + nHC),
  rRR = TRect(rRT.right + nSh - nW, nTC, rRT.right + nSh, nTC + nHC),
  rRC = TRect(0, nRBTop, nW, nRBTop + nHC );

  if (rSP.rPI.bRulerRight)
    prBMChannel->Canvas->CopyRect( rRR, prBMRulerR->Canvas, rRC );
  if (rSP.rPI.bRulerLeft)
    prBMChannel->Canvas->CopyRect( rRL, prBMRulerL->Canvas, rRC );

  // Display RA vert. rulers:
  nHC = prBBST->GetVertCrd( RelAmp, &nTC );
  rRL = TRect(rRT.left - nSh, nTC, rRT.left - nSh + nW, nTC + nHC),
  rRR = TRect(rRT.right + nSh - nW, nTC, rRT.right + nSh, nTC + nHC),
  rRC = TRect(0, 0 /*nRBTop*/, nW, /*nRBTop +*/ nHC );

  if (rSP.rPI.bRARulerRight)
    prBMChannel->Canvas->CopyRect( rRR, prBMAmpRulerR->Canvas, rRC );
  if (rSP.rPI.bRARulerLeft)
    prBMChannel->Canvas->CopyRect( rRL, prBMAmpRulerL->Canvas, rRC );

  prBMChannel->Canvas->CopyMode = cmSrcCopy;     // restore default copy mode

  // Copy all to screen:
  PaintBoxTrends->Canvas->CopyRect( rRCh, prBMChannel->Canvas, rRCh0 );
} // ***

// -----------------------------------------------------------------------------
void trMcSpectrTrendR::DisplayTrendForChannel( TCanvas *prC, TRect rR, short nCh )
{
  long lDT = lBR - rR.right;                   // coord. in index minus this is coord. in pixels
  int nBL = MAX( prBBST->F() - lDT, rR.left ),     // left coord of the first bitmap's spectrum in pixels
      nBR = MIN( prBBST->T() - lDT, rR.right-1 );  // right coord of the last bitmap's spectrum in pixels

  prC->Brush->Color = rPE.nBK1;

  if( nBL > rR.left )
    prC->FillRect( TRect( rR.left, rR.top, nBL+1, rR.bottom ) );  // rect. in trend zone without spectrums (before)
  if( nBR < rR.right-1 )
    prC->FillRect( TRect( nBR+1, rR.top, rR.right, rR.bottom ) ); // rect. in trend zone without spectrums (after)

  prBBST->Display( prC, nBL, rR.top, nCh, nBL + lDT, nBR + lDT );
} // ***

//------------------------------------------------------------------------------
void __fastcall trMcSpectrTrendR::GetDataInPoint(int X, int Y, bool bShowPanel)
{
  if (nPX == X && nPY == Y)
    return;
  nPX = X,  nPY = Y;

  int nX1 = 0,                         // left edge of displayed zone
      nX4 = PaintBoxTrends->Width - 1, // right edge of displayed zone
      nX2 = nX1 + LO(),         // beginning of bitmap(s) with color spectrums
      nX3 = nX4 - RO();         // end of bitmap(s) with color spectrums

  long lDT = lBR - nX3;                // coord. in index minus this is coord. in pixels

  int nX2B = MAX(prBBST->F() - lDT, nX2),   // left coord of the first bitmap's spectrum in pixels
      nX3B = MIN(prBBST->T() - lDT, nX3),   // right coord of the last bitmap's spectrum in pixels
      nYT  = HorAxes( PaintBoxTrends->Height, rD.nNmbChOut, 0 ) - nBH/2,  // top line of the first bitmap
      nYB  = HorAxes( PaintBoxTrends->Height, rD.nNmbChOut, rD.nNmbChOut - 1 ) - (nBH/2) + nBH - 1;  // bottom line of the last bitmap

  bool bInside = !( X < nX2B || X > nX3B || Y < nYT || Y > nYB );
  if( !bInside )
  {
    pCurrValueHintW->Hide();
    return;   // mouse is outside the trends area
  }

  PanelInPoint->Visible = bShowPanel;
  if (PanelInPoint->Visible)
    pCurrValueHintW->Hide();

  int nInsideChannel = -1;       // number of channel or -1 if border between bitmaps

  for( short nCh = 0; nCh < rD.nNmbChOut; nCh++ )
  {
    if( nCh )
      nYT = HorAxes( PaintBoxTrends->Height, rD.nNmbChOut, nCh ) - nBH/2; // top line of the curent bitmap

    if( Y >= nYT && Y < nYT + nBH - 1)
    {
      nInsideChannel = nCh;
      break;
    }
  }

  if (bShowPanel)
  {
    int nMdX = (PaintBoxTrends->Width - 1) / 2,
        nMdY = (PaintBoxTrends->Height - 1) / 2,
        nPT  = nMdY - PanelInPoint->Height/2,
        nPL  = nMdX - ((X < nMdX) ? 0 : PanelInPoint->Width);

    PanelInPoint->Top = nPT;  PanelInPoint->Left = nPL;
  }

  PanelTime->Caption = GetTimeString( (long) ((X + lDT)/rSP.rPI.fPixPerSec + 0.5) );

  PanelCEFPerCentHi->Caption = ((AnsiString)PanelCEFPerCentHi->Caption).sprintf("%2d", rSP.rPI.anSEFPercent[0]);
  PanelCEFPerCentLo->Caption = ((AnsiString)PanelCEFPerCentLo->Caption).sprintf("%2d", rSP.rPI.anSEFPercent[1]);

  bool bInsideCSA, bOK = false;
  trMcSTBCurrState rS;

  if (nInsideChannel >= 0)
  {
    int nBHH = prBBST->GetVertCrd( CSA );
    LabelChName->Caption = aasChNames[nInsideChannel];

    bOK = prBBST->GetStateInPoint( X + lDT, nYT + nBH - 1 - Y, nInsideChannel, &rS );
    bInsideCSA = rS.fV > 0.;

    PanelCSAData->Visible = bInsideCSA;
    LabelHz->Visible = bInsideCSA;
    LabelMkvHz->Visible = bInsideCSA;
    PanelRAData->Visible  = !bInsideCSA;
    Label4->Visible = !bInsideCSA;
    Label14->Visible = !bInsideCSA;

    if (bInsideCSA)
      PanelInPoint->Height = 130;
    else
      PanelInPoint->Height = 156;

    if( bOK )
    {
      // values received
      if( bInsideCSA )
      {
        // cursor inside CSA zone
        float fFrq = IND_FLOAT_EDGES(nBHH, rSP.rPI.fFrqF, rSP.rPI.fFrqT, nYT + nBH - 1 - Y);
        PanelFreq->Caption = C_TO_ANSI_STR(PanelFreq->Caption).sprintf("%3.1f", fFrq);
        PanelValue->Caption = C_TO_ANSI_STR(PanelValue->Caption).sprintf("%3.1f", rS.fV);    // value of spectrum for X, Y

        fFrq = IND_FLOAT_EDGES(nBHH, rSP.rPI.fFrqF, rSP.rPI.fFrqT, rS.nMax);
        PanelMaxFrq->Caption = C_TO_ANSI_STR(PanelMaxFrq->Caption).sprintf("%3.1f", fFrq);
        PanelMaxValue->Caption = C_TO_ANSI_STR(PanelMaxValue->Caption).sprintf("%3.1f", rS.fMax);    // value of max for this spectrum

        PanelTotAmp->Caption = C_TO_ANSI_STR(PanelTotAmp->Caption).sprintf("%3.1f", rS.fTotalEnergy);
        PanelSEFFrqHi->Caption = C_TO_ANSI_STR(PanelSEFFrqHi->Caption).sprintf("%3.1f", rS.fSEFHi);
        PanelSEFFrqLo->Caption = C_TO_ANSI_STR(PanelSEFFrqLo->Caption).sprintf("%3.1f", rS.fSEFLo);
        PanelEntropy->Caption = C_TO_ANSI_STR(PanelEntropy->Caption).sprintf("%1.2f", rS.fEntropy);
      }
      else
      {
        // cursor inside RA zone

        // common
        PanelFreq->Caption = IntToStr((int) rS.fRelEnergy);
        if (rS.fAbsEnergy > 0)
          PanelValue->Caption = C_TO_ANSI_STR(PanelValue->Caption).sprintf("%3.1f", rS.fAbsEnergy);
        else
          PanelValue->Caption = "";

        // energy in bands
        TPanel* aprPanels[8];
        aprPanels[0] = Panel2; aprPanels[1] = Panel3;
        aprPanels[2] = Panel4; aprPanels[3] = Panel5;
        aprPanels[4] = Panel6; aprPanels[5] = Panel7;
        aprPanels[6] = Panel8; aprPanels[7] = Panel9;

        for (int nB = 0; nB < rS.nBands; nB++)
        {
          aprPanels[2 * nB]->Caption = C_TO_ANSI_STR(aprPanels[2 * nB]->Caption).
            sprintf("%3.1f", rS.afAbsEn[rS.nBands - nB - 1]);
          aprPanels[2 * nB + 1]->Caption = C_TO_ANSI_STR(aprPanels[2 * nB + 1]->Caption).
            sprintf("%3.1f", rS.afRelEn[rS.nBands - nB - 1] * 100);
        }

        for (int nB = rS.nBands; nB < 4; nB++)
        {
          aprPanels[2 * nB]->Caption = "";
          aprPanels[2 * nB + 1]->Caption = "";
        }

        // ER trend
        Panel10->Caption = C_TO_ANSI_STR(Panel10->Caption).sprintf("%2.2f", rS.afERTrend[0]);
        Panel11->Caption = C_TO_ANSI_STR(Panel11->Caption).sprintf("%2.2f", rS.afERTrend[1]);
        Panel12->Caption = C_TO_ANSI_STR(Panel12->Caption).sprintf("%2.2f", rS.afERTrend[2]);
      }
    }
  }

  if( nInsideChannel < 0 || !bOK )
  {
    // mouse is between channels or error
    if( nInsideChannel < 0 )
      LabelChName->Caption = "";

    PanelFreq->Caption = ""; PanelMaxFrq->Caption = "";
    PanelSEFFrqHi->Caption = ""; PanelSEFFrqLo->Caption = "";
    PanelValue->Caption = ""; PanelMaxValue->Caption = "";
    PanelTotAmp->Caption = ""; PanelEntropy->Caption = "";

    Panel2->Caption = "";  Panel3->Caption = "";
    Panel4->Caption = "";  Panel5->Caption = "";
    Panel6->Caption = "";  Panel7->Caption = "";
    Panel8->Caption = "";  Panel9->Caption = "";
    Panel10->Caption = ""; Panel11->Caption = "";
    Panel12->Caption = "";
  }

  if( !bShowPanel && nInsideChannel >= 0 && bOK )
  {
    // show hint
    AnsiString sHint = bInsideCSA ?
    PadString(PanelFreq->Caption + LabelHz->Caption +
    "  " + PanelValue->Caption + LabelMkvHz->Caption, HINT_STR_LENGTH) :
    PadString(PanelFreq->Caption + LabelPerCent->Caption +
    (PanelValue->Caption.IsEmpty() ? (AnsiString) "" :
      (AnsiString) "  " + PanelValue->Caption + LabelMkv->Caption), HINT_STR_LENGTH);

    pCurrValueHintW->Show(X, Y, sHint.c_str(), PaintBoxTrends);
  }
} // ***

//------------------------------------------------------------------------------
void trMcSpectrTrendR::MoveMarker()
{
  if (bCaptured)
  {
    bool bScrPanel = rSP.rPI.bShowScreenPanel && (lScrPix > 0);
    if(bScrPanel)
    {
      int X, Y;
      GetMouseCoord(PaintBoxTrends, X, Y);

      double fh = 1. / rSP.rPI.fPixPerSec;   // step in time for pixels (in sec.)
      long lHalfScrPix = (rPE.fTScr / (2 * fh)) + 0.5;
      if (X < 0 || Y < 0 ||
        X > PaintBoxTrends->Width ||
        Y > PaintBoxTrends->Height)
      {
        TimerCursor->Enabled = false;
        TimerCursorTimer(NULL);
        bCaptured = false;
        Screen->Cursor = crDefault;
        return;
      }

      long nSigR = rPE.prCallback ? rPE.prCallback->GetRightBorder() / fh :
             2 * PaintBoxTrends->Width;
      if (X >= LO() + lHalfScrPix &&
        X <= MIN(PaintBoxTrends->Width - RO() - lHalfScrPix, nSigR + LO() - lHalfScrPix))
      {
        lMarkerPos = X;
        PanelScreenBorder->Left = lMarkerPos;
      }
    }
  }
} // ***

//---------------------------------------------------------------------------
// Source of externals ------------------------------------------------------
//---------------------------------------------------------------------------

// External | create object for spectral trends displaying -----------------------
trMcSpectrTrend *McCreateSpectrTrend( TWinControl * Parent,  // (In) parent for the TFrameSpectrTrend's child
                                      TWinControl * ButtonsPanel, // (In) panel for buttons
                                      TComponent * Owner,    // (In) owner for the TFrameSpectrTrend's child
                                      TWinControl *pPanelIndicators)
{
  trMcSpectrTrendR * prP = NULL;

  try
  {
    prP = new trMcSpectrTrendR ( NULL, pPanelIndicators );
    prP->Parent = Parent;
    prP->PanelButtons->Parent = ButtonsPanel;
    prP->PanelButtons->Left = 0;
    prP->PanelButtons->Top = 0;
  }
  catch(Exception &e)
  {
    ShowMessage(e.Message);
  }
  catch (...)  { CDELETE( prP ); }

  return (trMcSpectrTrend *)prP;
} // ***

// Code for objects ---------------------------------------------------------
//---------------------------------------------------------------------------

// External | ---------------------------------------------------------------
trMcSpcTrendPrmE::trMcSpcTrendPrmE( void )
{
  fTR = 60.,  fTScr = 20;  // Ot vinta

  nSC1 = clBlue,  nSC2 = clYellow,  nSC3 = clRed;
  nBK1 = clBlack,  nBK2 = (TColor)RGB(CLR_BK2, CLR_BK2, CLR_BK2);   // clGray;

  nSpMaxC1 = clRed;     // color for the max. peak of spectrums (dotted line on background)
  nSpMaxC2 = clGray;    // color for the second peak of spectrums (dotted line on background)
  nSEFColor = clBlack;  // color for SEF trends (dotted line on background)
  nEntropyC = clGreen;  // color of entropy trend
  nTrendsBKC = clWhite; // color for background of trends line (if no background selected,
                        // then the dotted line of color nTrendsBKC is drawn
  // delta
  pBands[0].fFrom = 0.5,  pBands[0].fTo = 3.5,  pBands[0].cColor = ((TColor)0x000000FF);
  // theta
  pBands[1].fFrom = 3.5,  pBands[1].fTo = 8,  pBands[1].cColor = ((TColor)0x00FFFF00);
  // alpha
  pBands[2].fFrom = 8,  pBands[2].fTo = 13,  pBands[2].cColor = clLime;
  // beta
  pBands[3].fFrom = 13,  pBands[3].fTo = 20,  pBands[3].cColor = clYellow;
  nSpcNormColor = clGray;

  nRulerFont = clBlack;
  nRulerBack = clInfoBk;

  TrMcSpTrScalePrm rMcSpTrScalePrm;
  nCSForeC = rMcSpTrScalePrm.nForeC;
  nCSActC = rMcSpTrScalePrm.nActC;
  nCSNActC = rMcSpTrScalePrm.nNActC;

  prCallback = NULL;
} // ***

// External | ---------------------------------------------------------------
void trMcSpcTrendPrmE::SetBandsColors( TColor nASpcNormColor, short nABands,
                     TColor * pnColors, float * pfFrqs)
{
  nSpcNormColor = nASpcNormColor;

  for( short nB=0; nB<nABands; nB++ )
  {
    pBands[nB].cColor = pnColors[nB];
    pBands[nB].fFrom = pfFrqs[nB];
    pBands[nB].fTo = pfFrqs[nB+1];
  }
} // ***

// External | ---------------------------------------------------------------
void trMcSpcTrendPrmE::SetColorScheme(TColor nASC1, TColor nASC2, TColor nASC3)
{ nSC1 = nASC1;   nSC2 = nASC2;   nSC3 = nASC3;    } // ***

// External | ---------------------------------------------------------------
bool trMcSpcTrendPrmE::operator == (const trMcSpcTrendPrmE & rS) const
{
  return (nSC1 == rS.nSC1) && (nSC2 == rS.nSC2) && (nSC3 == rS.nSC3) &&
         (nBK1 == rS.nBK1) && (nBK2 == rS.nBK2) &&
         (nSpMaxC1 == rS.nSpMaxC1) && (nSpMaxC2 == rS.nSpMaxC2) &&
         (nSEFColor == rS.nSEFColor) && (nEntropyC == rS.nEntropyC) &&
         (nTrendsBKC == rS.nTrendsBKC) &&
         (nRulerFont == rS.nRulerFont) &&
         (nRulerBack == rS.nRulerBack) &&
         BOOL_EQ(nSpcNormColor, rS.nSpcNormColor) &&
         !memcmp(pBands, rS.pBands, 4*sizeof(trBand)) &&
         prCallback == rS.prCallback &&
         nCSForeC == rS.nCSForeC &&
         nCSActC == rS.nCSActC &&
         nCSNActC == rS.nCSNActC
         ;
} // ***

// External | ---------------------------------------------------------------
trMcSpcTrendPrmI::trMcSpcTrendPrmI( void )
{
  fPixPerSec = Screen->Width / MC_STD_DEF_LENGTH;
#ifdef ONLY_CSA
  nCSAHeightPerCent = 100;
#else
  nCSAHeightPerCent = MC_STD_DEF_CSA_HPERCENT;
#endif

  fFrqF = MC_STD_FRQBAND_MIN,   fFrqT = MC_STD_FRQBAND_MAX;
  fFrqFS = MC_STD_DEF_MIN_SEF_FRQ,  fFrqToS = MC_STD_DEF_MAX_SEF_FRQ,
  fSSB = MC_STD_DEF_SEF_SMT, fEntSmoothing = MC_STD_DEF_SEF_SMT;
  anSEFPercent[0] = MC_DEF_CEF_PERCENT_1, anSEFPercent[1] = MC_DEF_CEF_PERCENT_2;
  nTransform = SqrRoot;

  fScaleMax = 150.,   fScaleSens = 100.;   // mkV**2 / Hz
  fScaleSensR = MC_STD_DEF_MAX_AMP/2.,
  fScaleSensMaxR = MC_STD_MAX_MAX_AMP/2.,  fScaleSensMinR = MC_STD_DEF_MIN_AMP/2.;   // mkV (normal, not peak-to-peak) P-P: < 100, >10
  nSGrades = MC_STD_DEF_NMB_COLORS;
  nSGradesR = MC_STD_DEF_NMB_COLORS; //3; // total 5 colors: less then min (1), small, medium, large (2-4), greater then max (5)
  bDisplayARTrend = false;

  bRulerLeft = true,   bRulerRight = false;
  bBandLeft = true,    bBandRight = false;
  bRARulerLeft = true, bRARulerRight = false;

  abTrends[0] = true,  abTrends[1] = true,   // SEF (Hi & Lo)
  abTrends[2] = true,  abTrends[3] = true,   // Max & Sec. Peak
  abTrends[4] = true;                        // entropy

  arTW[0] = Thick,   arTW[1] = Thick,
  arTW[2] = Thin,    arTW[3] = Medium,
  arTW[4] = Thick;

  bShowScalePanel = true;
  bShowIndicatorsPanel = true;
  abDigitalIndicator[0] = true,   abDigitalIndicator[1] = false;
  abDigitalIndicator[2] = false,  abDigitalIndicator[3] = true;
  abDigitalIndicator[4] = true,   abDigitalIndicator[5] = true;

  bShowSpectrHigherSEF = false;
  bShowScreenPanel = true;

  nDigitalIndicatorBackColor = (TColor)RGB(30, 30, 30);
} // ***

// External | ---------------------------------------------------------------
bool trMcSpcTrendPrmI::operator == (const trMcSpcTrendPrmI & rS) const
{
  return FLOAT_EQ( fPixPerSec, rS.fPixPerSec ) &&
         (nCSAHeightPerCent == rS.nCSAHeightPerCent) &&
         FLOAT_EQ( fFrqF, rS.fFrqF ) && FLOAT_EQ( fFrqT, rS.fFrqT ) &&
         FLOAT_EQ( fFrqFS, rS.fFrqFS ) && FLOAT_EQ( fFrqToS, rS.fFrqToS ) &&
         FLOAT_EQ( fSSB, rS.fSSB ) &&
         FLOAT_EQ( fEntSmoothing, rS.fEntSmoothing ) &&
         FLOAT_EQ(fScaleMax, rS.fScaleMax) && FLOAT_EQ(fScaleSens, rS.fScaleSens) &&
         FLOAT_EQ(fScaleSensR, rS.fScaleSensR) &&
         FLOAT_EQ(fScaleSensMaxR, rS.fScaleSensMaxR) && FLOAT_EQ(fScaleSensMinR, rS.fScaleSensMinR) &&
         (nSGrades == rS.nSGrades) &&  (nSGradesR == rS.nSGradesR) &&
         BOOL_EQ( bDisplayARTrend, rS.bDisplayARTrend ) &&
         anSEFPercent[0] == rS.anSEFPercent[0] &&
         anSEFPercent[1] == rS.anSEFPercent[1] &&
         nTransform == rS.nTransform &&

         BOOL_EQ(bRulerLeft, rS.bRulerLeft) &&
         BOOL_EQ(bRulerRight, rS.bRulerRight) &&
         BOOL_EQ(bRARulerLeft, rS.bRARulerLeft) &&
         BOOL_EQ(bRARulerRight, rS.bRARulerRight) &&
         BOOL_EQ(bBandLeft, rS.bBandLeft) &&
         BOOL_EQ(bBandRight, rS.bBandRight) &&

         BOOL_EQ(abTrends[0], rS.abTrends[0]) &&
         BOOL_EQ(abTrends[1], rS.abTrends[1]) &&
         BOOL_EQ(abTrends[2], rS.abTrends[2]) &&
         BOOL_EQ(abTrends[3], rS.abTrends[3]) &&
         BOOL_EQ(abTrends[4], rS.abTrends[4]) &&
         (arTW[0] == rS.arTW[0]) && (arTW[1] == rS.arTW[1]) &&
         (arTW[2] == rS.arTW[2]) && (arTW[3] == rS.arTW[3]) &&
         (arTW[4] == rS.arTW[4]) &&

         BOOL_EQ(bShowScalePanel, rS.bShowScalePanel) &&
         BOOL_EQ(bShowIndicatorsPanel, rS.bShowIndicatorsPanel) &&
         BOOL_EQ(abDigitalIndicator[0], rS.abDigitalIndicator[0]) &&
         BOOL_EQ(abDigitalIndicator[1], rS.abDigitalIndicator[1]) &&
         BOOL_EQ(abDigitalIndicator[2], rS.abDigitalIndicator[2]) &&
         BOOL_EQ(abDigitalIndicator[3], rS.abDigitalIndicator[3]) &&
         BOOL_EQ(abDigitalIndicator[4], rS.abDigitalIndicator[4]) &&
         BOOL_EQ(abDigitalIndicator[5], rS.abDigitalIndicator[5]) &&

         BOOL_EQ(bShowSpectrHigherSEF, rS.bShowSpectrHigherSEF) &&
         BOOL_EQ(bShowScreenPanel, rS.bShowScreenPanel) &&
         nDigitalIndicatorBackColor == rS.nDigitalIndicatorBackColor;
} // ***

// External | ---------------------------------------------------------------
bool trMcSpcTrendPrmI::AnyTrend()
{
  return
         abTrends[0] ||
         abTrends[1] ||
         abTrends[2] ||
         abTrends[3] ||
         abTrends[4];
}
//---------------------------------------------------------------------------
//  Source of locals --------------------------------------------------------
//---------------------------------------------------------------------------

// Local | Height of a band for a channel ----------------------------------
static int ChHeight( int nH, short nNCh, short nMinD )
{
  int nh = nH / nNCh,
      nd = 0;

  while( (nh > 0) && (nd < nMinD) )
  {
    nh--;

    int nAk = HorAxes( nH, nNCh, 0, nMinD/2 ) - (nh/2),
        nBk = nAk + nh - 1;
    nd = nAk;

    for( short nCh = 1; nCh < nNCh; nCh++ )
    {
      nAk = HorAxes( nH, nNCh, nCh, nMinD ) - (nh/2);
      int ndc = nAk - nBk - 1;
      nd = MIN( nd, ndc );
      nBk = nAk + nh - 1;
    }

    nd = MIN( nd, (nH-1) - nBk );
  }

  return nh;
} // ***

// Local / local | calculate mixture of 3 colors ---------------------------
static double ColorFun( float fX,  // in [0..1] linearily
                        float fY1, float fY2,  // some segment (for fY1 fX is 0, for fY2 fX is 1)
                        float fK ) // smoothing coeff (1. - linear interpolation)
{
  if( fabs(fY1-fY2) < 0.0000001 )
    return (fY1+fY2)*0.5;

  double fW = fX = 0.5 * ( (fX <= 0.5) ? powl(2.*fX,fK) : 2. - powl(2.*(1.-fX),fK) );  // in [0..1]; linearily for fK = 1.

  return  fW*fY2 + (1.-fW)*fY1;
} // ***

// Local | Create array with colors for map & color scale ----------------------
static void SetColors( TColor nC1, TColor nC2, TColor nC3, int nGrd,
                                                    TColor *pnC, double fSmooth)
{
  struct trC
  {
    double fR, fG, fB;
    void Set( TColor nClr )
    { fR = GetRValue(nClr);   fG = GetGValue(nClr);    fB = GetBValue(nClr); }
  } arC[3];

  arC[0].Set(nC1);   arC[1].Set(nC2);   arC[2].Set(nC3);

  for (short nC = 0; nC < nGrd; nC++)
  {
    double fX = IND_FLOAT_EDGES( nGrd, 0., 1., nC ),  // in [0..1]
           fY = (fX <= 0.5) ? 2*fX : 2*(fX-0.5); // in [0..1]; 1- fY is the weight of the edge color
    short nF = (fX <= 0.5) ? 0 : 1;

    pnC[nC] = (TColor)MAKE_RGB(
      ColorFun( fY, arC[nF].fR, arC[nF+1].fR, fSmooth),
      ColorFun( fY, arC[nF].fG, arC[nF+1].fG, fSmooth),
      ColorFun( fY, arC[nF].fB, arC[nF+1].fB, fSmooth)   );
  }
} // ***

// Local - draw rulers ----------------------------------------------------
static void DrawVertRulers( TCanvas *prC1, TCanvas *prC2, TRect rR, TColor nC,
              int nLW, double fA, double fB, double fStep, short nStep )
{
  // fill the canvas with black
  prC1->Brush->Color = clBlack;
  prC1->FillRect(rR);
  prC2->Brush->Color = clBlack;
  prC2->FillRect(rR);

  prC1->Font->Name = "Arial";
  prC1->Font->Size  = 8;
  prC1->Font->Style = TFontStyles() << fsItalic; // << fsBold
  prC1->Font->Color = nC;

  prC2->Font = prC1->Font;
  short nTW = prC1->TextWidth( "55" ) + 2*nLW;
  TRect rR1 = TRect( rR.left + nTW, rR.top, rR.Right, rR.bottom ),
        rR2 = TRect( rR.left, rR.top, rR.Right - nTW, rR.bottom );

  McDrawTRuler( prC1, rR1, nTW, nC, nLW, fA, fB, fStep, nStep, nStep, true );
  McDrawTRuler( prC2, rR2, nTW, nC, nLW, fA, fB, fStep, nStep, nStep, false );
} // ***

// Local - draw colorbar for bands ------------------------------------------
static void DrawBandColumn( TCanvas *prC, TRect rR, TColor cBorder, double fA,
                                         double fB, trBand *pBands, int nBands)
{
  TColor anC[10];
  float afF[10], afT[10],
        fBA = fB - fA;

  for( short nB = 0; nB < nBands; nB++ )
  {
    anC[nB] = pBands[nB].cColor;
    afF[nB] = (pBands[nB].fFrom - fA) / fBA;
    afT[nB] = (pBands[nB].fTo - fA) / fBA;
  }

  McDrawColoredBar( prC, rR, cBorder, 1, anC, nBands, afF, afT );
} // ***

// Local | get time string for seconds --------------------------------------
static AnsiString GetTimeString( long nSeconds, short nTK )
{
  bool bN = nSeconds < 0;
  nSeconds = bN ?  -nSeconds : nSeconds;

  long nHour = nSeconds / 3600,
       nMin  = (nSeconds % 3600) / 60,
       nSec  = nSeconds % 60;
  char s[80];
  if( nTK == 1 )
    sprintf(s, "%02d:%02d:%02d", nHour, nMin, nSec);
  else
    sprintf(s, "%02d:%02d", nHour, nMin);

  AnsiString sTime = s;
  return bN ? "-" + sTime : sTime;
} // ***

// Local | add spaces to bounds of string -----------------------------------
static AnsiString PadString(AnsiString sStr, long nMaxLen)
{
  long nL = sStr.Length();
  for (long i = 0; i < (nMaxLen - nL) / 2; ++i)
    sStr = " " + sStr;
  nL = sStr.Length();
  for (long i = 0; i < nMaxLen - nL; ++i)
    sStr = sStr + " ";

  return sStr;
} // ***

// Update buffer-container for the spectrum trends; display progress bar for long calculations
static bool UpdateBitmapBuffer( long *plF, long *plT, trMcBtmBufSpcTrend *prB, double fUPS )
{
  long lN = prB->N(),  lF = prB->F(),  lT = prB->T(),
       lFN = MAX(*plF, 0),  lTN = MIN(*plT, (lN - 1) + lFN),
       lFP = MAX(lF, lFN),  lTP = MIN(lT, lTN),
       lPT = MAX(lTP - lFP + 1, 0), // time of intersection (pixels)
       lTC = lTN - lFN + 1 - lPT;   // time of segment(s) to be calculated

  double fTC = lTC * prB->G() / fUPS;  // time in seconds corrected for the number of channels

  if( fTC < LONG_SIGNAL_TIME )
    return prB->Update( plF, plT );

  TCursor nCrs = Screen->Cursor;
  Screen->Cursor = crHourGlass;
// !!!  Application->ProcessMessages();
// int nTicks = fTC / (LONG_SIGNAL_TIME / (double) LONG_SIGNAL_TICKS);
#define LONG_SIGNAL_TICKS   4       // number of steps of progress bar to display signal of LONG_SIGNAL_TIME length
  prB->Update( plF, plT );
  Screen->Cursor = nCrs;
  return true;
}

// Local | get absolete mouse coordinates ------------------------------------
static void GetMouseCoord(TControl *pControl, int &X, int &Y)
{
  POINT MousePoint;
  if (GetCursorPos(&MousePoint))
  {
    ::ScreenToClient(pControl->Parent->Handle, &MousePoint);
    X = MousePoint.x - pControl->Left;
    Y = MousePoint.y - pControl->Top;
  }
}
