#include <bits/stdc++.h>
using namespace std;

#define int long long

// const int INF = 1e9;
const int INF = 1e18;

int solve_prime(int n, int k)
{
    int ans = INF, num;
    bool found = false;
    while (n--)
    {
        cin >> num;
        if (num % k == 0)
        {
            found = true;
        }
        ans = min(ans, k - num % k);
    }
    if (found)
    {
        return 0;
    }
    return ans;
}

int solve_4(int n)
{
    int ans = INF, num, evn = 0;
    bool f4 = false, f3 = false;
    while (n--)
    {
        cin >> num;
        int md4 = num % 4;
        if (md4 == 0)
        {
            f4 = true;
        }
        else if (md4 == 3)
        {
            f3 = true;
        }
        else if (md4 == 2)
        {
            evn++;
        }
    }
    if (f4 || evn >= 2)
    {
        return 0;
    }
    if (f3 || evn == 1)
    {
        return 1;
    }
    return 2;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    if (k != 4)
    {
        cout << solve_prime(n, k) << endl;
    }
    else
        cout << solve_4(n) << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
