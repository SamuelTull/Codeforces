# https://codeforces.com/contest/1912/problem/A

import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
print = lambda ans: os.write(1, ("\n".join(map(str, ans)) + "\n").encode())
print_line = lambda ans: os.write(1, (str(ans) + "\n").encode())

ans = []

x, k = map(int, input().split())
rows = [[] for _ in range(k)]
for ki in range(k):
    L, *nums = map(int, input().split())
    # track lowest it gets
    # when curr becomes positive, keep adding positive until -ve appears
    # repeat with lowest = curr = 0 from there
    # if we reach end of list and curr is -ve then no point getting any in this sublist
    i = 0
    while i < L:
        low = 0
        curr = 0
        while i < L and curr <= 0:
            curr += nums[i]
            if curr < low:
                low = curr
            i += 1
        while i < L and nums[i] >= 0:
            curr += nums[i]
            i += 1
        if curr > 0:
            rows[ki].append((curr, low))


ok = False
while not ok:
    ok = True
    for row in rows:
        if row and x + row[0][1] >= 0:
            # if we can afford it - get it - we already know it will increase the count
            ok = False
            x += row[0][0]
            row.pop(0)
print_line(x)


"""
clever solution 
x, k = map(int, input().split())
cand = []
for i in range(k):
    a = list(map(int, input().split()))
    psum, mnv, cur = 0, 0, 0
    for i in range(1, len(a)):
        psum += a[i]
        mnv = max(mnv, -psum)
        if psum > cur:
            cand.append([mnv, psum - cur])
            cur = psum
cand.sort()
for [v, w] in cand:
    if x >= v:
        x += w
print(x)
"""
