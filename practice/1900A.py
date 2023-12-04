# Cover in Water
# https://codeforces.com/contest/1900/problem/A

# if we have a gap size 3, infinite water source
# with only 2 placed
# otherwise have to fill all

# edit rather than count gaps,
# simply have to see if "..." in string
# if not then count "."


from collections import defaultdict

cases = int(input())

for _ in range(cases):
    _ = int(input())
    s = input()
    if "..." in s:
        print(2)
    else:
        print(s.count("."))
