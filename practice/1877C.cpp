#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

int solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    if (k > n + 1)
    {
        return 0;
    }

    if (k == 1)
    {
        return 1;
    }
    if (k == 2)
    {
        if (m <= n)
            return m;
        else
            return n + m / n - 1;
    }
    if (k == 3)
    {
        if (m <= n)
            return 0;
        else
            return m - (n + m / n - 1);
    }
    return 0;
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
        cout << solve() << endl;
    }

    return 0;
}
