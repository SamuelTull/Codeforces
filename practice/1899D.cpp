#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using ordered_set = __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>; // order_of_key(a);find_by_order(n) // greater<int> for descending order, less_equal for multiset

using ll = long long;
const int INF = 1e9;
const ll LLINF = 1e18;

int highestPowerOf2(int num)
{
    int power = 0;
    while (num % 2 == 0)
    {
        num /= 2;
        ++power;
    }
    return power;
}

pair<int, int> get_key(int num)
{

    int power = highestPowerOf2(num);
    return {num - power, num / (1 << power)};
}

void solve()

{
    int n, num;
    ll ans = 0;
    cin >> n;
    map<pair<int, int>, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        pair<int, int> curr = get_key(num);
        ans += m[curr];
        m[curr]++;
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
