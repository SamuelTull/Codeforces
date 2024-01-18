#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

void solve()
{
    int n, ans = 0, nt, T = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ans += __gcd(a[i], a[j]) * (n - j - 1);
        }
    }
    cout << ans << "\n";
}

// 12 x3  1 3
// 13 x2  1 2
// 14 x1  1 1
// 23 x2  1 2
// 24 x1  2 2
// 34 x1  1 1  = 11

// 3 4 6 12 ...

// 1: 1 2 3 4
// 2: 2 3 4
// 3: 1 3 4
// 4: 2 4
// 6: 3 4
// 12: 4


// 1: 1,2,>2  NOT others 
// 2: NOTHING
// 3: 3,6,>6 |  3,12,>12    NOT: 6,12,>12
// 4: 4,12,>12
// 6: 6,12,>12

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}