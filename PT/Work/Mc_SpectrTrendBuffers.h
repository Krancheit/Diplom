/*************************************************************************
  Module
    Cashed buffers used in spectrums' trend (DSA)
  File
     Mc_SpectrTrendBuffers.h

  Modified
    Date      Person		Comment
    ----------------------------------------------------------------------
    28-Aug-16 Larionov V.       Trends displaying changes
    05-Sep-13 Larionov V.       Total changes
    16-Oct-12 Larionov V.       Spectrum trend saving
    22-May-07 Yurovskiy         External trend with any index (0-100) included
    28-Mar-07 Yurovskiy         Cosmetics
    14-Feb-07 Yurovskiy         SEF comments
    29-Jan-07 Yurovskiy         Color for background of CSA trend added
    18-Jan-07 Yurovskiy         Cosmetics
    05-Dec-06 Yurovskiy         Modifications for the trend of AR ratio
    23-Oct-06 Yurovskiy         new fields for SEF added to trMcSTBPrmCSA
    12-Oct-06 Yurovskiy         GetValue() removed, GetStateInPoint() added
    10-Oct-06 Yurovskiy         new version of trend closed
    13-Sep-06 Yurovskiy         container is eredited from base container class in Mc_cashedBuffer.*
    02-Sep-06 Yurovskiy         many modifications; container for bitmap buffers written
    04-Aug-06 Yurovskiy         parameter added for spc. stat. buffer
    28-Jul-06 Yurovskiy         buffer for values of SEF & energy of bands in pixels' points added
    25-Jun-06 Yurovskiy         mean values of energy in given bands included; bitmap buffer modified
    19-Jun-06 Yurovskiy         interface with buffers modified; comments added
    28-Apr-06 Yurovskiy         nMaxSEFPt instead of nMaxPt
    30-Mar-06 Yurovskiy         Scale transformations added
    07-Mar-06 Yurovskiy         Interface  modified
    28-Feb-06 Yurovskiy         Modified
    19-Feb-06 Yurovskiy         Modified
    16-Feb-06 Yurovskiy         Original (extracted from Mc_SpectrTrend.cpp)
*************************************************************************/

#ifndef Mc_SpectrTrendBuffersH
#define Mc_SpectrTrendBuffersH

//---------------------------------------------------------------------------
// Includes -----------------------------------------------------------------
//---------------------------------------------------------------------------
#include <Graphics.hpp>           // Graphics::TBitmap
#include <Mc_CashedBuffers.h>     // trCashedBufferT, trCashedBufferN
#include <Mc_SpectrTrendProc.h>   // trMcSpcTrendProc

//---------------------------------------------------------------------------
// Defines ------------------------------------------------------------------
//---------------------------------------------------------------------------

#define MCSTB_MAX_TRENDS        5    // max. number of trends in container (for now
                                     // there are 2 only: CSA and Rel. Amplitudes)

// Styles for displayin trends ----------------------------------------------
#define MCSTB_DOTTED_TRANSPARENT 0   // dotted line of background color, transparent background
#define MCSTB_DOTTED_THINBK      1   // dotted line of line color, background of 1 pixels' width
#define MCSTB_DOTTED_THICKBK     2   // dotted line of line color, background of 3 pixels' width

#define MCSTB_MAX_BANDS          10  // max. number of frequency bands
#define MCSTB_MAX_INDNAME_LEN    10  // max. length of an external index to be displayed in amp. trends' field

// band schemes
#define MCSTB_BAND_WHOLE         0   // one band [MC_STD_FRQBAND_MIN, MC_STD_FRQBAND_MAX]
#define MCSTB_BAND_STANDART      1   // standart 4 bands (delta, theta, alpha, beta)
#define MCSTB_BAND_MANUAL        2   // manually adjusted bands

// ER trend
#define MC_ER_MAX_TRENDS_NUMBER 3    // max number of ER trends
#define MC_ER_TREND_BANDS_NUM 8      // number of bands (4 standart bands + 4 user bands)

//------------------------------------------------------------------------------
// Types -----------------------------------------------------------------------
//------------------------------------------------------------------------------

// *** Forwards (structs with parameters) --------------------------------------

