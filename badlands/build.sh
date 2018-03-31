#! /bin/bash

ROOT=$(pwd)

cd ../tools/gnu-highlite/bin
python ../../asciidoc/asciidoc.py \
-a language=cpp \
-a tabsize=4 \
--theme=volnitsky \
--backend slidy2 \
-a duration=15 \
-a copyright="Valentin Galea" \
--out-file=$ROOT/../docs/badlands/index.html \
$ROOT/$1

cd $ROOT
