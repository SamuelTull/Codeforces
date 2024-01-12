INF=  1e18;
MOD = 998244353
import sys 
input = sys.stdin.readline

n = int(input())
A = list(map(int,input().split()))

o, e, oe, eo, ee, oo = 0, 0, 0, 0, 0, 0 
print("a","ans", "o", "e", "oe", "eo", "ee", "oo")
ans = 0 
for a in A:
    if a %2:
        ans = (ans + eo + oe) % MOD
        oo = (oo + eo + o) % MOD
        eo = (eo + oe + e) % MOD
        o = (o + 1) % MOD
    else:
        ans = (ans + ee + oo) % MOD
        ee = (ee + ee + e) % MOD
        oe = (oe + oo + o) % MOD
        e = (e + 1) % MOD
    print(a, ans, o, e, oe, eo, ee, oo)
print(ans)


for i in range(13):
    print(chr(ord("A") + i), chr(ord("M") + i))