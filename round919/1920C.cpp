#include <bits/stdc++.h>
using namespace std;

#define int long long

int solve()
{

    int n, ans = 1;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int k = 1; k < n; k++)
    {
        if (n % k == 0)
        {
            int g = 0;

            for (int i = 1; i * k < n; i++)
            {
                for (int j = 0; j < k; j++)
                {
                    g = __gcd(g, abs(a[j] - a[i * k + j]));
                }
            }
            if (g != 1)
            {
                ans++;
            }
        }
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        cout << solve() << "\n";
    }

    return 0;
}
