import os


path = r"C:\codes\python\Test\files\1.py"

if os.path.exists(path):
    print("exists")

    print(os.path.split(path))