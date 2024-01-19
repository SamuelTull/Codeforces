#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
// const int INF = 1e9;

// clang-format off
#define dbv(x) cout << (#x) << ": " << x << "\n";
#define dbc(x) cout << (#x) << ": "; for (auto i : x) cout << i << " "; cout << "\n";
// clang-format on

bool solve()
{
    int n;
    string a, b, c;
    cin >> n >> a >> b >> c;
    int breaks = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i] && a[i] == c[i])
            breaks++;
        if (a[i] != b[i] && (a[i] == c[i] || b[i] == c[i]))
            breaks++;
    }
    return breaks < n;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        cout << (solve() ? "YES" : "NO") << "\n";
    return 0;
}