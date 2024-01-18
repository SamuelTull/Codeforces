#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

int solve()
{
    int n, a = INF, b = INF, sa = 0, sb = 0, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        sa += x;
        a = min(a, x);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        sb += x;
        b = min(b, x);
    }

    return min(sa + n * b, sb + n * a);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        cout << solve() << "\n";
    return 0;
}
