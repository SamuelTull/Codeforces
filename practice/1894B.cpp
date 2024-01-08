#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    int seen[101] = {0};
    int i2 = 0, i3 = 0;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        seen[nums[i]]++;
        if (i3 == 0 && seen[nums[i]] == 2)
        {
            if (!i2)
                i2 = i;
            else
                i3 = i;
        }
    }

    if (!i3)
    {
        cout << -1 << '\n';
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << (i == i3 ? 3 : ((i == i2 ? 2 : 1))) << ' ';
        }
        cout << '\n';
    }
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
