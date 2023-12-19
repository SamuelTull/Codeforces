import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    ss = []
    for i in range(n):
        ss.append(a[i] + b[i])

    ss = sorted(enumerate(ss), key=lambda x: x[1], reverse=True)
    A = 0
    B = 0
    for i in range(n):
        idx = ss[i][0]
        if i % 2 == 0:
            A += a[idx] - 1
        else:
            B += b[idx] - 1

    ans.append(str(A - B))

os.write(1, "\n".join(ans).encode())
