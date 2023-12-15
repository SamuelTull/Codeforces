import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []

for _ in range(int(input())):
    n = int(input())
    nums = list(map(int, input().split()))
    moves = 1
    a0 = nums[0]
    b0 = 0
    a = nums[0]
    b = 0
    l = 1
    r = n - 1
    while l <= r:
        if moves % 2 == 0:
            a0 = 0
            while l <= r and a0 <= b0:
                a0 += nums[l]
                l += 1
            a += a0
        else:
            b0 = 0
            while l <= r and b0 <= a0:
                b0 += nums[r]
                r -= 1
            b += b0
        moves += 1
    ans.append(str(moves) + " " + str(a) + " " + str(b))

os.write(1, "\n".join(ans).encode())
