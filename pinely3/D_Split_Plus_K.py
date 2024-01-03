import sys

input = sys.stdin.readline
from math import gcd

for _ in range(int(input())):
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    small, big = min(nums), max(nums)

    if small == big:
        print(0)
        continue

    if small <= k <= big:
        print(-1)
        continue

    if small > k:
        nums = [num - k for num in nums]
        g = gcd(*nums)
        print(sum((num // g) - 1 for num in nums))
    else:
        nums = [k - num for num in nums]
        g = gcd(*nums)
        print(sum((num // g) - 1 for num in nums))
