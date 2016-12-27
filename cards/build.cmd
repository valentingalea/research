rem @echo off

set ROOT=%CD%

cd ..\tools\gnu-highlite\bin
python ..\..\asciidoc\asciidoc.py %ROOT%\cards.txt
cd %ROOT%
