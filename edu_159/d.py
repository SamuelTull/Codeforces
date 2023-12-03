n, q = map(int, input().split())
S = input()

# precompute
X = [None] * (n + 1)
Y = [None] * (n + 1)
X[0] = Y[0] = x = y = 0

for i in range(n):
    if S[i] == "U":
        y += 1
    elif S[i] == "D":
        y -= 1
    elif S[i] == "L":
        x -= 1
    else:
        x += 1
    X[i + 1] = x
    Y[i + 1] = y

for i in range(q):
    x, y, l, r = map(int, input().split())
    found = False
    i = 0
    while i < l and not found:
        if X[i] == x and Y[i] == y:
            found = True
        i += 1
    while i < r and not found:
        j = l + r - i - 1
        cx = X[l - 1] + X[r] - X[j]
        cy = Y[l - 1] + Y[r] - Y[j]
        if cx == x and cy == y:
            found = True
        i += 1
    while i < n + 1 and not found:
        if X[i] == x and Y[i] == y:
            found = True
        i += 1
    print("YES" if found else "NO")
