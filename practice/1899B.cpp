#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    long long best = 0, curr, m, M;
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            m = 1e18;
            M = -1;

            for (int box = 0; box < n / i; box++)
            {
                curr = 0;
                for (int j = i * box; j < i * (box + 1); j++)
                {
                    curr += nums[j];
                }
                m = min(m, curr);
                M = max(M, curr);
            }
            best = max(best, M - m);
        }
    }
    cout << best << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
