import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []


for _ in range(int(input())):
    n = int(input())
    string = list(input().decode().rstrip())
    substring = []
    for i in range(n):
        while substring and string[substring[-1]] < string[i]:
            substring.pop()
        substring.append(i)
    m = len(substring)
    for i in range(m // 2):
        i1 = substring[i]
        i2 = substring[m - 1 - i]
        string[i1], string[i2] = string[i2], string[i1]
    if string == sorted(string):
        s = m - [string[i] for i in substring].count(string[substring[-1]])
        ans.append(str(s))
    else:
        ans.append("-1")
os.write(1, "\n".join(ans).encode())
