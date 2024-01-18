#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

bool solve()
{
    int n, k, x;
    cin >> n >> k;
    bool found = false;
    while (n--)
    {
        cin >> x;
        if (x == k)
            found = true;
    }
    return found;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        cout << (solve() ? "YES" : "NO") << "\n";
    return 0;
}