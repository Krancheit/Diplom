/*************************************************************************
  Module
    Cashed buffers used in spectrums' trend (DSA)
  File
     Mc_SpectrTrendBuffers.cpp
*************************************************************************/

//---------------------------------------------------------------------------
// Includes -----------------------------------------------------------------
//---------------------------------------------------------------------------

#include <math.h>

#include "Mc_SpectrTrendBuffers.h"
#include "Mc_SpectrTrendHi.h"
#include "Mc_SpectrTrendStorage.h"

//---------------------------------------------------------------------------
// Defines ------------------------------------------------------------------
//---------------------------------------------------------------------------

#ifndef MAX
  #define MAX( a, b )       ((a) > (b) ? (a) : (b) )
#endif
#ifndef MIN
  #define MIN( a, b )       ((a) < (b) ? (a) : (b) )
#endif
#ifndef CDELETE
  #define CDELETE( a )      { delete a;  a = NULL; }
#endif
#ifndef CDELETE_M
  #define CDELETE_M( a )    { delete[] a;  a = NULL; }
#endif
#ifndef CFREE
  #define CFREE( a )        { free( a );  a = NULL; }
#endif
#ifndef RINT
  #define RINT(a)           (int)( a + ((a > 0.) ? 0.5 : -0.5) )
#endif

// float int. [F1,F2] to pixels [0,...,K-1]:
#define FLOAT_IND( F1, F2, K, x )   (long)( (x>=F2) ? (long)(K-1) : (long)( (K)*(x-F1)/(F2-F1) ) )
#define FLOAT_EQ( a, b )            (fabs((a)-(b)) < 1e-9)
#define BOOL_EQ(a,b)                ( ((a) && (b)) || (!(a) && !(b)) )

#define MALO                1E-7
#define MAX_TREND_THICKNESS 3    // max. thickness of one - dim. trend
#define ADD_CSABUF_PIX      (1 + (MAX_TREND_THICKNESS/2))   // if one-dim. trends are present
                                 // then for CSA we need to have this number of pixels for colored
                                 // spectrums more than is reported by CheckInput()
#define CIRCLE_DOT_LINE_PIX 50   // line with trend begins (if possible) from the nearest left pixel which
                                 // index in CSA buf. is divisible by CIRCLE_DOT_LINE_PIX
#define PNT_HL 2                 // segment of pixels after which high/low color pixels are put in case of high/low signal
#define PNT_HL_SH (PNT_HL/2)

// default ER trends
#define ER_TREND_DEF1_DIVIDENT_BANDS_NUM 1
#define ER_TREND_DEF1_DIVIDENT { 0.5, 3.5 }
#define ER_TREND_DEF1_DIVISOR_BANDS_NUM 1
#define ER_TREND_DEF1_DIVISOR { 0., 20. }

#define ER_TREND_DEF2_DIVIDENT_BANDS_NUM 1
#define ER_TREND_DEF2_DIVIDENT { 8., 13. }
#define ER_TREND_DEF2_DIVISOR_BANDS_NUM 1
#define ER_TREND_DEF2_DIVISOR { 13., 20. }

//---------------------------------------------------------------------------
// Local variables & declaracions of local functions ------------------------
//---------------------------------------------------------------------------

// Local | find max of given array and it's position in array --------------
static float FindMax( float *pfF, int nNmpPoints, int *pnMaxPos );

// Local | find position and (opt) value of the second max. peak in array ---
static short FindSecondPeakPos( float * pfV,      // (In) data array
                                short nM,         // (In) number of points in pfV[]
                                short nMaxPos,    // (In) pos. of max. in pfV[]
                                                  // (In) (needed peak is maximal, but not in "nMaxPos" point)
                                float * pfVal = NULL // (Out/Opt) value of sec. peak
                                ); // Return value: pos. (1, ...,nM-2 of sec. peak; equals 0 if not found)

// Local | find SEF (spectrum edge frequency) point -------------------------
// Given equispaced values of non-negative function f() on [a, b], find a ---
// point y in (a,b) such that the integral for f() over [a, y] should be ----
// equal to given part of integral of f() over the total band [a,b] ---------
static double FindSEF(
              float * pfF,  // (In) array of func. values (should be >= 0, at least one > 0)
              int nN,       // (In) number of points in pfF[]
              double fA, double fB, // (In) segment [a,b]
              double fAl   // (In) this part of integral (should be in (0,1) - see above)
                     ); // Return value: needed point in [fA, fB] (returns "fB + 1" for bad input data (e.g., all zeroes in pfF[])

// Local | find SEF (see above) with optional possibilities --------------------
static double FindSEFExt(
              float * pfF,  int nN,  // (In) array of func values, "nN" points
              double fA, double fB,  // (In) segment for all "nN" values
              double fa, double fb,  // (In) segment inside [fA, fB], in which SEF is to be computed
              double fAl,            // (In) same as in FindSEF()
              double fH = 0.         // (In) length of segment (less than "fB - fA") for averaging values of pfF[] before SEF
                                     // is computed
                     ); // Return value: needed point in [fA, fB] (returns "fB + 1" for bad input data (e.g., all zeroes in pfF[])

// Local | Transform values of a N-points curve to the values of M-points curve,
// calculate max. of all points and it's position and save all it output ----
static void TransformLinearily( // has sence if N <= M or N ~ M
              int nIP,         // (In) number of points in input curve
              float *pfIC,     // (In) input curve ("nIP" values)
              int nOP,         // (In) number of points in output curve
              float *pfDG,     // (Out) output curve ("nOP" values of transformed signal)
              float *pfMax = NULL, // (Out/opt) max. of all values
              int *pnMaxNmb = NULL,// (Out/opt) index on which the max. is achieved
                                   // !! (should not be NULL if pfMax is not NULL)
              int *pnSecMaxNmb = NULL // (Out/opt) index on which the second peak is achieved
                              );     // !! if not NULL then also pfMax & pnMaxNmb should not be NULL
                                     // note: if *pnSecMaxNmb is 0 then the second peak does not exist;
                                     // otherwise *pnSecMaxNmb is in [1,...,nOP-1] (nOP should be >= 3)
                               // then index of this max. in array (as "int"))

// Local | ---------------------------------------------------------------------
// Transform multi-channel array of curves computed in one equi-spaced set  ----
// of time into another multi-channel array computed in another equi-spaced ----
// set of time. Number of values of input & output curves being the same. ------
// At the end of each output curve there are 2 additional values (indexies -----
// of max. and 2-nd peak pos.) -------------------------------------------------
// Values of input curves should be >= 0. Values of output curves are ----------
// as described below ----------------------------------------------------------
static void TransformLinearilyM(
              double fhH,      // (In) input curves are measured in { T(k) = fH*k, k=0, ... }
                               // output curves are measured in { t(j) = fh*j, j=0, ... }; fhH is fh / fH
              long nF, long nT,// (In) output curves are calcutated in t(j), j = nF, ..., nT (nT - nF + 1 curves)
                               // [this requests input curves calculated for T(k), k = K1, ...,K2,
                               //  K1 = [t(nF) / fH], K2 = [t(nT) / fH] + 1, (nK2 - nK1 + 1) input  curves needed)
              int nM,          // (In) input curve consists of "nM" points; output curve consists of "nM + 2" points
              float *pfI,      // (In) input curves (nK2 - nK1 + 1 curves, each of nM points length,
                               // each record with curve being "nISize" bytes)
              long nISize,     // (In) size of one input record (greater than or equal to nM*sizeof(*pfI))
              trMcFIDT *prDT, // (In) how to transform data from input to output
              short *pnO       // (Out) output curves; "nT-nF+1" records of "nM+2" length each:
                               // "nM" values of curve + index of max + index of 2-nd peak (0 if not present)
                               );

// Local | determine boards for pixels given signal boards and timing ----------
static void PixelsBoards(
              double fhH,       // (In) input signal is digitalized in { T(k) = fH*k, k=0, ... }
                                // left boards of pixels are { t(j) = fh*j, j=0, ... }; fhH is fh / fH
              long nF, long nT, // (In) range of time indexies for signal T(j), j = nF, ..., nT
              long *pnf, long *pnt // (Out) boards of pixels: pnf is pixel containing signal point nF,
                                   // pnt is pixel containing signal point nT (signal point is considered to belong
                                   // to a pixel, if it is greater or equal than left board of pixel and less then the
                                   // right board of pixel
                        )   { *pnf = nF / fhH,   *pnt = nF / fhH; }

// Local | determine boards for signal array given pixels' boards and timing ---
static void SignalBoards(
              double fhH,       // (In) input signal is digitalized in { T(k) = fH*k, k=0, ... }
                                // left boards of pixels are { t(j) = fh*j, j=0, ... }; fhH is fh / fH
              long nF, long nT, // (In) range of time indexies for pixels t(j), j = nF, ..., nT
              long *pnf, long *pnt, // (Out) boards of signal points: first is the rightmost before or equal nF,
                                    // last is leftmost after or equal nT
              long *pnF = NULL, long *pnT = NULL // (Out/Opt) pixels which signal points nF and nT belong to
                        )
{
  *pnf = nF * fhH,  *pnt = (long) nT * fhH;
  if( (nT * fhH) - (double)*pnt  > MALO ) (*pnt)++;
  if( pnF && pnT ) PixelsBoards( fhH, *pnf, *pnt, pnF, pnT );
} // ***

// Local | Display one dimentional signal over the needed graphic canvas -------
// Given steps in time for signal points and pixels and integer time indexies --
// for signal ------------------------------------------------------------------
static void Display1DSignal(
              double fhH,       // (In) input signal is digitalized in { T(k) = fH*k, k=0, ... }
                                // left boards of pixels are { t(j) = fh*j, j=0, ... }; fhH is fh / fH
              float *pfS,       // (In) input signal, (nT - nF + 1) values
              long nF, long nT, // (In) range of time indexies for signal points T(j), j = nF, ..., nT
                                // [this meand displaying in pixels range of t(k), k = K1, ...,K2,
                                //  K1 = [nF/fhH], K2 = [nT*fhH])
              double fT,        // (In) transform. coeff. of signal to pixels: ROUND(x*fT) is value in pixels, "x" is signal
              int nL,           // (In) Horizontal shift^ "nL" in abs. coordinates is zero on canvas 
              int nZ,           // (In) zero Y-coord. (i.e. X-axis) of signal in pixels
              TCanvas * prC     // (In) where to display (using current pen style & color)
                           );

#ifdef MMMMMMMMMMMMMMMMM



// Local | ---------------------------------------------------------------------
// Transform single-channel signal to the array of vertical values of pixels' --
// units. Linear interpolation of signal
// linear interpolation
// Transform multi-channel array of curves computed in one equi-spaced set  ----
// of time into another multi-channel array computed in another equi-spaced ----
// set of time. Number of values of input & output curves being the same. ------
// At the end of each output curve there are 2 additional values (indexies -----
// of max. and 2-nd peak pos.) -------------------------------------------------
// Values of input curves should be >= 0. Values of output curves are ----------
// as described below ----------------------------------------------------------
static void TransformLi(
              double fhH,      // (In) input curves are measured in { T(k) = fH*k, k=0, ... }
                               // output curves are measured in { t(j) = fh*j, j=0, ... }; fhH is fh / fH
              long nF, long nT,// (In) output curves are calcutated in t(j), j = nF, ..., nT (nT - nF + 1 curves)
                               // [this requests input curves calculated for T(k), k = K1, ...,K2,
                               //  K1 = [t(nF) / fH], K2 = [t(nT) / fH] + 1, (nK2 - nK1 + 1) input  curves needed)
              int nM,          // (In) input curve consists of "nM" points; output curve consists of "nM + 2" points
              float *pfI,      // (In) input curves (nK2 - nK1 + 1 curves, each of nM points length,
                               // each record with curve being "nISize" bytes)
              long nISize,     // (In) size of one input record (greater than or equal to nM*sizeof(*pfI))
              trMcFIDT *prDT, // (In) how to transform data from input to output
              short *pnO       // (Out) output curves; "nT-nF+1" records of "nM+2" length each:
                               // "nM" values of curve + index of max + index of 2-nd peak (0 if not present)
                               );
#endif

// Local | Calculate appr. value of integral over given band for the set -------
// of values of non-negative function (total band is [0..1]) -------------------
static double CalculateIntegralInBand(
              float *pfIC,        // (In) array of function values
              int nIP,            // (In) number of values in pfIC
              float fF, float fT  // (In) band (in [0..1])
              ); // return value: integral est. or zero for bad parameters

// Local | draw continious trend on some canvas --------------------------------
static void DrawTrendC( TCanvas *prC,                        // (In) on this canvas
                        TPoint * pnP, long lPoints,          // (In) array of points & number of points in it
                        TColor nBkC, TColor nFrC,            // (In) background color, foreground color
                        int nStyle );                        // (In) style of displaying (thick, thin, ... - defines in header)

// Local | draw non-continious trend on some canvas ----------------------------
static void DrawTrendNC( Graphics::TBitmap *prB,             // (In) on this bitmap
                        TPoint * pnP, long lPoints,          // (In) array of points & number of points in it
                        TColor nBkC, TColor nFrC,            // (In) background color, foreground color
                        int nStyle );                        // (In) style of displaying (thick, thin, ... - defines in header)

// Local | calculate spectrum entropy ------------------------------------------
static double CalculateSpectrumEntropy(
                        float* pfSP,          // (In) array with spectrum values
                        int nNP,              // (In) number of points in spectrum
                        float fF, float fT    // (In) band (in [0..1])
                        );

// Local | smooth spectrum -------------------------------------------------
static void SmoothSpectrum(
                        float* pfSB,          // (In) array with spectrum values
                        int nPN,              // (In) number of points in spectrum
                        float* pfSS,          // (Out) smoothed spectrum
                        double fSmBand        // (In) band for smoothing
                        );

//------------------------------------------------------------------------------
// Types -----------------------------------------------------------------------
//------------------------------------------------------------------------------

// *** 1/. Buffer for transformed spectrums ------------------------------------
// These are computed on base of subset of points of normal spectrums ----------
// This buffer is used by trPixBuf & trBtmBufCSA after initialization ----------
//------------------------------------------------------------------------------
struct trSpcBuf : trCashedBufferN
{
  trSpcBuf( void ) : trCashedBufferN() { prS = NULL;  prPCSA = NULL; }

  virtual ~trSpcBuf() {}

  bool Init( long nNSpc,                // (In) max. number of spectrums in buffer,
             int nAG,                   // (In) number of signal channels
             int nAIP,                  // (In) value for nIP (total number of points in input spectrum)
             int nAOP,                  // (In) value nOP (numbers of points in output spectrums)
             double fAMaxFrq,           // (In) value of fMaxFrq ([0..fAMaxFrq] is total frequency band)
             trMcSTBPrmCSA * prAPCSA,   // (In) value of prPCSA
			 trMcSpcTrendProc * prAS,   // (In) spectral processor - source of input spectrums
			 trMcSTBuffer * prASTBuffer // (In) buffer for whole calculated ST
			 );

  virtual void Reset( void ) { if( prPCSA ) SetSecondaryVars(); trCashedBufferN::Reset(); }

  void SetSecondaryVars( void )
  {
    nPF = FLOAT_IND( 0., fMaxFrq, nIP, prPCSA->fFrqF );
    nPT = FLOAT_IND( 0., fMaxFrq, nIP, prPCSA->fFrqTo );
  }

