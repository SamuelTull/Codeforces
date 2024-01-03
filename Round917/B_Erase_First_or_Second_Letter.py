import sys

input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    nums = input()
    cnt = [False] * 26
    ans = 0
    for i in range(n):
        if not cnt[ord(nums[i]) - ord("a")]:
            ans += n - i
            cnt[ord(nums[i]) - ord("a")] = True
    print(ans)
