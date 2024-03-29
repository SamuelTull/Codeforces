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
    int n;
    cin >> n;
    vector<ll> a(n, pow(2, 30) - 1);
    ll m[n][n];
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            cin >> m[r][c];
            if (r != c)
            {
                a[r] &= m[r][c];
                a[c] &= m[r][c];
            }
        }
    }

    bool ok = true;
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {

            if (r != c && m[r][c] != (a[r] | a[c]))
            {
                ok = false;
            }
        }
    }
    if (ok)
    {
        cout << "YES\n";
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    else
        cout << "NO\n";
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
