import os
from io import BytesIO
import bisect

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []

for _ in range(int(input())):
    n, k = map(int, input().split())
    if k >= 3:
        ans.append(0)
        input()
        continue
    nums = sorted(map(int, input().split()))
    s = nums[0]
    for i in range(n - 1):
        s = min(s, nums[i + 1] - nums[i])
    if k == 1:
        ans.append(s)
        continue

    for i in range(n):
        for j in range(i + 1, n):
            diff = nums[j] - nums[i]
            idx = bisect.bisect_left(nums, diff)
            s = min(s, nums[idx] - diff)
            if idx:  # =!= 0
                s = min(s, diff - nums[idx - 1])
    ans.append(s)


os.write(1, "\n".join(map(str, ans)).encode())
