#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> pairs(n);
    for (auto &p : pairs)
    {
        cin >> p.first >> p.second;
    }
    sort(pairs.begin(), pairs.end(), [](auto &a, auto &b)
         { return a.second < b.second; });
    set<int> seen;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        auto &a = pairs[i].first;
        auto idx = seen.lower_bound(a);
        ans += distance(idx, seen.end());
        seen.insert(idx, a);
    }
    cout << ans << "\n";
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
