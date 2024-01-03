import sys

input = sys.stdin.readline

from math import gcd, floor, log2


def solve(nums):
    # find the biggest power of 2 that divides all numbers
    # assume all numbers are even
    lo = 1
    hi = floor(log2(max(nums))) + 1
    while lo < hi:
        mid = (lo + hi) // 2
        if all(num % (2**mid) == 0 for num in nums):
            lo = mid + 1
        else:
            hi = mid
    return 2 ** (hi)


for _ in range(int(input())):
    n = int(input())
    nums = list(map(int, input().split()))
    nums = [num - min(nums) for num in nums]
    print(solve(nums))
