@echo [INFO] Define default value for BEID_DIR_QT_462_EXE if not defined yet
@echo [INFO] Input BEID_DIR_QT_462_EXE=%BEID_DIR_QT_462_EXE%
@set FILE_TO_FIND="bin\rcc.exe" "bin\uic.exe" "bin\moc.exe"
@echo [INFO] Looking for files: %FILE_TO_FIND%

@set FILE_NOT_FOUND=
@for %%i in (%FILE_TO_FIND%) do @if not exist "%BEID_DIR_QT_462_EXE%\%%~i" set FILE_NOT_FOUND=%%~i
@if "%FILE_NOT_FOUND%"=="" goto find_qt462_exe
@echo        Not found in "%BEID_DIR_QT_462_EXE%"

@set BEID_DIR_QT_462_EXE=%~dp0..\ThirdParty\Qt\4.6.2
@set FILE_NOT_FOUND=
@for %%i in (%FILE_TO_FIND%) do @if not exist "%BEID_DIR_QT_462_EXE%\%%~i" set FILE_NOT_FOUND=%%~i
@if "%FILE_NOT_FOUND%"=="" goto find_qt462_exe
@echo        Not found in "%BEID_DIR_QT_462_EXE%"

@set BEID_DIR_QT_462_EXE=C:\Qt\4.6.2
@set FILE_NOT_FOUND=
@for %%i in (%FILE_TO_FIND%) do @if not exist "%BEID_DIR_QT_462_EXE%\%%~i" set FILE_NOT_FOUND=%%~i
@if "%FILE_NOT_FOUND%"=="" goto find_qt462_exe
@echo        Not found in "%BEID_DIR_QT_462_EXE%"

@echo [ERROR] Qt 4.6.2 static library could not be found
@echo         If the path is different from "C:\Qt\4.6.2" or "%~dp0..\ThirdParty\Qt\4.6.2"
@echo         please define BEID_DIR_QT_462_EXE environment variable.
@exit /B 1

:find_qt462_exe
@echo        Found in "%BEID_DIR_QT_462_EXE%"
@exit /B 0