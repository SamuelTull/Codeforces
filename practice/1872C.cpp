#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

int lowest_factor(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return i;
    }
    return n;
}

void solve()
{
    int l, r, fact;
    cin >> l >> r;
    if (r <= 3)
        cout << -1;
    else if (r % 2 == 0)
        cout << r - 2 << " " << 2;
    else if (l < r)
        cout << r - 3 << " " << 2;
    else
    {
        fact = lowest_factor(r);
        if (fact == r)
            cout << -1;
        else
            cout << r - fact << " " << fact;
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
        cout << endl;
    }

    return 0;
}
