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
    int n, m = INF, ans = -1;

    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {

        cin >> a[i];
        if (a[i] < m)
            m = a[i];
    }

    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (!found)
            if (a[i] == m)
            {
                found = true;
                ans = i;
            }
            else
                continue;
        else
        {
            if (i < n - 1 && a[i + 1] < a[i])
            {
                cout << -1 << "\n";
                return;
            }
        }
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
