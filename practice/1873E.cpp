#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

bool fits(vector<int> &nums, int &n, int x, int &h)
{
    for (int i = 0; i < n && x >= 0; i++)
    {
        x -= max(0LL, h - nums[i]);
    }
    return x >= 0;
}

void solve()
{
    int n, x, l, r, m;
    cin >> n >> x;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    l = 0;
    r = nums[0] + x;
    while (l < r)
    {
        m = (l + r + 1) / 2;
        if (!fits(nums, n, x, m))
        {
            r = m - 1;
        }
        else
        {
            l = m;
        }
    }
    cout << l << endl;
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
