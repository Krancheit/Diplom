{*************************************************************************
  Module
    Common. Application init routines
  File
    cw_appl.pas
  Comment
    Utility routines to initiate application common vars
  Modified
    Date      Person            Comment
    ----------------------------------------------------------------------
    30-Sep-19 Abasov E.         CwApplStdInit: silentmode added
    25-Jul-14 Abasov E.         Handle close added
    10-Jul-13 Abasov E.         CwApplSetSingleLanguage added
    25-Nov-04 Abasov E.         CwApplStdDone added, CwApplStdInit changed
    01-Mar-04 Riabov A.         BDE stuff moved to ct_table.
    09-Sep-03 Riabov A.         CwApplSetMDIForm/CwApplGetMDIForm added.
    15-May-01 Abasov E.         CMM_SECTION moved to Cw_Res.pas
    11-May-01 Abasov E.         LoadStr()<-->CwLoadStr()

    ====== Revision on top ===============================================
    30-Nov-96 Riabov A.         Original
    02-Jul-97 Riabov A.         PAnsiChar functions added.
    06-Nov-97 Bolkhovitin V.    Appl init changed.
    13-Nov-97 Riabov A.         Profile functions added.
    19-May-98 Bolkhovitin V.    Bugs(?) fixed in CwApplStdInit
    16-Jul-98 Riabov A.         Get language proc added.
    31-Jul-98 Riabov A.         Appl init changed.
    29-Oct-98 Riabov A.         Changes.
    03-Jan-99 Riabov A.         Fixes.
    19-Feb-99 Riabov A.         Common INI sections moved to the interface.
    01-Mar-99 Riabov A.         Do not use qrep here.
    28-May-99 Riabov A.         CwApplGetLanguage() changed.
    03-Jun-99 Riabov A.         CwApplGetCharset() added.
    12-Apr-00 Riabov A.         Tuned for VER80.
    23-Jun-00 Riabov A.         Tuned for CBuilder 5.0.
    14-Sep-00 Riabov A.         In CwApplInitSession() SQL hour glass
                                cursor is handled. 
    19-Sep-00 Riabov A.         Changes for VER130
*************************************************************************}

unit Cw_appl;

interface

uses
  SysUtils, WinTypes, WinProcs, Messages, Classes, Graphics, Controls, Forms;

const {==================================================================}
  INIF_SECTION = 'INI Files';
  CMM_TEMP_DIR_KEY = 'TempDir';

{ PROCEDURES ============================================================}

procedure CwApplStdInit(sTitle, sHelp: string; nUniq: boolean; sHaltMsg: string; bSilentMode: boolean = false);
procedure CwApplStdInitP(psTitle, psHelp: PAnsiChar; nUniq: boolean; psHaltMsg: PAnsiChar; bSilentMode: boolean = false);
{ Standard application initialization }

procedure CwApplStdDone;
{ Standard application deinitialization }

function CwApplGetStdProfile(sProfile: string): string;
function CwApplGetStdProfileP(psDest, psProfile: PAnsiChar): PAnsiChar;
{ Returns full path to the profile in the EXE directory }

procedure CwApplSetProfile(sProfile: string);
procedure CwApplSetProfileP(sProfile: PAnsiChar);
function CwApplGetProfile: string;
function CwApplGetProfileP(psDest: PAnsiChar): PAnsiChar;
function CwApplGetSysProfile: string;
{ Get/Set standard program profile }

procedure CwApplSetSingleLanguage(sADefaultLanguage: string);
function CwApplGetLanguage(sProfilePath, sDefaultLanguage: string): string;

{$IFNDEF VER80}
function CwApplGetCharset: TFontCharset;
{ Returns program language and charset }
{$ENDIF}

procedure CwApplSetMDIForm(prForm: TForm);
function CwApplGetMDIForm: TForm;

implementation

uses
  Cf_fmt, Cw_util, Cw_dlg, cw_res;

var
  sApplProfile: string = ''; { Standard profile }
  prMDIForm: TForm = nil;    { MDI app main form pointer }
  hPrevInstance: THandle = 0;
  sSingleLanguage: string = '';

{ PROCEDURES ============================================================}

{* EXTERNAL **************************************************************
  Standard application deinitialization
*************************************************************************}
procedure CwApplStdDone;
begin
  if hPrevInstance <> 0 then
  begin
    ReleaseMutex(hPrevInstance);
    CloseHandle(hPrevInstance);
    hPrevInstance := 0;
  end
end;

{* EXTERNAL **************************************************************
  Standard application initialization
  Parameters
    sTitle - application title
    sHelp  - application help file
    nUniq  - if TRUE the procedure check if the application is already
             running and halts if so.
*************************************************************************}
procedure CwApplStdInit(sTitle, sHelp: string; nUniq: boolean;
  sHaltMsg: string; bSilentMode: boolean);

  procedure CorrectShortDate;
  var i, LastY, YCount:integer;
  begin
    YCount:=0;
    LastY:=0;
    for i:=1 to Length(ShortDateFormat) do
    begin
      if (ShortDateFormat[i]='y') or (ShortDateFormat[i]='Y') then
      begin
        inc(YCount);
        LastY:=i;
      end;
    end;
    if LastY=0 then
    begin
      ShortDateFormat:=ShortDateFormat + DateSeparator;
      LastY:=Length(ShortDateFormat);
    end;
    for i := YCount to 3 do
      System.Insert('y', ShortDateFormat, LastY);
  end;

