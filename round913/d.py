import os
from io import BytesIO
from math import ceil

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []


def valid(segs, k):
    l, r = 0, 0
    for seg in segs:
        # jump k in both dirs
        # intersection with seg
        l = max(l - k, seg[0])
        r = min(r + k, seg[1])
        if l > r:
            return False
    return True


def binary_search(segs):
    if valid(segs, 0):
        return 0
    # lowest k such that valid(seg, k) is true
    lo = 0
    hi = 10**9
    while lo + 1 < hi:
        mid = (lo + hi) // 2
        if valid(segs, mid):
            hi = mid
        else:
            lo = mid
    return hi


n_cases = int(input())
for _ in range(n_cases):
    this = 0
    n = int(input())
    segs = [tuple(map(int, input().decode().rstrip().split())) for _ in range(n)]
    ans.append(str(binary_search(segs)))
os.write(1, "\n".join(ans).encode())
