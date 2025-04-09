@echo off
setlocal enabledelayedexpansion

set PYTHON=python

:: Get pybind11 include paths
for /f "delims=" %%i in ('%PYTHON% -m pybind11 --includes') do set PYBIND11_INC=%%i
echo PYBIND11_INC = %PYBIND11_INC%

:: Get Python lib directory
for /f "delims=" %%i in ('%PYTHON% -c "import sysconfig; print(sysconfig.get_config_var('LIBDIR'))"') do set PYTHON_LIB_DIR=%%i
echo PYTHON_LIB_DIR = %PYTHON_LIB_DIR%

:: Get Python lib name (without .dll/.lib/.a)
for /f "delims=" %%i in ('%PYTHON% -c "import sysconfig; print(sysconfig.get_config_var('LDLIBRARY').replace('.dll','').replace('.lib','').replace('.a','').split('.')[0])"') do set PYTHON_LIB=%%i
echo PYTHON_LIB = %PYTHON_LIB%

:: Compile the module
echo Running g++...
g++ -O3 -Wall -shared -std=c++17 wordleBindings.cpp wordleGameEngine.cpp -o wordle_module.pyd %PYBIND11_INC% -L"%PYTHON_LIB_DIR%" -l%PYTHON_LIB%

if exist wordle_module.pyd (
    echo wordle_module.pyd built successfully!
) else (
    echo Build failed!
)

pause

