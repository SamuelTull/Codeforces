#include <bits/stdc++.h>
using namespace std;

#define int long long

bool solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        cnt[nums[i]]++;
    }
    if (cnt.size() > 2)
    {
        return false;
    }
    if (cnt.size() == 1)
    {
        return true;
    }
    auto it = cnt.begin();
    int a = it->second;
    it++;
    int b = it->second;

    if (abs(a - b) > 1)
    {
        return false;
    }
    return true;
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
