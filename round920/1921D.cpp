#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

int solve()
{
    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> a(n), b(m), c1(n), c2(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());
    for (int i = 0; i < n; i++)
    {
        c1[i] = b[i];
        c2[i] = b[m - n + i];
    }

    for (int i = 0; i < n; i++)
        ans += max(abs(a[i] - c1[i]), abs(a[i] - c2[i]));

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