  int nIP,        // total number of points in input spectrum (only subset used)
      nOP;        // total number of points in output spectrum (linear transform of segment [nPF, nPT] of input spectrum)

  double fMaxFrq;          // (In) [0..fAMaxFrq] is total frequency band
  trMcSTBPrmCSA * prPCSA;  // currently used parameters; if modified, Reset() is to be called
  trMcSpcTrendProc * prS;  // trend spectrums' processor (source of input spectrums)

  trMcSTBuffer * prSTBuffer; // buffer for whole calculated ST
  bool bExternalDS;          // flag, if use prSTBuffer instead of calculation

  // Secondary vars (calculated with other parameters)
  int  nPF, nPT;   // input spectrum in this interval of points only is to be used

protected: // ------------------------------------------------------------------
  friend struct trPixBuf;  // lF, lT, ....

  virtual void CheckInput( long *plF, long *plT )
  {
	if (bExternalDS)
	{
	  long lF, lT;
	  prSTBuffer->GetLimits(&lF, &lT);
	  *plF = MAX(*plF, lF);
	  *plT = MIN(*plT, lT);

	  if (*plT <= *plF) *plF = *plT = -1;
	}
	else
	{
	  float *pfS;
	  prS->GetSpectrums( plF, plT, &pfS );
    }
  }

  virtual void Fill( long lFromBufPos, long lFromInd, long lItems );
};

// *** 2/. Buffer for SEF (high & low) and energy in given bands ---------------
//------------------------------------------------------------------------------
struct trSpcStatBuf :  trCashedBufferN
{
  trSpcStatBuf( void ) {  prDT = NULL;  prS = NULL;  prPCSA = NULL; }

  virtual ~trSpcStatBuf() {}

  bool Init( long nN,                   // (In) max. number of spc. statistics' records in buffer
             int nAG,                   // (In) number of signal channels
             int nAIP,                  // (In) value for nIP (total number of points in input spectrum)
             double fAMaxFrq,           // (In) value of fMaxFrq ([0..fMaxFrq] is total frequency band)
             double fAhH,               // (In) value of fhH
             trMcFIDT * prADT,          // (In) value of prDT
             trMcSTBPrmCSA * prAPCSA,   // (In) value of prPCSA
             trMcSTBPrmRA * prAPRA,     // (In) parameters for this trend (bands' groups)
             trMcSpcTrendProc * prAS,   // (In) spectral processor - source of input spectrums
             trMcSTBuffer * prASTBuffer // (In) buffer for whole calculated ST
                        );

  short GetValuesForIndex( // get values of total energy, energies in band, ...
                           long lInd,             // (In) index for which the values are calculated
                           long lCh,              // (In) channel for which the values are calculated
                           double *pfTE = NULL,   // (Out) Value of total energy
                           double *pfTEInt = NULL,// (Out) Value of total energy in frequency
                                                  // interval [MC_STD_FRQBAND_MIN, MC_STD_FRQBAND_MAX]
                           bool bStandartBands = true,  // (In) flag, if output standart or user bands
                           double *pfEng = NULL,  // (Out) Values of energies in all groups of bands
                           short  *pnClrTE = NULL,// (Out) Color index corr. to total amplitude
                           short  *pnClrB = NULL, // (Out) Color indexes corr. to bands' amplitudes
                           double *pfERatio = NULL // (Out) values for energy ratio trend
                                                   // (MC_ER_MAX_TRENDS_NUMBER values)
                          );  // return value: 0 if amplitude in lower than limit, 1 if amplitude is in boards,
                              // 2 if amplitude is higher than limit, -1 if values are not avalilable

  short GetColorInd( double fE );    // get color index by energy value

  // void Update( long *plF, long *plT ); - in trCashedBufferT; also called externally
  int nIP;        // total number of points in input spectrum (only subset used)
  double  fMaxFrq, //[0..fMaxFrq] is total frequency band
          fhH;     // fh / fH, where fh is step in time for pixels' index, fH - same for spectrums' index

  trMcFIDT *prDT;       // config. of data transform to integer scale (e.g. transforms energy to amplitude)
                        // !! note: for now only square root is used; could be any function satisfying:
                        // Y(x) / Y(A)  = Y(x/A), any x, A > 0 (for ex., x**al)
  trMcSTBPrmCSA * prPCSA;      // currently used parameters; if modified, Reset() is to be called
  trMcSTBPrmRA * prPRA;        // parameters RA trend (bands' groups)
  trMcSpcTrendProc * prS;      // trend spectrums' processor (source of input spectrums)

  // bands for ER trend
  int nDividentBands;
  float afDividentFrom[MC_ER_TREND_BANDS_NUM];
  float afDividentTo[MC_ER_TREND_BANDS_NUM];
  int nDivisorBands;
  float afDivisorFrom[MC_ER_TREND_BANDS_NUM];
  float afDivisorTo[MC_ER_TREND_BANDS_NUM];

  trMcSTBuffer * prSTBuffer; // buffer for whole calculated ST
  bool bExternalDS;          // flag, if use prSTBuffer instead of calculation

  // Each record in buffer consists of: SEFHi (1), SEFLo (2),
  // spectral entropy,
  // energies in bands (3, ..., 3 + prSB->rB.nB - 1),
  // total energy of spectrum,
  // energies in 4 standart bands (delta, theta, alpha, beta),
  // energy in interval [MC_STD_FRQBAND_MIN, MC_STD_FRQBAND_MAX],
  // energy for 2 bands for each of MC_ER_MAX_TRENDS_NUMBER energy ratio trends

protected: // ------------------------------------------------------------------
  friend struct trBtmBufCSA;  friend struct trBtmBufRelAmp; // lF, lT, ....
  virtual void CheckInput( long *plF, long *plT );
  virtual void Fill( long lFromBufPos, long lFromInd, long lItems );

  
private:

  void CalculateERBands( void );    // calculate bands for ER trend

  void CalculateBandsGroup(         // calculate group of bands
         bool* pbBandMask,          // (In) bands mask (4 standart and 4 user bands)
         int* pnOutBands,           // (Out) number of output bands (intersection)
         float* pfFrom, float* pfTo // (Out) arrays with bands borders
         );
};

//  *** 3/. Buffer for transformed & linearily interpolated spectrums ----------
// (point <-> pixel)------------------------------------------------------------
//------------------------------------------------------------------------------
struct trPixBuf : trCashedBufferN
{
  trPixBuf() : trCashedBufferN() { prDT = NULL; prSB = NULL; prSSB = NULL; }

  virtual ~trPixBuf() {}

  bool Init( long nN,                      // (In) max. number of spectrums in buffer
             double fAhH, trMcFIDT *prADT, // (In) values of fhH, prDT
             trSpcBuf * prASB,             // (In) source of modified spectrums (calculated in given
                                           // subset of frq. band, number of points being equal to the number of pixels)
			 trSpcStatBuf * prASSB        // (In) source of parameters for SEF
			 );

  // get value of spectrum in needed point for the needed channel
  float GetValue( long lX, int lP, int lCh,           // (In) index (time), point nmb (frq.), channel nmb
                                                      // for lX < 0 all values are for the last computed spectrum
                                                      // for lX >= 0 but out of computed range, or bad parameters,
                                                      // then return value is -1, output parameters are undefined
                  float *pfMax, int *pnMax,           // (Out) max. of spectrum (mkV**2/Hz), point nmb. in which it is
                  float *pfSEFHi, float * pfSEFLo,    // (Out) SEF values (corr. to prSB->fSEFLevelHi, prSB->fSEFLevelLo)
                  float * pfEntropy,                  // (Out) entropy value
                  float *pfSecPeak = NULL,            // (Out/Opt) value of second peak (returned 0. if does not exist)
                  int   *pnSecPeak = NULL );          // (Out/Opt) second peak's pos (0 if does not exist)
                                                      // (Return value) value of spectrum (mkV**2/Hz) in (lX, lP)

  float GetCurrMax( void ) { return fCurrMax; }

  double fhH;       // fh / fH, where fh is step in time for pixels' index, fH - same for spectrums' index
  trMcFIDT *prDT;   // config. of data transform to integer scale
  float fCurrMax;   // maximum of spectrums (units: same as input from spectral processor, mkV**2/Hz)

  trSpcBuf * prSB;  // source of spectrums for this buffer
  trSpcStatBuf * prSSB; // source of parameters for SEF

protected: // ------------------------------------------------------------
  friend struct trBtmBufCSA;    // lF, lT, ....
  virtual void CheckInput( long *plF, long *plT );
  virtual void Fill( long lFromBufPos, long lFromInd, long lItems );
};

// *** 4/. Buffer with bitmap(s) for CSA (based on trPixBuf) -------------------
//------------------------------------------------------------------------------
struct trBtmBufCSA : trCashedBufferBmp
{
  trBtmBufCSA( void );
  virtual ~trBtmBufCSA( void ) { prPCSA = NULL; };

  bool Init( trPixBuf *prAPB,           // (In) value of prPB
             trSpcStatBuf *prASSB,      // (In) value of prSSB
             TColor *pnAC,              // (In) value of pnClr (pointer, not values)
             trMcSTBPrmCSA * prAPCSA,   // (In) value of prPCSA
             trMcSTBPrmExtInd *prAPEI   // (In/Opt) external index to be displayed
             );

  // void Update( long *plF, long *plT ); - in trCashedBufferT; also called externally

  trPixBuf * prPB;           // source of pixels for bitmaps + max. & second max. of spectrums
  trSpcStatBuf * prSSB;      // source of values of SEF

  trMcSTBPrmCSA * prPCSA;    // parameters for CSA (trends, ...); are modified externally
  TColor * pnClr;            // array with colors for spectrums' trend (prPB->nMax+1 elements for colored scale)

  trMcSTBPrmExtInd *prPEI; // external index to be displayed

protected: // ------------------------------------------------------------
  virtual void CheckInput( long *plF, long *plT );
  virtual void Fill( long lFromBufPos, long lFromInd, long lItems );
};

// *** 5/. Buffer with bitmaps for relative amplitudes (based on trSpcBuf)
// Bitmaps contain monochrome stripes; total height of a bitmap is the sum-
// of heights of all stripes. Each stripe represents a group of frq. bands;
// bands are determined in trPixBuf; width of each stripe is proportional -
// to the relative energy for all bands included in it (with certain data -
// transform); the color of each stripe represents the abs. value of this -
// energy -----------------------------------------------------------------
struct trBtmBufRelAmp : trCashedBufferBmp
{
  trBtmBufRelAmp( void ) { prSSB = NULL; }
  virtual ~trBtmBufRelAmp( void ) {};

  bool Init( trSpcStatBuf *prASB,    // (In) source of energy values in bands
             TColor *pnAC,           // (In) value of pnClr (pointer, not values)
             int nHeight,            // (In) height of bitmap
             trMcSTBPrmAR * prAPAR,  // (In) parameters for the AR trend
             trMcARVarProc * prAARP, // (In) processor for the AR trend values
             trMcSTBPrmExtInd *prAPEI // (In/Opt) external index to be displayed
             ); //

  void Set( trMcFIDT *prADT );     // (In) value of prDT

  // void Update( long *plF, long *plT ); - in trCashedBufferT; also called externally

  trSpcStatBuf * prSSB; // source of values of energy in bands

  TColor * pnClr;       // array with colors for colored scale; number of colors is (prDT->nMax + 1) + 2;
                        // last 2 colors are used to divide stripes; each divisor is on top on certain stripe
                        // (i.e., width of a stripe includes divisor on top of it); there are rBG.nNB stripes

  trMcSTBPrmAR  *prPAR; // parameters for the AR residuals trend
  trMcARVarProc *prARP; // processor for calculating the values of the AR residuals trend
  trMcSTBPrmExtInd *prPEI; // external index to be displayed

protected: // ------------------------------------------------------------
  virtual void CheckInput( long *plF, long *plT );
  virtual void Fill( long lFromBufPos, long lFromInd, long lItems );

private:

  int FillColumn(                  // fill column with height and color
                                   // corr. to given energy values
                  double fERatio,  // (In) energy in current band / total energy
                                   // (if < 0 => fill all column)
                  long nI,         // (In) cashed buffer index (for high/low color)
                  short nColInd,   // (In) color index
                  short nHL,       // (In) indicator of high/low value
                  short* pnP,      // (Out) filling array
                  int nP,          // (In) current position in array (must be < nSize)
                  int nSize,       // (In) size of array
                  bool bBorders = true  // (In/Opt) flag, if draw borders of stripe
                  );               // returns number of filled pixels

};

// *** 6. Buffer - container of all buffers for spectrum trends ----------------
//------------------------------------------------------------------------------
struct trMcBtmBufSpcTrendR : trMcBtmBufSpcTrend
{
  trMcBtmBufSpcTrendR( void ) : trMcBtmBufSpcTrend() { prARP = NULL; }
  virtual ~trMcBtmBufSpcTrendR( void ) { Done(); };

  virtual bool Init( trMcSpcTrendProc * prASP,   // (In) Spectral processor - source of input spectrums
                     long nN,                    // (In) Max. number of spectrums in buffers (same for non-interpolated & inperpolated spectrums;
                            // one interpolated spectrum is displayed in one vertical stripe of one pixel width; the
                            // number of non-interpolated spectrums needed to display all nN interpolated spectrums is
                            // less then or equal to nN)
					 trMcSTBPrmGen *prPG,        // (In) general parameters for all trend
                     trMcSTBPrmCSA *prPCSA,      // (In) parameters for CSA
                     trMcSTBScale  *prCSAScale,  // (In) scale configuration for CSA
                     trMcSTBPrmRA  *prPRA,       // (In) parameters for relative amplitudes
                     trMcSTBScale  *prRAScale,   // (In) scale configuration for rel. amplitudes trend
                     trMcSTBPrmAR  *prPAR,       // (In) parameters for the AR trend
					 trMcSTBPrmExtInd *prPEI,    // (In/Opt) source of external indexes (to be displayed on amp. trend's field)
					 void* pSTBuf,               // (In/Opt) buffer for ST
					 trMcSTProgressCallback* prClbck // (In/Opt) callback
					 );

  virtual void Reset( void ) { trCashedBufferBmp::Reset();  rBBR.Reset();  rBBC.Reset(); }

  virtual bool Set(  trMcSTBPrmGen *prPG = NULL,       // (In) general parameters for all trend
                     trMcSTBPrmCSA *prPCSA = NULL,     // (In) parameters for CSA
                     trMcSTBPrmRA  *prPRA = NULL,      // (In) parameters for relative amplitudes
                     trMcSTBPrmAR  *prPAR = NULL,      // (In) parameters for the AR trend
                     trMcSTBPrmExtInd *prPEI = NULL ); // (In/Opt) source of external indexes (to be displayed on amp. trend's field)

  virtual bool Resize( // Resize bitmaps (set new height and (opt) length)
             int nAH,       // (In) new heigt
             long lAN = 0   // (In/Opt) new length (if zero then keep the same length)
                     );

  virtual bool SetScales( trMcSTBScale  *prCSAScale = NULL,  // (In) scale configuration for CSA
                          trMcSTBScale  *prRAScale = NULL ); // (In) scale configuration for rel. amp. (see comments in Init())

