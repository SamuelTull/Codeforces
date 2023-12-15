import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []

for _ in range(int(input())):
    n = int(input())
    nums = list(map(int, input().split()))
    counter = {}
    for i in range(n):
        counter[nums[i]] = counter.get(nums[i], 0) + 1
    max_n = max(counter)
    out = 0
    for i in range(n):
        curr = nums[i]
        j = i + 1
        while j < n and curr <= max_n and counter:
            curr += nums[j]
            if curr in counter:
                out += counter[curr]
                del counter[curr]
            j += 1
    ans.append(str(out))
os.write(1, "\n".join(ans).encode())
