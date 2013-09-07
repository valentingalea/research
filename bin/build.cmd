@echo off

set ALL=_all.md
set OUT=FAQ

del %ALL%

for %%i in (..\src\*.md) do (
	type %%i
	echo.
	echo -------------------------------------------
	echo.
) >> %ALL%

pandoc %ALL% -o %OUT%.pdf
pandoc %ALL% -o %OUT%.html --to html5

start %OUT%.pdf

