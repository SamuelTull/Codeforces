import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []


for _ in range(int(input())):
    n, k = map(int, input().split())
    nums = n // k
    rem = n % k
    if nums == 0:
        ans.append("NO")
        continue
    if rem % 2 == 0:
        ans.append("YES")
        ans.append(" ".join([str(nums)] * (k - 1) + [str(nums + rem)]))
        continue
    if k % 2 == 0 or nums == 1:
        ans.append("NO")
    else:
        nums -= 1
        rem += k
        ans.append("YES")
        ans.append(" ".join([str(nums)] * (k - 1) + [str(nums + rem)]))


os.write(1, "\n".join(ans).encode())