  virtual bool GetStateInPoint( long lX, int lP, int lCh,   // (In) index (time), point nmb (frq.), channel nmb
                                                        // for lX < 0 all values are for the last computed spectrum
                                                        // for lX >= 0 but out of computed range, or bad parameters,
                                                        // then return value is false, output parameters are undefined
                                trMcSTBCurrState * prS  // (Out) struct with parameters determined by input values;
                                                        // value of lP out of range is legal; in this case, all fields in *prS
                                                        // except fV are filled, fV is -1.
                              )
   {
     if( !bInitialized || !prS )
       return false;

     short nCSAInd = (rPG.anT[0] == CSA) ? 0 : 1;
     int nB = (rPG.nH - 1) - (anT[nCSAInd] + anH[nCSAInd]  - 1);
     lP -= nB;  // corrected value of frq. pixel index for CSA
     bool bInsideCSA = (lP >= 0) && (lP < anH[nCSAInd]);

     float fV = rPB.GetValue( lX, (bInsideCSA ? lP : 0), lCh,
                   &prS->fMax, &prS->nMax, &prS->fSEFHi, &prS->fSEFLo,
                   &prS->fEntropy,
                   &prS->fSecPeak, &prS->nSecPeak );

     //if( fV < 0. )
     //  return false;

     prS->fV = bInsideCSA ? fV : -1.;

     if( ((lX >= 0) && !((lX >= rSSB.F()) && (lX <= rSSB.T()))) )
     {  prS->nBands = -1; return false; }

     lX = (lX > 0) ? lX : rBBR.T();

     // RA trend data
     double fTotalE = 0.,    // total energy of spectrum
            fEInt   = 0.,    // total energy in given interval
            afE[MCSTB_MAX_BANDS],  // energy in each group of bands
            afERatio[MC_ER_MAX_TRENDS_NUMBER];  // energy ratio

     rSSB.GetValuesForIndex( lX, lCh,
                             &fTotalE, &fEInt,
                             rPRA.nBandScheme == MCSTB_BAND_STANDART,
                             afE, NULL, NULL, prS->afERTrend );

     prS->fTotalEnergy = 2 * sqrt(fTotalE);
     if (rPRA.nBandScheme == MCSTB_BAND_WHOLE)
     {
       prS->nBands = 1;
       prS->afRelEn[0] = fEInt / fTotalE;
       prS->afAbsEn[0] = 2 * sqrt(fEInt);
     }
     else
     {
       prS->nBands = rPRA.nBandScheme == MCSTB_BAND_STANDART ? 4 : rPRA.rBG.nNG;
       for (int nB = 0; nB < prS->nBands; nB++)
       {
         prS->afRelEn[nB] = afE[nB] / fTotalE;
         prS->afAbsEn[nB] = 2 * sqrt(afE[nB]);
       }
     }

     prS->fAbsEnergy = -1;
     long lCursor = lP - anH[nCSAInd],
          lPos = 0;
     for (int nB = 0; nB < prS->nBands; nB++)
     {
       long nNewLvl = lPos + prS->afRelEn[nB] * (rPG.nH - anH[nCSAInd]);
       if (lCursor >= lPos && lCursor < nNewLvl)
       {
         prS->fAbsEnergy = prS->afAbsEn[nB];
         break;
       }

       lPos = nNewLvl;
     }

     prS->fRelEnergy = (double) (lP - anH[nCSAInd]) / (rPG.nH - anH[nCSAInd]) * 100;

     return true;
  }

  virtual float GetCurrMax( void )  { return bInitialized ? rPB.GetCurrMax() : -1.; }
  // !!!!tmp <--

  virtual double GetERTrendMax( void )
  {
    if (rSSB.F() < 0 || rSSB.T() < 0 || rSSB.F() > rSSB.T())
      return -1.;

    double fMax = -1.;

    trMcSpcTrendData *prD;
    prSP->Get( &prD );
    int nBands = rSSB.M() / sizeof(float);
    for (int nCh = 0; nCh < prD->nNmbChOut; nCh++)
    {
      float* pfS = (float*) rSSB.Pos(0, nCh);
      for (long nN = 0; nN < rSSB.T() - rSSB.F(); nN++)
        for (short nERT = 0; nERT < MC_ER_MAX_TRENDS_NUMBER; nERT++)
          if (rPRA.abShowERTrend[nERT])
            fMax = MAX(fMax,
              pfS[nN * nBands + nBands - 2 * (MC_ER_MAX_TRENDS_NUMBER - nERT)] /
              pfS[nN * nBands + nBands - 2 * (MC_ER_MAX_TRENDS_NUMBER - nERT) + 1]);
    }

    return fMax;
  }

  // get vert. coords of a trend
  virtual int GetVertCrd(
                  trMcSTBTrends nTType = CSA,      // (In) type of trend (CSA, RelAmp, ...)
                  int *pnT = NULL                  // (Out) top coord. in [0,H], where "H" is height of container
                        )                          // return value: height of this trend's bitmap
  {
    short nInd = (nTType == rPG.anT[0]) ? 0 : 1;
    if( pnT ) *pnT = anT[nInd];

    if( nInd == 1 && rPG.rCP.nNBB == 1 )
      return 0;

    return anH[nInd];
  }

  virtual bool SaveSpectrumTrend(                  // save spectrum trend to file
				  long nFrom,                      // (In) left border of saving ST
				  long nTo                         // (In) right border of saving ST
						)                          // returns false if failed to save
  {
	prSTBuffer->Save(nTo * rPG.fhH + 1, prCallback);
	rSB.bExternalDS = true;
	rSSB.bExternalDS = true;
	return true;
  }

protected:

  virtual void CheckInput( long *plF, long *plT )   // check boards for input segment & modify them to largest possible
                                                    // boards inside requested boards
  {
    short nCSANmb = (rPG.anT[0] == CSA) ? 0 : 1;
	if (anH[nCSANmb] > 0) rBBC.Update( plF, plT );
	rBBR.Update( plF, plT );
  }


  void Done( void )
  {
	rSB.Done();  rSSB.Done();  rPB.Done();  rBBC.Done();  rBBR.Done();
	CDELETE( prARP );
	trCashedBufferBmp::Done();
    bInitialized = false;
  }

  bool bInitialized;

  trMcSpcTrendProc * prSP;   // Spectrums' processor
  trMcARVarProc * prARP;     // Processor for AR residuals

  // Parameters:
  trMcSTBPrmGen rPG;       // general parameters for all trend
  trMcSTBPrmCSA rPCSA;     // parameters for CSA
  trMcSTBScale  rCSAScale; // colored scale config. for CSA
  trMcSTBPrmRA  rPRA;      // parameters for relative amplitudes
  trMcSTBScale  rRAScale;  // colored scale config. for rel. amplitudes
  trMcSTBPrmAR  rPAR;      // parameters for AR trend
  trMcSTBPrmExtInd rPEI;   // parameters for external indexes

  // Cashed buffers with numerical & bitmap data:
  trSpcBuf       rSB;  // depends upon spectral processor
  trSpcStatBuf   rSSB; // depends upon spectral processor
  trPixBuf       rPB;  // depends upon rSB
  trBtmBufCSA    rBBC; // depends upon rSB, rSSB & rSSB
  trBtmBufRelAmp rBBR; // depends upon rSSB

  // callback
  trMcSTProgressCallback* prCallback;

  // buffer for ST
  trMcSTBuffer* prSTBuffer;
};

//------------------------------------------------------------------------------
// External | Creation of the spectr trend buffer ------------------------------
//------------------------------------------------------------------------------
trMcBtmBufSpcTrend * McCreateSpectrTrendBuffer( void )
{
  try        { return (trMcBtmBufSpcTrend *) (new trMcBtmBufSpcTrendR()); }
  catch(...) { return NULL; }
} // ***


// *** Code for  trMcBtmBufSpcTrendR -------------------------------------------
//------------------------------------------------------------------------------

// Initialization --------------------------------------------------------------
bool trMcBtmBufSpcTrendR::Init( trMcSpcTrendProc * prASP, long nN, trMcSTBPrmGen *prPG,
				   trMcSTBPrmCSA *prPCSA, trMcSTBScale  *prCSAScale, trMcSTBPrmRA  *prPRA,
				   trMcSTBScale  *prRAScale, trMcSTBPrmAR  *prPAR, trMcSTBPrmExtInd *prPEI,
				   void* pSTBuf, trMcSTProgressCallback* prClbck )
{
  if( !prASP || nN < 3 || !prPG || !prPCSA || !prPRA )
	return false;

  if( prPG->rCP.nNBB > 2  ||  prPG->rCP.nNBB <=0 )
	return false;

  Done();

  prSP = prASP;
  trMcSpcTrendData *prD;
  trMcSpcTrendCfg rSTC;
  prSP->Get( &prD, NULL, NULL, &rSTC );

  rPG = *prPG;
  rPCSA = *prPCSA, rCSAScale = *prCSAScale;
  rPRA = *prPRA, rRAScale = *prRAScale;
  rPAR = *prPAR;
  rPEI = (prPEI) ? *prPEI : trMcSTBPrmExtInd();
  prSTBuffer = (trMcSTBuffer*) pSTBuf;
  prCallback = prClbck;

  long nNN = nN + 2*ADD_CSABUF_PIX;

  prARP = McCreateARVarProcProc();

  trMcARVarTrendCfg rARCfg;
  bool bOK = prARP->Init( prD, &rPAR.rP1, &rPAR.rP2, 100, &rARCfg ); // 100 is ot vinta

  long lM = bOK ? (long)((nNN * rPG.fhH*rSTC.lT) / rARCfg.lT) + 1 : 0;

  bOK = bOK ? prARP->Init( prD, &rPAR.rP1, &rPAR.rP2, lM, &rARCfg ) : false;

  bOK = rSB.Init( nNN, prD->nNmbChOut, rSTC.nP, prPG->nH, rSTC.fMaxFrq,
				  &rPCSA, prSP, prSTBuffer );

  bOK = bOK ? rSSB.Init( nNN, prD->nNmbChOut, rSTC.nP, rSTC.fMaxFrq, rPG.fhH,
						 rRAScale.prDT, &rPCSA, &rPRA, prSP, prSTBuffer ) : false;

  bOK = bOK ? rPB.Init( nNN, rPG.fhH, rCSAScale.prDT, &rSB, &rSSB ) : false;

  bOK = bOK ? rBBC.Init( &rPB, &rSSB, rCSAScale.pnC, &rPCSA, &rPEI ) : false;

  bOK = bOK ? rBBR.Init( &rSSB, rRAScale.pnC, prPG->nH, &rPAR, prARP, &rPEI ) : false;

  for( short nT = 0; nT < rPG.rCP.nNBB; nT++ )
	apBB[nT] = (rPG.anT[nT] == CSA) ?  (trCashedBufferBmp *) &rBBC : (trCashedBufferBmp *)&rBBR;

  bOK = bOK ? trCashedBufferBmpC::Init( apBB, &rPG.rCP, nN, rPG.nH ) : false;

  if( !bOK )
	{ Done();  return false; }
  return (bInitialized = true);
} // ***

// Set main parameters (all but scales) ----------------------------------------
bool trMcBtmBufSpcTrendR::Set( trMcSTBPrmGen *prPG, trMcSTBPrmCSA *prPCSA,
           trMcSTBPrmRA *prPRA, trMcSTBPrmAR *prPAR, trMcSTBPrmExtInd *prPEI )
{
  if( !bInitialized )
    return false;

  if( prPAR ) if( !prPAR->bDisplayed && !rPAR.bDisplayed )
  {
    rPAR = *prPAR;
    prPAR = NULL;
  }

  if( prPEI ) if( !prPEI->bDisplayed && !rPEI.bDisplayed )
  {
    rPEI = *prPEI;
    prPEI = NULL;
  }

  if( !prPG && !prPCSA && !prPRA && !prPEI )
    return true;

  // Flags & parameters:
  bool bVResize = false, bHResize = false, bTrends = false, bReInitCSA = false,
       bSEF = false, bBands = false, bPar1 = false, bPar2 = false, bRA = false;

  if( prPG )
  {
    bVResize = (prPG->nH != rPG.nH);                       // height modified
    bHResize = !FLOAT_EQ(prPG->fhH, rPG.fhH);              // length modified

    bTrends  = !(*prPG == rPG) && !bVResize && !bHResize;  // set of trends in container modified
    rPG = *prPG;
    rSSB.fhH = prPG->fhH;  rPB.fhH = prPG->fhH;
  }

  if( prPCSA )
  {
    bReInitCSA = !FLOAT_EQ(prPCSA->fFrqF, rPCSA.fFrqF)     ||
                 !FLOAT_EQ(prPCSA->fFrqTo, rPCSA.fFrqTo);
    bSEF       = !FLOAT_EQ(prPCSA->fFrqFS, rPCSA.fFrqFS)   ||
                 !FLOAT_EQ(prPCSA->fFrqToS, rPCSA.fFrqToS) ||
                 !FLOAT_EQ(prPCSA->fSSB, rPCSA.fSSB)       ||
                 !FLOAT_EQ(prPCSA->fSLevHi, rPCSA.fSLevHi) ||
                 !FLOAT_EQ(prPCSA->fSLevLo, rPCSA.fSLevLo) ||
                 !FLOAT_EQ(prPCSA->fEntSmoothing, rPCSA.fEntSmoothing);
    rPCSA = *prPCSA;
  }

  if( prPRA )
  {
    bBands = rPRA.BandsChanged(*prPRA);

    for (short nB = 0; nB < MC_ER_TREND_BANDS_NUM; nB++)
    {
      bBands = bBands || !FLOAT_EQ(rPRA.abDividentBands[nB], prPRA->abDividentBands[nB]);
      bBands = bBands || !FLOAT_EQ(rPRA.abDivisorBands[nB], prPRA->abDivisorBands[nB]);
    }

    bRA = !(*prPRA == rPRA);
    rPRA = *prPRA;
  }

  if( prPAR )
  {
    bPar1 = !(rPAR.rP1 == prPAR->rP1),  bPar2 = !(rPAR.rP2 == prPAR->rP2);
    rPAR = *prPAR;
  }

  if( prPEI )
    rPEI = *prPEI;

  // Settings & initialization:
  bool bOK = true;

  if( bPar1 || bPar2 )
    bOK = prARP->Set( bPar2 ? &rPAR.rP2 : NULL, bPar1 ? &rPAR.rP1 : NULL );

  if (bRA)
  {
    *(rSSB.prPRA) = rPRA;
    rBBR.Set( rRAScale.prDT );
  }

  if( bVResize || bReInitCSA )
    rSB.Reset();
  if( bHResize || bSEF || bBands || bReInitCSA )
  {
    rSSB.Reset();
  }
  if( bVResize || bReInitCSA || bHResize || bSEF || bBands )
    rPB.Reset();

  if( bVResize || bTrends )
  {
    if( bTrends )
    {
      trCashedBufferBmpC::Set( &rPG.rCP );
      for( short nT = 0; nT < rPG.rCP.nNBB; nT++ )
        apBB[nT] = (rPG.anT[nT] == CSA) ?  (trCashedBufferBmp *) &rBBC : (trCashedBufferBmp *)&rBBR;
    }
    bOK = bOK ? Resize(rPG.nH) : false; // Re-initialize rPB & rSB
  }

  Reset(); // also resets bitmap buffers; needed if trends or smth. else is modified

  return bOK;
} // ***

