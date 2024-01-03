import sys

input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    s = sum(map(int, input().split()))
    if s**0.5 % 1 == 0:
        print("YES")
    else:
        print("NO")
