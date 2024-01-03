import sys

input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    up = down = left = right = False
    for _ in range(n):
        this = 0
        x, y = map(int, input().split())
        if x > 0:
            right = True
        elif x < 0:
            left = True
        if y > 0:
            up = True
        elif y < 0:
            down = True
    if sum([up, down, left, right]) > 3:
        print("NO")
    else:
        print("YES")
