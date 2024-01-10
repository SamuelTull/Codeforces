#include <bits/stdc++.h>
using namespace std;

#define int long long

// const int INF = 1e9;
const int INF = 1e18;

void solve()
{
    int n, curr = 10;
    cin >> n;
    while (n--)
    {
        cout << curr << " ";
        curr += 1;
    }
    cout << endl;
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
