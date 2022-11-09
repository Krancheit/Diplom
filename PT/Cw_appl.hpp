// CodeGear C++Builder
// Copyright (c) 1995, 2010 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Cw_appl.pas' rev: 22.00

#ifndef Cw_applHPP
#define Cw_applHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member functions
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cw_appl
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
#define INIF_SECTION L"INI Files"
#define CMM_TEMP_DIR_KEY L"TempDir"
extern PACKAGE void __fastcall CwApplStdDone(void);
extern PACKAGE void __fastcall CwApplStdInit(System::UnicodeString sTitle, System::UnicodeString sHelp, bool nUniq, System::UnicodeString sHaltMsg, bool bSilentMode = false);
extern PACKAGE void __fastcall CwApplStdInitP(char * psTitle, char * psHelp, bool nUniq, char * psHaltMsg, bool bSilentMode = false);
extern PACKAGE System::UnicodeString __fastcall CwApplGetStdProfile(System::UnicodeString sProfile);
extern PACKAGE char * __fastcall CwApplGetStdProfileP(char * psDest, char * psProfile);
extern PACKAGE void __fastcall CwApplSetProfile(System::UnicodeString sProfile);
extern PACKAGE void __fastcall CwApplSetProfileP(char * sProfile);
extern PACKAGE System::UnicodeString __fastcall CwApplGetProfile(void);
extern PACKAGE System::UnicodeString __fastcall CwApplGetSysProfile(void);
extern PACKAGE char * __fastcall CwApplGetProfileP(char * psDest);
extern PACKAGE void __fastcall CwApplSetSingleLanguage(System::UnicodeString sADefaultLanguage);
extern PACKAGE System::UnicodeString __fastcall CwApplGetLanguage(System::UnicodeString sProfilePath, System::UnicodeString sDefaultLanguage);
extern PACKAGE Graphics::TFontCharset __fastcall CwApplGetCharset(void);
extern PACKAGE void __fastcall CwApplSetMDIForm(Forms::TForm* prForm);
extern PACKAGE Forms::TForm* __fastcall CwApplGetMDIForm(void);

}	/* namespace Cw_appl */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE)
using namespace Cw_appl;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Cw_applHPP
