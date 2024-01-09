#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, u, v, d, dd;
    cin >> n >> m;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    vector<set<pair<int, int>>> adj(n);
    while (m--)
    {
        cin >> u >> v;
        u--, v--;
        if (A[u] < A[v])
            adj[u].insert({v, 1});
        else if (A[u] > A[v])
            adj[v].insert({u, 1});
        else
        {
            adj[u].insert({v, 0});
            adj[v].insert({u, 0});
        }
    }

    queue<pair<int, int>> Q;
    vector<int> seen(n, 0);
    Q.push({0, 1});
    while (!Q.empty())
    {
        u = Q.front().first;
        d = Q.front().second;
        Q.pop();
        for (auto &pt : adj[u])
        {
            v = pt.first;
            dd = pt.second;
            if (seen[v] < d + dd)
            {
                Q.push({v, d + dd});
                seen[v] = d + dd;
            }
        }
    }
    cout << seen[n - 1];

    return 0;
}