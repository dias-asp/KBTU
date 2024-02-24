import re

s = "firstOfAll"
s = re.sub('[A-Z]', lambda m: ' ' + m.group(), s)
print(s)