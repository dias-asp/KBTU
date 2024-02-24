import re

s = "abbbbb"
x = re.fullmatch("ab*", s)
print(x)