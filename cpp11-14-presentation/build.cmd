set OUT=cpp11-14-presentation.txt
set INTRO=intro.txt
set LANG=new_lang_features.txt
set LAMBDA=lambda.txt
set MOVE=move_semantics.txt
set UTIL=util_and_libraries.txt
set MEM=multithreading_and_memory.txt

copy /A /Y %INTRO% + %LANG% + %LAMBDA% + %MOVE% + %UTIL% + %MEM% %OUT%

set HERE=%CD%
cd ..\tools\src-highlite\bin
..\..\asciidoc\asciidoc.py --backend slidy "..\..\..\cpp-presentation\%OUT%"

cd %HERE%