// Types of trends which may be included in container buffer -------------------
enum trMcSTBTrends { CSA = 0, RelAmp = 1 };  // will include additional trends in future

// Struct with general parameters for the spectrum trends' buffer --------------
struct trMcSTBPrmGen;

// Struct with colored scale used for CSA and rel. amp. bitmap buffers ---------
struct trMcSTBScale;

// Struct with parameters for CSA for the spectrum trends' buffer --------------
struct trMcSTBPrmCSA;

// Struct with parameters for rel. amplitudes for the spectrum trends' buffer --
struct trMcSTBPrmRA;

// Struct with parameters for AR variance ratio trend --------------------------
struct trMcSTBPrmAR;

// Struct with parameters for external indexes to be displayed on amp. trend ---
struct trMcSTBPrmExtInd;

// Struct with output parameters with current state of trent -------------------
struct trMcSTBCurrState;

// callback for progress bar ---------------------------------------------------
struct trMcSTProgressCallback;

// *** Buffer - container of all buffers for spectrum trends -------------------
//------------------------------------------------------------------------------
struct trMcBtmBufSpcTrend : trCashedBufferBmpC
{
  trMcBtmBufSpcTrend( void ) {}
  virtual ~trMcBtmBufSpcTrend( void ) {};

  virtual bool Init( trMcSpcTrendProc * prS,   // (In) Spectral processor - source of input spectrums
                     long nN,                  // (In) Max. number of spectrums in buffers (same for non-interpolated & inperpolated spectrums;
                            // one interpolated spectrum is displayed in one vertical stripe of one pixel width; the
                            // number of non-interpolated spectrums needed to display all nN interpolated spectrums is
                            // less then or equal to nN)
                     trMcSTBPrmGen *prPG,        // (In) general parameters for all trend
                     trMcSTBPrmCSA *prPCSA,      // (In) parameters for CSA
                     trMcSTBScale  *prCSAScale,  // (In) scale configuration for CSA
                                                 // number of colors is prDT->nMax + 1; last color is color of background
                                                 // (if not displaying trend higher than SEF)
                     trMcSTBPrmRA  *prPRA,       // (In) parameters for relative amplitudes
                     trMcSTBScale  *prRAScale,   // (In) scale configuration for rel. amplitudes trend
                                                 // number of colors is prDT->nMax + 4; last 4 colors: (1) top of a stripe, (2) bottom of a stripe,
                                                 // (3) "lower than scale minimum" indicator, (4) "upper than scale maximum" indicator
                                                 // divisors are on top and on bottom of every stripe (width of a stripes includes 2 divisors);
                                                 // there are prPRA->rBG.nNB stripes;
                                                 // data transform is linear for now; any transform satisfying: Y(x) / Y(A)  = Y(x/A), any x, A > 0 (for ex., x**al)
                                                 // may be used (for ex., show energy instead of mean amp.)
                     trMcSTBPrmAR  *prPAR,       // (In) parameters for the AR trend; trend is to displayed on the same bitmap as relative amplitudes
					 trMcSTBPrmExtInd *prPEI = NULL, // (In/Opt) source of external indexes (to be displayed on amp. trend's field)
					 void* pSTBuf = NULL,        // (In/Opt) buffer for ST
					 trMcSTProgressCallback* prClbck = NULL // (In/Opt) callback
                     ) = 0;

  virtual bool Set(  trMcSTBPrmGen *prPG = NULL,   // (In) general parameters for all trend
                     trMcSTBPrmCSA *prPCSA = NULL, // (In) parameters for CSA
                     trMcSTBPrmRA  *prPRA = NULL,  // (In) parameters for relative amplitudes
                     trMcSTBPrmAR  *prPAR = NULL,  // (In) parameters for the AR trend; trend is to displayed on the same bitmap as relative amplitudes
					 trMcSTBPrmExtInd *prPEI = NULL // (In/Opt) source of external indexes (to be displayed on amp. trend's field)
                      ) = 0;

  virtual bool SetScales(
                     trMcSTBScale  *prCSAScale = NULL, // (In) scale configuration for CSA
                     trMcSTBScale  *prRAScale = NULL   // (In) scale configuration for rel. amp. (see comments in Init())
                        ) = 0;

