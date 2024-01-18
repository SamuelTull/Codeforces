#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define dbv(x) cout << (#x) << ": " << x << "\n";
#define dbc(x) cout << (#x) << ": "; for (auto i : x) cout << i << " "; cout << "\n";
// clang-format on

void dfs(vector<vector<int>> &adj, vector<set<int>> &s, map<int, int> &m, int u, int p = -1)
{
    for (auto v : adj[u])
        if (v != p)
        {
            dfs(adj, s, m, v, u);
            s[u].insert(s[v].begin(), s[v].end());
        }
    s[u].insert(m[u]);
}

void solve()
{
    int n, q, u, v, l, r, x;
    cin >> n >> q;
    vector<vector<int>> adj(n);
    map<int, int> m;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        x--;
        m[x] = i;
    }
    vector<set<int>> s(n);
    dfs(adj, s, m, 0);

    while (q--)
    {
        cin >> l >> r >> x;
        l--, r--, x--;
        if (s[x].lower_bound(l) != s[x].end() && *s[x].lower_bound(l) <= r)
            cout << "YES\n";
        else
            cout << "NO\n";
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
        solve();
    return 0;
}