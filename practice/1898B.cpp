#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] < a[i + 1])
            continue;
        // ceil = (a + b - 1) / b
        int nums = (a[i] + a[i + 1] - 1) / a[i + 1];
        ans += nums - 1;
        a[i] = a[i] / nums;
    }

    cout << ans << endl;
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