// Resize vertical values ------------------------------------------------------
bool trMcBtmBufSpcTrendR::Resize( int nAH, long lAN )
{
  rPG.nH = nAH;

  if( !trCashedBufferBmpC::Resize( nAH, lAN ) ) // resize all bitmaps including container
    return false;

  long nNN = lN + 2*ADD_CSABUF_PIX;
  trMcSpcTrendData *prD;
  trMcSpcTrendCfg rSTC;
  prSP->Get( &prD, NULL, NULL, &rSTC );
  short nCSANmb = (rPG.anT[0] == CSA) ? 0 : 1;
  bool bOK = rSB.Init( nNN, lG, rSTC.nP, anH[nCSANmb], rSTC.fMaxFrq,
					   &rPCSA, prSP, prSTBuffer );

  bOK = bOK ? rPB.Init( nNN, rPG.fhH, rCSAScale.prDT, &rSB,
                        &rSSB) : false;
  return bOK;
} // ***

// Set parameters for scales) --------------------------------------------------
bool trMcBtmBufSpcTrendR::SetScales( trMcSTBScale  *prCSAScale,
                                                      trMcSTBScale  *prRAScale )
{
  if( !bInitialized )
    return false;

  if( !prCSAScale && !prRAScale )
    return true;

  bool bOK = true;

  if( prCSAScale )
  {
    rPB.prDT = prCSAScale->prDT;    rPB.Reset();
    bOK = bOK ? rBBC.Init( &rPB, &rSSB, prCSAScale->pnC, &rPCSA, &rPEI ) : false;
    rCSAScale = *prCSAScale;
  }

  if( prRAScale )
  {
    rBBR.Set( prRAScale->prDT );
    rRAScale = *prRAScale;
  }

  Reset();

  return bOK;
} // ***

// Code for  trSpcBuf  ---------------------------------------------------------

//------------------------------------------------------------------------------
bool trSpcBuf::Init( long nNSpc, int ng, int nip,  int nop,  double fAMaxFrq,
							  trMcSTBPrmCSA * prAPCSA, trMcSpcTrendProc * prAS,
							  trMcSTBuffer * prASTBuffer)
{
  nIP = nip,  nOP = nop,  fMaxFrq = fAMaxFrq;
  prPCSA = prAPCSA,   prS = prAS,   prSTBuffer = prASTBuffer;
  SetSecondaryVars();  // calculate nPF, nPT

  bExternalDS = prSTBuffer ? prSTBuffer->IsSaved() : false;

  return trCashedBufferN::Init( nNSpc, (nOP + 3) * sizeof(float), ng );
  // nOP spectrum points + (1)max. value + (2)max. index + (3)sec. peak index
} // ***


//------------------------------------------------------------------------------
void trSpcBuf::Fill( long lFromBufPos, long lFromInd, long lItems )
{ // should be already checked that input spectrums exist

  float *pfS;
  long lToInd = lFromInd + lItems - 1;
  // lFromInd & lToInd should not be modified (checked before)
  if (!bExternalDS) prS->GetSpectrums( &lFromInd, &lToInd, &pfS );
  else prSTBuffer->GetSpectrum( lFromInd, lToInd, &pfS );
  long lIPl   = nPT - nPF + 1, // number of points in input spectrum to be calculated
       lIBPnt = nIP*lG;        // number of points in one input block (spectrums for all channels)

  for( short ng = 0; ng < lG; ng++ )
  {
    float *pfIB  = pfS + nIP*ng;   // first input point for this channel
	for( char *psOB = (char*)Pos( lFromBufPos, ng ), *psE = (char*)Pos( lFromBufPos + lItems, ng ); ;  )
    {
      float *pfOB = (float*)psOB;
      TransformLinearily( lIPl, (pfIB + nPF), nOP, pfOB, pfOB + nOP, (int*)(pfOB+nOP+1), (int*)(pfOB+nOP+2) );

      if( psOB + lM >= psE )
        break;

	  pfIB += lIBPnt,  psOB += lM;
    }
  }
} // ***

// Buffer for SEF (high & low) and energy in given bands -----------------------
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
bool trSpcStatBuf::Init( long nAN, int nAG, int nAIP, double fAMaxFrq,
                         double fAhH, trMcFIDT * prADT, trMcSTBPrmCSA * prAPCSA,
                         trMcSTBPrmRA * prAPRA, trMcSpcTrendProc * prAS,
                         trMcSTBuffer * prASTBuffer)
{
  nIP = nAIP,  fMaxFrq = fAMaxFrq,  fhH  = fAhH,  prDT = prADT;  prPCSA = prAPCSA;
  nDividentBands = nDivisorBands = 0;
  prPRA = prAPRA,   prS = prAS; prSTBuffer = prASTBuffer;
  CalculateERBands();
  bExternalDS = prSTBuffer ? prSTBuffer->IsSaved() : NULL;
  return trCashedBufferN::Init( nAN, (9 + prPRA->rB.nNB + 2 * MC_ER_MAX_TRENDS_NUMBER) * sizeof(float), nAG );
  // Each record in buffer consists of: SEFHi (1), SEFLo (2),
  // spectral entropy,
  // energies in bands (3, ..., 3 + prSB->rB.nB - 1),
  // energies in 4 standart bands (delta, theta, alpha, beta),
  // total energy of spectrum,
  // energy in interval [MC_STD_FRQBAND_MIN, MC_STD_FRQBAND_MAX],
  // energy for 2 bands for each of MC_ER_MAX_TRENDS_NUMBER energy ratio trends
} // ***

//------------------------------------------------------------------------------
void trSpcStatBuf::CheckInput( long *plF, long *plT )
{
  long lkf = (*plF)*fhH,      // left point for spectrums' index
       lkt = (*plT)*fhH + 1;  // right point for spectrums' index

  float *pfS;
  if (!bExternalDS) prS->GetSpectrums( &lkf, &lkt, &pfS );
  else prSTBuffer->GetLimits(&lkf, &lkt);
  double fW = (lkf / fhH);
  long lW = fW,  lkf_ = lW*fhH,
       lNF = lW + ((lkf_ < lkf) ? 1 : 0),
       lNT = (lkt / fhH);

  if( (lkf < 0) || (lkt <= lkf) || (lNT < lNF) )
  { // nothing may be computed
    *plF = *plT = -1;
    return;
  }

  *plF = MAX( *plF, lNF );    // these boards may be achieved
  *plT = MIN( *plT, lNT );    // these boards may be achieved
} // ***

//------------------------------------------------------------------------------
void trSpcStatBuf::Fill( long lFromBufPos, long lFromInd, long lItems )
{
  if (trCashedBufferN::F() < 0 &&
      trCashedBufferN::T() < 0)
    // reseted
    CalculateERBands();

  for( short ng = 0; ng < lG; ng++ )
  {
    long lK = lFromInd;
    for( char *psOB = (char*)Pos(lFromBufPos, ng), *psE = (char*)Pos(lFromBufPos + lItems - 1, ng); ;  )
    {
      double ftkH = (lK++) * fhH;  // time point for pixel lK divided by step in time for spectrums
      long lJ = ftkH;              // index of last spectrum before "lK" point in pixels' scale
      double fD = ftkH - lJ;       // value in [0..1] determining interpolation
      float *pfOB = (float*)psOB;

      long lP1 = lJ, lP2 = lP1 + 1;  float *pfS;
      // lFromInd & lToInd should not be modified (checked before)
      if (!bExternalDS) prS->GetSpectrums( &lP1, &lP2, &pfS );
      else prSTBuffer->GetSpectrum( lP1, lP2, &pfS );

      if (!pfS)
        break;

      float * pfS1 = pfS + (ng*nIP),          // left spectrum
            * pfS2 = pfS1 + (lG*nIP),         // right spectrum
            * pfSB = new float[nIP],
            * pfSS = prPCSA->fEntSmoothing > MALO ? new float[nIP] : NULL;
      for( int nI = 0; nI < nIP; nI++ )
        pfSB[nI] = pfS1[nI] + fD*(pfS2[nI] - pfS1[nI]);

      double fA = 0., fB = fMaxFrq,  fa = prPCSA->fFrqFS, fb = prPCSA->fFrqToS;

      // SEFi
      pfOB[0] = (float) FindSEFExt( pfSB, nIP, fA, fB, fa, fb, prPCSA->fSLevHi, prPCSA->fSSB );
      pfOB[1] = (float) FindSEFExt( pfSB, nIP, fA, fB, fa, fb, prPCSA->fSLevLo, prPCSA->fSSB );

      // entropy
      if (pfSS)
        // smooth spectrum
        SmoothSpectrum(pfSB, nIP, pfSS, prPCSA->fEntSmoothing / fMaxFrq);

      pfOB[2] = CalculateSpectrumEntropy( pfSS ? pfSS : pfSB, nIP, 0., 1.);

      // user bands
      for( short nB = 0; nB < prPRA->rB.nNB; nB++ )
      {
        double fI = prPRA->rB.fC *
                    CalculateIntegralInBand( pfSB, nIP,
                    prPRA->rB.afF[nB] / fMaxFrq, prPRA->rB.afT[nB] / fMaxFrq );
        *(pfOB + 3 + nB) = fI;
      }

      // standart bands
      trMcSpcTrendPrmE rPrm;
      for( short nB = 0; nB < 4; nB++ )
      {
        double fI = prPRA->rB.fC *
                    CalculateIntegralInBand( pfSB, nIP,
                    rPrm.pBands[nB].fFrom / fMaxFrq, rPrm.pBands[nB].fTo / fMaxFrq );
        *(pfOB + 3 + prPRA->rB.nNB + nB) = fI;
      }

      // total energy
      double fI = prPRA->rB.fC *
                    CalculateIntegralInBand( pfSB, nIP, 0, MC_STD_MAX_FRQ / fMaxFrq);
      *(pfOB + 7 + prPRA->rB.nNB) = fI;

      // energy in band [MC_STD_FRQBAND_MIN, MC_STD_FRQBAND_MAX]
      fI = prPRA->rB.fC *
             CalculateIntegralInBand( pfSB, nIP,
             MC_STD_FRQBAND_MIN / fMaxFrq, MC_STD_FRQBAND_MAX / fMaxFrq );
      *(pfOB + 8 + prPRA->rB.nNB) = fI;

      // energy for ER trends

      for (short nERT = 0; nERT < MC_ER_MAX_TRENDS_NUMBER; nERT++)
      {
        // ER trend bands
        int nDividentB, nDivisorB;
        float afDividentF[MC_ER_TREND_BANDS_NUM], afDividentT[MC_ER_TREND_BANDS_NUM],
              afDivisorF[MC_ER_TREND_BANDS_NUM], afDivisorT[MC_ER_TREND_BANDS_NUM];
        switch(nERT)
        {
          case 0:
          {
            nDividentB = ER_TREND_DEF1_DIVIDENT_BANDS_NUM;
            nDivisorB = ER_TREND_DEF1_DIVISOR_BANDS_NUM;
            float afTmp_Divident[] = ER_TREND_DEF1_DIVIDENT;
            float afTmp_Divisor[] = ER_TREND_DEF1_DIVISOR;
            memcpy( afDividentF, afTmp_Divident, nDividentB * sizeof(float) );
            memcpy( afDividentT, afTmp_Divident + nDividentB, nDividentB * sizeof(float) );
            memcpy( afDivisorF, afTmp_Divisor, nDivisorB * sizeof(float) );
            memcpy( afDivisorT, afTmp_Divisor + nDivisorB, nDivisorB * sizeof(float) );
            break;
          }

          case 1:
          {
            nDividentB = ER_TREND_DEF2_DIVIDENT_BANDS_NUM;
            nDivisorB = ER_TREND_DEF2_DIVISOR_BANDS_NUM;
            float afTmp_Divident[] = ER_TREND_DEF2_DIVIDENT;
            float afTmp_Divisor[] = ER_TREND_DEF2_DIVISOR;
            memcpy( afDividentF, afTmp_Divident, nDividentB * sizeof(float) );
            memcpy( afDividentT, afTmp_Divident + nDividentB, nDividentB * sizeof(float) );
            memcpy( afDivisorF, afTmp_Divisor, nDivisorB * sizeof(float) );
            memcpy( afDivisorT, afTmp_Divisor + nDivisorB, nDivisorB * sizeof(float) );
            break;
          }

          case 2:
          {
            nDividentB = nDividentBands;
            nDivisorB = nDivisorBands;
            memcpy( afDividentF, afDividentFrom, nDividentB * sizeof(float) );
            memcpy( afDividentT, afDividentTo, nDividentB * sizeof(float) );
            memcpy( afDivisorF, afDivisorFrom, nDivisorB * sizeof(float) );
            memcpy( afDivisorT, afDivisorTo, nDivisorB * sizeof(float) );
            break;
          }
        }

        fI = 0;
        for (short nB = 0; nB < nDividentB; nB++)
          fI += prPRA->rB.fC *
                CalculateIntegralInBand( pfSB, nIP, afDividentF[nB] / fMaxFrq, afDividentT[nB] / fMaxFrq );
        *(pfOB + 9 + prPRA->rB.nNB + nERT * 2) = fI;

        fI = 0;
        for (short nB = 0; nB < nDivisorB; nB++)
          fI += prPRA->rB.fC *
                CalculateIntegralInBand( pfSB, nIP, afDivisorF[nB] / fMaxFrq, afDivisorT[nB] / fMaxFrq );
        *(pfOB + 10 + prPRA->rB.nNB + nERT * 2) = fI;
      }

      if (pfSB) delete[] pfSB;
      if (pfSS) delete[] pfSS;

      if( psE == psOB )
        break;
      psOB += lM;
    }
  }
} // ***

//------------------------------------------------------------------------------
short trSpcStatBuf::GetValuesForIndex( long lI, long lCh, double* pfTE, double *pfTEInt, bool bStandartBands,
                                       double *pfEng, short *pnClrTE, short* pnClrB, double *pfERatio )
{
  if( lI < lF || lI > lT )
    return -1;

  int nBands = (lM / sizeof(float)) - 3;  // number of frq. bands (including total energies and
                                          // energies for energy ratio trend)
  float * pfI = (float*) Pos( lI - lF, lCh ) + 3; // beginning of the band

  // total energy
  double fETotal = 0.,
         fEInt = 0.;

  fETotal = pfI[nBands - 2 - 2 * MC_ER_MAX_TRENDS_NUMBER];
  fEInt = pfI[nBands - 1 - 2 * MC_ER_MAX_TRENDS_NUMBER];

  if ( pfTE )
    *pfTE = fETotal;
  if ( pfTEInt )
    *pfTEInt = fEInt;
  if ( pfERatio )
    for (int nERT = 0; nERT < MC_ER_MAX_TRENDS_NUMBER; nERT++)
      pfERatio[nERT] = pfI[nBands - 2 * (MC_ER_MAX_TRENDS_NUMBER - nERT) + 1] > MALO ?
                       pfI[nBands - 2 * (MC_ER_MAX_TRENDS_NUMBER - nERT)] /
                       pfI[nBands - 2 * (MC_ER_MAX_TRENDS_NUMBER - nERT) + 1] : 0.;

  // old code: colors of amplitudes out of limits removed for now
  double fAmp = (fETotal > MALO) ? 2. * sqrt(fETotal)  : 0.;
  double fW = prDT->Y( prDT->fC * fAmp );
  bool bLow = fW < 0., bHigh = fW > 1.;   // flag: value of total amplitude out of limit

  if( pnClrTE )
    *pnClrTE = GetColorInd(fETotal);

  if( pfEng ) // Energies in each group of bands
  {
    if (bStandartBands)
    {
      for( short nB = 0; nB < 4; nB++ )
      {
        pfEng[nB] = pfI[nB + prPRA->rB.nNB];
        if (pnClrB)
          pnClrB[nB] = GetColorInd(pfEng[nB]);
      }
    }
    else
    {
      for( short nBG = 0; nBG < prPRA->rB.nNB; nBG++ )
      {
        double fEx = 0;
        for( short nB = 0; nB < prPRA->rB.nNB; nB++ )
          if( prPRA->rBG.abBG[nBG][nB] ) fEx += pfI[nB];  // total energy in this group of bands
        pfEng[nBG] = fEx;

        if (pnClrB)
          pnClrB[nBG] = GetColorInd(fEx);
      }
    }
  }

  return bLow ? 0 : bHigh ? 2 : 1;
} // ***

