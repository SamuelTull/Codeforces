// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;

// clang-format on
int power(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int inverse(int a)
{
    return power(a, MOD - 2);
}

int solve()
{
    int n, m, k, num;
    cin >> n >> m >> k;
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> num >> num >> num;
        sum = (sum + num) % MOD;
    }
    int N = n * (n - 1) / 2 % MOD; // number of pairs: n choose 2
    int invN = inverse(N);
    int p = m * invN % MOD; // m/N

    // each iteration add sum/m with probability p.
    // this is equal to sum/N
    // each iteration the sum increases by 1 with prob p, and 0 with prob 1-p.
    // so add p to sum each time

    int res = 0;
    for (int i = 0; i < k; i++)
    {
        res += sum * invN % MOD;
        res %= MOD;
        sum += p;
        sum %= MOD;
    }
    return res;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        cout << solve() << "\n";
    return 0;
}