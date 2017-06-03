@echo off

set ROOT=%CD%

cd ..\tools\gnu-highlite\bin
python ..\..\asciidoc\asciidoc.py ^
-a language=cpp ^
-a tabsize=4 ^
--theme=volnitsky ^
--backend slidy ^
--verbose ^
--out-file=%ROOT%\..\docs\badlands\index.html ^
"%ROOT%\cpp_badlands.txt"

cd %ROOT%
