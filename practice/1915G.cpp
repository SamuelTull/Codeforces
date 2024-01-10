#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve()
{
    int n, m, u, v, w;
    cin >> n >> m;
    vector<vector<pair<int, int>>> nums(n);
    while (m--)
    {
        cin >> u >> v >> w;
        u--;
        v--;
        nums[u].push_back({v, w});
        nums[v].push_back({u, w});
    }
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // not exactly dikstras as add many of the same state to the Q, but these arent expanded.
    // could use an indexed priority queue to update priority of element in Q, but not in C++ STL.
    vector<vector<ll>> seen(1001, vector<ll>(n, LLINF));
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> Q;
    Q.push({0, arr[0], 0});
    while (!Q.empty())
    {
        auto [t, s, u] = Q.top();
        Q.pop();
        if (seen[s][u] < t)
            continue;
        if (u == n - 1)
        {
            cout << t << "\n";
            return;
        }
        for (auto [v, w] : nums[u])
        {
            ll new_t = t + w * s;
            int new_s = min(s, arr[v]);
            if (seen[new_s][v] > new_t)
            {

                seen[new_s][v] = new_t;
                Q.push({new_t, new_s, v});
            }
        }
    }
    cout << -1 << "\n";
}

int main()
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
