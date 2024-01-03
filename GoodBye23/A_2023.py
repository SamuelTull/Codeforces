import sys

input = sys.stdin.readline

for _ in range(int(input())):
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))

    prod = 1
    for i in range(n):
        prod *= nums[i]
    if 2023 % prod == 0:
        out = ["1"] * k
        out[0] = str(2023 // prod)
        print("YES")
        print(" ".join(out))
    else:
        print("NO")
