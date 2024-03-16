
import codecs


f = open("t.txt", "r")
print(f.read())
cnt = 0
for x in f:
    cnt += 1

print(cnt)
