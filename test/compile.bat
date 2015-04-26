@echo off
rem "Compiling script for Visual Studio"

setlocal EnableDelayedExpansion

where cl.exe > nul 2>&1
if %errorlevel% == 1 @(
    set VSCOMNTOOLS=""
    if "%VS90COMNTOOLS%"  neq "" set VSCOMNTOOLS="%VS90COMNTOOLS%"
    if "%VS100COMNTOOLS%" neq "" set VSCOMNTOOLS="%VS100COMNTOOLS%"
    if "%VS110COMNTOOLS%" neq "" set VSCOMNTOOLS="%VS110COMNTOOLS%"
    if "%VS120COMNTOOLS%" neq "" set VSCOMNTOOLS="%VS120COMNTOOLS%"
    if "%VS130COMNTOOLS%" neq "" set VSCOMNTOOLS="%VS130COMNTOOLS%"

    if "%_RECURSION%" == "" (
        if !VSCOMNTOOLS! neq "" (
            start cmd /K "set _RECURSION=yes & !VSCOMNTOOLS!\vsvars32.bat & %0 %1"
            exit 0
        )
    )

    echo Error: cl.exe is not found, please run "vsvars32.bat" first.
    exit /B 1
)

if "%1" == "" echo usage: compile.bat sourcefile & exit /B 1

@echo on
cl /W3 /EHsc /I../src /nologo "%~1"
