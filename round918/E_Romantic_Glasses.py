import sys

input = sys.stdin.readline

import random

random_seed = random.randint(0, 10**9)

# solution 1
for _ in range(int(input())):
    n = int(input())
    nums = list(map(int, input().split()))

    pref_sums = {random_seed}
    s = 0
    for i in range(n):
        s += nums[i] if i % 2 else -nums[i]
        if s ^ random_seed in pref_sums:
            print("YES")
            break
        pref_sums.add(s ^ random_seed)
    else:
        print("NO")

# # solution 2
# for _ in range(int(input())):
#     n = int(input())
#     nums = list(map(int, input().split()))
#     pref_sums = [0]
#     for i in range(n):
#         pref_sums.append(pref_sums[-1] + (nums[i] if i & 1 else -nums[i]))
#     pref_sums.sort()
#     for i in range(n):
#         if pref_sums[i] == pref_sums[i + 1]:
#             print("YES")
#             break
#     else:
#         print("NO")
