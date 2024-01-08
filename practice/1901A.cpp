#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int ans = nums[0];
    for (int i = 1; i < n; i++)
    {
        ans = max(ans, nums[i] - nums[i - 1]);
    }
    ans = max(ans, 2 * (x - nums[n - 1]));
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
