/************************************************************************
  File        : Mc_SpectrTrendProc.h

  Description :
    1. Calculations of spectrums for the CSA (compressed spectrum
  analysis). Calculates spectrum estimators in equispaced time intervals of
  equal length and then the moving averages of those to get final estimators.
  Uses data source and spectrum processor (Mc_SpectrProc.*).
    2. Calculation of trend of the values of ratio of the AR model residuals variance
  and total signal varuance for given multi-channel signal.

  Rev.History :

   Date      Person       Comment
   ---------------------------------------------------------------------
   28-Aug-16 Larionov V.  Lag added
   26-Nov-07 Yurovskiy    Cosmetics
   18-Jan-07 Yurovskiy    Cosmetics
   05-Dec-06 Yurovskiy    Modifications for the trend of AR ratio
   03-Nov-06 Yurovskiy    AR model variance tremd added
   30-Oct-06 Yurovskiy    Averaging of spectrums modified: non-symmetric mode added
   23-Aug-06 Yurovskiy    Get() added
   20-Jun-06 Yurovskiy    Number of spectrums included into Init() params
   27-Apr-06 Yurovskiy    Max. length of trend increased to 800 sec.
   17-Jan-06 Yurovskiy    Defines modified; time for spc. trend increased
   01-Dec-05 Yurovskiy    Adaptive spectrums added to interface
   03-Oct-05 Chernyavskiy pbChOn changed again
   22-Sep-05 Chernyavskiy pbChOn changed in trMcSpcTrendData; SetChOn() added
   15-Sep-05 Yurovskiy    data source modified, GetSpectrum() removed; defines modified
   10-Sep-05 Yurovskiy    Set() modified
   25-Aug-05 Yurovskiy    Destructor for data source
   07-Aug-05 Yurovskiy    operators ==
   26-Jul-05 Yurovskiy    cosmetics
   21-Jul-05 Yurovskiy    structs modified; constructors added
   15-Jul-05 Yurovskiy    new defines; modifications
   06-Jul-05 Yurovskiy    Original
************************************************************************/
#ifndef __MC_SPECTRPTRENDROC_H
#define __MC_SPECTRPTRENDROC_H

//------------------------------------------------------------------------------
// Includes --------------------------------------------------------------------
//------------------------------------------------------------------------------
#include <Mc_SpectrumAnalysis.h>   // types of window
#include <Mc_SpectrProc.h>         // trBrSpcFrqCfg
//#include "Mc_SigDefs.h"          // maximum number of channels

//------------------------------------------------------------------------------
// Defines ---------------------------------------------------------------------
//------------------------------------------------------------------------------
#define MC_STP_MAX_CHANNELS   16   // max. number of signal channels in trend

#define MC_STP_SPC_SEGM_MIN   1.   // min. length of time segment to calculate "primary" spectrums (Sec.)
#define MC_STP_SPC_SEGM_MAX   16.  // max. length of time segment to calculate "primary" spectrums (Sec.)
#define MC_STP_SPC_SEGM_DEF   4.   // default length of time segment to calculate "primary" spectrums (Sec.)

#define MC_STP_INTSEC_DEF     0.5  // coeff. of intersection for two neighbour segments for calculating
                                   // "primary" spectrums (the middle of the next time interval is
                                   // t(k+1) = t(k) + (1-K)*Dlt, where "K" is the coeff. of intersection,
                                   // "Dlt" is the length of a segment to calculate spectrum, t(k) is the middle of
                                   // the previous segment; min. value is 0 (no intersection)
#define MC_STP_INTSEC_MAX     0.8  // max. coeff. of intersection (see comments above)

#define MC_STP_MIN_SPC_PNT    64   // min. number of signal points in one segment for calculatimg spectrums
#define MC_STP_MAX_SPC_PNT    8192 // max. number of signal points in one segment for calculatimg spectrums
#define MC_STP_MIN_STEP_PNT   32   // min. number of points between the centers of two neighbour segments to
                                   // calculate spectrums

