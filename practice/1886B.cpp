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
    int px, py, ax, ay, bx, by;
    cin >> px >> py >> ax >> ay >> bx >> by;
    long double ans;
    // case 1, A surrounds both O and P
    long double AP = sqrt((ax - px) * (ax - px) + (ay - py) * (ay - py));
    long double BP = sqrt((bx - px) * (bx - px) + (by - py) * (by - py));
    long double AB = sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
    long double AO = sqrt((ax - 0) * (ax - 0) + (ay - 0) * (ay - 0));
    long double BO = sqrt((bx - 0) * (bx - 0) + (by - 0) * (by - 0));

    ans = min(max(AP, AO), max(BP, BO));
    ans = min(ans, max(max(AP, BO), AB / 2));
    ans = min(ans, max(max(BP, AO), AB / 2));
    cout << setprecision(15) << ans << endl;
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
