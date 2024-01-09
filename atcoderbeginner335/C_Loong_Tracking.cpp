#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using ordered_set = __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>; // order_of_key(a);find_by_order(n) // greater<int> for descending order, less_equal for multiset

void solve(int &n, vector<pair<int, int>> &nums, int &front)
{
    int q;
    cin >> q;
    char c;
    int x, y;
    if (q == 1)
    {
        cin >> c;
        x = nums[front].first;
        y = nums[front].second;

        front = (front - 1 + n) % n;
        if (c == 'L')
            nums[front] = {x - 1, y};
        else if (c == 'R')
            nums[front] = {x + 1, y};
        else if (c == 'U')
            nums[front] = {x, y + 1};
        else if (c == 'D')
            nums[front] = {x, y - 1};
    }
    else
    {
        cin >> x;
        cout << nums[(front + x - 1) % n].first << " " << nums[(front + x - 1) % n].second << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> nums(n);
    for (int i = 0; i < n; i++)
    {
        nums[i] = {i + 1, 0};
    }
    int front = 0;
    while (q--)
    {

        solve(n, nums, front);
    }

    return 0;
}
