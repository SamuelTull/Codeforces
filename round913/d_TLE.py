import os
from io import BytesIO
from math import ceil

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []


def dist(a, b):
    ax, ay = a
    bx, by = b
    if ay < bx:
        return bx - ay
    elif ax > by:
        return ax - by
    else:
        return 0


n_cases = int(input())
for _ in range(n_cases):
    this = 0
    n = int(input())
    segments = [(0, 0)]
    for _ in range(n):
        segments.append(tuple(map(int, input().decode().rstrip().split())))
    for jump in range(1, n + 1):
        for i in range(n + 1 - jump):
            this = max(this, ceil(dist(segments[i], segments[i + jump]) / jump))
    ans.append(str(this))
os.write(1, "\n".join(ans).encode())
