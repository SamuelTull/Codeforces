#include <bits/stdc++.h>
using namespace std;

#define int long long

// const int INF = 1e9;
const int INF = 1e18;

void solve()
{
    int n, m = 0;
    cin >> n;
    string s;
    cin >> s;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        if (s[n - 1 - i] == '0')
        {
            nums.push_back(i);
            m++;
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        ans += nums[i] - i;
        cout << ans << " ";
    }
    for (int i = m; i < n; i++)
    {
        cout << "-1 ";
    }
    cout << endl;
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