//------------------------------------------------------------------------------
short trSpcStatBuf::GetColorInd( double fE )
{
  double fAmp = (fE > MALO) ? 2. * sqrt(fE)  : 0.,
         fW = prDT->Y( prDT->fC * fAmp );

  fW *= (double) prDT->nMax;
  long lMax = prDT->nMax - 1,      // output value for colored scale: 0, ..., lMax (index of scale's bin)
       lW = MAX(fW, 0.);

  return (short) (MIN(lW, lMax));  // index of color of stripes
} // ***

//------------------------------------------------------------------------------
void trSpcStatBuf::CalculateERBands( void )
{
  // divident bands
  CalculateBandsGroup(prPRA->abDividentBands, &nDividentBands, afDividentFrom, afDividentTo);

  // divisor bands
  CalculateBandsGroup(prPRA->abDivisorBands, &nDivisorBands, afDivisorFrom, afDivisorTo);
} // ***

//------------------------------------------------------------------------------
void trSpcStatBuf::CalculateBandsGroup( bool* pbBandMask, int* pnOutBands, float* pfFrom, float* pfTo )
{
  *pnOutBands = 0;

  int nBandInd1 = 0,
      nBandInd2 = 0;

  trMcSpcTrendPrmE rPrmE;

  // divident bands
  while(nBandInd1 < 4 || nBandInd2 < 4)
  {

    while (!pbBandMask[nBandInd1] &&
           nBandInd1 < 4)
      nBandInd1++;

    while (!pbBandMask[nBandInd2 + 4] &&
           nBandInd2 < 4)
      nBandInd2++;

    // process standart interval #nBandInd1 and user interval #nBandInd2

    bool bUseBand1 = false,
         bUseBand2 = false;
    if (nBandInd1 < 4 && nBandInd2 < 4)
    {
      // both exist
      bUseBand1 = rPrmE.pBands[nBandInd1].fFrom < prPRA->rB.afF[nBandInd2];

      // if intersection?
      if ( bUseBand1 && prPRA->rB.afF[nBandInd2] < rPrmE.pBands[nBandInd1].fTo ||
          !bUseBand1 && prPRA->rB.afT[nBandInd2] > rPrmE.pBands[nBandInd1].fFrom)
      {
        // make one of some

        float fL = MIN( rPrmE.pBands[nBandInd1].fFrom, prPRA->rB.afF[nBandInd2] ),
              fR = MAX( rPrmE.pBands[nBandInd1].fTo, prPRA->rB.afT[nBandInd2] );
        
        bool bAdd1 = false,
             bAdd2 = false;

        do
        {
          if (bAdd1)
          {
            fR = MAX( fR, rPrmE.pBands[nBandInd1 + 1].fTo );
            nBandInd1++;
          }

          if (bAdd2)
          {
            fR = MAX( fR, prPRA->rB.afT[nBandInd2 + 1] );
            nBandInd2++;
          }
            
          bAdd1 = nBandInd1 < 3 && rPrmE.pBands[nBandInd1 + 1].fFrom <= fR;
          bAdd2 = nBandInd2 < 3 && prPRA->rB.afF[nBandInd2 + 1] <= fR;
        }
        while(bAdd1 || bAdd2);

        // add megaintersect interval
        pfFrom[*pnOutBands]   = fL;
        pfTo[(*pnOutBands)++] = fR;

        nBandInd1++;
        nBandInd2++;
        
        bUseBand1 = bUseBand2 = false;
      }
      else
        // use first
        bUseBand2 = !bUseBand1;
    }
    else if (nBandInd1 < 4)
      // use standart band
      bUseBand1 = true;
    else if (nBandInd2 < 4)
      // use user band      
      bUseBand2 = true;

    if (bUseBand1)
    {
      // use standart band      
      pfFrom[*pnOutBands]   = rPrmE.pBands[nBandInd1].fFrom;
      pfTo[(*pnOutBands)++] = rPrmE.pBands[nBandInd1++].fTo;           
    }
    else if (bUseBand2)
    {
      // use user band
      pfFrom[*pnOutBands]   = prPRA->rB.afF[nBandInd2];
      pfTo[(*pnOutBands)++] = prPRA->rB.afT[nBandInd2++];
    }
  }

} // ***

// Code for  trPixBuf  ------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
bool trPixBuf::Init( long nW, double fAhH, trMcFIDT *prADT,
                     trSpcBuf * prASB, trSpcStatBuf * prASSB)
{
  prSB = prASB;  prSSB = prASSB;
  fhH = fAhH;   prDT = prADT;  fCurrMax = 0.;

  return trCashedBufferN::Init( nW, (prSB->nOP + 2) * sizeof(short), prSB->G() );
} // ***

//---------------------------------------------------------------------------
void trPixBuf::CheckInput( long *plF, long *plT )
{
  long lkf = (*plF)*fhH,      // left point for spectrums' index
       lkt = (*plT)*fhH + 1;  // right point for spectrums' index

  prSB->Update( &lkf, &lkt );
  double fW = (lkf / fhH);
  long lW = fW,  lkf_ = lW*fhH,
       lNF = lW + ((lkf_ < lkf) ? 1 : 0),
       lNT = (lkt / fhH);

  if( (lkf < 0) || (lkt <= lkf) || (lNT < lNF) )
  { // nothing may be computed
	*plF = *plT = -1;
	fCurrMax = 0.;
	return;
  }

  *plF = MAX( *plF, lNF );    // these boards may be achieved
  *plT = MIN( *plT, lNT );    // these boards may be achieved

  // compute max. for all values in [*plF, *plT]:
  fCurrMax = 0.;
  for( long lg = 0; lg < prSB->lG; lg++ ) // max. for spectrums inside pixels' interval
  {
    for( long lm = lkf + 1 - prSB->lF; lm < lkt - prSB->lF; lm++ )
    {
	  float fM = *( ((float*)prSB->Pos( lm, lg )) +  prSB->nOP);
      if( fCurrMax < fM ) fCurrMax = fM;
    }

    // max. for the left edge:
    float fML1 = *( ((float*)prSB->Pos( lkf     - prSB->lF, lg )) +  prSB->nOP),
          fML2 = *( ((float*)prSB->Pos( lkf + 1 - prSB->lF, lg )) +  prSB->nOP),
          fML  = fML1 + (fML2 - fML1)*( (*plF)*fhH - lkf ),
          fMR1 = *( ((float*)prSB->Pos( lkt - 1 - prSB->lF, lg )) +  prSB->nOP),
          fMR2 = *( ((float*)prSB->Pos( lkt     - prSB->lF, lg )) +  prSB->nOP),
          fMR  = fMR1 + (fMR2 - fMR1)*( (*plT)*fhH - (lkt-1) ),
          fM   = MAX( fML, fMR );
	if( fCurrMax < fM ) fCurrMax = fM;
  } // for channels
} // ***

//---------------------------------------------------------------------------
void trPixBuf::Fill( long lFromBufPos, long lFromInd, long lItems )
{ // should be already checked that input spectrums exist

  long lK1 = lFromInd * fhH,                   // time index of the first input curve
       lSpPnt = lM / sizeof( short ),          // number of points in one record in this buffer
       lSSBPnt = prSSB->M() / sizeof( float ), // number of points in spc. stat. buffer's record (first two points are SEF)
       nOP = prSB->nOP;

  double fA = prSSB->prPCSA->fFrqF,
         fB = prSSB->prPCSA->fFrqTo;

  short *pnBk = new short[nOP];
  for( int nI = 0;  nI < nOP;  nI++ ) pnBk[nI] = prDT->nMax;
  short nCIL = prDT->nMax + 1, nCIH = prDT->nMax + 2;

  for( short ng = 0; ng < lG; ng++ )
  {
    short *pnS = (short*)Pos( lFromBufPos, ng );                   // beginning of record of spectrum and max. values for needed pos. & channel

    TransformLinearilyM( fhH, lFromInd, lFromInd + lItems - 1, nOP,
                         (float*)prSB->Pos(lK1 - prSB->lF, ng), prSB->lM,
                         prDT, pnS );

    float *pfSEF = (float*)prSSB->Pos( lFromInd - prSSB->F(), ng ); // beginning of record with SEF values

    for( long nP = 0;  nP < lItems; nP++ )
    {
      if( !prSB->prPCSA->bShowSpectrHigherSEF )
      {
        int nYS = FLOAT_IND( fA, fB, nOP, (*pfSEF) ),
            nPS = nYS + 1;  nPS = MAX(nPS, 1);
        if( nPS <= nOP - 1 )
          memcpy( pnS + nPS, pnBk, (nOP - nPS)*(sizeof(*pnS)) );
      }

      // todo
      int nI = nP + lFromInd;
      short nHL = prSSB->GetValuesForIndex( nI, ng );
      bool bLow = (nHL == 0),  bHigh = (nHL == 2);
      if( bLow || bHigh ) // Amplitude out of limit
        for( short nPP = 0; nPP < nOP; nPP++ )
        {
          short nPHL = (nI%2) ? nPP : nPP + PNT_HL_SH;
          if( !(nPHL % PNT_HL) )
            pnS[nPP] = bLow ? nCIL : nCIH;
        }

      if( nP < lItems - 1 )
        pnS += lSpPnt, pfSEF += lSSBPnt;
    }
  }
  delete[] pnBk;
} // ***

// get value of spectrum in needed point for the needed channel -----------
float trPixBuf::GetValue( long lX, int lP, int lCh, float *pfMax, int *pnMax,
                 float *pfSEFHi, float * pfSEFLo, float * pfEntropy,
                 float *pfSecPeak, int*pnSecPeak )
{
  // (lX - in index crd., lP - number of point in array)
  if( (lF < 0 || lT < 0) ||
      ((lX >= 0) && !((lX >= lF) && (lX<=lT))) ||
      !((lP >=0) && (lP < prSB->nOP)) )
    return -1.;

  if( lX < 0 ) lX = lT;

  double fX1 = lX * fhH; // time in spectrums' time scale (vectors' numbers)
  long lX1  = (long)fX1,
       lPos = lX1 - prSB->lF;
  float fD = fX1 - lX1;

  float *pfB1 = (float*)prSB->Pos( lPos, lCh ),
        *pfB2 = (float*)prSB->Pos( lPos + 1, lCh ),
        *pfB = new float[prSB->nOP];
  for( int nI = 0; nI < prSB->nOP; nI++ )
    pfB[nI] = pfB1[nI] + fD*(pfB2[nI] - pfB1[nI]);

  *pfMax = FindMax( pfB, prSB->nOP, pnMax );
  float fSP;   int nSPP;
  if( pfSecPeak || pnSecPeak ) nSPP = FindSecondPeakPos( pfB, prSB->nOP, *pnMax, &fSP );
  if( pfSecPeak ) *pfSecPeak = fSP;
  if( pnSecPeak ) *pnSecPeak = nSPP;

  float fVal = pfB[lP];
  delete [] pfB;

  if( lX < prSSB->F() || lX > prSSB->T()  )
    *pfSEFHi = *pfSEFLo = -1.;
  else
  {
    pfB1 = (float*) prSSB->Pos( lX - prSSB->F(), lCh );
    *pfSEFHi = pfB1[0],  *pfSEFLo = pfB1[1],
    *pfEntropy = pfB1[2];
  }

  return fVal;
} // ***

// Code for  trBtmBufCSA  ------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
trBtmBufCSA::trBtmBufCSA( void ) : trCashedBufferBmp()
{
  prPB = NULL; prPCSA = NULL;
} // ***

//------------------------------------------------------------------------------
bool trBtmBufCSA::Init( trPixBuf *prAPB,  trSpcStatBuf *prASSB,  TColor *pnAC,
                        trMcSTBPrmCSA * prAPCSA, trMcSTBPrmExtInd *prAPEI )
{
  if( !prAPB )
    return false;  // not complete check ... may not be present at all

  Done();
  prPB = prAPB,  prSSB = prASSB, prPEI = prAPEI;

  if( !trCashedBufferBmp::Init( prPB->N() - 2*ADD_CSABUF_PIX, prPB->G(), prPB->prSB->nOP, pf32bit ) )
    return false;

  pnClr = pnAC;
  prPCSA = prAPCSA;
  return true;
} // ***

//---------------------------------------------------------------------------
void trBtmBufCSA::CheckInput( long *plF, long *plT )
{
  *plF = MAX( *plF - ADD_CSABUF_PIX, 0 );
  *plT += ADD_CSABUF_PIX;
  prSSB->Update( plF, plT );
  prPB->Update( plF, plT );
  *plF += ADD_CSABUF_PIX;
  *plT -= ADD_CSABUF_PIX;
} // ***