// Max. number of "primary" spectrums averaged in one "time-averaged" spectum
#define MC_STP_TIMEAVR_MAX    11   // corr. to nK = 5 for symmetric mode; more than sufficient (min. is nK = 0 - no averaging)
#define MC_STP_TIMEAVR_DEF    3    // default number of "primary" spectrums used to calculate time-averaged spectrum (nK = 1)

#define MC_STP_WINDOW_DEF     BSP_WINDOW_TRIANGULAR // type of the weight function for the time averaging of spectrums

#define MC_STP_THRESHOLD_DEF  0.8  // threshold for adaptive spectrums
#define MC_STP_MAXSEGMENT_DEF 30.  // max. segment for calculating adaptive spectrums (even if threshold condition is not
                                   // satisfied, number of "primary" spectrums averaged to form adaptive spectrum is limited
                                   // so that the length of the total time segment should be not larger then MC_STP_MAXSEGMENT_DEF Sec.)

// Default configuration for spectrum calculations -----------------------------
#define MC_STP_SPC_TYPE_DEF   BSP_MAPS_SPC_CFG // sets default parameters to trBrSpcEstCfg & trBrSpcFrqCfg if used in constructor


#define MC_STP_FRQ_BAND       64   // Frequency band for spectrums is  [0..al*MC_STP_FRQ_BAND] (Hz); must be power of 2
                                   // (total band used in calculations is [0..2*al*MC_STP_FRQ_BAND])
                                   // "al" depends upon the sampling rate (N) and is 1 if N is a power of 2 and is in (0.5..1] if not

#define MC_STP_FRQ_RES        0.25 // Minimal distance between two neighbour points calculated is al*MC_STP_FRQ_RES (in Hz);
                                   // (1/MAPS_FRQ_RES) must be power of 2; "al": see above
#define MC_STP_SPC_EST        BSP_PERIODOGRAM_EST // type of spectrum estimator: ordinary periodogram, smothed in frq. domain (fast and not precise)

// Defaults for AR residuals' variance trend -----------------------------------
// Trend is the ratio of variance of residuals to variance of signal -----------
#define MC_STP_MIN_AR_ORDER   0.05  // min. AR order for the autoregressive model (Sec.)
#define MC_STP_MAX_AR_ORDER   2.    // min. AR order for the autoregressive model (Sec.)
#define MC_STP_DEF_AR_ORDER   0.1   // default AR order for the autoregressive model (Sec.)

#define MC_STP_MIN_AR_EST     MC_STP_SPC_SEGM_MIN  // min. signal segment for calculating AR model (Sec.)
#define MC_STP_MAX_AR_EST     MC_STP_SPC_SEGM_MAX  // max. signal segment for calculating AR model (Sec.)
#define MC_STP_DEF_AR_EST     4.   // default signal segment for calculating AR model (Sec.)

#define MC_STP_MIN_AR_CLC     0.1  // min. period of time for calculation of next AR trend value (Sec.)
#define MC_STP_MAX_AR_CLC     8    // max. period of time for calculation of next AR trend value (Sec.)
#define MC_STP_DEF_AR_CLC     1    // default period of time for calculation of next AR trend value (Sec.)

#define MC_STP_MAX_AR_AVR     (MC_STP_TIMEAVR_MAX*MC_STP_MAX_AR_EST)  // max. segment for averaging of AR trend (Sec.)
#define MC_STP_DEF_AR_AVR     4.   // default segment for averaging of AR trend (Sec.)

#define MC_STP_MAX_AR_AVRPNT  (int)((MC_STP_MAX_AR_AVR / MC_STP_MIN_AR_CLC) + 0.5) // max. points to average AR trend

#define MC_STP_DEF_AR_MODEL   LevDrb // default AR model (see trMcARVarPrm)
#define MC_ARTREND_RECLEN     3      // length of record for AR trend (ratio, variance of residuals, variance of signal)

// Error codes -----------------------------------------------------------------
#define MC_STP_NO_ERROR       0   // OK
#define MC_STP_NOT_INIT       1   // Object is not initialized yet
#define MC_STP_BAD_PRM        2   // Bad input parameters
#define MC_STP_NO_MEMORY      3   // Out of memory
#define MC_STP_GENERIC_ERR    99  // Other error

