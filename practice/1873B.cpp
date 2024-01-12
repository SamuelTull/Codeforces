#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

void solve()
{
    int n, m = INF, mi;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        if (nums[i] < m)
        {
            m = nums[i];
            mi = i;
        }
    }
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (i == mi)
            ans *= nums[i] + 1;
        else
            ans *= nums[i];
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
