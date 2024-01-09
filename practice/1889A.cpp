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
    string s;
    cin >> s;
    if (n % 2)
    {
        cout << -1 << "\n";
        return;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            cnt++;
        }
    }
    if (cnt != n / 2)
    {
        cout << -1 << "\n";
        return;
    }

    cnt = 0;
    int left = 0, right = n - 1;
    vector<int> ans;

    while (left < right)
    {
        if (s[left] == s[right])
        {
            cnt++;
            if (s[left] == '1')
            {
                ans.push_back(left);
                s = ".." + s;
                s[left] = '0';
                s[left + 1] = '1';
                left++;
                right++;
            }
            else
            {
                ans.push_back(right + 1);
                s = s + "..";
                s[right + 1] = '0';
                s[right + 2] = '1';
                left++;
                right++;
            }
        }
        else
        {
            left++;
            right--;
        }
    }
    cout << cnt << "\n";
    for (int i = 0; i < cnt; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
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
