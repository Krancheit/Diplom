/*************************************************************************
  Module
    Mortara.
  File
    Br_Mortara.h
  Comment
    Mortara DLL intarface.
  Modified
    Date      Person            Comment
    ----------------------------------------------------------------------
    06-Jun-07 Abasov E.         1st & 2nd amplitudes to trMcSpcTrendDta
    02-Apr-07 Abasov E.         Renamed (Mc_ExtEEGConnect.h)
    30-Mar-07 Abasov E.         MC_STP_MAX_CHANNELS <--> MC_STP_MAX_PD_CHANNELS
    26-Mar-07 Abasov E.         MC_STP_CHAN_NAME_LEN value changed
    22-Mar-07 Abasov E.         Original
*************************************************************************/

#ifndef __MC_EEXTEEGCONNECT_H
#define __MC_EEXTEEGCONNECT_H

// Includes -----------------------------------------------------------------

// Const --------------------------------------------------------------------
#define MC_STP_MAX_PD_CHANNELS   4    // max. number of signal channels in trend
#define MC_STP_CHAN_NAME_LEN    10   // chan name length

// Types --------------------------------------------------------------------
#pragma option push -a4

// device (data receive) configuration (received from outside) -----------------
struct TrDeviceCfg
{
  short nSampleRate;    // sample rate
  long lChanMask;       // mask of channels. Will be used first (low) 8 bits.
                        // E.g. 0x000000FF - all channels are on
};

// processed data configuration (sent to outside) ------------------------------
struct TrProcessedDataCfg
{
  short nChannels;     // number of channels in spectral trend (<= MC_STP_MAX_PD_CHANNELS)
  double fSampleRate;  // out data (spectral trend info) sample rate (im Hz); may be less than 1.
  struct
  { // Configuration of each channel for spectrum trend
    short nFirst;    // first electrode in channel (0,1,...,7)
    short nSecond;   // second electrode in channel (0,1,...,7)
                     // channel is formed as "signal in first electrode" - "signal in second electrode"
    char asName[MC_STP_CHAN_NAME_LEN];  // name of channel (e.g. " Fp1 - Fp2")
  } asChan[MC_STP_MAX_PD_CHANNELS];
};

// Processed data (output record will contain number of sets of such structures,
// each set consisting of TrProcessedDataCfg::nChannels structures, number of sets
// is determined by the time passed from the previous output and ---------------
// TrProcessedDataCfg::fSampleRate parameter -----------------------------------
struct TrProcessedData
{ // !!! to be completed later; struct will contain also other parameters of spectrum trend
  double fSEFHi;     // SEF frequency (high)
  int nHiSEFPercent; // percent for high SEF (e.g. 90)

  double fSEFLo;     // SEF frequency (high)
  int nLoSEFPercent; // percent for low SEF (e.g. 50)

  double fAmp1,      // 1st peak (max of spectrum) mkV^2/Hz
         fFrq1,      // Frequency on which 1st peak is reached (Hz)
         fAmp2,      // 2nd peak of spectrum mkV^2/Hz
         fFrq2;      // Frequency on which 2nd peak is reached (Hz)
};

// ----------------------------------------------------------------------------
typedef long TrMonitorID;  // ID passed to Neurotravel program on it's start.
                           // Is used to determine what monitor is controlled by
                           // "Poso letto"

// Base object used to receive EEG from a monitor and to send processed data to
// this monitor ----------------------------------------------------------------
class TrMortara
{
public:
  virtual ~TrMortara() {};

  // Initialization:
  virtual bool Init(
    TrMonitorID rMonitorID,                 // (In) monitor ID
    TrProcessedDataCfg *prProcessedDataCfg, // (In) configuration of processed data
    TrDeviceCfg *prDeviceCfg                // (Out) device configuration
    ) = 0;  // Return: on error - false

  // Set processed data configuration (is set in Init() method for the first time)
  virtual bool Set(
    TrProcessedDataCfg *prProcessedDataCfg // (In) configuration of processed data
    ) = 0;    // Return: on error - false

  // Receive (read) data from Mortara device
  virtual bool ReceiveData(
    short *pnBuffer,        // (Out) data buffer (sets of vectors,
                            // each vector contains signal data for all channels
                            // (see TrDeviceCfg::lChanMask), e.g. 8
    long nNeedVectors,      // (In) number of needed vectors
    long *pnReceivedVectors // (Out) number of actually read vectors
    ) = 0;    // Return: on error - false

  // Send processed EEG data outside (see comments to TrProcessedData)
  virtual bool SendProcessedData(
    TrProcessedData *prPData, // processed data (array of TrProcessedData)
    long nRecords             // number of records
                              // (each record contains number of sets of
                              // TrProcessedData, each set consisting of
                              // TrProcessedDataCfg::nChannels structures,
                              // i.e. 'lenght' of prPData array will be
                              // TrProcessedDataCfg::nChannels * nRecords)
    ) = 0;  // Return: on error - false
};
#pragma option pop

#endif
// End of file --------------------------------------------------------------
