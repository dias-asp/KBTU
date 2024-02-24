import re

s = "first_of_all"
s = re.sub("_[a-z]", lambda m: m.group()[-1].upper(), s)
print(s)