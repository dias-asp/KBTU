import re

s = "1A2B3C4D5"
s = re.split("[A-Z]", s)
print(s)