import sys

input = sys.stdin.readline

from math import gcd, floor, log2


def solve(nums):
    lo = 1
    hi = 57
    while lo < hi:
        mid = (lo + hi) // 2
        n = len(set(num % (2**mid) for num in nums))
        if n == 1:
            lo = mid + 1
        elif n == 2:
            return 2**mid
        else:
            hi = mid
    return 2**lo


for _ in range(int(input())):
    n = int(input())
    nums = list(map(int, input().split()))
    print(solve(nums))
