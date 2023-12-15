# https://codeforces.com/problemset/problem/1898/B

from math import ceil
import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []


from math import log2


def get_power_2(N, p):
    power = int(log(N, p))
    return power, p**power, N - (p**power)


# k is ceil. add k-1 ops.
# next min is a/k floor.

for _ in range(int(input())):
    n = int(input())
    nums = list(map(int, input().split()))
    print("CASE", n, nums)
    m = nums[-1]
    out = 0
    for i in range(n - 2, -1, -1):
        if nums[i] > m:
            k = log2(nums[i])
            if int(k) == k:
                print(k, int(k), True)
                out += k
            else:
                print(k, int(k) + 1, False)
                out += int(k) + 1
                m -= 1
        elif nums[i] < m:
            m = nums[i]
    ans.append(out)

os.write(1, "\n".join(map(str, ans)).encode())
