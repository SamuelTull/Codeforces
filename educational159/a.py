# A. Binary Imbalance
# https://codeforces.com/contest/1902/problem/A

# can insert infinite zeros between 01
# otherwise: YES if only 0s/ NO if only 1s
# can simply check if there is a zero in s

n_tests = int(input())
for _ in range(n_tests):
    n = int(input())
    s = input()
    if "0" in s:
        print("YES")
    else:
        print("NO")
