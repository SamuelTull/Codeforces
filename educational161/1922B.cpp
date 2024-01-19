#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
// const int INF = 1e9;

// clang-format off
#define dbv(x) cout << (#x) << ": " << x << "\n";
#define dbc(x) cout << (#x) << ": "; for (auto i : x) cout << i << " "; cout << "\n";
// clang-format on

int choose3(int n)
{
    if (n < 3)
        return 0;
    return (n * (n - 1) * (n - 2)) / 6;
}
int choose2(int n)
{
    if (n < 2)
        return 0;
    return (n * (n - 1)) / 2;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int, int, greater<int>> mp;
    for (int i = 0; i < n; i++)
        mp[a[i]]++;
    int ans = 0, curr = 0;

    for (auto it : mp)
    {
        ans += choose3(it.second); // equilateral
        curr += it.second;
        ans += choose2(it.second) * (n - curr); // isosceles - pick a smaller edge
    }

    // if a,b,c are sides of triangle, with a>=b>=c, require a<b+c.
    // since edges are 2^a, 2^b, 2^c if a>b>=c then 2^a > 2^b+2^c - bad!
    // need a=b
    // for each a, can have aaa or aac where c<a.

    cout << ans << "\n";
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