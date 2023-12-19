import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []

for _ in range(int(input())):
    n = int(input())
    nums = list(map(int, input().split()))
    seen = set()
    mex = 0
    mexs = []
    for i in range(n):
        seen.add(nums[i])
        while mex in seen:
            mex += 1
        if mexs and mexs[-1][0] == mex:
            mexs[-1][1] += 1
        else:
            mexs.append([mex, 1])
    c = sum(mex[0] * mex[1] for mex in mexs)
    best = c
    for i in range(n - 1):
        this = nums[i]
        this_mex = 1 if this == 0 else 0
        mexs[0][1] -= 1
        c -= this_mex
        this_sum = 0
        while mexs and mexs[-1][0] > this:
            this_sum += mexs[-1][1]
            c -= (mexs[-1][0] - this) * mexs[-1][1]
            mexs.pop()
        mexs.append([this, this_sum])
        c += n
        mexs.append([n, 1])
        best = max(best, c)
    ans.append(str(best))
os.write(1, "\n".join(ans).encode())
