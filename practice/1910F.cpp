#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

int count(int u, int p, vector<vector<int>> &adj, vector<int> &cnt) // node, parent
{
    int ans = 1;
    for (int v : adj[u])
        if (v != p)
            ans += count(v, u, adj, cnt);
    cnt[u] = ans;
    return ans;
}

void solve()
{
    int n, k, u, v;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // root at vertex 0
    // count number in each subtree
    vector<int> cnt(n);
    count(0, -1, adj, cnt);
    vector<int> freq;
    for (int u = 0; u < n; u++)
        for (int v : adj[u])
            if (v > u) // avoid double counting, > so ignore root (0)
                freq.push_back(cnt[v] * (n - cnt[v]));
    sort(freq.begin(), freq.end(), greater<int>());
    int ans = 0;
    for (int i = 0; i < k - 1; i++)
        ans += freq[i];
    for (int i = k - 1; i < n - 1; i++)
        ans += freq[i] * 2;
    cout << ans << "\n";
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