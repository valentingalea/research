@echo off

set ALL=_all.md
set OUT=FAQ.pdf

if exist %ALL% del %ALL%

for %%i in (..\src\*.md) do (
	type %%i
	echo.
	echo -------------------------------------------
	echo.
) >> %ALL%

pandoc %ALL% -o %OUT% --toc --toc-depth=5 --from=markdown_github

start %OUT%

