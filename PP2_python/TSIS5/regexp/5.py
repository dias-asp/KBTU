import re

s = "aoAo..aooa bbb_asd,,dasb"
s = re.fullmatch("a.*b", s)
print(s)