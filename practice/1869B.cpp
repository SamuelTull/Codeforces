#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

int dist(pair<int, int> a, pair<int, int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve()
{
    int n, k, ai, bi;
    cin >> n >> k >> ai >> bi;
    ai--;
    bi--;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
    int da = ai < k ? 0 : INF; // a to a city
    int db = bi < k ? 0 : INF; // b to a city

    for (int i = 0; i < k; i++)
    {
        da = min(da, dist(v[ai], v[i]));
        db = min(db, dist(v[bi], v[i]));
    }

    int ans = min(da + db, dist(v[ai], v[bi]));
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
    {
        solve();
    }

    return 0;
}
