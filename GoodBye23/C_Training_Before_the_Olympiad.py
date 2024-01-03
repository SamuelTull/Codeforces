import sys

input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    nums = list(map(int, input().split()))
    ans = []
    no = ne = s = 0
    for i in range(n):  # turn is 0 indxed
        if nums[i] % 2:
            no += 1
        s += nums[i]

        if i == 0:
            ans.append(s)
        else:
            if no % 3 == 1:
                ans.append(s - ((no // 3) + 1))
            else:
                ans.append(s - no // 3)
    print(" ".join(map(str, ans)))
