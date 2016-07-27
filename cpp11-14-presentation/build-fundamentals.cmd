@echo off

set OUT=cpp-fundamentals.txt
set IN=main.txt
set ROOT=%CD%

if not exist bin md bin
cd src-fundamentals
copy /A /Y %IN% ..\bin\%OUT%
cd ..

rem 
rem GNU Source-highlight
rem http://www.gnu.org/software/src-highlite/
rem win32 binaries from http://gnuwin32.sourceforge.net/packages/source-highlight.htm
rem 
cd tools\gnu-highlite\bin
python ..\..\asciidoc\asciidoc.py -a language=cpp ..\..\..\bin\%OUT%
cd %ROOT%
