#include <bits/stdc++.h>
using namespace std;

#define int long long

// const int INF = 1e9;
const int INF = 1e18;

void solve()
{
    int n, num, sum = 0;
    cin >> n;
    n--;
    while (n--)
    {
        cin >> num;
        sum += num;
    }
    cout << -sum << endl;
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
