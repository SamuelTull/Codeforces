import sys

input = sys.stdin.readline

for _ in range(int(input())):
    a, b, c = map(int, input().split())
    if a == b:
        print(c)
    elif a == c:
        print(b)
    else:
        print(a)
