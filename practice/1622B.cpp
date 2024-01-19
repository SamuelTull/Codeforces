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
    int n;
    string s;
    cin >> n;
    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0];
        a[i][1] = i;
    }
    sort(a.begin(), a.end());

    cin >> s;
    int i0 = 1, i1 = count(s.begin(), s.end(), '0') + 1;

    for (int i = 0; i < n; i++)
    {
        int idx = a[i][1];
        if (s[idx] == '0')
            a[i][2] = i0++;
        else
            a[i][2] = i1++;
    }

    sort(a.begin(), a.end(), [](auto a, auto b)
         { return a[1] < b[1]; });
    for (int i = 0; i < n; i++)
        cout << a[i][2] << " ";
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