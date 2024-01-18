#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

int solve()
{
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n), pref(n + 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end(), greater<int>());

    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + a[i];

    int ans = -INF;
    for (int i = 0; i <= k; i++)
    {
        int curr = pref[n] - 2* pref[min(n, x + i)] + pref[i];
        ans = max(ans, curr);
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
