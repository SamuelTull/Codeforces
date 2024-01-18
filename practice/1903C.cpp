#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), suf(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    suf[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suf[i] = suf[i + 1] + a[i];

    int ans = suf[0];
    for (int i = 1; i < n; i++)
    {
        if (suf[i] > 0)
            ans += suf[i];
    }
    cout << ans << "\n";
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
