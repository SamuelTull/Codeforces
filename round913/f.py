import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
ans = []

cases = int(input())
for _ in range(cases):
    a = []
    n = int(input())
    s = list(map(int, input().decode().rstrip().split()))
    min_index, min_val = min(enumerate(s), key=lambda x: x[1])
    max_index, max_val = max(enumerate(s), key=lambda x: x[1])

    if min_val == max_val:
        ans.append(0)
        continue

    min_val_left = min_index
    min_val_right = min_index
    while s[(min_val_left - 1) % n] == min_val:
        min_val_left = (min_val_left - 1) % n
    while s[(min_val_right + 1) % n] == min_val:
        min_val_right = (min_val_right + 1) % n

    max_val_left = max_index
    max_val_right = max_index
    while s[(max_val_left - 1) % n] == max_val:
        max_val_left = (max_val_left - 1) % n
    while s[(max_val_right + 1) % n] == max_val:
        max_val_right = (max_val_right + 1) % n

    curr = min_val_right
    inc = True
    while curr != (min_val_left - 1) % n:
        next_ = (curr + 1) % n
        if s[next_] < s[curr]:
            inc = False
            break
        curr = next_

    curr = max_val_right
    dec = True
    while curr != (max_val_left - 1) % n:
        next_ = (curr + 1) % n
        if s[next_] > s[curr]:
            dec = False
            break
        curr = next_

    if inc:
        # move [min_val_left, n-1] to the front (n - min_val_left)
        # flip, move [0, min_val_left-1], flip back = 1 + min_val_left + 1
        if min_val_left == 0:
            a.append(0)
        a.append(n - min_val_left)
        a.append(1 + min_val_left + 1)
    if dec:
        # move [max_val_left, n-1] to the front then flip (n - max_val_left + 1 )
        # flip then move [0, max_val_left -1 ] =  1 + max_val_left
        a.append(n - max_val_left + 1)
        a.append(1 + max_val_left)

    if a:
        ans.append(min(a))
    else:
        ans.append(-1)
os.write(1, "\n".join(map(str, ans)).encode())
