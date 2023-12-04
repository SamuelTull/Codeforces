n, q = map(int, input().split())
S = input()
# L to the left of l (with 1 indexing)
# R to the right of r (with 1 indexing)

from collections import defaultdict

pts = defaultdict(list)
pts[(0, 0)].append(0)
lst = [(0, 0)]
x = y = 0
for i in range(n):
    if S[i] == "U":
        y += 1
    elif S[i] == "D":
        y -= 1
    elif S[i] == "L":
        x -= 1
    else:
        x += 1
    pts[(x, y)].append(i + 1)
    lst.append((x, y))

# just have to check if x,y is in or L+R-x i think

for _ in range(q):
    x, y, l, r = map(int, input().split())
    l -= 1
    Lx, Ly = L = lst[l]
    Rx, Ry = R = lst[r]
    found = False

    for i in pts[(x, y)]:
        if i <= l or i >= r:
            found = True
            break
    if not found:
        for i in pts[(Lx + Rx - x, Ly + Ry - y)]:
            if l < i < r:
                found = True
                break
    print("YES" if found else "NO")
