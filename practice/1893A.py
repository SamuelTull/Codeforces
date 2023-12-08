# https://codeforces.com/problemset/problem/1893/A
# A. Anonymous Informant
# if we shift from a this moves to the end of the list
# we are at 1 5 2 6 3
# we must have chosen 3 to shift from
# we must have been at 2 6 3 1 5  (pointer at end goes left 3)
# if at any point we reach a number > n can terminate

# if we have tried k times and not terminated
# then we must have cycled
# k different "orders" k+1 are okay, pidgeonhole principle we have hit one twice
import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []

cases = int(input())
for _ in range(cases):
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))

    p = n - 1  # pointer
    for _ in range(min(n, k)):
        if nums[p] > n:
            ans.append("No")
            break
        p = (p - nums[p]) % n
    else:
        ans.append("Yes")


os.write(1, "\n".join(ans).encode())
