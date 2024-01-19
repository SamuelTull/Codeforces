#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
// const int INF = 1e9;

// clang-format off
#define dbv(x) cout << (#x) << ": " << x << "\n";
#define dbc(x) cout << (#x) << ": "; for (auto i : x) cout << i << " "; cout << "\n";
// clang-format on

void solve()
{
    int n, q, x, y, ans;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<bool> close(n); // closest is to right
    close[0] = true;
    int dl, dr;
    for (int i = 1; i < n - 1; i++)
    {
        dl = a[i] - a[i - 1];
        dr = a[i + 1] - a[i];
        if (dr < dl)
            close[i] = true;
    }
    vector<int> costR(n - 1), costL(n - 1), prefR(n), suffL(n);
    for (int i = 0; i < n - 1; i++)
    {
        costR[i] = close[i] ? 1 : a[i + 1] - a[i];
        costL[i] = !close[i + 1] ? 1 : a[i + 1] - a[i];
    }
    for (int i = 0; i < n - 1; i++)
        prefR[i + 1] = prefR[i] + costR[i];

    for (int i = n - 1; i > 0; i--)
        suffL[i - 1] = suffL[i] + costL[i - 1];

    cin >> q;
    while (q--)
    {
        cin >> x >> y;
        y--;
        x--;
        if (x < y)
            ans = prefR[y] - prefR[x];
        else
            ans = suffL[y] - suffL[x];
        cout << ans << "\n";
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
        // cout << solve() << "\n";
        // cout << (solve() ? "YES" : "NO") << "\n";
        solve();
    return 0;
}