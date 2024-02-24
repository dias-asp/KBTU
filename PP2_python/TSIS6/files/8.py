import os

path = "C:\codes\python\Test\files\t1.txt"

if os.access(path, os.F_OK) and os.path.exists(path):
    os.remove(path)