//------------------------------------------------------------------------------
// Types -----------------------------------------------------------------------
//------------------------------------------------------------------------------

// Forwards --------------------------------------------------------------------
//------------------------------------------------------------------------------
// Data source with parameters (number of channels, sample rate, ...)
struct trMcSpcTrendData;

// Parameters for the spectrum' estimators of spectrum trend (see notes below)
struct trMcSpcTrendPrmP;   // primary spectrums (length of segment & intersection, est. type)
struct trMcSpcTrendPrmTA;  // time averaged spectrums (length of segment, window type)

struct trMcSpcTrendCfg;    // config. structure for spectrum trend (number of points in spectrum, real frq. band,
                           // time points in which specrums are calculated) - output of initialized trend object

// Parameters for the trend of AR model variance
struct trMcARVarPrm1;      // base parameters for the AR var. trend (AR order, time segment for model, type of AR model)
struct trMcARVarPrm2;      // settable parameters for the AR var. trend (segment for averaging of trend, frequency of recalculation)

struct trMcARVarTrendCfg;  // Config. structure for AR residuals trend

// Template object for calculating trend of spectrums --------------------------
struct trMcSpcTrendProc
{
  virtual bool Init( // Initialization
     trMcSpcTrendData * prTD,  // (In) source of multi-channel data
     trMcSpcTrendPrmP * prPP,  // (In) parameters for "primary" spectrums
     trMcSpcTrendPrmTA * prPA, // (In) parameters for time-averaged spectrums
     long nSpcInBuf,           // (In) max. number of multi-channel spectrums saved in buffer
                               //      GetSpectrums() can compute not more than this quantity of spectrums

     trMcSpcTrendCfg * prCfg   // (Out) config. parameters for the initialized object based on input
                   ) = 0;

  virtual bool Set( // Set new parameters
     trMcSpcTrendPrmTA * prPA, // (In) parameters for time-averaged spectrums (not used if NULL)
     trMcSpcTrendPrmP * prPP,  // (In) parameters for "primary" spectrums (not used if NULL)
     trMcSpcTrendCfg * prCfg   // (Out) config. parameters for the modified object
                   ) = 0; // Note: all fields in *prPP require complete recalculation
                          // of "primary" spectrums if modified

  virtual bool Get( // Get parameters
     trMcSpcTrendData **pprTD = NULL, // (Out) pointer to source of multi-channel data
     trMcSpcTrendPrmP *prPP = NULL,   // (Out/opt) parameters for "primary" spectrums
     trMcSpcTrendPrmTA *prPA = NULL,  // (Out/opt) parameters for time-averaged spectrums
     trMcSpcTrendCfg *prCfg = NULL    // (Out/opt) config. parameters for the initialized object based on input
                  ) = 0;

  virtual bool GetSpectrums( // Get time-averaged spectrums in needed time segment (or max. possible time segment inside it)
          long *plKF,        // (In/Out) leftmost time point of the center of signal segment to compute the main spectrum
                             // in average (if there is average); on exit: min. available time point
          long *plKT,        // (In/Out) rightmost time point of the center of signal segment to compute the main spectrum
                             // in average (if there is average); on exit: max. available time point
          // should be: *plKF >= 0, *plKT > *plKF, quantity of (*plKT - *plKF + 1) may never be greater than
          // value of "nSpcInBuf" used in Init()
          float **ppfSpc     // (Out) pointer to the record with all spectrum arrays (all channels)
                             // "*plKT - *plKF + 1" records
                             // !! memory is allocated inside and is deallocated on object's destruction
                  ) = 0; // return true and *ppfSpc = NULL means that there is no data

  virtual short GetErrorCode( void ) = 0; // get error code after the last operation

  virtual ~trMcSpcTrendProc( void ){}
};

