/************************************************************************
  File        : Mc_SpectrTrendProc.cpp

  Description : Calculations of spectrums for the CSA (compressed spectrum
  analysis). Calculates spectrum estimators in equispaced time intervals of
  equal length and then the moving averages of those to get final estimators.
  Uses data source and spectrum processor (Mc_SpectrProc.*).

  Rev.History :

   Date      Person       Comment
   ---------------------------------------------------------------------
   28-Aug-16 Larionov V. Lag added
   13-Apr-15 Larionov V. Intervals changes
   27-Feb-08 Abasov E.   Cosmetics
   18-Jan-07 Yurovskiy   Cosmetics
   08-Dec-06 Yurovskiy   Fixes
   05-Dec-06 Yurovskiy   Modifications for the trend of AR ratio
   23-Nov-06 Yurovskiy   AR trend finished & fixed
   09-Nov-06 Yurovskiy   AR trend added (not finished)
   30-Oct-06 Yurovskiy   Averaging of spectrums modified: non-symmetric mode added 
   24-Aug-06 Yurovskiy   Get() added
   20-Jun-06 Yurovskiy   Number of spectrums included into Init() params
   19-Feb-06 Yurovskiy   Changes of the interface for cashed buffers
   30-Jan-06 Yurovskiy   ComputeTimeAveragedSpectrum() fixed
   25-Jan-06 Yurovskiy   Initialized() instead of pB
   17-Jan-06 Yurovskiy   Defines modified; time for spc. trend increased
   16-Jan-06 Yurovskiy   fixes
   13-Dec-05 Yurovskiy   CheckInput() fixed
   01-Dec-05 Yurovskiy   Adaptive spectrums added to interface
   15-Sep-05 Yurovskiy   data source modified, GetSpectrum() removed, ...
   10-Sep-05 Yurovskiy   Set() modified
   26-Jul-05 Yurovskiy   cosmetics
   21-Jul-05 Yurovskiy   structs modified; constructors added
   15-Jul-05 Yurovskiy   First version ended (not debugged)
   06-Jul-05 Yurovskiy   Original
************************************************************************/

//---------------------------------------------------------------------------
// Includes -----------------------------------------------------------------
//---------------------------------------------------------------------------
#include <math.h> // fabs

#include "Mc_CashedBuffers.h"      // trCashedBufferN
#include "Mc_SpectrProc.h"         // trBrTSpectralProcessor
#include "Mc_FFT.h"                // ACorrF()
#include "Mc_SpectrTrendProc.h"

//---------------------------------------------------------------------------
// Defines ------------------------------------------------------------------
//---------------------------------------------------------------------------
#define MC_ARMODEL_LEVDRB (short)trMcARVarPrm1::LevDrb
#define MC_ARMODEL_BURG   (short)trMcARVarPrm1::LevDrb
#define MC_ARMODEL_LSTSQ  (short)trMcARVarPrm1::LeastSq

#ifndef CDELETE
  #define CDELETE(p) { if(p) { delete p; p = NULL; }}
#endif
#ifndef CFREE
  #define CFREE(p)   { if(p) { free( p ); p = NULL; }}
#endif
#ifndef MAX
  #define MAX( a, b ) ( (a) > (b) ? (a) : (b) )
#endif
#ifndef MIN
  #define MIN( a, b ) ( (a) < (b) ? (a) : (b) )
#endif

#define FLOAT_EQ( a, b )    (fabs((a)-(b)) < 1e-9)
#define BOOL_EQ(a,b)        ( ((a) && (b)) || (!(a) && !(b)) )

#define MALO 1E-6

//------------------------------------------------------------------------------
// Local variables & declarations of local functions ---------------------------
//------------------------------------------------------------------------------

// Local | calculate autocovariance function for the given signal segment ------
static bool ACovF(
             float *pfS,     // (In) buffer with signal
             int nN,         // (In) number of signal points in *pfS
             int nM,         // (In) number of lags of ACF
             float *pfACF    // (Out) values with ACovF ("nM+1" values; values are biased,
                             // equally normalized by (1./nN)), pfACF[0] is signal variance
                             // pfACF[i]/pfACF[0], i = 0,..., nM are estimators of autocorrelation function
                  );

// Local | calculate AR parameters for sigle channel signal --------------------
static bool ARParameters(
             float *pfS,     // (In) buffer with signal
             int nP,         // (In) number of signal points in *pfS
             short nModel,   // (In) type of AR estimator (MC_ARMODEL_LEVDRB, ...)
             short *pnAO,    // (In/Out) AR order (requested on input, reached on output)
             double *pfVar,  // (Out) estimator of variance of the input signal
             double *pfSgm,  // (Out) variance of residuals
             double *pfA = NULL  // (Out/opt) AR parameters (nAO + 1 values: pfA[0] is 1.,
                             // pfA[k] is parameter with index "k",
                             // k = 1, ..., nAO
                        ); // return value: true if calculated, false if error occured

// Local | calculate AR parameters for multi-channel signal --------------------
static bool ARParametersM(
              trMcSpcTrendData * prTD,  // (In) source of multi-channel data
              long lF, long lT,         // (In) Segment of signal to be elaborated (from "lF" to "lT")
              short nAO,                // (In) AR order (requested)
              short nModel,             // (In) type of AR estimator (MC_ARMODEL_LEVDRB, ...)
              double *fVar,             // (Out) estimated variances of input signal ("prTD->nNmbChOut" values)
              double *pfSgm,            // (Out) estimated variances of residuals ("prTD->nNmbChOut" values)
              short *pnAO,              // (Out/Opt) reached AR orders for all channels ("prTD->nNmbChOut" values)
              double *pfA = NULL        // (Out/Opt) AR parameters ( "(nAO + 1)*prTD->nNmbChOut" values;
                                        // as in ARParameters(), repeated "prTD->nNmbChOut" times
                         );

