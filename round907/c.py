import os
from io import BytesIO
from math import ceil

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []

for _ in range(int(input())):
    n = int(input())
    a = sorted(map(int, input().split()))
    i = 0
    j = n - 1
    curr = 0
    x = 0
    while i < j:
        if x + a[i] < a[j]:
            x += a[i]
            i += 1
        elif x + a[i] == a[j]:
            curr += x + a[i] + 1
            i += 1
            j -= 1
            x = 0
        else:
            dx = a[j] - x
            a[i] -= dx
            curr += x + dx + 1
            j -= 1
            x = 0
    if i == j:
        if a[i] < 2:
            curr += a[i]
        else:
            a[i] -= x
            dx = ceil(a[i] / 2)
            curr += x + dx + 1

    ans.append(str(curr))
    # want to ultimate as few times as poss
    # attack from smallest first until curr = biggest

os.write(1, "\n".join(ans).encode())
