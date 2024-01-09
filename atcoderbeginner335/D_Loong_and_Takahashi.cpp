#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using ordered_set = __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>; // order_of_key(a);find_by_order(n) // greater<int> for descending order, less_equal for multiset

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int ci = n / 2, cj = n / 2, di = 0, dj = -1, ddi, ddj;

    vector<vector<string>> nums(n, vector<string>(n));
    nums[ci][cj] = "T";

    for (int i = 1; i < n * n; i++)
    {
        ddi = dj;
        ddj = -di;

        if (nums[ci + ddi][cj + ddj] == "")
        {
            di = ddi;
            dj = ddj;
        }
        ci += di;
        cj += dj;
        nums[ci][cj] = to_string(i);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << "\n";
    }
}