const
  asDay: array [1..7] of string[3] = ('Вос', 'Пон', 'Втр', 'Срд', 'Чет',
    'Пят', 'Суб');
var
  sMutexName: array[0..255] of Char;

begin
  if nUniq then
  begin
    StrPCopy(sMutexName, sTitle);
    hPrevInstance := CreateMutex(nil, FALSE, sMutexName);

    if GetLastError = ERROR_ALREADY_EXISTS then
    begin
      CwApplStdDone;
      if not bSilentMode then
        CwShowWarning(sHaltMsg);
      Halt;
    end;
  end;

  CurrencyString := '';
  CurrencyFormat :=  3;
  NegCurrFormat :=  5;
  ThousandSeparator := ',';
  CurrencyDecimals := 2;
  DecimalSeparator := '.';

  CorrectShortDate;

{$IFDEF RUSSIAN}
  for i:=1 to 7 do
    ShortDayNames[i] := asDay[i];
{$ENDIF}

  Application.Title := sTitle;
  Application.HelpFile := sHelp;

{$IFNDEF VER80}
  Application.UpdateFormatSettings := false;
{$ENDIF}

  CwDlgUpdateCaptions;
end;

{* EXTERNAL **************************************************************
*************************************************************************}

procedure CwApplStdInitP(psTitle, psHelp: PAnsiChar; nUniq: boolean;
  psHaltMsg: PAnsiChar; bSilentMode: boolean);
var
  sTitle, sHelp, sHaltMsg: string;
begin
  CfStrPas(sTitle, psTitle);
  CfStrPas(sHelp, psHelp);
  CfStrPas(sHaltMsg, psHaltMsg);
  CwApplStdInit(sTitle, sHelp, nUniq, sHaltMsg, bSilentMode);
end;

{* EXTERNAL **************************************************************
  Returns full path to the profile, assuming that we use application EXE
  directory as the file location.
  Parameters
    sProfile - profile name
*************************************************************************}

function CwApplGetStdProfile(sProfile: string): string;
begin
  Result := ExtractFilePath(Application.ExeName) + sProfile;
end;

{* EXTERNAL **************************************************************
*************************************************************************}

function CwApplGetStdProfileP(psDest, psProfile: PAnsiChar): PAnsiChar;
var
  s, sProfile: string;
begin
  CfStrPas(sProfile, psProfile);
  s := CwApplGetStdProfile(sProfile);
  Result := StrPCopy(psDest, s);
end;

{* EXTERNAL **************************************************************
*************************************************************************}

procedure CwApplSetProfile(sProfile: string);
begin
  sApplProfile := sProfile;
end;

{* EXTERNAL **************************************************************
*************************************************************************}

procedure CwApplSetProfileP(sProfile: PAnsiChar);
var
  sP: string;
begin
  CfStrPas(sP, sProfile);
  CwApplSetProfile(sP);
end;

{* EXTERNAL **************************************************************
*************************************************************************}

function CwApplGetProfile: string;
begin
  Result := sApplProfile;
end;

{* EXTERNAL **************************************************************
*************************************************************************}

function CwApplGetSysProfile: string;
begin
  Result := CwGetPrivateProfile(CwApplGetProfile, INIF_SECTION, 'System');

  if Result='' then
    Result := CwApplGetProfile
  else
    Result := CwApplGetStdProfile(Result);
end;

{* EXTERNAL **************************************************************
*************************************************************************}

function CwApplGetProfileP(psDest: PAnsiChar): PAnsiChar;
var
  s: string;
begin
  s := CwApplGetProfile;
  Result := StrPCopy(psDest, s);
end;

{* EXTERNAL **************************************************************
*************************************************************************}

procedure CwApplSetSingleLanguage(sADefaultLanguage: string);
begin
  sSingleLanguage := sADefaultLanguage;
end;

{* EXTERNAL **************************************************************
  Returns program language
*************************************************************************}

function CwApplGetLanguage(sProfilePath, sDefaultLanguage: string): string;
var
  s: string;
begin
  if sSingleLanguage = '' then
  begin
{$IFDEF USEPROFILE}
  s := CwGetPrivateProfile(sProfilePath, CMM_SECTION, 'Language');
{$ELSE}
  s := CwLoadStr(499);
{$ENDIF}
  end
  else
    s := sSingleLanguage;

  if sDefaultLanguage='' then
    sDefaultLanguage := 'English';

  if s='' then
    s := sDefaultLanguage;

  Result := s;
end;

{* EXTERNAL **************************************************************
  Returns program font char set
*************************************************************************}

{$IFNDEF VER80}
function CwApplGetCharset: TFontCharset;
var
  s: string;
  c: longint;
begin
  s := CwLoadStr(500);

  if s='' then
    s := 'DEFAULT_CHARSET';

  if IdentToCharset(s, c) then
    Result := c
  else
    Result := 1;
end;
{$ENDIF}

{* EXTERNAL **************************************************************
  Sets MDI app main form
*************************************************************************}
procedure CwApplSetMDIForm(prForm: TForm);
begin
  prMDIForm := prForm;
end;

{* EXTERNAL **************************************************************
  Returns MDI app main form
*************************************************************************}
function CwApplGetMDIForm: TForm;
begin
  Result := prMDIForm;
end;

initialization

finalization
  CwApplStdDone;

end.

{ END OF FILE ************************************************************** }
