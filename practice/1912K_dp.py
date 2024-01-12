
INF=  1e18;
MOD = 998244353
import sys 
input = sys.stdin.readline


n = 11# int(input())
odd = [3,1,4,1,5,9,2,6,5,3,6]#list(map(int,input().split()))
no =0 
valid_3 = False 
valid_3_vector = []
for i in range(n):
    odd[i] = (odd[i] % 2) == 1

    if odd[i]:
        no += 1 
        if (not valid_3) and no <= 3:
            valid_3_vector.append(1)
    elif (not valid_3) and (i+1-no == 1):
        valid_3_vector.append(0)
    
    if (not valid_3) and len(valid_3_vector) == 3:
        valid_3 = True
        when_valid_3 = i
        type_valid_3 = 0 if valid_3_vector == [0,1,1] else (1 if valid_3_vector ==  [1,1,0] else 3)



print(odd)
print("Odd", no)
print("Valid 3", valid_3, "type", type_valid_3, "when", when_valid_3)


ne = n - no 
ans = (1 << ne) 
ans -= 1 + ne + ne * (ne-1) // 2

print("all even", ans)

dp = [[0 for i in range(3)] for j in range(n)]
dp[when_valid_3][type_valid_3] = 1
for i in range(when_valid_3+1, n):
    if (odd[i]):
            dp[i][0] = dp[i - 1][0] + dp[i - 1][2]
            dp[i][1] = dp[i - 1][1]
            dp[i][2] = dp[i - 1][2] + dp[i - 1][1]
    else:
            dp[i][0] = dp[i - 1][0]
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2])
            dp[i][2] = dp[i - 1][2]

    print(i, dp[i-1], dp[i], dp[i+1])