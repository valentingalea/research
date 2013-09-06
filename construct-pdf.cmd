@echo off

set ALL=_all.md
set OUT=FAQ.pdf

del %ALL%

for %%i in (*.md) do (
	if /I not %%i==README.md (
		type %%i >> %ALL%
		echo. >> %ALL%
		echo ------------------------------------------- >> %ALL%
		echo. >> %ALL%
	)
)

pandoc %ALL% -o %OUT%

start %OUT%
