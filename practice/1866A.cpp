#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

void solve()
{
    int n, ans = INF, num;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        ans = min(ans, abs(num));
    }

    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}
