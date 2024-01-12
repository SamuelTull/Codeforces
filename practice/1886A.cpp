#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

void solve()
{
    int n;
    cin >> n;
    // 1 1 1 = 3
    // 1 1 2 = 1
    // 1 2 2 = 2
    // 2 2 2 = 3

    if (n % 3 == 0)
    {
        if (n - 1 - 4 > 4)
        {
            cout << "YES\n"
                 << 1 << " " << 4 << " " << n - 1 - 4 << endl;
            return;
        }
    }
    else if (n % 3 == 1)
    {
        if (n - 1 - 2 > 2)
        {
            cout << "YES\n"
                 << 1 << " " << 2 << " " << n - 1 - 2 << endl;
            return;
        }
    }
    else
    {
        if (n - 2 - 1 > 2)
        {
            cout << "YES\n"
                 << 2 << " " << 1 << " " << n - 2 - 1 << endl;
            return;
        }
    }
    cout << "NO\n";
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
