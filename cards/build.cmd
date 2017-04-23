@echo off

set ROOT=%CD%

cd ..\tools\gnu-highlite\bin
python ..\..\asciidoc\asciidoc.py ^
-a language=cpp ^
-a disable-javascript ^
-a tabsize=4 ^
--theme=volnitsky ^
"%1"

cd %ROOT%
