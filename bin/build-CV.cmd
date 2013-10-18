@echo off

set OUT=Valentin-Galea

cd ..\CV
if exist %OUT%.pdf del /Q %OUT%.pdf
::if exist %OUT%.tex del /Q %OUT%.tex

pandoc CV.md -o %OUT%.pdf --from=markdown_github --variable mainfont=Arial --variable sansfont=Arial --variable monofont="Courier New" --variable fontsize=10pt --latex-engine=xelatex
::pandoc %OUT%.tex -o %OUT%.pdf --variable mainfont=Arial --variable sansfont=Arial --variable monofont="Courier New" --variable fontsize=10pt --latex-engine=xelatex
::pandoc CV.md -o %OUT%.html --from=markdown_github --variable mainfont=Arial --variable sansfont=Arial --variable monofont="Courier New" --variable fontsize=10pt --latex-engine=xelatex
::pandoc CV.md -o %OUT%.docx --variable mainfont=Arial --variable sansfont=Arial --variable monofont="Courier New" --variable fontsize=10pt

if exist %OUT%.pdf start %OUT%.pdf
