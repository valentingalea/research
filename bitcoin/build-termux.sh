ROOT=$(pwd)

cd ../tools/gnu-highlite/bin
python2 ../../asciidoc/asciidoc.py \
-a language=cpp \
-a tabsize=4 \
--theme=volnitsky \
--backend slidy2 \
-a duration=30 \
-a copyright="Valentin Galea" \
--verbose \
--out-file=$ROOT/../docs/bitcoin/index.html \
$ROOT/cpp_bitcoin.adoc

cd $ROOT
