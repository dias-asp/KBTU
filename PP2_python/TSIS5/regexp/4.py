import re

s = "aoAoaooa bbb_asddas"
x = re.search("[A-Z][a-z]+", s)
print(x)