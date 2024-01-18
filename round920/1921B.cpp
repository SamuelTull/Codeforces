#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

void solve()
{
    int n, FP = 0, FN = 0; // false positive, false negative
    string s, t;
    cin >> n;
    cin >> s >> t;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1' && t[i] == '0')
            FP++;
        else if (s[i] == '0' && t[i] == '1')
            FN++;
    }
    cout << max(FP, FN) << "\n";
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
        // cout << solve() << "\n";
        // cout << (solve() ? "YES" : "NO") << "\n";
    }

    return 0;
}