// Local | check trMcARVarPrm1 param. structure --------------------------------
static bool ChecktrMcARVarPrm1( trMcARVarPrm1 *prP1 )
{
  return prP1 ?
    (prP1->fAROrder >= MC_STP_MIN_AR_ORDER) && (prP1->fAROrder <= MC_STP_MAX_AR_ORDER) &&
    (prP1->fTEst >= MC_STP_MIN_AR_EST) && (prP1->fTEst <= MC_STP_MAX_AR_EST ) &&
    (prP1->fAROrder <= 0.5*prP1->fTEst) &&
    (prP1->fTClc >= MC_STP_MIN_AR_CLC) && (prP1->fTClc <= MC_STP_MAX_AR_CLC) :
    false;
} // ***

// Local | check trMcARVarPrm1 param. structure --------------------------------
static bool ChecktrMcARVarPrm2( trMcARVarPrm2 *prP2 )
{
  return prP2 ? (prP2->fTAvr >= 0.) && (prP2->fTAvr <= MC_STP_MAX_AR_AVR) : false;
} // ***

//------------------------------------------------------------------------------
// Types -----------------------------------------------------------------------
//------------------------------------------------------------------------------

// Real object for calculating trend of spectrums ---------------------------
struct trMcSpcTrendProcR : trMcSpcTrendProc, trCashedBufferN
{
  trMcSpcTrendProcR( void )
  {
    prSP = NULL;
    nErrorCode = MC_STP_NO_ERROR;
  }

  virtual bool Init( // Initialization
     trMcSpcTrendData * prTD,  // (In) source of multi-channel data
     trMcSpcTrendPrmP * prPP,  // (In) parameters for "primary" spectrums
     trMcSpcTrendPrmTA * prPA, // (In) parameters for time-averaged spectrums
     long nSpcInBuf,           // (In) max. number of multi-channel spectrums saved in buffer
                               //      GetSpectrums() can compute not more than this quantity of spectrums

     trMcSpcTrendCfg * prCfg   // (Out) config. parameters for the initialized object based on input
                   )
  {
    trMcSpcTrendProcR::Done();

    bool bOK = (prTD && prPP && prPA && prCfg );
    bOK = bOK ? prTD->prDS && (prTD->nNmbCh > 0) && (prTD->nSampRate > 2) &&
                (prTD->fUPT > MALO) &&  // others in prTD are checked in prSP->Init()
                (prTD->nNmbChOut <= MC_STP_MAX_CHANNELS ) &&
                (prPP->fDT >= MC_STP_SPC_SEGM_MIN) && (prPP->fDT <= MC_STP_SPC_SEGM_MAX) &&
                ((prPA->nK >= 0) && (prPA->nK <= (prPA->bSymmAvr ? MC_STP_TIMEAVR_MAX/2:MC_STP_TIMEAVR_MAX-1) ))
                : false;

    if( !bOK )
      return SetErrorCode( MC_STP_BAD_PRM );

    rTD = *prTD;  rPP = *prPP;  rPA = *prPA;

    bOK = bOK ? (bool) (prSP = BrCreateSpectralProcessor()) : false;

    bOK = bOK ? (prSP->Init( GetSignal, rTD.prDS, rTD.nNmbCh, rTD.nNmbChOut, rTD.pbChOn,
                   rTD.nSampRate, &rPP.rFC, rTD.fUPT, &rCfg.fMaxFrq ) == BSP_NO_ERROR) : false;

    rCfg.nP = (rPP.rFC.SignalPoints()/2 + 1);
    rCfg.lT = (rPP.fDT * (1. - rPP.fAl) * rTD.nSampRate) + 0.5;

    bOK = bOK ? SetSpcBuffers( nSpcInBuf ) : false; // indicator of initialization: pfPSB

    if( bOK )
      *prCfg = rCfg;

    return SetErrorCode( bOK ? MC_STP_NO_ERROR : MC_STP_GENERIC_ERR );
  }

  virtual bool Set( // Set new parameters
     trMcSpcTrendPrmTA * prPA,       // (In) parameters for time-averaged spectrums (not used if NULL)
     trMcSpcTrendPrmP * prPP,        // (In) parameters for "primary" spectrums (not used if NULL)
     trMcSpcTrendCfg * prCfg         // (Out) config. parameters for the modified object
                  ) // Note: all fields in *prPP require complete recalculation of primary spectrums if modified
  {
    if( !rBMA.Initialized() )
      return SetErrorCode( MC_STP_NOT_INIT );

    trMcSpcTrendPrmTA * prPPA = prPA ? prPA : &rPA;

    if( prPP )
      return Init( &rTD, prPP, prPPA, N(), prCfg );  // reset all inside

    *prCfg = rCfg;
    if( !prPA )
      SetErrorCode( MC_STP_NO_ERROR );

    if( !((prPA->nK >= 0) && (prPA->nK <= (prPA->bSymmAvr ? MC_STP_TIMEAVR_MAX/2:MC_STP_TIMEAVR_MAX-1))) )
      return SetErrorCode( MC_STP_BAD_PRM );

    rPA = *prPA;
    rBMA.Reset();
    return SetErrorCode( MC_STP_NO_ERROR );
  } // ***

