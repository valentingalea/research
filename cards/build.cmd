@echo off

set ROOT=%CD%

cd ..\tools\gnu-highlite\bin
python ..\..\asciidoc\asciidoc.py --out-file "%ROOT%\..\docs\cards.html" "%ROOT%\cards.txt"
cd %ROOT%
