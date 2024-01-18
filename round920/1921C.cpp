#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

bool solve()
{
    int n, f, a, b;
    cin >> n >> f >> a >> b;
    int prev = 0, now;
    while (n--)
    {
        cin >> now;
        f -= min(b, a * (now - prev));
        prev = now;
    }
    return f > 0;
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

        cout << (solve() ? "YES" : "NO") << "\n";
    }

    return 0;
}
