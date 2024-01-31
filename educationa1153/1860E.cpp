// clang-format off
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define int long long
const int MOD = 998244353;
const int INF = 1e18; // 1e9
const int MAXBIT = 62;//30

// clang-format on

void solve()
{

    // c1o2d3e4c5o6d7e
    int n;
    string s;
    cin >> s;
    n = s.size();
    vector<vector<int>> adj(n);
    map<array<char, 2>> dummy;
    for (int i = 1; i < n; i++)
    {
        if (i < n - 1)
        {
            adj[i].push_back(i + 1);
            adj[i + 1].push_back(i);
            dist[i][i + 1] = 1;
            dist[i + 1][i] = 1;
        }
        array<char, 2> key = {s[i - 1], s[i]};
        for (int j : mp[key])
        {
            adj[j].push_back(i);
            adj[i].push_back(j);
            dist[i][j] = 1;
            dist[j][i] = 1;
        }
        mp[key].push_back(i);
    }
    // floyd warshall
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (dist[i][k] == 0)
                continue;
            for (int j = i + 1; j < n; j++)
            {
                if (dist[k][j] == 0)
                    continue;
                if (dist[i][j] == 0)
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    dist[j][i] = dist[i][j];
                }
                else
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    dist[j][i] = dist[i][j];
                }
            }
        }
    }
    int O;
    cin >> O;
    while (O--)
    {
        int a, b;
        cin >> a >> b;
        cout << dist[a][b] << "\n";
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        // cout << solve() << "\n";
        // cout << (solve() ? "YES" : "NO") << "\n";
        solve();
    return 0;
}