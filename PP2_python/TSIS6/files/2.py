import os
import re

path = r"C:\codes\python\Test\files\1.py"

if os.access(path, os.F_OK):
    print("exists")
if os.access(path, os.R_OK):
    print("readable")
if os.access(path, os.W_OK):
    print("writeable")
if os.access(path, os.EX_OK):
    print("executable")

    