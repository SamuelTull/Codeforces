n, q = map(int, input().split())
S = input()

X = [0] * (n + 1)
Y = [0] * (n + 1)
x = 0
y = 0
for i in range(n):
    s = S[i]
    if s == "U":
        y += 1
    elif s == "D":
        y -= 1
    elif s == "L":
        x -= 1
    elif s == "R":
        x += 1
    X[i + 1] = x
    Y[i + 1] = y

for i in range(q):
    x, y, l, r = map(int, input().split())
    S = {(i, j) for i, j in zip(X[:l], Y[:l])}  # indexing might be 1 off
    S = set()
    for i, j in zip(X[r:], Y[r:]):
        print("PRE", i, j)
        S.add((i, j))

    print(S)
    if (x, y) in S:
        print("YES")
        continue

    # between l and r
    posX = X[l - 1]  # indexing might be 1 off
    posY = Y[l - 1]  # indexing might be 1 off
    S = {((2 * posX - i), (2 * posY - j)) for i, j in zip(X[l:r], Y[l:r])}
    S = set()
    for i, j in zip(X[l:r], Y[l:r]):
        print("DURING", i, j)
        S.add(((2 * posX - i), (2 * posY - j)))

    print(S)
    if (x, y) in S:
        print("YES")
        continue

    posX2 = X[r]  # indexing might be 1 off
    posY2 = Y[r]  # indexing might be 1 off

    dx = posX2 - posX
    dy = posY2 - posY
    S = {(i + dx, j + dy) for i, j in zip(X[r:], Y[r:])}
    S = set()
    for i, j in zip(X[r:], Y[r:]):
        print("POST", i, j)
        S.add((i + dx, j + dy))
    print(S)
    if (x, y) in S:
        print("YES")
        continue
    print("NO")
