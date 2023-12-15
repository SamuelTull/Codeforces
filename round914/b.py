import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []


for _ in range(int(input())):
    n = int(input())
    nums = list(map(int, input().split()))
    nums_sorted = sorted(nums, reverse=True)
    cache = {}
    cache[nums_sorted[0]] = n - 1
    curr = sum(nums)
    for i in range(1, n):
        curr -= nums_sorted[i - 1]
        if nums_sorted[i - 1] <= curr:
            cache[nums_sorted[i]] = cache[nums_sorted[i - 1]]
        else:
            cache[nums_sorted[i]] = n - 1 - i
    out = []
    for num in nums:
        out.append(cache[num])
    ans.append(" ".join(map(str, out)))
os.write(1, "\n".join(ans).encode())
