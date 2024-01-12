#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

void solve()
{
    int n, m, mina = INF;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mina = min(mina, a[i]);
    }
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(b.begin(), b.end(), greater<int>());
    int bi = 0, ai = 0;
    while (ai < n && bi < m)
    {
        if (b[bi] >= a[ai])
        {
            cout << b[bi] << " ";
            bi++;
        }
        else
        {
            cout << a[ai] << " ";
            ai++;
        }
    }
    while (ai < n)
    {
        cout << a[ai] << " ";
        ai++;
    }
    while (bi < m)
    {
        cout << b[bi] << " ";
        bi++;
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
    {
        solve();
    }

    return 0;
}