  virtual bool Get( // Get parameters
     trMcSpcTrendData **pprTD,        // (Out) pointer to source of multi-channel data
     trMcSpcTrendPrmP *prPP = NULL,   // (Out/opt) parameters for "primary" spectrums
     trMcSpcTrendPrmTA *prPA = NULL,  // (Out/opt) parameters for time-averaged spectrums
     trMcSpcTrendCfg *prCfg = NULL    // (Out/opt) config. parameters for the initialized object based on input
                  )
  {
    if( !rBMA.Initialized() )
      return SetErrorCode( MC_STP_NOT_INIT );
    if( pprTD ) *pprTD = &rTD;
    if( prPP ) *prPP = rPP;
    if( prPA ) *prPA = rPA;
    if( prCfg ) *prCfg = rCfg;
    return SetErrorCode( MC_STP_NO_ERROR );
  }

  virtual bool GetSpectrums( // Get time-averaged spectrums in needed time segment (or max. possible time segment inside it)
        long *plF,         // (In/Out) time point of the center of signal segment to compute first spectrum (see GetSpectrum())
                           // on exit: min. available time point
        long *plT,         // (In/Out) time point of the center of signal segment to compute last spectrum
                           // on exit: max. available time point
        float **ppfSpc     // (Out) pointer to the record with all spectrum arrays (all channels) (see GetSpectrum());
                           // "*plKT - *plKF + 1" records
                           // !! memory is allocated inside and is deallocated on object's destruction
                ) // return code false with no error means that there is  no data (in this case *plKF and *plKT are negative)
  {
    if( !rBMA.Initialized() )
      return SetErrorCode( MC_STP_NOT_INIT );
    if( !plF || !plT || !ppfSpc || ((plF && plT) && (*plT < *plF)) ||
         (*plT - *plF + 1 > trCashedBufferN::lN) )
      return SetErrorCode( MC_STP_BAD_PRM );

    *plF = MAX(rPA.nK, *plF);

    if( *plF > *plT )
    {
      *plF = *plT = -1;
      return SetErrorCode( MC_STP_NO_ERROR );
    }

    rBMA.Update( plF, plT );
    *ppfSpc = ((*plF >= 0) && (*plT >= *plF)) ? (float*)rBMA.Pos( *plF - rBMA.F() ) : NULL;
    return SetErrorCode( MC_STP_NO_ERROR );
  } // ***

  // check boards for input segment & modify them to largest possible; check
  // the presence of data for the total needed segment
  void CheckInput( long *plF, long *plT )
  {
    *plF = MAX(*plF, 0);

    long lDl = rCfg.lT,  // centers of signal segments (in signal vectors) are k*lDl
         lT = SpcWidth(),
         lT2 = lT / 2;
    long lSF = (*plF * lDl) - lT2,          // first signal point
         lST = (*plT * lDl) - lT2 + lT - 1; // last signal point

    rTD.prDS->CheckBoards( &lSF, &lST ); // get largest possible interval inside the requested one

    lST -= rPP.nLag;

//    *plF = MAX(*plF, ((lSF + lT2)/lDl) + ( ((lSF + lT2)%lDl) ? 1 : 0));
    *plF = ((lSF + lT2)/lDl) + ( ((lSF + lT2)%lDl) ? 1 : 0);
    *plT = MIN(*plF + N() - 1, ((lST - lT + 1 + lT2)/lDl));
    if( *plT < *plF ) { *plF = *plT = -1; }
  } // ***

  virtual void Fill( long lFromBufPos, long lFromInd, long lItems )  // fill needed part of buffer with segment with needed indexes
  {
    for( long nI = 0; nI < lItems; nI++ )
    {
      float *pfSpc = NULL;
      ComputePrimarySpectrum( lFromInd + nI, &pfSpc );
      memcpy( Pos(lFromBufPos + nI), pfSpc, lM );
    }
  } // ***

  struct trCashedBufferMAS : trCashedBufferN  // buffer for the moving averaged spectrums
  {
    bool Init( trMcSpcTrendProcR * prASTP )
    { prSTP = prASTP; return trCashedBufferN::Init( prSTP->N() - 2*MC_STP_TIMEAVR_MAX, prSTP->M() ); }

    virtual void CheckInput( long *plF, long *plT )
    {
      long lPSF = *plF - prSTP->rPA.nK,
           lPST = *plT + (prSTP->rPA.bSymmAvr ? prSTP->rPA.nK : 0);

      prSTP->Update( &lPSF, &lPST );

      // !!! is it need
      lPST = MIN(lPST, lPSF + N());

      *plF = lPSF + prSTP->rPA.nK;
      *plT = lPST - (prSTP->rPA.bSymmAvr ? prSTP->rPA.nK : 0);

      if( !( (*plF >= 0 ) && (*plT >= *plF) ) )
      {
        *plF = *plT = -1;
        return; // no data in these boards
      }
    }

    virtual void Fill( long lFromBufPos, long lFromInd, long lItems )
    {
      for( long nI = 0; nI < lItems; nI++ )
        prSTP->ComputeTimeAveragedSpectrum( lFromInd + nI, (float*)Pos(lFromBufPos + nI) );
    }

    bool Initialized( void ) { return (bool) pB; }

