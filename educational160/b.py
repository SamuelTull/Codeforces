import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []

for _ in range(int(input())):
    nums = input().decode().rstrip()
    n = len(nums)
    ones = 0
    zeros = 0

    for i in range(n):
        if nums[i] == "0":
            zeros += 1
        else:
            ones += 1

    curr_ones = 0
    curr_zeros = 0
    for i in range(n):
        if nums[i] == "0" and curr_zeros < ones:
            curr_zeros += 1
        elif nums[i] == "1" and curr_ones < zeros:
            curr_ones += 1
        else:
            break
    ans.append(str(n - curr_ones - curr_zeros))

os.write(1, "\n".join(ans).encode())
