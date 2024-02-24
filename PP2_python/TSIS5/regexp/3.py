import re

s = "aoaoaooa bbb_asddas"
x = re.search("[a-z]*_[a-z]*", s)
print(x)