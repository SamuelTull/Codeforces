#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

void solve()
{
    int n, m, M, ans = 0, x;
    cin >> n;
    vector<int> a(n), moves;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(begin(a), end(a));
    m = a[0];
    M = a[n - 1];
    while (m != M)
    {
        if (m % 2 == 0)
            x = 0;
        else
            x = 1;
        m = (m + x) / 2;
        M = (M + x) / 2;
        ans += 1;
        moves.push_back(x);
    }
    cout << ans << "\n";
    if (ans && ans <= n)
    {
        for (int i = 0; i < ans; i++)
        {
            cout << moves[i] << " ";
        }
        cout << "\n";
    }
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
        // cout << solve() << "\n";
        // cout << (solve() ? "YES" : "NO") << "\n";
    }

    return 0;
}
