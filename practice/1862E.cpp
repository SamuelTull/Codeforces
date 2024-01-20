#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
// const int INF = 1e9;

// clang-format off
#define dbv(x) cout << (#x) << ": " << x << "\n";
#define dbc(x) cout << (#x) << ": "; for (auto i : x) cout << i << " "; cout << "\n";
// clang-format on

int ans(int n, int m, int d, vector<int> &a, int idx, int prev, map<array<int, 3>, int> &memo, int maxA)
{
    if (m == 0)
        return 0;
    if (idx == n)
        return 0;
    if (memo.count({m, idx, prev}))
        return memo[{m, idx, prev}];

    if (d * (idx - prev) > maxA * m)
        return 0;

    int res1 = a[idx] - d * (idx - prev) + ans(n, m - 1, d, a, idx + 1, idx, memo, maxA);
    int res2 = ans(n, m, d, a, idx + 1, prev, memo, maxA);
    // dbv(m);
    // dbv(idx);
    // dbv(res1);
    // dbv(res2);
    return memo[{m, idx, prev}] = max(res1, res2);
}

int solve()
{
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<array<int, 3>, int> memo;
    int maxA = *max_element(a.begin(), a.end());
    return ans(n, m, d, a, 0, -1, memo, maxA);
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