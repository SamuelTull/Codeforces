#include <bits/stdc++.h>
using namespace std;

#define int long long

// const int INF = 1e9;
const int INF = 1e18;

bool solve()
{
    int a, b, c;
    cin >> a >> b >> c;

    if (a == b && a == c)
        return true;

    vector<int> nums = {a, b, c};
    sort(nums.begin(), nums.end());
    a = nums[0];
    b = nums[1];
    c = nums[2];
    if (b % a != 0 || c % a != 0)
        return false;

    int ans = (b / a - 1) + (c / a - 1);
    return ans <= 3;
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
        cout << (solve() ? "YES" : "NO") << endl;
    }

    return 0;
}
