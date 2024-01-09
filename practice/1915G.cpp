#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using ordered_set = __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>; // order_of_key(a);find_by_order(n) // greater<int> for descending order, less_equal for multiset

using ll = long long;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve()
{
    int n, m, u, v, w;
    cin >> n >> m;
    vector<map<int, int>> nums(n);
    while (m--)
    {
        cin >> u >> v >> w;
        u--;
        v--;
        if (nums[u].find(v) == nums[u].end())
        {
            nums[u][v] = w;
        }
        else
        {
            nums[u][v] = min(nums[u][v], w);
        }

        if (nums[v].find(u) == nums[v].end())
        {
            nums[v][u] = w;
        }
        else
        {
            nums[v][u] = min(nums[v][u], w);
        }
    }
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    map<pair<int, int>, ll> seen;
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> Q;
    Q.push({0, arr[0], 0});
    while (!Q.empty())
    {
        auto [t, s, u] = Q.top();
        Q.pop();
        if (u == n - 1)
        {
            cout << t << "\n";
            return;
        }
        s = min(s, arr[u]);
        for (auto [v, w] : nums[u])
        {
            if (seen.find({s, v}) == seen.end() || seen[{s, v}] > t + w * s)
            {
                seen[{s, v}] = t + w * s;
                Q.push({t + w * s, s, v});
            }
        }
    }
    cout << -1 << "\n";
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
