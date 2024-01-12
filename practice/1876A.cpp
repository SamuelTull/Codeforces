#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

void solve()
{
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int b;
    map<int, int> mp; // use the fact that map is sorted
    for (int i = 0; i < n; i++)
    {
        cin >> b;
        if (b < p) // have unlimited p
            mp[b] += a[i];
    }
    mp[p] = INF;

    n--; // have to tell at least one person
    int cost = p, change;
    for (auto it = mp.begin(); it != mp.end() && n; it++)
    {
        change = min(n, it->second);
        cost += change * it->first;
        n -= change;
    }

    cout << cost << endl;
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