  virtual bool GetStateInPoint( long lX, int lP, int lCh,   // (In) index (time in pixels), point nmb (frq.), channel nmb
                                                        // for lX < 0 all values are for the last computed spectrum
                                                        // for lX >= 0 but out of computed range, or bad parameters,
                                                        // then return value is false, output parameters are undefined
                                trMcSTBCurrState * prS  // (Out) struct with parameters determined by input values;
                                                        // value of lP out of range is legal; in this case, all fields in *prS
                                                        // except fV are filled, fV is -1.
                              ) = 0;

  // !!!!tmp:
  virtual float GetCurrMax( void ) = 0;
  // !!!!tmp:

  virtual double GetERTrendMax( void ) = 0;

  // get vert. coords of a trend
  virtual int GetVertCrd(
                  trMcSTBTrends nTType = CSA,      // (In/Opt) type of trend (CSA, RelAmp, ...)
                  int *pnT = NULL                  // (Out/Opt) top coord. in [0,H], where "H" is height of container
						) = 0;                     // return value: height of the bitmap for the trend "nTType"

  virtual bool SaveSpectrumTrend(                  // save spectrum trend to file
				  long nFrom,                      // (In) left border of saving ST
				  long nTo                         // (In) right border of saving ST
						) = 0;                     // returns false if failed to save
};

// Struct with general parameters for the spectrum trends' buffer --------------
struct trMcSTBPrmGen
{
  double fhH;               // fh / fH, where fh is step in time for pixels' index, fH - same for spectrums' index;
							// must be: fhH <= 1
  int nH;                   // height of zone with bitmap with all trends for one channel

  trMcSTBTrends anT[3];     // which trends are in container (ordered from top to bottom)
  trCashedBufBmpCPrm rCP;   // number of trends in container and how they are placed

  bool operator == ( const trMcSTBPrmGen & );
};

// Forward | Object for data transform (i.e., from spectrums to pixels) --------
struct trMcFIDT; // transformation of non-negative signal to integer scale

// Struct determining a colored scale settings (used in CSA & RA bitmap buffers)-
struct trMcSTBScale
{
  TColor *pnC;              // Colors for colored scale (pointer, not values)
                            // not less then "prDT->nMax" colors (used for scale);
                            // additional colors may be present (for borders, ...)
  trMcFIDT *prDT;           // Scale transform (determines also the number of colors in pnC)
};

// Struct with parameters for CSA for the spectrum trends' buffer --------------
struct trMcSTBPrmCSA
{
  trMcSTBPrmCSA( void );    // sets defaults

  double fFrqF, fFrqTo;     // Frq. band used in interpolated spectrums (should be a subset of total frq. band)
                            // Total frq. band is specified externally
  double fFrqFS, fFrqToS;   // Frq. band to calculate SEF values (should be a subset of frq. band in prS)
  double fSSB;              // SEF smoothing band: if fSSB > 0 then the values of spectrum are smoothed
                            // with rect. window with fSSB width
  double fSLevHi, fSLevLo;  // Values of SEF: assuming that [a..b] is total freq. band for SEF,
                            // freq. "x" is SEF value with level "fL" if total energy of spectrum in [x..b] is "fL" part of
                            // the total energy in [a,b]
  double fEntSmoothing;     // entropy smoothing band

  bool abTrends[5];         // ? display single trends (0 - SEFHi, 1 - SEFLo, 2 - Max, 3 - second peak)
  short anTrendStyles[5];   // styles for displaying trend: 0 - dotted line of background color on transparent background,
                            // 1 - dotted line of line color on solid background, 2 - dotted line of line color on thick (3 pixels) solid background
                            // see defines above
  TColor anTrendColors[6];  // colors for trens' foreground + color for trends' background
  bool bShowSpectrHigherSEF; // ? display CSA for frequencies higher than SEF High value
};

