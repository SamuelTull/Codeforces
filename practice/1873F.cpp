#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), h(n), pref(n + 1), h_groups(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];

        if (h[i - 1] % h[i] == 0)
            h_groups[i + 1] = h_groups[i];
        else
            h_groups[i + 1] = h_groups[i] + 1;
    }

    int best = 0;
    for (int i = 1; i < n + 1; i++)
    {

        int l = i, r = n, m;
        while (l < r)
        {

            m = (l + r + 1) / 2;
            if (h_groups[m] != h_groups[i] || pref[m] - pref[i - 1] > k)
            {
                r = m - 1;
            }
            else
            {
                l = m;
            }
        }
        // doesnt check length 1 valid during binary search
        if (r == i && a[i - 1] > k)
            continue;
        best = max(best, r - i + 1);
    }
    cout << best << endl;
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
        solve();
    }

    return 0;
}
