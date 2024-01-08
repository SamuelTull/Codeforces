#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef __gnu_pbds::tree<
    int,
    __gnu_pbds::null_type,
    greater<int>,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update>
    ordered_set;
// s.order_of_key(a);
// s.find_by_order(n);

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

    ordered_set seen;
    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        auto &a = pairs[i].first;
        ans += seen.order_of_key(a);
        seen.insert(a);
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
