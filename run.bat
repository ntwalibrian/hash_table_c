@echo off
set PATH=C:\msys64\ucrt64\bin;%PATH%
gcc %1 -o %~n1.exe
if %errorlevel% equ 0 (
    echo Running program...
    %~n1.exe
)