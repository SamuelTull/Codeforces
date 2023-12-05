import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
n = int(input())
ans = []
for _ in range(n):
    s = []
    bs = 0
    Bs = 0
    S = input().decode().rstrip()
    for i in range(len(S) - 1, -1, -1):
        if S[i] == "b":
            bs += 1
        elif S[i] == "B":
            Bs += 1
        else:
            if S[i] in "abcdefghijklmnopqrstuvwxyz":
                if bs > 0:
                    bs -= 1
                else:
                    s.append(S[i])
            else:
                if Bs > 0:
                    Bs -= 1
                else:
                    s.append(S[i])
    ans.append("".join(s[::-1]))

os.write(1, "\n".join(ans).encode())