    virtual ~trCashedBufferMAS( void ) {}

    trMcSpcTrendProcR * prSTP;
  } rBMA;

  virtual short GetErrorCode( void ) { return nErrorCode; } // get error code after the last operation

  virtual ~trMcSpcTrendProcR( void ) { Done(); }

// private:

  bool SetSpcBuffers( long lSpcInBuf )
  {
    long lSpcSize = rTD.nNmbChOut * rCfg.nP * sizeof(float); // size of one record with multichannel spectrum
    bool bOK = trCashedBufferN::Init( lSpcInBuf + 2*MC_STP_TIMEAVR_MAX, lSpcSize );
    return bOK ? rBMA.Init( this ) : false;
  } // ***

  long SpcWidth( void )
  {
    long lT = (rPP.fDT * rTD.nSampRate) + 0.5;
    if( !(lT % 2) ) lT--;  // must be even
    return lT;
  }

  // Compute "primary" spectrum and store it in given buffer
  bool ComputePrimarySpectrum( long lSpcNmb, float **ppfSpc )
  {
    long lTC = lSpcNmb*rCfg.lT;   // lTC - center of signal segment (in signal vectors)
    trMcSignalSegments rSS;
    long lT = SpcWidth();
    long nF = lTC - lT/2;
    rSS.Add(nF, nF + lT - 1);

    short nP; // will be equal to rCfg.nP  !! izmenitt'
    double fMax;  // not used (temporarily ?)
    return (prSP->GetSpectrums( rSS, &rPP.rSC, &nP, ppfSpc, &fMax ) == BSP_NO_ERROR);
    // pfSpc is a pointer to the first spectrum array; all these pointers
    // are:  { (pfSpc+k*nP), k=0,...,N}; "N" is the number of output channels
    // *pfM is maximum of maximums of ALL spectrum arrays
  } // ***

  bool ComputeTimeAveragedSpectrum( long lSpcNmb, float *pfSpc )
  {
    short nNmbP = rPA.bSymmAvr ? (2*rPA.nK + 1) : rPA.nK + 1;     // number of primary spectrums

    float * aafSpc[MC_STP_TIMEAVR_MAX]; // pointers to primary spectrums' records
    for( short nPS = -rPA.nK, nPT = (rPA.bSymmAvr ? rPA.nK : 0); nPS <= nPT; nPS++ )
      if( !(bool) (aafSpc[nPS + rPA.nK] = (float*)trCashedBufferN::Pos(nPS + lSpcNmb - trCashedBufferN::lF) ))
        return false;

    double fW = 0., afW[MC_STP_TIMEAVR_MAX];  // weights for time-averaging
    for( short nPS = 0; nPS <= rPA.nK; nPS++ )
    {
      afW[nPS] = Window( nPS/(double)(rPA.nK + 1), rPA.nWinType );
      fW += (nPS ? (rPA.bSymmAvr ? 2. : 1.) : 1.) * afW[nPS];
    }

    for( short nPS = 0; nPS <= rPA.nK; nPS++ )
      afW[nPS] /= fW;

    for( int nCh = 0; nCh < rTD.nNmbChOut; nCh++ )
    {
      int nChSh = nCh * rCfg.nP; // offset from the beginning of spc. record to spc. for curr. channel
      // pointers to spectrums for current channel:
      float * pfS0 = aafSpc[rPA.nK] + nChSh, // primary spectrum in center
            * apfSN[MC_STP_TIMEAVR_MAX/2],   // primary spectrums with negative time shift
            * apfSP[MC_STP_TIMEAVR_MAX/2],   // primary spectrums with positive time shift
            * pfSpcO = pfSpc + nChSh;        // time averaged spectrum

      for( short nPS = 0; nPS < rPA.nK; nPS++ )
      {
        apfSN[ nPS ] = aafSpc[ rPA.nK - nPS - 1 ] + nChSh;
        if( rPA.bSymmAvr )
          apfSP[ nPS ] = aafSpc[ rPA.nK + nPS + 1 ] + nChSh;
      }

      double fW = afW[0];
      for( float *pfTS = pfSpcO, *pfPS = pfS0, *pfE = pfSpcO + rCfg.nP; pfTS < pfE; pfTS++ )
        *pfTS = fW * (*pfPS++); // spectrum with zero index is stored to output

      for( short nS = 0; nS < rPA.nK; nS++ )
      {
        double fW = afW[nS+1];
        for( float *pfTS = pfSpcO, *pfPSN = apfSN[nS], *pfPSP = apfSP[nS],
                   *pfE = pfSpcO + rCfg.nP; pfTS < pfE; pfTS++ )
        {
          double fV = rPA.bSymmAvr ? (*pfPSN++) + (*pfPSP++) : (*pfPSN++);
          *pfTS += fW * fV;
        }
      }
    }

    return true;
  } // ***

  void Done( void )
  {
    trCashedBufferN::Done();
    rBMA.Done();
    CDELETE( prSP );
  }

  bool SetErrorCode( short nErr ) { return (nErrorCode = nErr) == MC_STP_NO_ERROR; }

  static short * GetSignal( long lFrom, long lHowMany, long *plHowMany, void *pP )
  { return ((trMcSpcTrendDataSource*)pP)->Get( lFrom, lHowMany, plHowMany ); }

  trMcSpcTrendData rTD;     // source of multi-channel data

