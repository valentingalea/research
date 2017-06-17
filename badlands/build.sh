#! /bin/bash

ROOT=$(pwd)

cd ../tools/gnu-highlite/bin
python ../../asciidoc/asciidoc.py \
-a language=cpp \
-a tabsize=4 \
--theme=volnitsky \
--backend slidy2 \
-a duration=30 \
-a copyright="Valentin Galea" \
--verbose \
--out-file=$ROOT/../docs/badlands/index.html \
$ROOT/cpp_badlands.txt

cd $ROOT
