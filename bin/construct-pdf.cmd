@echo off

set ALL=_all.md
set OUT=FAQ.pdf

del %ALL%

for %%i in (..\src\*.md) do (
	type %%i
	echo.
	echo -------------------------------------------
	echo.
) >> %ALL%

pandoc %ALL% -o %OUT%

start %OUT%

