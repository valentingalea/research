@echo off

set ALL=_all.md
set OUT=FAQ.pdf

del %ALL%

for %%i in (*.md) do (
	if /I not %%i==README.md (
		if /I not %%i==%ALL% (
			type %%i
			echo.
			echo -------------------------------------------
			echo.
		)
	)
) >> %ALL%

pandoc %ALL% -o %OUT%

start %OUT%

