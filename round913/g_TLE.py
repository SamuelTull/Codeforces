import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []


cases = int(input())

# find nums = [1 << i + 1 << ai for all i ]
# find the smallest subset of nums that xor to reversed(s)
# dp[i][j] = min number of elements to xor to j using first i elements of nums

for case_i in range(cases):
    n = int(input())
    s = int(input().decode().rstrip()[::-1], 2)
    nums = list(map(int, input().decode().rstrip().split()))
    for i in range(len(nums)):
        nums[i] = (1 << (nums[i] - 1)) + (1 << (i))
    S = list(set(nums))

    dp = [[1e10] * (1 << (n + 1)) for _ in range(len(S) + 1)]
    dp[0][0] = 0
    for i in range(1, len(S) + 1):
        for j in range((1 << (n + 1))):
            dp[i][j] = min(dp[i][j], dp[i - 1][j])
            dp[i][j ^ S[i - 1]] = min(dp[i][j ^ S[i - 1]], dp[i - 1][j] + 1)
    if dp[len(S)][s] == 1e10:
        ans.append("-1")
    else:
        ans.append(str(dp[len(S)][s]))
        subset = []
        j = s
        for i in range(len(S), 0, -1):
            if dp[i][j] != dp[i - 1][j]:
                subset.append(nums.index(S[i - 1]) + 1)
                j ^= S[i - 1]
        ans.append(" ".join(map(str, subset)))

os.write(1, "\n".join(ans).encode())
