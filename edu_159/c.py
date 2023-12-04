# will end up at biggest
# find biggest missing from [B, B-x, B-2x, ... , B-nx] and add i operations
# could add B+x instead of B-nx, but both require n more operations
# find largest x such that all nums congruent (mod x)
# gcd of all differences

from math import gcd
from functools import reduce

n_cases = int(input())

for i_case in range(n_cases):
    n = int(input())
    if n == 1:
        input()
        print(1)
        continue
    nums = set(map(int, input().split()))
    nums_max = max(nums)
    x = reduce(gcd, (nums_max - num for num in nums))
    i = 1
    while i < n and nums_max - (x * i) in nums:
        i += 1
    print(i + sum((nums_max - num) // x for num in nums))
