import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
n = int(input())
ans = []
for _ in range(n):
    S = input().decode().rstrip()
    bs = 0
    Bs = 0
    smalls = []
    bigs = []
    for i in range(len(S)):
        if S[i] == S[i].lower():
            if S[i] == "b":
                if smalls:
                    smalls.pop(-1)
            else:
                smalls.append(i)
        else:
            if S[i] == "B":
                if bigs:
                    bigs.pop(-1)
            else:
                bigs.append(i)

    ans.append("".join((S[i] for i in sorted(smalls + bigs))))

os.write(1, "\n".join(ans).encode())
