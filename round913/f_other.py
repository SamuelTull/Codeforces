# Credit booskako
# https://codeforces.com/contest/1907/submission/236030313

T = int(input())
for t in range(T):
    N = int(input())
    A = list(map(int, input().split()))

    increase_strong = 0
    increase_strong_list = []
    increase_weak = 0
    decrease_strong = 0
    decrease_strong_list = []
    decrease_weak = 0
    for i in range(1, N):
        if A[i - 1] < A[i]:
            increase_strong += 1
            increase_strong_list.append(i)
            increase_weak += 1
        elif A[i - 1] > A[i]:
            decrease_strong += 1
            decrease_strong_list.append(i)
            decrease_weak += 1
        elif A[i - 1] == A[i]:
            increase_weak += 1
            decrease_weak += 1

    print("increase_strong", increase_strong, "increase_weak", increase_weak)
    print("decrease_strong", decrease_strong, "decrease_weak", decrease_weak)
    print("increase_strong_list", increase_strong_list)
    print("decrease_strong_list", decrease_strong_list)

    INF = 10**20
    ans = INF

    if increase_weak == N - 1:
        ans = min(ans, 0)

    if decrease_weak == N - 1:
        ans = min(ans, 1)

    if decrease_strong == 1 and A[-1] <= A[0]:
        calc = N - decrease_strong_list[0]
        ans = min(ans, calc)
        calc = 1 + decrease_strong_list[0] + 1
        ans = min(ans, calc)

    if increase_strong == 1 and A[-1] >= A[0]:
        calc = N - increase_strong_list[0] + 1
        ans = min(ans, calc)
        calc = 1 + increase_strong_list[0]
        ans = min(ans, calc)

    if ans == INF:
        print(-1)
    else:
        print(ans)
