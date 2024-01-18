#include <bits/stdc++.h>
using namespace std; // clang-format off
#define dbg(x) cout << (#x) << ": " << x << "\n";
#define dbg1(x) cout << (#x) << ": "; for (auto i : x) cout << i << " "; cout << "\n"; // clang-format on
#define int long long
const int INF = 1e18;
// const int INF = 1e9;

void solve()
{
    int x, y, n;
    cin >> x >> y >> n;
    vector<int> a(n);
    a[n - 1] = y;
    for (int i = 1; i < n; i++)
        a[n - i - 1] = a[n - i] - i;
    if (a[0] < x)
        cout << "-1\n";
    else
    {
        a[0] = x;
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
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
        solve();
    return 0;
}