#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

int solve()
{
    int n, k, x;
    cin >> n >> k >> x;
    if (k > n)
        return -1;
    int ans = k * (k - 1) / 2;
    if (x < k - 1)
        return -1;
    if (x <= k)
        return ans + (k - 1) * (n - k);
    return ans + x * (n - k);
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
        cout << solve() << endl;
    }

    return 0;
}
