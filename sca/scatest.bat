@echo off

@REM  Copyright 2006 The Apache Software Foundation or its licensors, as applicable.
@REM
@REM  Licensed under the Apache License, Version 2.0 (the "License");
@REM  you may not use this file except in compliance with the License.
@REM  You may obtain a copy of the License at
@REM
@REM     http://www.apache.org/licenses/LICENSE-2.0
@REM
@REM  Unless required by applicable law or agreed to in writing, software
@REM  distributed under the License is distributed on an "AS IS" BASIS,
@REM  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
@REM  See the License for the specific language governing permissions and
@REM  limitations under the License.



@setlocal

if "%TUSCANY_SCACPP%" == "" (
echo "TUSCANY_SCACPP not set"
set TUSCANY_SCACPP=%cd%\deploy
)
echo using TUSCANY_SCACPP: %TUSCANY_SCACPP%

if "%AXIS2C_HOME%" == "" (
echo "AXIS2C_HOME not set"
goto end
)
echo using Axis2C: %AXIS2C_HOME%"

if "%TUSCANY_SDOCPP%" == "" (
echo "TUSCANY_SDOCPP not set"
goto end
)
echo using TUSCANY_SDOCPP: %TUSCANY_SDOCPP%

set TUSCANY_SCACPP_SYSTEM_ROOT=%cd%\projects\tuscany_sca\tuscany_sca_test\testSCASystem
set PATH=%TUSCANY_SCACPP%\bin;%TUSCANY_SDOCPP%\bin;%AXIS2C_HOME%\lib;%PATH%

cd projects\tuscany_sca\tuscany_sca_test
Release\tuscany_sca_test
:end
@endlocal
