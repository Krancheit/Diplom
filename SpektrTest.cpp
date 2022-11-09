//---------------------------------------------------------------------------

#include <vcl.h>
#include <cw_appl.hpp>
#pragma hdrstop
USEFORM("Mc_SpectrTrendHi.cpp", FrameSpectrTrend); /* TFrame: File Type */
USEFORM("Mc_CfgEnergyRatioTrend.cpp", FormERTrendBands);
USEFORM("Mc_FreqBandsForm.cpp", FormFreqBands);
USEFORM("Mc_Freque.cpp", FormParamSin);
USEFORM("SpektDraw.cpp", FormSpectrTrend);
USEFORM("Mc_SpectrTrendSettings.cpp", FormSpectrTrendSettings);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 CwApplSetProfile(CwApplGetStdProfile("SpektrDraw.ini"));
				 Application->Initialize();
		Application->CreateForm(__classid(TFormSpectrTrend), &FormSpectrTrend);
		Application->Run();
		}
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
