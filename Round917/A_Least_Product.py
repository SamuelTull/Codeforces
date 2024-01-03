import sys

input = sys.stdin.readline

ans = []
for _ in range(int(input())):
    n = int(input())
    nums = list(map(int, input().split()))

    if 0 in nums or sum(num < 0 for num in nums) % 2 == 1:
        ans.append("0")
    else:
        ans.append("1\n1 0")
print("\n".join(ans))
