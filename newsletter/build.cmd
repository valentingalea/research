@echo off

set ROOT=%CD%

cd ..\tools\gnu-highlite\bin
python ..\..\asciidoc\asciidoc.py ^
-a language=cpp ^
-a disable-javascript ^
-a linkcss ^
-a tabsize=4 ^
--theme=volnitsky ^
--no-header-footer ^
"%1"

cd %ROOT%
