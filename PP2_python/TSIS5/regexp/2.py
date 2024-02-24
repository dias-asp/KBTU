import re

s = "abbb"
x = re.fullmatch("ab{2,3}", s)
print(x)