  trMcSpcTrendPrmP rPP;     // parameters for "primary" spectrums
  trMcSpcTrendPrmTA rPA;    // parameters for time-averaged spectrums

  trMcSpcTrendCfg rCfg;     // config. parameters for the initialized object based on input

  trBrTSpectralProcessor * prSP; // spectral processor (calculates spectrums)

  short nErrorCode;
};

// Template object for calculating the variance of noize for AR model ----------
struct trMcARVarProcR : trMcARVarProc, trCashedBufferN
{
  trMcARVarProcR( void ) { nErrorCode = MC_STP_NO_ERROR; }

  virtual bool Init( // Initialization
     trMcSpcTrendData * prTD,  // (In) source of multi-channel data
     trMcARVarPrm1 * prP1,     // (In) parameters for the AR var. trend (base)
     trMcARVarPrm2 * prP2,     // (In) parameters for the AR var. trend (settable)
     long nRecInBuf,           // (In) max. number of of output blocks in buffer
                               // (each block consists of "N" vectors, where "N"
                               // is the number of input signal channels; each vector
                               // consists of 3 values: (1) ratio of noize variance to signal
                               // variance; (2) noize variance; (3) signal variance;
                               // timing corresponds to *prP1 value
     trMcARVarTrendCfg * prCfg // (Out) config. parameters for the initialized object based on input
                   )
  {
    trMcARVarProcR::Done();

    bool bOK = (prTD && prP1 && prP2 && prCfg );
    bOK = bOK ? prTD->prDS && (prTD->nNmbCh > 0) && (prTD->nSampRate > 2) &&
                (prTD->fUPT > MALO) &&  // others in prTD are checked in prSP->Init()
                (prTD->nNmbChOut <= MC_STP_MAX_CHANNELS ) &&
                ChecktrMcARVarPrm1(prP1) && ChecktrMcARVarPrm2(prP2)
                : false;

    if( !bOK )
      return SetErrorCode( MC_STP_BAD_PRM );

    rTD = *prTD;  rP1 = *prP1;  rP2 = *prP2;

    rCfg.nAR = (prTD->nSampRate * rP1.fAROrder) + 0.5;
    rCfg.nEst = (prTD->nSampRate * rP1.fTEst) + 0.5;
    rCfg.nAR  = MIN( rCfg.nAR, rCfg.nEst/2 );

    rCfg.lT = (prTD->nSampRate * rP1.fTClc) + 0.5;

    if( rCfg.nEst < 3 || !rCfg.lT )
      return SetErrorCode( MC_STP_BAD_PRM );

    rCfg.nK = (rP2.fTAvr / rP1.fTClc) + 0.5;

    bOK = bOK ? SetBuffers( nRecInBuf ) : false;

    if( bOK )
      *prCfg = rCfg;

    return SetErrorCode( bOK ? MC_STP_NO_ERROR : MC_STP_GENERIC_ERR );
  }

  virtual bool Set( // Set new parameters
     trMcARVarPrm2 * prP2 = NULL, // (In/Opt) parameters for the AR var. trend (settable)
     trMcARVarPrm1 * prP1 = NULL  // (In/Opt) parameters for the AR var. trend (base;
                                  // if modified, then re-init of object is performed)
                   )      // Note: all fields in *prPP require complete recalculation
                          // of "primary" spectrums if modified
  {
    if( !rBMA.Initialized() )
      return SetErrorCode( MC_STP_NOT_INIT );

    if( !( (prP2 ? ChecktrMcARVarPrm2(prP2) : true) || (prP1 ? ChecktrMcARVarPrm1(prP1) : true) ) )
      return SetErrorCode( MC_STP_BAD_PRM );

    if( prP1 )
      return Init( &rTD, prP1, prP2 ? prP2 : &rP2, rBMA.N(), &rCfg );

    if( !prP2 )
      return SetErrorCode( MC_STP_NO_ERROR );

    rP2 = *prP2;
    rBMA.Reset();
    return SetErrorCode( MC_STP_NO_ERROR );
  }

  virtual bool Get( // Get parameters
     trMcSpcTrendData **pprTD = NULL, // (Out/opt) pointer to source of multi-channel data
     trMcARVarPrm1 * prP1 = NULL,     // (Out/opt) parameters for the AR var. trend (base)
     trMcARVarPrm2 * prP2 = NULL,     // (Out/opt) parameters for the AR var. trend (settable)
     trMcARVarTrendCfg * prCfg = NULL // (Out/opt) config. parameters for the initialized object based on input
                  )
  {
    if( !rBMA.Initialized() )
      return SetErrorCode( MC_STP_NOT_INIT );

    if( pprTD ) *pprTD = &rTD;
    if( prP1 ) *prP1 = rP1;
    if( prP2 ) *prP2 = rP2;
    if( prCfg ) *prCfg = rCfg;

    return true;
  }

