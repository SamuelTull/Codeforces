#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {

        ans += abs(nums[i] - nums[i + 1]) + abs(nums[n + i] - nums[n + i + 1]);
    }
    cout << ans << '\n';
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << ' ' << nums[n + i] << '\n';
    }
}

int main()
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