// Struct with parameters for rel. amplitudes for the spectrum trends' buffer --
struct trMcSTBPrmRA
{ // bands of rel. frequencies, in which mean spectrum energy should be calculated
  struct trBands { short nNB; // number of bands
                   float afF[MCSTB_MAX_BANDS], afT[MCSTB_MAX_BANDS]; // beginnings/ends of bands;
                   // are all in [0,1] (corr. to [0,nIP-1]; should be: afF[K] > afT[K]; afF[K+1] >= afT[K])
                   // as real frq. band is [0..F] with unknown F, and energy (i.e. integral) is computed
                   // for the total band being [0..1], the calculated values should be later multiplied by F
                   double fC; // coeff. by which the output values are to be multiplied. It is max. freq. F (see above)
                              // if the orig. values of spectrum are measured in phys. units, or smth. else if not.
                 } rB;

  typedef bool tBandsInGroup[MCSTB_MAX_BANDS];
  struct trBGroups { short nNG;                            // number of bands' groups
                     tBandsInGroup abBG[MCSTB_MAX_BANDS];  // arBG[i][j] is a flag: is band "j" included in the group "i"
                   } rBG;   // for each bands' group the height of the displayed stripe is proportional to
                            // the part of energy for this group with respect to the total energy in ALL bands (not all groups)
                            // the color is the same for all stripes is determined by the value of total amplitude in all bands

  // energy ratio trend (ER trend)

  // bands for ER trend

  bool abDividentBands[MC_ER_TREND_BANDS_NUM];
  bool abDivisorBands[MC_ER_TREND_BANDS_NUM];

  bool abShowERTrend[MC_ER_MAX_TRENDS_NUMBER];        // ? display ER trends
  short anERTrendStyle[MC_ER_MAX_TRENDS_NUMBER];  // style for displaying ER trends:
                            // 0 - dotted line of background color on transparent background,
                            // 1 - dotted line of line color on solid background, 2 - dotted line of line color on thick (3 pixels) solid background
                            // see defines above
  TColor anTrendColors[2];  // colors for trend's foreground + color for trend's background

  double fMaxAmp;           // maximal amplitude of energy ratio visible on trend

  bool bMaxAmpAutoAdjust;   // auto adjust max amplitude

  // misc

  short nBandScheme;        // band scheme (see defines)

  bool bCutAmpTrend;        // flag, if cut amp trend above its part of total energy

  trMcSTBPrmRA();
  bool operator == ( const trMcSTBPrmRA & ) const;
  bool BandsChanged( const trMcSTBPrmRA & ) const;
};

// Struct for color & line style for any 1-dimentional trend -------------------
struct trMcSTB1DTrend
{
  bool bDisplayed;     // ? is this trend currently displayed
  TColor nCB, nCF;     // colors of trend (background, foreground)
  short nStyle;        // styles for displaying trend: 0 - dotted line of background color on transparent background,
                       // 1 - dotted line of line color on solid background, 2 - dotted line of line color on thick (3 pixels) solid background
                       // see defines above
  trMcSTB1DTrend( void ) { bDisplayed = false, nCB = clWhite, nCF = clBlack, nStyle = MCSTB_DOTTED_THICKBK; }
};

// Struct with parameters for AR variance ratio trend --------------------------
struct trMcSTBPrmAR : trMcSTB1DTrend
{
  trMcARVarPrm1 rP1;
  trMcARVarPrm2 rP2;
  trMcSTBPrmAR( void ) { nCF = clWhite; } // !!!
}; // ***

// Struct with parameters for external indexes to be displayed on amp. trend ---
struct trMcSTBPrmExtInd : trMcSTB1DTrend
{
  trMcSpcTrendDataSource * prD[MC_STP_MAX_CHANNELS]; // pointers to sources of each index (some of them may be NULL)
  short nNmbChn;       // number of channels, i.e. possibly non-zero values in prD[] (should be equal to number of channels in spectrum trend)
  double fSampleRate;  // sample rate (1./sec)
  char asName[MCSTB_MAX_INDNAME_LEN];                // string with label ("name") of index (e.g. "BIS")
  // range of index should be modified from 0 to 100; negative values mean that index is absent
  trMcSTBPrmExtInd( void ) { nCF = clYellow, nNmbChn = 0, prD[0] = 0; }
};

