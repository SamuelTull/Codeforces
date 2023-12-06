# Dont need to check every point
# Only have to check the first and last time we reach (x, y)
# And whether we reach R+L-X between L and R

import bisect
import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline


def binary_search(sorted_lst, low, high):
    left = bisect.bisect_left(sorted_lst, low)
    return left != len(sorted_lst) and sorted_lst[left] <= high


n, q = map(int, input().split())
S = input().decode().rstrip()

DIR = {"U": (0, 1), "D": (0, -1), "L": (-1, 0), "R": (1, 0)}
pts = {(0, 0): [0]}
lst = [(0, 0)]

for i in range(n):
    dx, dy = DIR[S[i]]
    pt = (lst[-1][0] + dx, lst[-1][1] + dy)
    if pt not in pts:
        pts[pt] = [i + 1]
    else:
        pts[pt].append(i + 1)
    lst.append(pt)

ans = ["NO"] * q
for qi in range(q):
    x, y, l, r = map(int, input().split())
    l -= 1
    pt = (x, y)
    if pt in pts:
        if pts[pt][0] <= l or pts[pt][-1] >= r:
            ans[qi] = "YES"
    if ans[qi] == "NO":
        Lx, Ly = lst[l]
        Rx, Ry = lst[r]
        pt_2 = (Lx + Rx - x, Ly + Ry - y)
        if pt_2 in pts:
            left = bisect.bisect_left(pts[pt_2], l + 1)
            if left != len(pts[pt_2]) and pts[pt_2][left] <= r - 1:
                ans[qi] = "YES"
os.write(1, "\n".join(ans).encode())
