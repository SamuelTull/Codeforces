import sys

input = sys.stdin.readline

for _ in range(int(input())):
    n, k, d = map(int, input().split())
    a = list(map(int, input().split()))
    v = list(map(int, input().split()))

    ans = -1
    for di in range(min(2 * n + 2, d)):
        ans = max(ans, sum(a[i] - 1 == i for i in range(n)) + (d - di - 1) // 2)

        for i in range(v[di % k]):
            a[i] += 1

    print(ans)
"""
1) add 1 to a[0:v(i%k)] 
2) c = num in correct pos, reset arr []

after 1 reset, can you beat doing it every other day? 
NO 
if today is i, if we reset today then we gain Xi for today + (d-i)//2 

when do we reset? 

if num > pos then no point tracking it. 
"""
