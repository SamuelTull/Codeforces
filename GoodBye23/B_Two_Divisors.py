import sys

input = sys.stdin.readline

from math import lcm


for _ in range(int(input())):
    a, b = map(int, input().split())
    lcm_ = lcm(a, b)
    if lcm_ == b:
        p = b // a
        print(b * p)
    else:
        print(lcm_)
