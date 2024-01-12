#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

void solve()
{
    int nx, ns;
    cin >> nx >> ns;
    string x, s;
    cin >> x >> s;

    if (x.find(s) != string::npos)
    {
        cout << 0 << endl;
        return;
    }
    int i = 0;
    while (i < 1 || x.size() < 2 * s.size())
    {
        i++;
        x = x + x;
        if (x.find(s) != string::npos)
        {
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
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