// Template object for calculating the variance of noize for AR model ----------
struct trMcARVarProc
{
  virtual bool Init( // Initialization
     trMcSpcTrendData * prTD,  // (In) source of multi-channel data
     trMcARVarPrm1 * prP1,     // (In) parameters for the AR var. trend (base)
     trMcARVarPrm2 * prP2,     // (In) parameters for the AR var. trend (settable)
     long nPntInBuf,           // (In) max. number of of output blocks in buffer
                               // (each block consists of "N" vectors, where "N"
                               // is the number of input signal channels; each vector
                               // consists of 3 values: (1) ratio of noize variance to signal
                               // variance; (2) noize variance; (3) signal variance;
                               // timing corresponds to *prP1 value
     trMcARVarTrendCfg * prCfg // (Out) config. parameters for the initialized object based on input
                   ) = 0;

  virtual bool Set( // Set new parameters
     trMcARVarPrm2 * prP2 = NULL, //(In/Opt) parameters for the AR var. trend (settable)
     trMcARVarPrm1 * prP1 = NULL  // (In/Opt) parameters for the AR var. trend (base;
                                  // if modified, then re-init of object is performed)
                   ) = 0; // Note: all fields in *prPP require complete recalculation
                          // of "primary" spectrums if modified

  virtual bool Get( // Get parameters
     trMcSpcTrendData **pprTD = NULL, // (Out/opt) pointer to source of multi-channel data
     trMcARVarPrm1 * prP1 = NULL,     // (Out/opt) parameters for the AR var. trend (base)
     trMcARVarPrm2 * prP2 = NULL,     // (Out/opt) parameters for the AR var. trend (settable)
     trMcARVarTrendCfg * prCfg = NULL // (Out/opt) config. parameters for the initialized object based on input
                  ) = 0;

  virtual bool GetARTrend( // Get AR var. trend in needed time segment (or max. possible time segment inside it)
          long *plKF,        // (In/Out) time point  the first block of data
                             // on exit: min. available time point (time units: number of
          long *plKT,        // (In/Out) time point of the last block of data
                             // on exit: max. available time point (time units: same as for the signal points)
          // should be: *plKF >= 0, *plKT > *plKF, quantity of (*plKT - *plKF + 1) may never be greater than
          // value of "nPntInBuf" used in Init()
          float **ppfDta     // (Out) pointer to the record with all data blocks (all channels)
                             // "*plKT - *plKF + 1" blocks
                             // !! memory is allocated inside and is deallocated on object's destruction
                  ) = 0; // return true and *ppfSpc = NULL means that there is no data

  virtual short GetErrorCode( void ) = 0; // get error code after the last operation

  virtual ~trMcARVarProc( void ){}
};

// Structs needed for the main object ------------------------------------------

// Abstract data source --------------------------------------------------------
struct trMcSpcTrendDataSource
{ // get pointer to buffer with multi-channel data
  virtual void CheckBoards( long *plF, long *plT ) = 0;  // check if there is signal in [*plF, *plT]
                                             // and return largest segment inside it if not;
                                             // return [-1, -1] if the segment is empty
  virtual short* Get( long lFrom,            // (In) from this data vector
                      long lHowMany,         // (In) How many data vectors
                      long *plHowMany ) = 0; // (Out) how many vectors read (<= lHowMany)
       // Return pointer to buffer or NULL if there is no data starting from "lFrom" vector

  virtual void Reset() {}

  virtual ~trMcSpcTrendDataSource() {}
};

// Data source with parameters -------------------------------------------------
struct trMcSpcTrendData
{
  trMcSpcTrendDataSource * prDS;
  short nNmbCh;         // number of signal channels
  short nSampRate;      // data points per time unit (i.e., second)
  float fUPT;           // number of units of input signal in one tension unit

  short nNmbChOut;      // number of output spectrum channels (<=nNmbCh)
  bool *pbChOn;         // which input channels are elaborated
};

