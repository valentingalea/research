#! /bin/bash

ROOT=$(pwd)

cd ../tools/gnu-highlite/bin
python ../../asciidoc/asciidoc.py \
-a language=cpp \
-a tabsize=4 \
--theme=volnitsky \
--backend slidy2 \
-a duration=45 \
-a copyright="Valentin Galea" \
--verbose \
--out-file=$ROOT/../docs/shaderbox/index.html \
$ROOT/main.adoc

cd $ROOT
