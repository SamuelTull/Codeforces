# B. Laura and Operations
# https://codeforces.com/contest/1900/problem/B

# If 3 zeros return 000
# If 2 zeros eg X00 return 100
# Otherwise can reduce any value by 2
# eg a,b,c -> a-1,b-1,c+1 -> a-2,b,c
# reduce to mod 2
#   if we get to 000 then we were at 222 or 220 both return 111
#   if we get to 111 return 111
#   if we get to 100 return 100
#   if we get to 101 return 010

# edit post submission
# seems that 1<= a,b,c RTQ!
# if and only if difference between b and c is even
# we can make b and c equal (once equal can make X,0,0)
# suffices to check if difference between b and c is even
# return 1 - (b-c) % 2, 1 - (c-a) % 2, 1 - (a-b) % 2


cases = int(input())

for i in range(cases):
    a, b, c = map(int, input().split())
    zeros = [a, b, c].count(0)

    if zeros == 3:
        print(0, 0, 0)
    elif zeros == 2:
        d = max(a, b, c)
        print(a // d, b // d, c // d)
    else:
        a = a % 2
        b = b % 2
        c = c % 2
        if a == b == c:
            print(1, 1, 1)
        elif [a, b, c].count(1) == 1:
            print(a, b, c)
        else:
            print(1 - a, 1 - b, 1 - c)
