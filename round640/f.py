import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []

for _ in range(int(input())):
    n0, n1, n2 = map(int, input().split())
    if n1 == 0:  # can assume solution so either all 1s or all 0s
        if n2 == 0:
            out = "0" * (n0 + 1)
        else:
            out = "1" * (n2 + 1)
    else:
        out = (
            "0" * n0 + "01" * ((n1 + 1) // 2) + "1" * n2 + ("0" if n1 % 2 == 0 else "")
        )
    ans.append(out)
os.write(1, "\n".join(ans).encode())
