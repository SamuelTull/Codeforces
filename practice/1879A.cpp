#include <bits/stdc++.h>
using namespace std;

#define int long long

// const int INF = 1e9;
const int INF = 1e18;

void solve()
{
    int n, W, E, s, e;
    cin >> n >> W >> E;
    bool ok = true;
    for (int i = 1; i < n; i++)
    {
        cin >> s >> e;
        if (s >= W && e >= E)
        {
            ok = false;
        }
    }
    cout << (ok ? W : -1) << endl;
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
