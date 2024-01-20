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
    int n, m, num;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int b = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> num;
        b |= num;
    }

    // get XOR of all elements
    int ans = 0, ans1 = 0;
    for (int i = 0; i < n; i++)
    {
        ans ^= a[i];
        ans1 ^= (a[i] | b);
    }

    if (ans1 < ans)
        swap(ans, ans1);
    cout << ans << " " << ans1 << "\n";
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