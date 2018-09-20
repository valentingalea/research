#! /bin/bash

node convert.js

# default way to enable plugins in asciidoctor doesn't seem to work
# so I cheated and created my own mini mechanism
sed -e '/dependencies:/ {' -e 'r plugins.js' -e 'd }' -i main.html

cp main.html ../docs/shaderbox/index.html
