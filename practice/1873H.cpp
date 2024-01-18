#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

pair<int, int> dfs1(vector<vector<int>> &adj, int &n, int &start)
{
    // find distance from b to cycle (and the node)
    stack<pair<int, int>> q;
    vector<bool> vis(n + 1, false);
    vector<int> dist(n + 1);
    q.push({start, 0});
    while (!q.empty())
    {
        auto [n1, d] = q.top();
        q.pop();
        vis[n1] = true;
        dist[n1] = d;
        for (auto &n2 : adj[n1])
        {
            if (!vis[n2])
                q.push({n2, d + 1});
            else if (d > dist[n2] + 1)
                return {n2, dist[n2]};
        }
    }
    return {-1, -1};
}

int bfs(vector<vector<int>> &adj, int &n, int &start, int &target)
{
    // find distance from a to b
    queue<pair<int, int>> q;
    vector<bool> vis(n + 1, false);
    q.push({start, 0});
    while (!q.empty())
    {
        auto [n1, d] = q.front();
        q.pop();
        if (n1 == target)
            return d;
        if (vis[n1])
            continue;
        vis[n1] = true;
        for (auto &n2 : adj[n1])
            q.push({n2, d + 1});
    }
    return -1;
}

bool solve()
{
    // n nodes, n edges, tree + 1 edge -> exactly 1 cycle
    int n, a, b, n1, n2;
    cin >> n >> a >> b;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
    auto [target, bdist] = dfs1(adj, n, b);
    int adist = bfs(adj, n, a, target);
    return adist > bdist;
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