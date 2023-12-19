import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []

for _ in range(int(input())):
    string = input().decode().rstrip()
    n = len(string)
    for i in range(1, n // 2):
        if string[i] != "0":
            ans.append(string[:i] + " " + string[i:])
            break
    else:
        a = string[: n // 2]
        b = string[n // 2 :]
        if b[0] != "0" and int(a) < int(b):
            ans.append(a + " " + b)
        else:
            ans.append("-1")

os.write(1, "\n".join(ans).encode())