// Struct with output parameters with current state of trend in a point --------
struct trMcSTBCurrState
{ // All parameters correspond to some time point; those not determined are set to -1
  // 1. CSA parameters
  float fV;             // Value of spectrum  in some freq. point. Unique parameter
                        // depending upon freq. point. Maybe the unique undefined (set to -1.)
  float fMax;           // Max. of spectrum (mkV**2/Hz)
  int nMax;             // Pos of max of spectrum (in pixels' indexies, frq. 0 is pixel index 0)
  float fSecPeak;       // Value of second peak in spectrum (0. if does not exist)
  int   nSecPeak;       // Pos of second peak (0 if does not exist)
  float fSEFHi, fSEFLo; // SEF (high and low) values, measured in frq. scale
  float fEntropy;       // value of spectrum entropy

  // 2. Parameters for bands' amplitudes (rel. amplitude: 100 * (fAs / fA) %)
  double fRelEnergy;    // relative energy in given point
  double fAbsEnergy;    // absolute energy in given point

  short nBands;                 // Number of bands
  double fTotalEnergy;          // total amplitude in all bands (normal amplitudes, not "peak-peak")
  double afRelEn[MCSTB_MAX_BANDS];  // relative energy for each band
  double afAbsEn[MCSTB_MAX_BANDS];  // absolute energy for each band

  double afERTrend[MC_ER_MAX_TRENDS_NUMBER];  // ER trends
};

// Object for data transform (i.e., from spectrums to pixels) ------------------
//------------------------------------------------------------------------------
struct trMcFIDT // transformation of non-negative signal to integer scale
{
  double fC;       // transform coeff.: value of input curve should be multiplied by this to belong to [0..1]
                   // (i.e., scale sensitivity in non-transformed values)
  int nMax;        // output integer value is original value transformed to scale of "nMax" bins; it is in  0, ..., nMax-1;
                   // last bin contain also all values which are greater then or equal to "nMax"

  virtual double Y( double fX ) { return fX; } // transform from input segment (usually [0..1]) to [0..1]; linear by default
  // Notes:
  // - If scale remains non-transformed (so, bins are not uniform; X() used to calculate bins)
  // - If the scale is transformed (it represents the transformed units, bins are equal)
  // normalized input signal (that is, y = MIN( x * fC, 1 ), x >= 0 - input signal)
  // should be transformed by Y(x): z = Y(y), then multiplied result integer value is
  //  n = [min(z*nMax, nMax-1)], [] - integer part

  virtual double X( double fY ) { return fY; } // inverse transform (used from [0..1] to [0..1], defined for [0,inf] to [0,inf])

  void Set( double fAC, int nAMax ) { fC = fAC,  nMax = nAMax; }
};

// Linear data transform (given interval [min,max] is transformed to [0,1] -----
struct trMcLinearFIDT : trMcFIDT
{
  double fMi, fMa, fR;
  virtual double Y( double fX ) { return (fX - fMi) / fR; } // transform from input segment (usually [0..1]) to [0..1]; linear by default
  virtual double X( double fY ) { return fY*fR + fMi;     } // transform from input segment (usually [0..1]) to [0..1]; linear by default
  void Set( double fAMi, double fAMa, int nAMax )
  { fC = 1.,  nMax = nAMax,  fMi = fAMi,  fMa = fAMa, fR = fMa - fMi; }
};

// Square root data transform --------------------------------------------------
struct trMcSqrFIDT : trMcFIDT
{
  virtual double Y( double fX ); // Y(x) = sqrt( x )
  virtual double X( double fY ); // X(y) = y*y
};

// Log data transform -------------------------------------------------------
struct trMcLogFIDT : trMcFIDT
{
  trMcLogFIDT( void ); // set constants for fK = 5.
  virtual double Y( double fX );   // Y(x) = ln(1 + (exp(fK)-1)*x) / fK;    fK should be in [1..10]
  virtual double X( double fY );   // X(y) = (exp(fK*y) - 1) / (exp(fK) - 1)

  void Set( double fAC, int nAMax, double fK = 5. );

  double fK, fC1, fC2, fC3;  // fC1 is (exp(fK)-1); fC2 is 1/fK; fC3 is 1/fC1 (see comment above)
};

// callback for progress bar ---------------------------------------------------
struct trMcSTProgressCallback
{
  virtual void ShowProgress(int nProgress) = 0; // show progress
};

// External | Creation of the spectr trend buffer -----------------------------
trMcBtmBufSpcTrend * McCreateSpectrTrendBuffer( void );
#endif
