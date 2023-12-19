import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []

for _ in range(int(input())):
    n = int(input())
    nums = input().decode().strip()
    s = 0
    for i in range(26):
        if nums.count(chr(65 + i)) > i:
            s += 1

    ans.append(str(s))
os.write(1, "\n".join(ans).encode())
