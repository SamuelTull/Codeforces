#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using ordered_set = __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>; // order_of_key(a);find_by_order(n) // greater<int> for descending order, less_equal for multiset

void solve()
{
    int n, ans = 0, lines = 2;
    cin >> n;

    for (int j = 0; j < lines; j++)
    {
        bool prev = false;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '*')
                if (prev)
                    ans++;
                else
                    prev = true;

            else
                prev = false;
        }
    }
    cout << ans << endl;
    // top and bottom seperate...
    // all jump right same as all jump left
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
