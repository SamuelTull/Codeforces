"""
takes input "dir"
copies X.py to a/b/c/d/e/f.py
creates a/b/c/d/e/f/.in 

"""
import sys
import shutil
import os

try:
    d = sys.argv[1]
except:
    d = input("dir: ")

if not os.path.exists(d):
    os.mkdir(d)
    for i in "abcdef":
        shutil.copy("X.py", f"{d}/{i}.py")
        open(f"{d}/{i}.in", "w").close()
    open(f"{d}/README.md", "w").close()
else:
    print("dir already exists")
