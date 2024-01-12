#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    if (k < (n - 1) + (m - 1))
    {
        cout << "NO" << endl;
        return;
    }
    // parity
    // needs to be an
    // k same parity as (n - 1) + (m - 1)
    if (k % 2 != (n - 1 + m - 1) % 2)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    // if need extra 4s  11 12 22 21
    // if need extra 2 11 12 22 21 then down then right
    // else across then down
    // colour square 11 12 22 21. then colour border, nothing else matters 

    // top line
    for (int j = 0; j < m - 1; j++)
    {
        cout << (j % 2 ? "B " : "R ");
    }
    cout << endl;
    // other horizontal
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            cout << "R ";
        }
        cout << endl;
    }
    // last line
    for (int j = 0; j < m - 1; j++)
    {
        cout << ((n + j) % 2 ? "R " : "B ");
    }
    cout << endl;

    for (int i = 0; i < n - 1; i++)
    {
        // first line
        if (i == 0)
            cout << "B ";
        else
            cout << (i % 2 ? "B " : "R ");
        // other vertical
        for (int j = 1; j < m - 1; j++)
        {
            cout << "B ";
        }
        // last line
        cout << ((m + i) % 2 ? "R " : "B ");
        cout << endl;
    }

    // int loops = (k - (n - 1) - (m - 1)) / 4;
    // int rem = (k - (n - 1) - (m - 1)) % 4;
    // cout << k << " = " << (n - 1) + (m - 1) << " + " << loops << " * 4 + " << rem << " ? " << (k == (n - 1) + (m - 1) + loops * 4 + rem) << endl;
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
