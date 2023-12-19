import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []


for _ in range(int(input())):
    n = int(input())
    cnt = [0 for _ in range(n)]
    for i in range(n - 1):
        a, b = map(int, input().split())
        cnt[a - 1] += 1
        cnt[b - 1] += 1
    s = 0
    for i in range(n):
        if cnt[i] == 1:
            s += 1
    ans.append(str((s + 1) // 2))

os.write(1, "\n".join(ans).encode())
