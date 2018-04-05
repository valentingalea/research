// instalation:
// https://github.com/asciidoctor/asciidoctor-reveal.js#node-javascript-setup

var asciidoctor = require('asciidoctor.js')();
require('asciidoctor-reveal.js');

var attributes = {'revealjsdir': 'node_modules/reveal.js@'};
var options = {safe: 'safe', backend: 'revealjs', attributes: attributes};
asciidoctor.convertFile('main.adoc', options);
