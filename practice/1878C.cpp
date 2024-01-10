#include <bits/stdc++.h>
using namespace std;

#define int long long

// const int INF = 1e9;
const int INF = 1e18;

bool solve()
{
    int n, k, x;
    cin >> n >> k >> x;
    int mn = k * (1 + k) / 2;
    int mx = k * (n + n - k + 1) / 2;
    if (x < mn || x > mx)
    {
        return false;
    }
    return true;
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
        cout << (solve() ? "YES" : "NO") << endl;
    }

    return 0;
}