// Parameters for the spectrum trend -------------------------------------------
// (divided into 2 structures for the purpose of optimization: modification
// of the first structure requires complete recalculation of trend)
// Notes:
// - a spectrum for trend is weighted time-averaging on interval ([T1, T2]) of "primary"
//   spectrums computed for intervals ([a(j), b(j)]), such that all [a(j), b(j)]
//   are inside [T1, T2];
// - intervals {[a(j), b(j)]} are equispaced and intersected; (intersection is such
//   that the shift for an interval [a(j+1), b(j+1)] with respect to [a(j), b(j)] is constant for all "j");
// - the weights {w(j)} for averaged primary spectrums are based on some "window" function;
//   sum of all w(j) is equal to 1. There are two types of averaging:
//     1. Normal averaging: max. weight is assigned to the rightmost spectrum,
//  higher value of distance between  T2 and the middle of [a(j),b(j)]
//   gives lower value of w(j);
//     2. Symmetric averaging: max. weight is assigned to spectrum in the center
//   [T1, T2]; higher value of distance between the middle of [T1, T2] and the middle of [a(j),b(j)]
//   gives lower value of w(j);

// Parameters for primary spectrum ---------------------------------------------
struct trMcSpcTrendPrmP
{
  double fDT;           // length of time interval for calculating "primary" spectrums
                        // (should such that the corr. number of signal points
                        // should be in [MC_STP_MIN_SPC_PNT, MC_STP_MAX_SPC_PNT])
  double fAl;           // coeff. of intersection for two neighbour segments for calculating spectrums;
                        // should be in [0, 1) and such that the number of signal
                        // points in time segment of length (1-fAl)*fDT should be not less than MC_STP_MIN_STEP_PNT

  int nLag;             // lag for right border spectrum updating

  // Note: for adaptive spectrums only the values of fAl: 3/4; 2/3; 1/2 and 0 are available;
  // value of fAl is rounded to the closest one of these values

  trBrSpcFrqCfg rFC;    // frq. band & frq. resolution (Br_SpectrProc.h)
  trBrSpcEstCfg rSC;    // type & parameters of spectrum estimator for "primary" spectrums (Br_SpectrProc.h)

  trMcSpcTrendPrmP( void );  // setting defaults to all parameters (see defines)
  bool operator == (const trMcSpcTrendPrmP &) const;
};

// Parameters for time-averaged spectrum ---------------------------------------
struct trMcSpcTrendPrmTA
{
  enum Mode { Averaged, Adaptive } nSpcMode;  // mode: averaging of "primary" spectrums or
                                              // adaptive choice of epoch's length on which the
                                              // "primary" spectrums are averaged
  // Parameters for averaged mode:
  bool bSymmAvr;   // ? symmetric averaging (averaged spectrums are both in "past" and "future"
                   // with respect to the calculated point); otherwise only "past" values are used
  short nK;        // (nK >= 0); number of additional spectrums used for averaging in "past" and "future":
                   //    - if bSymmAvr is true: "2*nK + 1" primary spectrums averaged,
                   // total segment of data is of length fDT*(2*nK*(1-fAl) + 1) sec.,
                   // time interval for time-averaged spectrum is [a(j-nK), b(j+nK)];
                   //    - if bSymmAvr is false: "K + 1" primary spectrums averaged,
                   // total segment of data is of length fDT*(nK*(1-fAl) + 1) sec.;
                   // time interval for time-averaged spectrum is [a(j-nK), b(j)];
                   // "j" is determined by the first parameter in trMcSpcTrendProc::Get();
                   // {[a(l),b(l)], l = ...} are time intervals for primary spectrums (see above);
                   // so, time-averaged spectrum is weighted as below:
  short nWinType;  // type of smoothing function (defines in Mc_SpectrumAnalysis.h), determining
                   // the weights for averaging "primary spectrums"

  // Parameters for adaptive mode:
  double fThr;     // threshold (in [0, 1]); if the "distance" between previously computed averaged spectrum
                   // and the next "primary" spectum supers fThr, then the new segment for spectrum starts;
                   // otherwise, the primary spectrum is united with the previously computed spectrum
  double fTMax;    // max. time segment (Sec.) for adaptive spectrum (if the total segment on which the
                   // "primary" specrums are averaged supers fTMax, then the next "primary" spectrum is not added
                   // to previously computed spectrum but start a new averaged spectrum instead)


