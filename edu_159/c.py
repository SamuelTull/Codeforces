# will end up at biggest
# find biggest missing from [B, B-x, B-2x, ... , B-nx] and add i operations
# could add B+x instead of B-nx, but both require n more operations

from math import gcd
from functools import reduce

n_cases = int(input())

for i_case in range(n_cases):
    n = int(input())
    if n == 1:
        input()
        print(1)
        continue
    nums = sorted(map(int, input().split()), reverse=True)
    x = reduce(gcd, (nums[0] - num for num in nums[1:]))
    i = 1
    while i < n and nums[0] - (x * i) == nums[i]:
        i += 1
    print(i + sum((nums[0] - num) // x for num in nums[1:]))

    # nums = set(map(int, input().split()))
    # nums_max = max(nums)
    # x = reduce(gcd, (nums_max - num for num in nums))
    # i = 1
    # while i < n and nums_max - (x * i) in nums:
    #     i += 1
    # print(i + sum((nums_max - num) // x for num in nums))
