@echo off

set ROOT=%CD%

cd ..\tools\gnu-highlite\bin
python ..\..\asciidoc\asciidoc.py ^
-a language=cpp ^
-a tabsize=4 ^
--theme=volnitsky ^
--backend slidy ^
"%1"

cd %ROOT%
