import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []

for _ in range(int(input())):
    n = input().decode().rstrip()
    l = len(n)
    out = []
    for i in range(l):
        if n[i] != "0":
            out.append(n[i] + "0" * (l - i - 1))
    ans.append(str(len(out)))
    ans.append(" ".join(out))


os.write(1, "\n".join(ans).encode())