  virtual bool GetARTrend( // Get AR var. trend in needed time segment (or max. possible time segment inside it)
          long *plF,        // (In/Out) time point  the first block of data
                            // on exit: min. available time point (time units: number of
          long *plT,        // (In/Out) time point of the last block of data
                            // on exit: max. available time point (time units: same as for the signal points)
          // should be: *plKF >= 0, *plKT > *plKF, quantity of (*plKT - *plKF + 1) may never be greater than
          // value of "nPntInBuf" used in Init()
          float **ppfDta    // (Out) pointer to the record with all data blocks (all channels)
                            // "*plKT - *plKF + 1" blocks
                            // !! memory is allocated inside and is deallocated on object's destruction
                  )// return true and *ppfSpc = NULL means that there is no data
  {
    if( !rBMA.Initialized() )
      return SetErrorCode( MC_STP_NOT_INIT );
    if( !plF || !plT || !ppfDta || ((plF && plT) && (*plT < *plF)) ||
         (*plT - *plF + 1 > trCashedBufferN::lN) )
      return SetErrorCode( MC_STP_BAD_PRM );

    *plF = MAX(rCfg.nK, *plF);

    if( *plF > *plT )
    {
      *plF = *plT = -1;
      return SetErrorCode( MC_STP_NO_ERROR );
    }

    rBMA.Update( plF, plT );
    *ppfDta = ((*plF >= 0) && (*plT >= *plF)) ? (float*)rBMA.Pos( *plF - rBMA.F() ) : NULL;
    return SetErrorCode( MC_STP_NO_ERROR );
  }

  // check boards for input segment & modify them to largest possible inside requested boards
  void CheckInput( long *plF, long *plT )
  {
    *plF = MAX(*plF, 0);
    long lDl = rCfg.lT,  // centers of signal segments (in signal vectors) are k*lDl
         lT = rCfg.nEst, // length of segment for AR estimator (in signal points)
         lT2 = lT / 2,
         lSF = (*plF * lDl) - lT2,          // first signal point
         lST = (*plT * lDl) - lT2 + lT - 1; // last signal point

    rTD.prDS->CheckBoards( &lSF, &lST ); // get largest possible interval inside the requested one
    *plF = ((lSF + lT2)/lDl) + ( ((lSF + lT2)%lDl) ? 1 : 0);
    *plT = ((lST - lT + 1 + lT2)/lDl);
    if( *plT < *plF ) { *plF = *plT = -1; }
  } // ***

  virtual void Fill( long lFromBufPos, long lFromInd, long lItems )  // fill needed part of buffer with segment with needed indexes
  {
    for( long nI = 0; nI < lItems; nI++ )
      ComputePrimaryARTrend( lFromInd + nI, (float*)Pos(lFromBufPos + nI) );
  } // ***

  struct trCashedBufferMAR : trCashedBufferN  // buffer for the moving averaged spectrums
  {
    bool Init( trMcARVarProcR * prASTP )
    { prSTP = prASTP; return trCashedBufferN::Init( prSTP->N() - MC_STP_MAX_AR_AVRPNT, prSTP->M() ); }

    virtual void CheckInput( long *plF, long *plT )
    {
      long lPSF = *plF - prSTP->rCfg.nK,
           lPST = *plT;

      prSTP->Update( &lPSF, &lPST );
      
      // !!! is it need
      lPST = MIN(lPST, lPSF + N());

      *plF = lPSF + prSTP->rCfg.nK,
      *plT = lPST;

      if( !( (*plF >= 0 ) && (*plT >= *plF) ) )
      {
        *plF = *plT = -1;
        return; // no data in these boards
      }
    }

    virtual void Fill( long lFromBufPos, long lFromInd, long lItems )
    {
      for( long nI = 0; nI < lItems; nI++ )
        prSTP->ComputeTimeAveragedARTrend( lFromInd + nI, (float*)Pos(lFromBufPos + nI) );
    }

    bool Initialized( void ) { return (bool) pB; }

    virtual ~trCashedBufferMAR( void ) {}

    trMcARVarProcR * prSTP;
  } rBMA;

  virtual short GetErrorCode( void ) { return nErrorCode; } // get error code after the last operation

  virtual ~trMcARVarProcR( void ){ trMcARVarProcR::Done(); }

// private:
  bool SetBuffers( long lRecInBuf )
  {
    long lRecSize = rTD.nNmbChOut * MC_ARTREND_RECLEN * sizeof(float); // size of one record with ratio, residuals' variance, signal variance
    bool bOK = trCashedBufferN::Init( lRecInBuf + MC_STP_MAX_AR_AVRPNT, lRecSize );
    return bOK ? rBMA.Init( this ) : false;
  } // ***

  // Compute "primary" spectrum and store it in given buffer
  bool ComputePrimaryARTrend( long lRecNmb, float *pfRec )
  {
    long lTC = lRecNmb*rCfg.lT,   // lTC - center of signal segment (in signal vectors)
         lTF = lTC - rCfg.nEst/2,
         lTT = lTF + rCfg.nEst - 1;
    double afVar[MC_STP_MAX_CHANNELS],
           afSgm[MC_STP_MAX_CHANNELS];
    short anAO[MC_STP_MAX_CHANNELS];

    bool bOK = ARParametersM( &rTD, lTF, lTT, rCfg.nAR, (short)rP1.nModel,
                              afVar, afSgm, anAO );
    if( !bOK )
      bOK = false;

    for( short nCh = 0; nCh < rTD.nNmbChOut; nCh++ )
    {
      float *pfCR = (pfRec + (nCh*MC_ARTREND_RECLEN));
      double fVar = afVar[nCh], fSgm = afSgm[nCh];
      pfCR[0] = (fVar > MALO) ? fSgm/fVar : 0.,  pfCR[1] = fSgm,  pfCR[2] = fVar;
    }

    return bOK;
  } // ***

