#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
// const int INF = 1e9;

// clang-format off
#define dbv(x) cout << (#x) << ": " << x << "\n";
#define dbc(x) cout << (#x) << ": "; for (auto i : x) cout << i << " "; cout << "\n";
// clang-format on

// if we watch the last film at idx i, then we subt i*d
// keep m best as

void solve()
{
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 0, S = 0;
    multiset<int> s;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= 0)
            continue;
        s.insert(a[i]);
        S += a[i];
        if (s.size() > m)
        {
            S -= *s.begin();
            s.erase(s.begin());
        }
        ans = max(ans, S - d * (i + 1));
    }
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
        solve();
    return 0;
}