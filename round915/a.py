import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []

for _ in range(int(input())):
    n, m = map(int, input().split())
    ans.append(str(max(n, m)))


os.write(1, "\n".join(ans).encode())
