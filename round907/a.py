import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []


for _ in range(int(input())):
    n = int(input())
    nums = list(map(int, input().split()))
    ok = True
    cur = nums[0]
    i = 1
    while 2**i < n and ok:
        curr = nums[2**i]
        j = 1
        while 2**i + j < 2 ** (i + 1) and (2**i + j) < n:
            if nums[2**i + j] < curr:
                ok = False
                break
            curr = nums[2**i + j]
            j += 1
        i += 1
    if ok:
        ans.append("YES")
    else:
        ans.append("NO")
os.write(1, "\n".join(ans).encode())
