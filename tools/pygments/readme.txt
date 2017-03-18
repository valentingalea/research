http://pygments.org/

= update python
python -m pip install -U pip setuptools

= install
pip install <package>.whl

= dump style (ex. 'vs') - from python cmd
from pygments.styles import STYLE_MAP # optional
from pygments.formatters import HtmlFormatter
print HtmlFormatter(style='vs').get_style_defs('.highlight')