//------------------------------------------------------------------------------
void trBtmBufCSA::Fill( long lFromBufPos, long lFromInd, long lItems )
{
  long lSpPnt = prPB->lM / sizeof( short ),         // number of points in pixels' spectrum record (same as prBm[??]->Height + 2)
       lSSBPnt = prSSB->lM / sizeof( float ),       // number of points in spc. stat. buffer's record (first two points are SEF)
       lFF = MAX(prSSB->lF, prPB->lF), lTT = MIN(prSSB->lT, prPB->lT),
       nPntBefore = MIN(lFromInd - lFF, ADD_CSABUF_PIX),
       lToInd     = lFromInd + lItems - 1,
       nPntAfter  = MIN(lTT - lToInd, ADD_CSABUF_PIX),
       nNTrendPnt = lItems + nPntBefore + nPntAfter + 1, // number of points in trend (first one - before first pixel (if any), last - after last)
       nFTrendPnt = lFromBufPos - nPntBefore;            // first index inside buffer for trend displaying

  long nFFTP = lFromInd - nPntBefore;  // if possible, move first trend point to the first left point divisible by CIRCLE_DOT_LINE_PIX
  while( nFFTP % CIRCLE_DOT_LINE_PIX ) nFFTP--;
  if( nFFTP >= lFF )
  {
    nPntBefore = lFromInd - nFFTP;
    nNTrendPnt = lItems + nPntBefore + nPntAfter + 1;
    nFTrendPnt = lFromBufPos - nPntBefore;
  }

  TColor *pnCl = new TColor[lItems];
  TPoint * pnPM   = prPCSA->abTrends[2] ?  new TPoint[nNTrendPnt] : NULL,
         * pnPM1  = prPCSA->abTrends[3] ?  new TPoint[nNTrendPnt] : NULL,
         * pnPMS  = prPCSA->abTrends[0] ?  new TPoint[nNTrendPnt] : NULL,
         * pnPMS1 = prPCSA->abTrends[1] ?  new TPoint[nNTrendPnt] : NULL,
         * pnEnt  = prPCSA->abTrends[4] ?  new TPoint[nNTrendPnt] : NULL;

  double fA = prSSB->prPCSA->fFrqF,   // freq. segment (for calculating 1-dim. trends in pixels)
         fB = prSSB->prPCSA->fFrqTo;

  double fhHI;
  long lIF, lIT, lIItems;  // indexies for trend of external indexes (from, to, how many)
  float *pfEIS = NULL;

  if( prPEI->bDisplayed )
  {
    trMcSpcTrendCfg rSTC;
    trMcSpcTrendData *prD;
    prPB->prSB->prS->Get( &prD, NULL, NULL, &rSTC );
    fhHI = prSSB->fhH * ( ((double) rSTC.lT / prD->nSampRate ) * prPEI->fSampleRate );
    SignalBoards( fhHI, lFromInd - nPntBefore, lToInd + nPntAfter, &lIF, &lIT );
    // trend is displayed for each channel separately; it may not exist
    // for some channels; boards are also not controlled (it is displayed what is possible to display)

    //lIF /= fhHI; lIT /= fhHI;

    lIItems = lIT - lIF + 1;
    pfEIS = new float [lIItems];
  }

  for( int ng = 0; ng < lG; ng++ )
  {
    Graphics::TBitmap *prB = pprBM[ng];
    short *pnS = (short*)prPB->Pos( lFromInd - prPB->lF, ng ); // beginning of record of spectrum and max. values for needed pos. & channel

    // 1. draw trend itself
    for( int nl = 0; nl < prB->Height; nl++ )
    {
      short * pnSR = pnS + nl;
      for( TColor *pnC = pnCl, *pnE = pnC + lItems - 1;  ;  )
      {
        *pnC = pnClr[ *pnSR ];
        if( pnC == pnE )
          break;
        pnSR += lSpPnt;  pnC++;
      }
      memcpy( ((DWORD *) prB->ScanLine[prB->Height - nl -1]) + lFromBufPos, pnCl, sizeof(DWORD)*lItems );
    }

    if( prPCSA->abTrends[0] || prPCSA->abTrends[1] || prPCSA->abTrends[2] ||
        prPCSA->abTrends[3] || prPCSA->abTrends[4] )
    { // 2. Draw max., second peak lines, SEF and entropy values
      short *pnMax = ((short*) prPB->Pos( lFromInd - prPB->lF - nPntBefore, ng )) + lSpPnt - 2;
      float * pfSEF = (float*) prSSB->Pos( lFromInd - prSSB->lF - nPntBefore, ng ); // beginning of record with SEF values

      for( long nP = 0, nIP = nFTrendPnt;  nP < nNTrendPnt; nP++, nIP++ )
      {
        if( pnPM )
          pnPM[nP] = TPoint( nIP, prB->Height - pnMax[0] - 1 ); // (X,Y) - coord. of max
        if( pnPM1 )
          pnPM1[nP] = TPoint( nIP, prB->Height - pnMax[1] - 1); // (X,Y) - coord. of the 2-nd peak; X = 0: not displayed

        int anY[2];
        for( short nS = 0; nS < 2; nS++ )
          anY[nS] = FLOAT_IND( fA, fB, prB->Height, pfSEF[nS] );

        int nEntropy = FLOAT_IND( 0., 1., prB->Height, pfSEF[2] );;

        if( pnPMS )
          pnPMS[nP] = TPoint( nIP, prB->Height - anY[0] - 1 );  // (X,Y) - coord. of SEF1
        if( pnPMS1 )
          pnPMS1[nP] = TPoint( nIP, prB->Height - anY[1] - 1);  // (X,Y) - coord. of SEF2
        if( pnEnt )
          pnEnt[nP] = TPoint( nIP, prB->Height - nEntropy - 1); // (X,Y) - coord. of entropy

        if( nP < nNTrendPnt - 2 )
          pnMax += lSpPnt, pfSEF += lSSBPnt;  // point after last point: Y-axis - the same as for the last point, if nPntAfter is 0
      }

      // draw trends
      DrawTrendC( prB->Canvas, pnPM, nNTrendPnt,   prPCSA->anTrendColors[5],
                  prPCSA->anTrendColors[2], prPCSA->anTrendStyles[2] );
      DrawTrendNC( prB, pnPM1, nNTrendPnt,         prPCSA->anTrendColors[5],
                   prPCSA->anTrendColors[3], prPCSA->anTrendStyles[3] );
      DrawTrendC( prB->Canvas, pnPMS1, nNTrendPnt, prPCSA->anTrendColors[5],
                  prPCSA->anTrendColors[1], prPCSA->anTrendStyles[1] );
      DrawTrendC( prB->Canvas, pnPMS, nNTrendPnt,  prPCSA->anTrendColors[5],
                  prPCSA->anTrendColors[0], prPCSA->anTrendStyles[0] );
      DrawTrendC( prB->Canvas, pnEnt, nNTrendPnt,  prPCSA->anTrendColors[5],
                  prPCSA->anTrendColors[4], prPCSA->anTrendStyles[4] );
    }

    if( !prPEI->bDisplayed || !prPEI->prD[ng] )
      continue;

    // Display trend of external indexes
    prPEI->prD[ng]->CheckBoards( &lIF, &lIT );  // check if there is signal in [*plF, *plT]
    lIItems = lIT - lIF + 1;
    long lHM = 0;

    short * pnEIS = prPEI->prD[ng]->Get( lIF, lIItems, &lHM );
    // !!! to be modified: not display negative values
    if( pnEIS && (lHM == lIItems) )
    {
      for( int nP = 0; nP < lIItems;  nP++ ) pfEIS[nP] = pnEIS[nP];
      prB->Canvas->Pen->Color = prPEI->nCF;
      Display1DSignal( fhHI, pfEIS, lIF, lIT, (prB->Height-1)/100., lFromInd - lFromBufPos, prB->Height-1, prB->Canvas );
    }

  } // for( int ng ...)

  delete[] pnCl;
  CDELETE_M( pnPM ); CDELETE_M( pnPM1 ); CDELETE_M( pnPMS ); CDELETE_M( pnPMS1 );
} // ***

// *** Buffer with bitmaps for relative energy (amplitudes) (based on trSpcBuf)
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
bool trBtmBufRelAmp::Init( trSpcStatBuf *prASB, TColor *pnAC, int nHeight,
             trMcSTBPrmAR * prAPAR, trMcARVarProc * prAARP, trMcSTBPrmExtInd *prAPEI )
{
  if( !prASB )
    return false;

  prSSB = prASB,  pnClr = pnAC,  prPAR = prAPAR;
  prARP = prAARP, prPEI = prAPEI;

  return trCashedBufferBmp::Init( prSSB->N() - 2*ADD_CSABUF_PIX, prSSB->G(), nHeight, pf32bit );
} // ***

//---------------------------------------------------------------------------
void trBtmBufRelAmp::CheckInput( long *plF, long *plT )
{
  prSSB->Update( plF, plT );

  if( !((*plF >=0 ) && (*plF <= *plT)) || !prPAR->bDisplayed )
    return;

  *plF = MAX( *plF - ADD_CSABUF_PIX, 0 );
  *plT += ADD_CSABUF_PIX;

  trMcSpcTrendCfg rSTC;
  prSSB->prS->Get( NULL, NULL, NULL, &rSTC );
  trMcARVarTrendCfg rARCfg;
  prARP->Get( NULL, NULL, NULL, &rARCfg );
  double fhHA = prSSB->fhH * ( (double) rSTC.lT / (double) rARCfg.lT );
  long lAF = *plF * fhHA,
       lAT = (*plT * fhHA) + 1;
  float *pfDta; prARP->GetARTrend( &lAF, &lAT, &pfDta );
  // !! trend for external index is not checked (it is displayed if it is)

  *plF += ADD_CSABUF_PIX;
  *plT -= ADD_CSABUF_PIX;
} // ***

//------------------------------------------------------------------------------
void trBtmBufRelAmp::Set( trMcFIDT *prADT ) { prSSB->prDT = prADT;  Reset(); }

//------------------------------------------------------------------------------
void trBtmBufRelAmp::Fill( long lFromBufPos, long lFromInd, long lItems )
{
  long lToInd = lFromInd + lItems - 1,
       nPntBefore = ADD_CSABUF_PIX,  // ?? probably to be modified
       nPntAfter  = ADD_CSABUF_PIX;

  int nH = pprBM[0]->Height;
  trMcSTBPrmRA *prP = prSSB->prPRA;
  trMcFIDT * prDT = prSSB->prDT;

  TColor *pnCl = new TColor[lItems];

  short *pnPx = new short[(nH + 1) * lItems];

  TPoint *apnERTrend[MC_ER_MAX_TRENDS_NUMBER];    // energy ratio trend
  for (int nERT = 0; nERT < MC_ER_MAX_TRENDS_NUMBER; nERT++)
   apnERTrend[nERT] = new TPoint[lItems];

  // Variables for 1-dim. trends (initialized only if a trend is displayed)
  trMcSpcTrendCfg rSTC;
  trMcSpcTrendData *prD;
  trMcARVarTrendCfg rARCfg;
  double fhHA, fhHI;
  long lAF, lAT, lAItems;  // indexies for AR trend (from, to, how many)
  long lIF, lIT, lIItems;  // indexies for trend of external indexes (from, to, how many)
  float *pfARDta, *pfARS = NULL, *pfEIS = NULL;

  bool bCut = prP->bCutAmpTrend;

  prSSB->prS->Get( &prD, NULL, NULL, &rSTC );

  if( prPAR->bDisplayed )
  {
    prARP->Get( NULL, NULL, NULL, &rARCfg );
    fhHA = prSSB->fhH * ( (double) rSTC.lT / (double) rARCfg.lT );

    SignalBoards( fhHA, lFromInd - nPntBefore, lToInd + nPntAfter, &lAF, &lAT );
    prARP->GetARTrend( &lAF, &lAT, &pfARDta ); // trend in last point may not exist
    lAItems = lAT - lAF + 1;
    pfARS = new float [lAItems];
  }

  if( prPEI->bDisplayed )
  {
    fhHI = prSSB->fhH * ( ((double) rSTC.lT/prD->nSampRate ) * prPEI->fSampleRate );
    SignalBoards( fhHI, lFromInd - nPntBefore, lToInd + nPntAfter, &lIF, &lIT );
    // trend is displayed for each channel separately; it may not exist
    // for some channels; boards are also not controlled (it is displayed what is possible to display)

    //lIF /= fhHI; lIT /= fhHI;

    lIItems = lIT - lIF + 1;
    pfEIS = new float [lIItems];
  }

  for( int ng = 0; ng < lG; ng++ )
  {
    Graphics::TBitmap *prB = pprBM[ng];
    short *pnP = pnPx;

    for( long nI = lFromInd; nI <= lToInd; nI++ )
    {
      double fTotalE = 0.,    // total energy of spectrum
             fEInt   = 0.;    // total energy in given interval
      double afE[MCSTB_MAX_BANDS];  // energy in each group of bands
      double afERatio[MC_ER_MAX_TRENDS_NUMBER];  // energy ratio
      short nCIS,   // index of color of stripes
            anECIS[MCSTB_MAX_BANDS],  // indexes of color of each bands
            nBands = prP->nBandScheme == MCSTB_BAND_STANDART ? 4 : prP->rBG.nNG,
            nHL = prSSB->GetValuesForIndex( nI, ng, &fTotalE, &fEInt,
                                            prP->nBandScheme == MCSTB_BAND_STANDART,
                                            afE, &nCIS, anECIS, afERatio );
      bool bHigh = (nHL == 2),  bLow = (nHL == 0);

      for (int nERT = 0; nERT < MC_ER_MAX_TRENDS_NUMBER; nERT++)
        apnERTrend[nERT][nI - lFromInd] = TPoint( lFromBufPos + nI - lFromInd,
                                                  nH - FLOAT_IND( 0., prP->fMaxAmp, nH, afERatio[nERT] ) );

      double fBH = 0.;
      short nCIT = prDT->nMax,   nCIB = prDT->nMax+1,  // indexes of border colors (top, bottom)
            nCIL = prDT->nMax+2, nCIH = prDT->nMax+3;  // indexes of colors for values out of limit
      int nStrT;  // top of stripe in pixels (is the top of the last stripe on exit of the next cycle)

      if (prP->nBandScheme == MCSTB_BAND_WHOLE)
      {
        // one stripe corr. to fEInt
        fBH = (fTotalE > MALO) ? fEInt / fTotalE : 0;
        nStrT = FillColumn(bCut ? fBH : -1, nI, nCIS, nHL, pnP, 0, nH );
      }
      else
      {
        // multiple stripes corr. to afE[]
        short nPStrT = -1;
        short nBandIndex = 0;
        for( short nBG = 0; nBG < nBands; nBG++ )
        {
          while (prP->nBandScheme == MCSTB_BAND_MANUAL &&
                 !prP->rBG.abBG[nBandIndex][nBandIndex] &&
                 nBandIndex < MCSTB_MAX_BANDS)
            nBandIndex++;

          if (nBandIndex == MCSTB_MAX_BANDS)
            // oops...
            break;

          // Determine position (height & top) of the stripe nBandIndex:
          fBH += (fTotalE > MALO) ? afE[nBandIndex] / fTotalE : 0;  // stripes all equal for zero energy
          nStrT = FillColumn(fBH, nI, anECIS[nBandIndex], nHL, pnP, nPStrT+1, nH );
          nPStrT = nStrT;
          nBandIndex++;
          if( nStrT == nH-1 )
            break;
        }

        if (!bCut)
        {
          // last stripe for energy remnant
          double fRemnEnergy = fTotalE;
          nBandIndex = 0;
          for( short nBG = 0; nBG < nBands; nBG++ )
          {
            while (prP->nBandScheme == MCSTB_BAND_MANUAL &&
                 !prP->rBG.abBG[nBandIndex][nBandIndex] &&
                 nBandIndex < MCSTB_MAX_BANDS)
              nBandIndex++;

            if (nBandIndex == MCSTB_MAX_BANDS)
              // oops...
              break;

            fRemnEnergy -= afE[nBandIndex++];
          }

          if (fRemnEnergy > MALO)
          {
            fBH += (fTotalE > MALO) ? fRemnEnergy / fTotalE : 0;
            nStrT = FillColumn(fBH, nI, prSSB->GetColorInd(fRemnEnergy), nHL, pnP, nPStrT+1, nH );
          }
        }
      }

      // all above RA trend
      FillColumn( -1, nI, nCIB, nHL, pnP, nStrT + 1, nH, false );

      if( nI < lToInd )
        pnP += nH;
    }

    for( int nl = 0; nl < nH; nl++ )
    {
      short * pnP = pnPx + nl;
      for( TColor *pnC = pnCl, *pnE = pnC + lItems - 1; ;  pnC++, pnP += nH )
      {
        *pnC = pnClr[ *pnP ];
        if( pnC == pnE )
          break;
      }
      memcpy( ((DWORD *) prB->ScanLine[nH-nl-1]) + lFromBufPos, pnCl, sizeof(DWORD)*lItems );
    }


    for (int nERT = 0; nERT < MC_ER_MAX_TRENDS_NUMBER; nERT++)
      if (prP->abShowERTrend[nERT])
      // display energy ratio trend
      DrawTrendC( prB->Canvas, apnERTrend[nERT], lItems, prP->anTrendColors[1],
                  prP->anTrendColors[0], prP->anERTrendStyle[nERT] );
	/*
    if( prPAR->bDisplayed )
    {
      // Display trend of ratio of AR residuals' variance to signal variance:
      int nARRL = MC_ARTREND_RECLEN * lG,   nARO = MC_ARTREND_RECLEN * ng;
      for( float *pfO = pfARS, *pfI = pfARDta + nARO, *pfE = pfO + lAItems;
                                                  pfO < pfE;  pfI += nARRL )
        *pfO++ = *pfI;

      prB->Canvas->Pen->Color = prPAR->nCF;
      Display1DSignal( fhHA, pfARS, lAF, lAT, (double)nH, lFromInd - lFromBufPos, nH-1, prB->Canvas );
    }
    */

    if( !prPEI->bDisplayed || !prPEI->prD[ng] )
      continue;

    // Display trend of external indexes
    prPEI->prD[ng]->CheckBoards( &lIF, &lIT );  // check if there is signal in [*plF, *plT]
    lIItems = lIT - lIF + 1;
    long lHM = 0;

    short * pnEIS = prPEI->prD[ng]->Get( lIF, lIItems, &lHM );
    // !!! to be modified: not display negative values
    if( pnEIS && (lHM == lIItems) )
    {
      for( int nP = 0; nP < lIItems;  nP++ ) pfEIS[nP] = pnEIS[nP];
      prB->Canvas->Pen->Color = prPEI->nCF;
      Display1DSignal( fhHI, pfEIS, lIF, lIT, (nH-1)/100., lFromInd - lFromBufPos, nH-1, prB->Canvas );
    }
  }

  delete[] pnCl;
  delete[] pnPx;

  for (int nERT = 0; nERT < MC_ER_MAX_TRENDS_NUMBER; nERT++)
    delete[] apnERTrend[nERT];

  if( pfARS ) delete[] pfARS;    if( pfEIS ) delete[] pfEIS;
} // ***