  trMcSpcTrendPrmTA( void );  // setting defaults to all parameters (see defines)
  bool operator == (const trMcSpcTrendPrmTA & ) const;
};

// Config. structure for spectrum trend (number of points in spectrum, real frq. band,...)
struct trMcSpcTrendCfg
{
  short nP;        // Total number of points in each spectrum array
  double fMaxFrq;  // real frq. band is [0..fMaxFrq]; fMaxFrq is in (0.5*F, F], where F is
                   // requested frq. band from trBrSpcFrqCfg; precise value is determine by the
                   // sample rate
  long lT;         // Time (in signal vectors) determining the time set in which spectrums are computed:
                   // t(k) = k*lT, k = 0, 1, 2, ...; spectrums (both "primary" and "averaged" are
                   // computed in this set;
                   // "lT" is time shift of neighbour intervals to compute "primary" spectrums
                   // determined in trMcSpcTrendPrmP (namely, fDT*(1. - fAl)), measured in signal vectors
};

// Base parameters for the AR var. trend (time segment, AR model) --------------
struct trMcARVarPrm1
{ // all time segments are converted into integer value of signal points
  double fAROrder; // Order of AR model (sec.)
  double fTEst;    // Length of the time segment of signal for calculating AR model
                   // (should be more than 2*fAROrder)
  double fTClc;    // period of time for calculation of the neighbour points of trend;
                   // it would be reasonable to select fTCalc so that
                   // 1./ F << fTClc << fTEst, where "F" is signal sample rate

  enum { LevDrb, Burg, LeastSq } nModel;  // used AR model: Levinson-Durbin, Burg, least squares

  trMcARVarPrm1( void );  // set defaults
  bool operator == ( const trMcARVarPrm1 & ) const;
};

// Parameters for the trend the values of ratio of the AR model residuals ------
// variance and total signal varuance ------------------------------------------

// Settable parameters for the AR var. trend -----------------------------------
struct trMcARVarPrm2
{ // all time segments are converted into integer value of signal points
  double fTAvr;    // length of time interval for averaging the ratio of "DEt/DXt",
                   // where DEt is variance of residuals, DXt is variance of input signal
                   // (both measured on signal segment of length trMcARVarPrm1::fTEst)

  short nWinType;  // type of smoothing function (defines in Mc_SpectrumAnalysis.h), determining
                   // the weights for averaging the trend's values

  trMcARVarPrm2( void );  // set defaults
  bool operator == ( const trMcARVarPrm2 & ) const;
};

// Config. structure for AR residuals trend ------------------------------------
struct trMcARVarTrendCfg
{ // values corresponding to trMcARVarPrm1 & trMcARVarPrm2
  int nAR;         // AR order (in signal points)
  int nEst;        // length of signal segment used for AR model estimator (in signal points)
  long lT;         // Time determining the time set in which the values of
                   // averaged ratio  "DEt/DXt"  (DEt is variance of residuals,
                   // DXt is variance of input signal) are computed:
                   // t(k) = k*lT, k = 0, 1, 2, ...;
                   // "lT" is period of time determined by trMcARVarPrm1::fTClc (in signal points)

  int nK;          // Number of additional averaged points of AR trend
                   // (measured in periods of time of "lT" signal points length)
                   // If nK is 0, then no averaging is performed; otherwise,
                   // the weighted sum of current value plus "nK" past values is calculated;
                   // the weights are determined by trMcARVarPrm2::nWinType
};


//------------------------------------------------------------------------------
// Interface -------------------------------------------------------------------
//------------------------------------------------------------------------------

// Create object for calculating the trend of spectrums ------------------------
trMcSpcTrendProc * McCreateSpcTrendProc( void );

// Create object for calculating the trend of AR model residuals' variance -----
trMcARVarProc * McCreateARVarProcProc( void );

#endif // __MC_SPECTRPTRENDROC_H
