import re

s = "firstOfAll"
s = re.sub("[A-Z]", lambda m: '_' + m.group().lower(), s)
print(s)