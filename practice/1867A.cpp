#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(begin(a), end(a), greater<pair<int, int>>());
    for (int i = 0; i < n; i++)
    {
        b[i] = {a[i].second, i + 1};
    }
    sort(begin(b), end(b));
    for (int i = 0; i < n; i++)
    {
        cout << b[i].second << " ";
    }
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
        cout << endl;
    }

    return 0;
}
