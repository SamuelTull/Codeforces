#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;
const int bits = 30;

int get(vector<vector<int>> &nums, int &l, int &r)
{
    int ans = 0;
    for (int j = 0; j < bits; j++)
    {
        if (nums[r][j] - nums[l - 1][j] == r - l + 1)
        {
            ans += (1 << j);
        }
    }
    return ans;
}

void solve()
{
    int n, num, q, L, l, r, m, k, curr;
    cin >> n;
    vector<vector<int>> nums(n + 1, vector<int>(bits));
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        for (int j = 0; j < bits; j++)
        {
            nums[i + 1][j] = nums[i][j] + ((num >> j) & 1);
        }
    }

    cin >> q;

    while (q--)
    {
        cin >> L >> k;
        // want max m such that l & l+1 & l+2 ... & l+m >= k
        if (get(nums, L, L) < k)
        {
            cout << -1 << " ";
            continue;
        }
        l = L; // get(nums,L,L) >=k
        r = n; // ?
        while (l < r)
        {
            m = (l + r) / 2 + 1;
            if (get(nums, L, m) >= k)
            {
                l = m;
            }
            else
            {
                r = m - 1;
            }
        }
        cout << l << " ";
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
