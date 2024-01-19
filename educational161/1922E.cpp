#include <bits/stdc++.h>
using namespace std;
#define int long long

// clang-format off
#define dbv(x) cout << (#x) << ": " << x << "\n";
#define dbc(x) cout << (#x) << ": "; for (auto i : x) cout << i << " "; cout << "\n";
// clang-format on

array<int, 2> maxpow2(int n)
{
    int p = 0, c = 1;
    while (c * 2 <= n)
    {
        c *= 2;
        p++;
    }
    return {p, c};
}

void solve()
{
    int n, VAL = 0;
    cin >> n;
    auto [p, c] = maxpow2(n);
    n -= c;

    vector<int> ans(p);
    vector<bool> extra(p); // insert after i?
    iota(ans.begin(), ans.end(), 1);
    int nx = 0;

    while (n)
    {
        auto [p2, c] = maxpow2(n);
        n -= c;
        nx++;
        extra[p - p2 - 1] = true;
    }

    cout << p + nx << "\n";
    for (int i = 0; i < p; i++)
    {
        cout << ans[i] << " ";
        if (extra[i])
        {
            cout << VAL << " ";
            VAL--;
        }
    }
    cout << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        // cout << solve() << "\n";
        // cout << (solve() ? "YES" : "NO") << "\n";
        solve();
    return 0;
}