  bool ComputeTimeAveragedARTrend( long lRecNmb, float *pfRec )
  {
    short nNmbP = rCfg.nK + 1;     // number of primary spectrums

    float * aafDta[MC_STP_MAX_AR_AVRPNT]; // pointers to primary spectrums' records
    for( short nPS = -rCfg.nK, nPT = 0; nPS <= nPT; nPS++ )
      if( !(bool) (aafDta[nPS + rCfg.nK] = (float*)trCashedBufferN::Pos(nPS + lRecNmb - trCashedBufferN::lF) ))
        return false;

    double fW = 0., afW[MC_STP_MAX_AR_AVRPNT];  // weights for time-averaging
    for( short nPS = 0; nPS <= rCfg.nK; nPS++ )
    {
      afW[nPS] = Window( nPS/(double)(rCfg.nK + 1), rP2.nWinType );
      fW += afW[nPS];
    }

    for( short nPS = 0; nPS <= rCfg.nK; nPS++ )
      afW[nPS] /= fW;

    for( int nCh = 0; nCh < rTD.nNmbChOut; nCh++ )
    {
      int nChSh = nCh * MC_ARTREND_RECLEN; // offset from the beginning of spc. record to spc. for curr. channel
      // pointers to spectrums for current channel:
      float * pfS0 = aafDta[rCfg.nK] + nChSh, // rightmost non averaged record
            * apfSN[MC_STP_MAX_AR_AVRPNT/2],  // non averaged record with negative time shift
            * pfRecO = pfRec + nChSh;         // time averaged record

      for( short nPS = 0; nPS < rCfg.nK; nPS++ )
        apfSN[ nPS ] = aafDta[ rCfg.nK - nPS - 1 ] + nChSh;

      double fW = afW[0];
      for( float *pfTS = pfRecO, *pfPS = pfS0, *pfE = pfRecO + MC_ARTREND_RECLEN; pfTS < pfE; pfTS++ )
        *pfTS = fW * (*pfPS++); // weighted record with zero index is stored to output

      for( short nS = 0; nS < rCfg.nK; nS++ )
      {
        double fW = afW[nS+1];
        for( float *pfTS = pfRecO, *pfPSN = apfSN[nS],
                   *pfE = pfRecO + MC_ARTREND_RECLEN; pfTS < pfE; pfTS++ )
        {
          double fV = *pfPSN++;
          *pfTS += fW * fV;
        }
      }
    }

    return true;
  } // ***

  void Done( void )
  {
    trCashedBufferN::Done();
    rBMA.Done();
  }

  bool SetErrorCode( short nErr ) { return (nErrorCode = nErr) == MC_STP_NO_ERROR; }

  trMcSpcTrendData rTD;    // source of multi-channel data

  trMcARVarPrm1 rP1;       // base parameters for the AR var. trend
  trMcARVarPrm2 rP2;       // settable parameters for the AR var. trend
  trMcARVarTrendCfg rCfg;  // Config. structure for AR residuals trend

  short nErrorCode;
};

//------------------------------------------------------------------------------
// Code (ext.) -----------------------------------------------------------------
//------------------------------------------------------------------------------

// Create object for calculating the trend of spectrums ------------------------
trMcSpcTrendProc * McCreateSpcTrendProc( void )
{
  try         { return (trMcSpcTrendProc *) new trMcSpcTrendProcR(); }
  catch(...)  { return NULL; }
} // ***

// Create object for calculating the trend of AR model residuals' variance -----
trMcARVarProc * McCreateARVarProcProc( void )
{
  try         { return (trMcARVarProc *) new trMcARVarProcR(); }
  catch(...)  { return NULL; }
} // ***

//------------------------------------------------------------------------------

//---------------------------------------------------------------------------
trMcSpcTrendPrmP::trMcSpcTrendPrmP( void )
{
  fDT = MC_STP_SPC_SEGM_DEF;
  fAl = MC_STP_INTSEC_DEF;
  nLag = 0;
  trBrSpcFrqCfg rFCC(MC_STP_SPC_TYPE_DEF);  rFC = rFCC;
  trBrSpcEstCfg rSCC(MC_STP_SPC_TYPE_DEF);  rSC = rSCC;
} // ***

//---------------------------------------------------------------------------
bool trMcSpcTrendPrmP::operator == (const trMcSpcTrendPrmP & rP) const
{
  return FLOAT_EQ( fDT, rP.fDT) && FLOAT_EQ( fAl, rP.fAl ) && nLag == rP.nLag && (rSC == rP.rSC);
  // rFC is not temporarily compared
} // ***

//---------------------------------------------------------------------------
trMcSpcTrendPrmTA::trMcSpcTrendPrmTA( void )
{
  nSpcMode = Averaged;
  bSymmAvr = false; // !!true;
  nK = MC_STP_TIMEAVR_DEF;
  nWinType = MC_STP_WINDOW_DEF;

  fThr = MC_STP_THRESHOLD_DEF;
  fTMax = MC_STP_MAXSEGMENT_DEF;
} // ***

//---------------------------------------------------------------------------
bool trMcSpcTrendPrmTA::operator == (const trMcSpcTrendPrmTA & rP ) const
{
  if( rP.nSpcMode != nSpcMode )
    return false;

  return (nSpcMode == Averaged) ?
           (nK == rP.nK) && (nWinType == rP.nWinType) && BOOL_EQ(bSymmAvr, rP.bSymmAvr) :
           FLOAT_EQ( rP.fThr, fThr) && FLOAT_EQ( rP.fTMax, fTMax);
} // ***

