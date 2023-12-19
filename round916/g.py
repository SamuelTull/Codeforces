import os
from io import BytesIO
import bisect

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []
MOD = 998244353


def count(nums):
    n = len(nums)
    if n == 2:
        return 1


(1).bit_length()


for _ in range(int(input())):
    n = int(input())
    nums = [int(x) - 1 for x in input().split()]
    print("NUMS", nums)

    ans_1 = 0
    ans_2 = 1

    cnt = [0] * n
    this_cnt = 0

    i_start = 0
    for i in range(2 * n):
        cnt[nums[i]] += 1
        if cnt[nums[i]] == 1:
            this_cnt += 1
        else:
            this_cnt -= 1
        if this_cnt == 0:
            ans_1 += 1
            ans_2 = (ans_2 * count(nums[i_start : i + 1])) % MOD
            i_start = i + 1
            this_cnt = 0

    ans.append(str(ans_1) + " " + str(ans_2))

os.write(1, "\n".join(ans).encode())
