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
    int n, num, cnt = 0; // cnt is number of distinct elements
    cin >> n;

    map<int, int> seen;
    vector<bool> left(n), right(n);

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (seen.find(num) == seen.end())
        {
            // first occurence
            cnt++; // increment count
            left[i] = true;
            right[i] = true;
            seen[num] = i; // save index incase we see it again
        }
        else
        {
            // not first occurence
            right[seen[num]] = false; // not the right occurence
            seen[num] = i;            // update index
            right[i] = true;          // is currently right occurence
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    { // cnt now used as distinct elements to the right of i

        if (left[i])
        {
            // can pair with any right occurence
            ans += cnt;
        }
        if (right[i])
        {
            // decrement elements
            cnt--;
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
