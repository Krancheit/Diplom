//---------------------------------------------------------------------------

#ifndef SpektDrawH
#define SpektDrawH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Mc_SpectrTrendHi.h>
#include <math.h>
#include <ExtCtrls.hpp>

#include <Mc_Freque.h>



//---------------------------------------------------------------------------

class TFormSpectrTrend : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TLabel *Label5;
        TLabel *LabelToTime;
        TLabel *Label6;
        TLabel *Label4;
        TLabel *LabelFromTime;
        TLabel *Label1;
        TEdit *EditTime;
        TButton *ButtonFastFwd;
        TButton *ButtonFwd;
        TButton *ButtonRew;
        TButton *ButtonFastRew;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall ButtonFwdClick(TObject *Sender);

private:	// User declarations

    // navigator bar and spectrum trend callback
    struct trSpectrTrendCallback: trMcSpcTrendCallback
    {
      TFormSpectrTrend* prSigForm;
      trSpectrTrendCallback() { prSigForm = NULL; }

      virtual void SetPosition(double fPos)
      { }

      virtual long GetRightBorder()
      { return -1; }

      virtual TrMcExamine* GetExamine()
      { return NULL; }
      } rSTCallback;
	  friend class trSpectrTrendCallback;

public:  // User declarations
		__fastcall TFormSpectrTrend(TComponent* Owner);
		__fastcall ~TFormSpectrTrend();
		trMcSpectrTrend* SpTr;
		trMcSpcTrendData rD;  // (In) data source
        trMcSpcTrendPrmE rP;  // (In) parameters for spectrum trend
		trMcSpcTrendDataSource *prDS;
		//McSpectrDataFreq *prFreq;
		  // (In) parameters for Sin

};

//---------------------------------------------------------------------------
extern PACKAGE TFormSpectrTrend *FormSpectrTrend;
//---------------------------------------------------------------------------
#endif
