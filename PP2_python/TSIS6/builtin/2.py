s = "ASDad"
import re

print(f"Uppercase: {len(re.findall("[A-Z]", s))}")
print(f"Lowercase: {len(re.findall("[a-z]", s))}")
