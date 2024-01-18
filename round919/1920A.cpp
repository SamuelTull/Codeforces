#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using ordered_set = __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
// order_of_key(a);find_by_order(n)
// greater<int> for descending order, less_equal for multiset

int solve()
{
    int n, a, x, m = 1, M = INF;
    cin >> n;
    ordered_set s;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> x;
        if (a == 1)
            m = max(m, x);
        else if (a == 2)
            M = min(M, x);
        else if (x >= m && x <= M)
            s.insert(x);
    }
    // num between M and m
    if (m > M)
        return 0;

    int ans = M - m + 1;
    if (s.size() > 0)
        ans -= s.order_of_key(M + 1) - s.order_of_key(m);
    return ans;
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
        cout << solve() << "\n";
        // cout << (solve() ? "YES" : "NO") << "\n";
    }

    return 0;
}
