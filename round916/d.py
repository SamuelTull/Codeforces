import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))

    # get max 3 and the idex
    a = sorted(enumerate(a), key=lambda x: x[1], reverse=True)[:3]
    b = sorted(enumerate(b), key=lambda x: x[1], reverse=True)[:3]
    c = sorted(enumerate(c), key=lambda x: x[1], reverse=True)[:3]

    this = 0
    for ai, av in a:
        for bi, bv in b:
            for ci, cv in c:
                if ai != bi and ai != ci and bi != ci:
                    this = max(this, av + bv + cv)

    ans.append(str(this))

os.write(1, "\n".join(ans).encode())