//------------------------------------------------------------------------------
trMcARVarPrm1::trMcARVarPrm1( void )  // set defaults
{
  fAROrder = MC_STP_DEF_AR_ORDER, fTEst = MC_STP_DEF_AR_EST, fTClc = MC_STP_DEF_AR_CLC;
  nModel = MC_STP_DEF_AR_MODEL;
} // ***

//------------------------------------------------------------------------------
bool trMcARVarPrm1::operator == ( const trMcARVarPrm1 & rP ) const
{
  return FLOAT_EQ( fAROrder, rP.fAROrder ) && FLOAT_EQ( fTEst, rP.fTEst ) &&
         FLOAT_EQ( fTClc, rP.fTClc ) && (nModel == rP.nModel);
} // ***

//------------------------------------------------------------------------------
trMcARVarPrm2::trMcARVarPrm2( void )  // set defaults
{  fTAvr = MC_STP_DEF_AR_AVR, nWinType = MC_STP_WINDOW_DEF;  } // ***

//------------------------------------------------------------------------------
bool trMcARVarPrm2::operator == ( const trMcARVarPrm2 & rP ) const
{ return FLOAT_EQ( fTAvr, rP.fTAvr ) && (nWinType == rP.nWinType); } // ***

//------------------------------------------------------------------------------
// Source of locals ------------------------------------------------------------
//------------------------------------------------------------------------------

// Local | calculate autocorrelation function for the given signal segment -----
static bool ACovF(
             float *pfS,     // (In) buffer with signal
             int nN,         // (In) number of signal points in *pfS
             int nM,         // (In) number of lags of ACF
             float *pfACF    // (Out) values with ACovF ("nM+1" values; values are biased,
                             // equally normalized by (1./nN)), pfACF[0] is signal variance
                             // pfACF[i]/pfACF[0], i = 0,..., nM are estimators of autocorrelation function
                  )
{

  float fMean, fVar, fSQnorm;
  korr = false;
  ACorrF( pfS, pfACF, nN, nM, fMean, fVar, fSQnorm );

  return  GetFFTError() == NO_FFT_ERROR;
} // ***

// Local | calculate AR parameters for sigle channel signal --------------------
static bool ARParameters( float *pfS, int nP, short nModel, short *pnAO,
                                    double *pfVar,  double *pfSgm, double *pfA )
{
  if( nModel != MC_ARMODEL_LEVDRB )
    return false; // !!! not implemented

  int nAO = *pnAO; // requested AR order
  float *pfACF = new float[2*(nAO + 1)],
        *pfAP = (pfACF + (nAO + 1));

  bool bOK = ACovF( pfS, nP, nAO, pfACF );
  if( bOK ) bOK = ARParamLevDurb( pfACF, pnAO, &pfAP, pfSgm );

  if( bOK )
  {
    *pfVar = pfACF[0];
    if( pfA )
      for( int nP = 0; nP <= *pnAO; nP++ ) pfA[nP] = (double) pfAP[nP];
  }
  else
  {
    *pnAO = 0, *pfVar = 0.,  *pfSgm = 0.;
  }

  delete [] pfACF;
  return bOK;
}  // ***

// Local | calculate AR parameters for multi-channel signal --------------------
static bool ARParametersM( trMcSpcTrendData * prTD, long lF, long lT, short nAO,
            short nModel, double *pfVar, double *pfSgm, short *pnAO, double *pfA )
{
  long lHM = 0;
  short *pnB = prTD->prDS->Get( lF, lT - lF + 1, &lHM );
  if( !pnB || (lHM != lT - lF + 1) )
    return false;

  float *pfS = (float*) malloc( lHM*sizeof(float) + (pfA ? (nAO+1)*sizeof(double) : 0) );  // for one channel signal signal
  double *pfAs = pfA ? (double*) (pfS + lHM) : NULL;  // for AR parameters

  bool bOK = (bool)pfS;

  for( int nCh = 0, nChR = 0, nNmbCh = prTD->nNmbCh;  bOK && (nCh < nNmbCh); nCh++, nChR++ )
  {
    if( bOK ) bOK = (nChR < prTD->nNmbChOut);
    if( !bOK || (prTD->pbChOn ? !prTD->pbChOn[nCh] : false) )
      continue;

    short *pnBC = pnB + nCh; // first data point for channel nCh (nChR)
//    for( float *pfSC = pfS, *pfE = pfS + lHM;  pfSC < pfE;  pfSC++ )
//      *pfSC = (float)*pnBC,  pnBC += nNmbCh;
    for( float *pfSC = pfS, *pfE = pfS + lHM - 1;  ;  )
    {
      *pfSC = (float)*pnBC;  if( pfSC == pfE ) break;
      pfSC++,  pnBC += nNmbCh;
    }

    short nAOs = nAO;
    double fV = 0., fSgm = 0.;
    bOK = ARParameters( pfS, lHM, nModel, &nAOs, &fV, &fSgm, pfAs );
    pfVar[nChR] = fV;               // zero if !bOK
    pfSgm[nChR] = fSgm;             // zero if !bOK
    if( pnAO ) pnAO[nChR] = nAOs;   // zero if !bOK

    if( bOK )
    {  if( pfA ) memcpy( pfA + (nChR*(nAO+1)), pfAs, (nAO+1)*sizeof(double) ); }
    else
      bOK = false;  // debug
  }

  if( pfS ) free(pfS);
  return bOK;
} // ***

// End of file -----------------------------------------------------------------

