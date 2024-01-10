#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using ordered_set = __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>; // order_of_key(a);find_by_order(n) // greater<int> for descending order, less_equal for multiset

using ll = long long;
const int INF = 1e9;
const ll LLINF = 1e18;

void print(vector<int> &arr)
{
    for (auto &i : arr)
        cout << i << " ";
    cout << endl;
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> arr(n), max_left(n, -1), max_right(n, -1), i_arr(n), n_i_arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        i_arr[i] = i + arr[i];           // how much we need if we shoot anywere to left of i
        n_i_arr[i] = n - i - 1 + arr[i]; // how much we need if we shoot anywere to right of i
    }
    for (int i = 1; i < n; i++)
    {
        max_left[i] = max(max_left[i - 1], n_i_arr[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        max_right[i] = max(max_right[i + 1], i_arr[i + 1]);
    }

    ll ans = LLINF;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, max(arr[i], max(max_left[i], max_right[i])));
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}
