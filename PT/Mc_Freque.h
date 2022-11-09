//---------------------------------------------------------------------------

#ifndef Mc_FrequeH
#define Mc_FrequeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include "Mc_SpectrTrendProc.h"


const double FRQ_MIN   =  5.;  	// freq. of sinusoid (Hz) for the first channel
const double FRQ_MAX   =  15.; 	// freq. of sinusoid for the last channel
const double FRQ_DELTA  =  4;  	// curr. freq of sinusoid varies in +-FRQ_DLT
const double TIME_DELTA =  10.; 	// trend of frq. is periodic with this period (Sec)



//---------------------------------------------------------------------------
struct McSpectrDataFreq
{
  double frqmin;
  double frqmax;
  double frqdelta;
  double timeper;


  McSpectrDataFreq(double frqmi = FRQ_MIN, double frqma = FRQ_MAX,
					 double frqdelt = FRQ_DELTA, double timepe = TIME_DELTA)
  {
   frqmin = frqmi, frqmax = frqma, frqdelta = frqdelt, timeper = timepe;
  }
  bool operator == ( const McSpectrDataFreq & rSFreq ) const
  { return (frqmin == rSFreq.frqmin) && (frqmax == rSFreq.frqmax) &&
		   (frqdelta == rSFreq.frqdelta) && (timeper == rSFreq.timeper); }
};

static  McSpectrDataFreq rDataFreq = McSpectrDataFreq() ;

//---------------------------------------------------------------------------
struct McFreqApply
 {
	virtual void Apply( void * ) = 0;
 };

//---------------------------------------------------------------------------
class TFormParamSin : public TForm
{
__published:	// IDE-managed Components
	TPageControl *pgc1;
	TTabSheet *ts1;
	TButton *btnOK;
	TButton *btnCancel;
	TTimer *tmrApply;
	TButton *btnDefault;
	TPanel *pnl2;
	TGroupBox *grpMaxFreq;
	TLabel *lblHz1;
	TTrackBar *TrackBarMaxFreq;
	TPanel *pnlMaxFreq;
	TGroupBox *grpMinFreq;
	TLabel *lbl5;
	TTrackBar *TrackBarMinFreq;
	TPanel *pnlMinFreq;
	TGroupBox *grpDeltaFreq;
	TLabel *lbl6;
	TTrackBar *TrackBarDeltaFreq;
	TPanel *pnlDeltaFreq;
	TGroupBox *grpPeriod;
	TLabel *lbl7;
	TTrackBar *TrackBarPeriod;
	TPanel *pnlPeriod;
	void __fastcall btnOKClick(TObject *Sender);
	void __fastcall btnDefaultClick(TObject *Sender);
	void __fastcall TrackBarChange(TObject *Sender);
	/*void __fastcall FormShow(TObject *Sender); */
private:	// User declarations
	McSpectrDataFreq rFreqIn, rFreqOut,rFreqApplied; //main original,current,applied
	McSpectrDataFreq *prFreqIn;                      //main pointer
	McFreqApply *prFreqAp;                               //main apply
	bool BlockChangings;

	void ReadParamFreq (McSpectrDataFreq *prFreqConfig);

public:		// User declarations


	__fastcall TFormParamSin(TComponent* Owner,
							McSpectrDataFreq * rFreq,
							McFreqApply * prFreqAp = NULL);

	//__fastcall ~TFormParamSin();

	void RestoreFreqOptions(McSpectrDataFreq * rFreq);

};

McSpectrDataFreq *BrGetSpcTrendFreq( McSpectrDataFreq *prDataFreq=NULL );

void BrSetSpcTrendFreq(McSpectrDataFreq *prDataFreq = NULL );
//---------------------------------------------------------------------------
bool McEditSetFreq (void );

//---------------------------------------------------------------------------
extern PACKAGE TFormParamSin *FormParamSin;
//---------------------------------------------------------------------------
#endif
