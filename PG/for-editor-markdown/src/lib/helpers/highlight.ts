const Hljs = require('highlight.js/lib/highlight')

Hljs.registerLanguage('css', require('highlight.js/lib/languages/css'))
Hljs.registerLanguage('json', require('highlight.js/lib/languages/json'))
Hljs.registerLanguage('less', require('highlight.js/lib/languages/less'))
Hljs.registerLanguage('scss', require('highlight.js/lib/languages/scss'))
Hljs.registerLanguage('javascript',require('highlight.js/lib/languages/javascript'))
Hljs.registerLanguage('typescript',require('highlight.js/lib/languages/typescript'))
Hljs.registerLanguage('html',require('highlight.js/lib/languages/xml'))
Hljs.registerLanguage('java',require('highlight.js/lib/languages/java'))
Hljs.registerLanguage('arduino',require('highlight.js/lib/languages/arduino'))
Hljs.registerLanguage('cpp',require('highlight.js/lib/languages/cpp'))
Hljs.registerLanguage('php',require('highlight.js/lib/languages/php'))
Hljs.registerLanguage('python',require('highlight.js/lib/languages/python'))
Hljs.registerLanguage('ruby',require('highlight.js/lib/languages/ruby'))

export default Hljs
