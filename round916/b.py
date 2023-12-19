import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []

for _ in range(int(input())):
    this = []
    n, k = map(int, input().split())
    for i in range(n - k, n + 1):
        this.append(i)
    for i in range(n - k - 1, 0, -1):
        this.append(i)

    ans.append(" ".join(map(str, this)))

os.write(1, "\n".join(ans).encode())
