@echo off
rem *************************************************************************
rem $Id$
rem Module
rem   EEG WIN
rem File
rem   MakeExe.Bat
rem Comment
rem   "Make" file for CBuilder 5.0
rem *************************************************************************

if exist ..\Work goto con1
  md ..\Work 
:con1
  
copy *.* ..\Work

cd ..\Work
del *.il*
del *.tds

rem "%CBUILDER50%\make" -DBCB50 -f Exe.mak
cd ..\Src

rem End of file *************************************************************
