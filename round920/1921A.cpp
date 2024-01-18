#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

void solve()
{
    int n = 4, cx, cy, x = INF, X = -INF, y = INF, Y = -INF;
    while (n--)
    {

        cin >> cx >> cy;
        x = min(x, cx);
        X = max(X, cx);
        y = min(y, cy);
        Y = max(Y, cy);
    }
    cout << (X - x) * (Y - y) << "\n";
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
