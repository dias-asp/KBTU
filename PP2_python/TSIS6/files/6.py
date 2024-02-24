import os

c = 'A'
while c <= 'Z':
    path = r"C:\codes\python\Test\files\textfiles" + r'\\' + c + ".txt"
    f = open(path, "w")
    f.close()
    c = chr(ord(c) + 1)

