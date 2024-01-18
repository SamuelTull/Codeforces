#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
// const int INF = 1e9;
const int MOD = 998244353;

// clang-format off
#define dbv(x) cout << (#x) << ": " << x << "\n";
#define dbc(x) cout << (#x) << ": "; for (auto i : x) cout << i << " "; cout << "\n";
// clang-format on

int solve()
{
    int n, m;
    cin >> n;
    vector<int> a(n);
    map<int, array<int, 2>> mp;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> mp[a[i]][0];
    cin >> m;
    vector<int> c(m);
    for (int i = 0; i < m; i++)
        cin >> c[i];
    for (int i = 0; i < m; i++)
        cin >> mp[c[i]][1];
    int ans = 1;
    for (auto i : mp)
    {
        array<int, 2> v = i.second;
        if (v[1] > v[0])
            return 0;
        else if (v[1] < v[0])
            ans = (ans * 2) % MOD;
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    while (t--)
        cout << solve() << "\n";
    return 0;
}