//------------------------------------------------------------------------------
int trBtmBufRelAmp::FillColumn( double fERatio, long nI, short nColInd, short nHL,
                                short* pnP, int nP, int nSize, bool bBorders )
{
  trMcFIDT * prDT = prSSB->prDT;
  short nCIT = prDT->nMax,   nCIB = prDT->nMax+1,  // indexes of border colors (top, bottom)
        nCIL = prDT->nMax+2, nCIH = prDT->nMax+3;  // indexes of colors for values out of limit
  bool bHigh = (nHL == 2),  bLow = (nHL == 0);

  int nHeight = 0;    // height of curr stripe in pixels
  if (fERatio > 0)
    nHeight = FLOAT_IND( 0., 1., nSize, fERatio );
  else
    nHeight = nSize;

  if (bBorders)
    pnP[nP++] = nCIB;  // index of border color (bottom)

  for( short nN = nP; nN < nHeight; nN++ )
  {
    short nPHL = (nI % 2) ? nN : nN + PNT_HL_SH;
    bool bHLC = !(nPHL % PNT_HL);
    pnP[nN] = bHigh && bHLC ? nCIH : bLow &&  bHLC ? nCIL : nColInd;
  }

  if (bBorders)
    pnP[nHeight] = nCIT; // index of border color (top)

  return nHeight;
} // ***

// Code for trMcSTBPrmGen  -----------------------------------------------------

// -----------------------------------------------------------------------------
bool trMcSTBPrmGen::operator == ( const trMcSTBPrmGen &rP )
{
  if( !FLOAT_EQ(fhH, rP.fhH) || nH != rP.nH || rCP.nNBB != rP.rCP.nNBB ||
      rCP.ndH != rP.rCP.ndH || rCP.nDC != rP.rCP.nDC )
    return false;

  for( short nT = 0; nT < rCP.nNBB; nT++ )
    if( anT[nT] != rP.anT[nT] || !FLOAT_EQ(rCP.afRH[nT], rP.rCP.afRH[nT]) )
      return false;

  return true;
} // ***

// Code for parameters' stuctures ----------------------------------------------

// Constructor trMcSTBPrmCSA  --------------------------------------------------
trMcSTBPrmCSA::trMcSTBPrmCSA( void )
{
  fFrqF = 0., fFrqTo = 20.,
  fFrqFS = 0.5,  fFrqToS = fFrqTo,  fSSB = 2., fSLevHi = 0.9,  fSLevLo = 0.5,
  fEntSmoothing = 2.;

  abTrends[0] = abTrends[1] = abTrends[2] = abTrends[3] = abTrends[4] = true;
  anTrendStyles[0] = anTrendStyles[1] = anTrendStyles[4] = MCSTB_DOTTED_THICKBK;
  anTrendStyles[2] = anTrendStyles[3] = MCSTB_DOTTED_TRANSPARENT;
  anTrendColors[0] = anTrendColors[1] = clBlack;
  anTrendColors[2] = clRed;   anTrendColors[3] = clGray;
  anTrendColors[4] = clGreen; anTrendColors[5] = clWhite;
} // ***

// trMcSTBPrmRA ----------------------------------------------------------------
trMcSTBPrmRA::trMcSTBPrmRA()
{
  memset(this, 0, sizeof(trMcSTBPrmRA));

  // standart bands
  trMcSpcTrendPrmE rPrm;
  rB.nNB = 4;
  rBG.nNG = rB.nNB;
  for (int i = 0; i < rB.nNB; i++)
  {
    rB.afF[i] = rPrm.pBands[i].fFrom;
    rB.afT[i] = rPrm.pBands[i].fTo;
    rBG.abBG[i][i] = true;
  }

  // index delta trend
  abDividentBands[0] = true;
  abDivisorBands[2] = abDivisorBands[3] = true;
  nBandScheme = 1;

  // ER trends
  abShowERTrend[0] = true;
  abShowERTrend[1] = false;
  abShowERTrend[2] = false;
  anERTrendStyle[0] = 2;
  anERTrendStyle[1] = 1;
  anERTrendStyle[2] = 0;
  fMaxAmp = 1.;
  bMaxAmpAutoAdjust = true;
}

//------------------------------------------------------------------------------
bool trMcSTBPrmRA::operator == ( const trMcSTBPrmRA & rP ) const
{
  if( anTrendColors[0] != rP.anTrendColors[0] || anTrendColors[1] != rP.anTrendColors[1] ||
      !FLOAT_EQ(fMaxAmp, rP.fMaxAmp) ||
      !BOOL_EQ(bMaxAmpAutoAdjust, rP.bMaxAmpAutoAdjust) ||
      nBandScheme != rP.nBandScheme ||
      !BOOL_EQ(bCutAmpTrend, rP.bCutAmpTrend ) )
    return false;

  // ER trends
  for (short nT = 0; nT < MC_ER_MAX_TRENDS_NUMBER; nT++)
  {
    if (!BOOL_EQ(abShowERTrend[nT], rP.abShowERTrend[nT]) ||
        anERTrendStyle[nT] != rP.anERTrendStyle[nT])
      return false;
  }

  // ER trends bands
  for (short nB = 0; nB < MC_ER_TREND_BANDS_NUM; nB++)
  {
    if (!BOOL_EQ(abDividentBands[nB], rP.abDividentBands[nB]) ||
        !BOOL_EQ(abDivisorBands[nB], rP.abDivisorBands[nB]))
      return false;
  }

  return !BandsChanged(rP);
} // ***

//------------------------------------------------------------------------------
bool trMcSTBPrmRA::BandsChanged( const trMcSTBPrmRA & rP ) const
{
  if( rB.nNB != rP.rB.nNB || !FLOAT_EQ(rB.fC, rP.rB.fC) || rBG.nNG != rP.rBG.nNG)
    return true;

  for( int nb = 0; nb < rB.nNB; nb++ )
    if( !FLOAT_EQ(rB.afF[nb], rP.rB.afF[nb]) || !FLOAT_EQ(rB.afT[nb], rP.rB.afT[nb]) )
      return true;

  for( int nb = 0; nb < rB.nNB; nb++ )
    for( int ng = 0; ng < rBG.nNG; ng++ )
       if( !BOOL_EQ(rBG.abBG[ng][nb], rP.rBG.abBG[ng][nb]) )
         return true;

  return false;
} // ***

// Square root data transform -----------------------------------------------
double trMcSqrFIDT::Y( double fX ) { return (fX > 1e-9) ? sqrt(fX) : 0.; }
double trMcSqrFIDT::X( double fY ) { return fY * fY;  }

// Log data transform -------------------------------------------------------
trMcLogFIDT::trMcLogFIDT( void ) { Set( 1., 100, 5. );  }

void trMcLogFIDT::Set( double fAC, int nAMax, double fAK )
{
  trMcFIDT::Set( fAC, nAMax );
  fK = MAX( fAK, 1 ),  fC1 = exp( fK ) - 1.,  fC2 = 1./fK,  fC3 = 1./fC1;
} // ***

double trMcLogFIDT::Y( double fX ) { return log(1. + fC1*fX) * fC2;  }
double trMcLogFIDT::X( double fY ) { return (exp(fK*fY) - 1.) * fC3; }

//---------------------------------------------------------------------------
// Code of locals -----------------------------------------------------------
//---------------------------------------------------------------------------

// Local | find max of given array and it's position in array --------------
static float FindMax( float *pfF, int nNmbPoints, int *pnMaxPos )
{
  float fM = pfF[0];  int nMP = 0;

  float *pfFF = pfF;
  for( int nP = 1; nP < nNmbPoints; nP++ )
    if( *(++pfFF) > fM )
    {
      fM = *pfFF,  nMP = nP;
    }

  *pnMaxPos = nMP;
  return fM;
} // **

// Local | find position and (opt) value of the second max. peak in array ---
static short FindSecondPeakPos( float * pfV, short nM, short nMaxPos, float *pfVal )
{ // compute second peak position:
  float fA, fB = pfV[0], fC = pfV[1], fPeakVal = 0.;
  short nPeakNmb = 0; // 0 means that it does not exist
  bool bFirst = true;

  for( long nJ = 1; nJ < nM-1; nJ++ )
  {
    fA = fB;   fB = fC;   fC = pfV[nJ+1];
    if( (nJ != nMaxPos) && ((fA < fB) && (fB > fC)) )
    {
      if( bFirst )
      { fPeakVal = fB;  nPeakNmb = nJ;  bFirst = false;  continue; } // initialize with the first peak different from given pos.

      if( fPeakVal < fB )
      {
        fPeakVal = fB;
        nPeakNmb = nJ;
      }
    }
  }

  if( pfVal ) *pfVal = fPeakVal;

  return nPeakNmb;
} // ***

// Local | find SEF (spectrum edge frequency) point ----------------------------
static double FindSEF( float * pfF, int nN, double fA, double fB, double fAl )
{
  if( fAl >= 1. - MALO )
    return fB;

  nN--; // number of points is now nN + 1;  pfF[k], k = 0, ..., nN
  double fH = (fB - fA) / (double)nN;
  double * pfS = new double[nN+1];
  pfS[nN] = pfF[nN];
  for( int nP = nN - 1; nP >= 0; nP-- )
    pfS[nP] = pfS[nP+1] + pfF[nP];

  double fYN = pfF[nN],
         fS0Al = (pfS[0] - 0.5*(pfF[0] + fYN)) * (1. - fAl);

  if( fS0Al < MALO )
  {
    delete [] pfS;
    return fB + 1.;
  }

  int nK = nN;

  for( int nP = nN - 1; nP >= 0; nP-- )
    if( (pfS[nP] - 0.5*(pfF[nP] + fYN) >= fS0Al) || !nP )
    {
      nK = nP + 1;  break;
    }

  double fDl = fS0Al - ((nK == nN) ? 0. : pfS[nK] - 0.5*(pfF[nK] + fYN)),
         fBk = (pfF[nK-1] + pfF[nK]) * 0.5,
         fBt = (fDl <= MALO) ? 1. : (fBk - fDl <= MALO) ? 0. : 1. - fDl/fBk;

  delete [] pfS;

  return fA + (fH * (nK - 1 + fBt));
} // ***

// Local / local | Smooth values of function with rect. window -----------------
static void SmoothRectW(
              float *pfF,  // (In) array with values (nN + 2*nWW values, in [-nNWW, ..., nN -1 + nWW]
              int nN,      // (In) number of values to be smoothed
              int nWW  )   // (In) window width is 2*nWW + 1  points
{
  float * pfFW = (float*) calloc( nN, sizeof(*pfF) );
  double fW = 1. / (2*nWW + 1.);

  for( int nP = 0; nP < nN;  nP++ )
  {
    float *pfFP = pfF + nP;
    double fS = *pfFP;
    for( short nPP = 1; nPP <= nWW; nPP++ )
      fS += (pfFP[-nPP] + pfFP[nPP]);
    pfFW[nP] = fS * fW;
  }

  memcpy( pfF, pfFW, nN * sizeof( *pfF ) );
  free( pfFW );
} // ***

// Local | find SEF (see above) with optional possibilities --------------------
static double FindSEFExt( float * pfF, int nN, double fA, double fB,
                          double fa, double fb, double fAl, double fH )
{
  if( (nN < 2) || (fAl >= 1. - MALO) )
    return fB;

  int nNF  = FLOAT_IND( fA, fB, nN, fa ),
      nNT  = FLOAT_IND( fA, fB, nN, fb ),
      nNS2 = FLOAT_IND( fA, fB, nN, fH/2. );

  nNF = (nNF >= 0 && nNF < nN - 1) ?  nNF : 0;
  nNT = (nNT > nNF && nNT < nN)    ?  nNT : nN - 1;
  int nNN = (nNT - nNF + 1);
  if( nNN < 3 )
    return fB;

  nNS2 = MAX(nNS2, 0);  while( 2*nNS2 + 1 > nNN ) nNS2--;

  float *pfF1 = nNS2 ? (float*) calloc((2*nNS2 + nNN), sizeof(*pfF)) : pfF;

  if( nNS2 )
  {
    memcpy( pfF1 + nNS2, pfF + nNF, nNN*sizeof(*pfF) );
    for( short nP = 1;  nP <= nNS2; nP++ )
    {
      int nK = nNF - nP;
      pfF1[nNS2 - nP] = pfF[nK >= 0 ? nK : - nK];

      nK = nNT + nP;
      pfF1[nNS2+nNN-1 + nP] = pfF[nK < nN ? nK : nN - (nK - nN + 2) ];
    }

    SmoothRectW( pfF1 + nNS2, nNN, nNS2 );
  }

  double fSEF = FindSEF( pfF1 + nNS2, nNN, fa, fb, fAl );

  if( nNS2 ) free( pfF1);
  return fSEF;
}

