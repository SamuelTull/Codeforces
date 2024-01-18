#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

void solve()
{
    int n, ans = 0, num;
    bool equal = true;
    cin >> n >> ans;
    for (int i = 1; i < n; i++)
    {
        cin >> num;
        ans ^= num;
    }
    if (n % 2 == 0)
    {
        cout << "2\n1 " << n << "\n1 " << n << "\n";
    }
    else
    {
        cout << "4\n1 " << n - 1 << "\n1 " << n - 1
             << "\n2 " << n << "\n2 " << n << "\n";
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
