# https://codeforces.com/problemset/problem/1883/G2
# G. Dances

import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []

for _ in range(int(input())):
    n, m = map(int, input().split())
    a = sorted(map(int, input().split()))
    b = sorted(map(int, input().split()))
    p1 = 0
    p2 = 0
    ct = 0
    max_unused = 0
    while p1 < n - 1 and p2 < n:
        if a[p1] < b[p2]:
            p1 += 1
            p2 += 1
            ct += 1
        else:
            max_unused = b[p2]
            p2 += 1

    if p2 < n:
        max_unused = b[-1]
    extra = max(0, m - max_unused + 1)
    ans.append((n - 1 - ct) * m + extra)

    # with c = -1 the number of operations is  n - 1 - ct
    # as we have counted the number of elements in b > a
    # we also keep track of the largest element in b that is not used
    # for c < max_unused we dont need another operation
    # for c >= max_unused we need exactly 1 more operation
    # i think this is O(nlogn) and better than O(nlognlogm) that tutorial suggests

os.write(1, "\n".join(map(str, ans)).encode())