// Local | Transform values of a N-points curve to the values of M-points curve
static void TransformLinearily( int nN, float *pfI, int nM, float *pfO,
                            float *pfMax, int *pnMaxNmb, int *pnSecMaxNmb )
{
  long nN1 = nN-1, nM1 = nM-1;
  float fMax = pfO[nM-1] = pfI[nN-1];
  int nMaxNmb = nM-1;
  bool bMax = (bool)pfMax && (bool)pnMaxNmb;

  for( long nJ = 0; nJ <= nM-2; nJ++ )
  {
    double fT = (nJ/(double)(nM1)) * nN1;
    int nKJ = fT;
    double fX = pfI[nKJ], fX1 = pfI[nKJ + 1],
           fV = fX + (fX1 - fX)*(fT - nKJ);
    if( bMax )
      if( fMax < fV )  { fMax = fV;  nMaxNmb = nJ; }
    pfO[nJ] = fV;
  }

  if( bMax )  { *pfMax = fMax;  *pnMaxNmb = nMaxNmb; }

  if( !pnSecMaxNmb || !bMax )
    return;

  // compute second peak position:
  float fA, fB = pfO[0], fC = pfO[1];
  int nMaxNmb1 = 0;
  for( long nJ = 1; nJ < nM-1; nJ++ )
  {
    fA = fB;   fB = fC;   fC = pfO[nJ+1];

    if( (nJ != nMaxNmb) && ((fA < fB) && (fB > fC)) )
      nMaxNmb1 = nJ;
  }
  *pnSecMaxNmb = nMaxNmb1;  // if 0 then second peak does not exist
} // ***

// Local | Transform multi-channel array of curves computed in one equispaced sets
// of curves' arg (e.g.,frq) & time into another multi-channel array of -----
// curves computed in another sets of curves' arg & time --------------------
static void TransformLinearilyM( double fhH, long lF, long lT, int nM,
           float *pfI, long lIRS, trMcFIDT *prDT, short *pnO )
{
  long lK1 = lF * fhH,       // time index of the first input curve
       lMax = prDT->nMax - 1;
 //      lK2 = lT * fhH + 1;   // time index of the last input curve
 //      lN  = lK2 - lK1 + 1;  // number of input curves

  float * pfD = new float[nM],
        * pfOV = new float[nM],
        * pfF;
  double fC = prDT->fC,
         fM = prDT->nMax;

  for( long lm = lF, lk = lK1-1; lm <= lT; lm++ )
  {
    long lkc = lm * fhH;
    double fAj;
    if( lkc != lk )
    {
      lk = lkc;
      pfF = (float*) ((char*)pfI + (lk-lK1) * lIRS);
      float * pfF1 = (float*) ((char*)pfF + lIRS);

      for( short nI = 0; nI < nM; nI++ )
        pfD[nI] = pfF1[nI] - pfF[nI];

      fAj = (lm * fhH) - lk;
    }
    else fAj += fhH;

    short *pnOC = pnO + (lm - lF)*(nM + 2),
          *pnOc = pnOC;

    double fMax = 0.; // fC * (*pfF + fAj* *pfD);
    short nMaxPos = 0, nP = -1;

    for( float *pf1 = pfF, *pf2 = pfD, *pfE = (pf1 + nM); pf1 < pfE; pf1++ )
    {
      double fW = fC * (*pf1 + fAj* *pf2++);
      fW = MIN( fW, 1. );
      fW = prDT->Y( fW ) * fM;  // scale transformation

      pfOV[++nP] = fW;
      if( fMax < fW )
      {
        fMax = fW;
        nMaxPos = nP;
      }

      long lW = fW;  lW = MIN( lW, lMax );
      *pnOc++ = (short) lW;
    }
    *pnOc++ = nMaxPos;
    *pnOc   = FindSecondPeakPos( pfOV, nM, nMaxPos );
  }

  delete[] pfD;     delete[] pfOV;
} // ***

// Local | Display one dimentional signal over the needed graphic canvas -------
// Given steps in time for signal points and pixels and integer time indexies --
// for pixels ------------------------------------------------------------------
static void Display1DSignal_( double fhH, long nF, long nT, float *pfS, double fT, // !!!!!
                                                 int nL, int nZ, TCanvas * prC )
{
  long lAF = nF * fhH,   lAT = (nT * fhH) + 1,   lAItems = lAT - lAF + 1;
  double fHh = 1. / fhH;
  TPoint * pnP = new TPoint[lAItems + 1];

  for( int nI = 0;  nI < lAItems;  nI++ )
    pnP[nI].x = -nL + (nI + nF)*fHh, pnP[nI].y = nZ - (pfS[nI]*fT);

  prC->Polyline( pnP, lAItems - 1 );

  delete [] pnP;
} // ***

// Local | calculate integral over given band (total band is [0..1]) --------
static double CalculateIntegralInBand( float *pfIC, int nNP, float fF, float fT )
{

  if( fF < 0. || fT > 1. || fF >= fT )
    return 0.;

  double fH = 1./(nNP - 1);
  int nK1 = (int) (fF/fH) + 1,
      nK2 = (int) (fT/fH);  // nK1 < nNP - 1; nK2 <= nNP - 1

  double fS = 0.;
  if( nK2 > nK1 )
  {
    for( int nK = nK1; nK <= nK2; nK++ )
      fS += pfIC[nK];
    fS = fH * (fS - 0.5*(pfIC[nK1] + pfIC[nK2]));
  }

  double fAl = (double)nK1 - fF/fH;
  if( fAl > MALO ) // non-completed left segment:
  {
    double fY2 = pfIC[nK1],
           fY1 = pfIC[nK1-1] + (fY2 - pfIC[nK1-1])*(1. - fAl);

    fS += (fY1 + fY2) * 0.5 * fAl * fH;
  }

  fAl = fT/fH - (double)nK2;
  if( fAl <= MALO )
    return fS;
  // non-completed right segment:
  double fY1 = pfIC[nK2],
         fY2 = fY1 + (pfIC[nK2+1] - fY1)*fAl;

  return fS += (fY1 + fY2) * 0.5 * fAl * fH;
} // ***

// Local / Local | find longest segment with equal Y-coord. -----------------
static int FindConstYSegment( TPoint *pnP, long nPNmb )
{
  if( nPNmb < 2 )
    return 0;

  long lK = 0;
  while( lK < nPNmb-1 && pnP[0].y == pnP[lK+1].y ) lK++;
  return MAX( lK - 1, 0 );
} // ***

// Local/local | Simlify array of points for polyline (unite lines if possible) ---
static long SimplifyLinePoints( TPoint * pnP, long nPntNmb )
{
  long lNP = nPntNmb,
       lP = 0;
  TPoint *pnPT = pnP;

  while( true )
  {
    long lK = FindConstYSegment( pnPT, lNP - lP );
    if( lK > 2 )
    {
      memmove( (pnPT + 1), (pnPT + lK + 1), (lNP - (lP + lK + 1))*sizeof(*pnP) );
      lNP -= lK;
    }

    if( ++lP > lNP - 3 )
      break;

    pnPT++;
  }

  return lNP;
} // ***

// Local | local draw polyline with 2 colors (thick or thin) ----------------
#define BK_NONE   0x0
#define BK_THIN   0x1
#define BK_THICK  0x2
#define FR_NONE   0x0
#define FR_DOT    0x4
#define FR_SOLID  0x8

#define DOTTED_NOBK     (BK_NONE  | FR_DOT)   // dotted line with transparent background
#define DOTTED_THINBK   (BK_THIN | FR_DOT)    // dotted line with background of 1 pixel width
#define DOTTED_THICKBK  (BK_THICK | FR_DOT)   // dotted line with background of 3 pixels with
#define SOLID_THICKBK   (BK_THICK | FR_SOLID) // solid line with background of 3 pixels with
#define NO_LINE_THICKBK (BK_THICK | FR_NONE)  // no foreground line, only background line of 3 pixels width

static void DrawPolyLine( TCanvas * prC, TPoint *pnP, long lNmbP,
                   TColor nBkC, TColor nFrC, int nLineCfg = DOTTED_NOBK )
{
  if( nLineCfg != DOTTED_NOBK )
  {
    prC->Pen->Width = (nLineCfg == DOTTED_THINBK) ? 1 : 3;
    prC->Pen->Style = psSolid;
    prC->Pen->Color = nBkC;
    prC->Polyline( pnP, lNmbP - 1 );
  }

  if( nLineCfg != NO_LINE_THICKBK )
  {
    prC->Pen->Width = 1;
    prC->Pen->Style = (nLineCfg == SOLID_THICKBK) ? psSolid : psDot;
    prC->Pen->Color = nFrC;
    prC->Polyline( pnP, lNmbP - 1 );
  }
} // ***

// Local | draw continious trend on some canvas ----------------------------
static void DrawTrendC( TCanvas *prC,
          TPoint * pnP, long lPoints, TColor nBkC, TColor nFrC, int nStyle )
{
  if( !pnP )
    return;

  int oldbk = SetBkMode(prC->Handle, TRANSPARENT);
  prC->Pen->Mode = pmCopy;

  long lPnt = SimplifyLinePoints( pnP, lPoints );
  nStyle = (nStyle == MCSTB_DOTTED_TRANSPARENT) ? DOTTED_NOBK :
           (nStyle == MCSTB_DOTTED_THINBK)      ? DOTTED_THINBK : DOTTED_THICKBK;

  if( lPnt )
    DrawPolyLine( prC, pnP, lPnt, nBkC, (nStyle == DOTTED_NOBK ) ? nBkC : nFrC, nStyle );

  SetBkMode(prC->Handle, oldbk);
} // ***

// Local | draw non-continious trend on some canvas ------------------------
static void DrawTrendNC( Graphics::TBitmap *prB,
          TPoint * pnP, long lPoints, TColor nBkC, TColor nFrC, int nStyle )
{
  if( !pnP )
    return;
  int oldbk = SetBkMode(prB->Canvas->Handle, TRANSPARENT);
  prB->Canvas->Pen->Mode = pmCopy;

  long lPnt = SimplifyLinePoints( pnP, lPoints ),
       lMI = prB->Height - 1,
       lP1, lP2 = - 1;

  nStyle = (nStyle == MCSTB_DOTTED_TRANSPARENT) ? DOTTED_NOBK :
           (nStyle == MCSTB_DOTTED_THINBK)      ? DOTTED_THINBK : DOTTED_THICKBK;
  nFrC = (nStyle == DOTTED_NOBK ) ? nBkC : nFrC;

  while( true )
  {
    lP1 = lP2 + 1;
    while( (lP1 < lPnt - 1) && (pnP[lP1].y == lMI) ) lP1++;
    if( lP1 >= lPnt - 1 )
      break;

    lP2 = lP1 + 1;
    while( (lP2 < lPnt - 1) && (pnP[lP1].y != lMI) ) lP2++;
    bool bNextSegm = (pnP[lP2].y == lMI);
    if( bNextSegm )
    {
      pnP[lP2].y = pnP[lP2-1].y;
      lP2--;  // last point: may not be needed "--"
    }

    if( lP2 > lP1 )
      DrawPolyLine( prB->Canvas, (pnP + lP1), lP2 - lP1 + 1, nBkC, nFrC, nStyle );

    if( bNextSegm )
      pnP[lP2+1].y = lMI;
  }
  SetBkMode(prB->Canvas->Handle, oldbk);
} // ***

// Local | Display one dimentional signal over the needed graphic canvas -------
// Given steps in time for signal points and pixels and integer time indexies --
// for signal ------------------------------------------------------------------
static void Display1DSignal(
              double fhH,       // (In) input signal is digitalized in { T(k) = fH*k, k=0, ... }
                                // left boards of pixels are { t(j) = fh*j, j=0, ... }; fhH is fh / fH
              float *pfS,       // (In) input signal, (nT - nF + 1) values
              long nF, long nT, // (In) range of time indexies for signal points T(j), j = nF, ..., nT
                                // [this requests input signal calculated for T(k), k = K1, ...,K2,
                                //  K1 = [t(nF) / fH], K2 = [t(nT) / fH] + 1, (nK2 - nK1 + 1) input signal points needed)
              double fT,        // (In) transform. coeff. of signal to pixels: ROUND(x*fT) is value in pixels, "x" is signal
              int nL,           // (In) left coord. of output zone in pixels (zero pixel on canvas is "nL" in abs. coordinates)
              int nZ,           // (In) zero Y-coord. (i.e. X-axis) of signal in pixels
              TCanvas * prC     // (In) where to display (using current pen style & color)
                           )
{
  int nItems = nT - nF + 1;
  TPoint * pnP = new TPoint[nItems];
  double fHh = 1. / fhH;

  for( int nSP = 0;  nSP < nItems;  nSP++ )
  {
    pnP[nSP].x = ((nSP + nF) * fHh)  - nL;
    pnP[nSP].y = nZ - (pfS[nSP]*fT);
  }

  bool bNoise = false;
  int nFrom = 0;
  for( int nSP = 0;  nSP < nItems;  nSP++ )
  {
    bool bN = pfS[nSP] < 0.;
    if (bN != bNoise)
    {
      if (bN)
        DrawPolyLine(prC, &pnP[nFrom], nSP - nFrom, clBlack, clWhite, MCSTB_DOTTED_TRANSPARENT);
      else
        DrawPolyLine(prC, &pnP[MAX(0, nFrom - 1)], nSP - nFrom + 2, clBlack, clWhite, DOTTED_THINBK);
      bNoise = bN;
      nFrom = nSP;
    }
  }

  if (bNoise)
    DrawPolyLine( prC, &pnP[MAX(0, nFrom - 1)], nItems - nFrom + 1, clBlack, clWhite, DOTTED_THINBK);
  else
    DrawPolyLine( prC, &pnP[MAX(0, nFrom - 1)], nItems - nFrom + 1, clBlack, clWhite, MCSTB_DOTTED_TRANSPARENT );

  delete [] pnP;
} // ***

// Local | calculate spectrum entropy --------------------------------------
static double CalculateSpectrumEntropy( float* pfSP, int nNP, float fF, float fT )
{
  if (!pfSP || nNP <= 0)
    return 0.;

  if( fF < 0. || fT > 1. || fF >= fT )
    return 0.;

  // borders
  double fH = 1. / (nNP - 1);
  int nK1 = (int) (fF / fH) + 1,
      nK2 = (int) (fT / fH);

  // 1. normalize spectrum
  double fNorm = 0.;
  for (int nN = nK1; nN <= nK2; nN++)
    fNorm += pfSP[nN];

  // 2. calculate entropy
  double fEntropy = 0.;
  for (int nN = nK1; nN <= nK2; nN++)
  {
    if (pfSP[nN] > MALO)
      fEntropy += (pfSP[nN] / fNorm) * log ( fNorm / pfSP[nN] ) / log(2);
  }

  fEntropy /= log(nK2 - nK1 + 1) / log(2);

  return fEntropy;
}  // ***

// Local | smooth spectrum -------------------------------------------------
static void SmoothSpectrum( float* pfSB, int nPN, float* pfSS, double fSmBand )
{
  double fH = 1. / (nPN - 1);
  int nW  = (int) (fSmBand / fH + 0.5);
  double fAv = -1.;
  int nAvTo = 0;
  for (int nN = 0; nN < nPN; nN++)
  {
    if (nAvTo <= nN)
    {
      int nNAvTo = MIN((nN / nW + 1) * nW, nPN);
      fAv = 0.;
      if (nNAvTo > nAvTo)
      {
        for (int nP = nAvTo; nP < nNAvTo; nP++)
          fAv += pfSB[nP];
        fAv /= nNAvTo - nAvTo;
      }
      nAvTo = nNAvTo;
    }
    pfSS[nN] = fAv;
  }

  return;
}
