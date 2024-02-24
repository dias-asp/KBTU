import re

s = "oAo..aooa bbb_asd,,dasb"
s = re.sub("[., ]", ":", s)
print(s)