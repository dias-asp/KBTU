import time
c = 0
while True:
    path = r"C:\codes\python\Test\files\virus\\" + chr(65 + c) + ".txt"
    f = open(path, "w")
    time.sleep(2)
    c += 1
    if (c == 26):
        break
