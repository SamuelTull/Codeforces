#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

vector<vector<bool>> get_path(vector<vector<int>> &d, vector<vector<bool>> &island, int r, int c, int min_d)
{
    int n = d.size(), m = d[0].size();
    vector<vector<bool>> path(n, vector<bool>(m));
    queue<pair<int, int>> Q;
    Q.push({r, c});
    path[r][c] = true;
    while (!Q.empty())
    {
        auto [r, c] = Q.front();
        Q.pop();
        for (auto [nr, nc] : vector<pair<int, int>>{{r + 1, c}, {r - 1, c}, {r, c + 1}, {r, c - 1}})
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !path[nr][nc] && !island[nr][nc] && d[nr][nc] >= min_d)
            {
                Q.push({nr, nc});
                path[nr][nc] = true;
            }
    }
    return path;
}

bool check_path(vector<vector<bool>> &path, vector<vector<bool>> &island)
{
    int n = path.size(), m = path[0].size();
    deque<pair<int, int>> Q;
    vector<vector<bool>> visited(n, vector<bool>(m));
    for (int r = 0; r < n; r++)
        for (int c = 0; c < m; c++)
            if (island[r][c])
            {
                Q.push_back({r, c});
                visited[r][c] = true;
            }
    while (!Q.empty())
    {
        auto [r, c] = Q.front();
        Q.pop_front();

        if (r == 0 || r == n - 1 || c == 0 || c == m - 1)
            return false;
        for (int dr = -1; dr <= 1; dr++)
        {
            for (int dc = -1; dc <= 1; dc++)
            {
                int nr = r + dr, nc = c + dc;
                if (!visited[nr][nc] && !path[nr][nc])
                {
                    Q.push_back({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }
    }
    return true;
}

void print(vector<vector<int>> &d, vector<vector<bool>> &island)
{
    for (int r = 0; r < d.size(); r++)
    {
        for (int c = 0; c < d[r].size(); c++)
            if (island[r][c])
                cout << '#';
            else
                cout << d[r][c];
        cout << "\n";
    }
}

void print(vector<vector<bool>> &island, vector<vector<bool>> &path)
{
    for (int r = 0; r < island.size(); r++)
    {
        for (int c = 0; c < island[r].size(); c++)
            if (island[r][c])
                cout << 'I';
            else if (path[r][c])
                cout << '#';
            else
                cout << " ";
        cout << "\n";
    }
}

void solve()
{

    // find distance from volcano to each point
    int n, m, q, r, c;
    string line;
    cin >> n >> m >> q;
    vector<vector<int>> d(n, vector<int>(m)); // manhatten to closest mine
    vector<vector<bool>> island(n, vector<bool>(m)), visited(n, vector<bool>(m));
    queue<tuple<int, int, int>> Q; // for calculating d
    for (int r = 0; r < n; r++)
    {
        cin >> line;
        for (int c = 0; c < m; c++)
        {
            if (line[c] == '#')
                island[r][c] = true;
            else if (line[c] == 'v')
            {
                Q.push({r, c, 0});
                visited[r][c] = true;
            }
        }
    }

    while (!Q.empty())
    {
        auto [r, c, dist] = Q.front();
        Q.pop();
        d[r][c] = dist;
        visited[r][c] = true;
        for (auto [nr, nc] : vector<pair<int, int>>{{r + 1, c}, {r - 1, c}, {r, c + 1}, {r, c - 1}})
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc]) // fly over islands as manhatten distance
                Q.push({nr, nc, dist + 1});
    }
    // print(d, island);

    while (q--)
    {
        cin >> r >> c;
        r--;
        c--;
        // path with maximum safety.
        // upper bound is d[r][c]
        // lower bound is 0
        // if i is possible i+1 is possible
        // binary search
        int lo = 0, hi = d[r][c];
        while (lo < hi)
        {
            int mid = (lo + hi + 1) / 2;
            // cout << "lo " << lo << " hi " << hi << " mid " << mid << endl;
            // traverse from d[r][c], only allowed if d[i][c] >= mid
            vector<vector<bool>> path = get_path(d, island, r, c, mid);
            // print(island, path);
            // check if complete path
            if (check_path(path, island))
                lo = mid; // mid is possible
            else
                hi = mid - 1;
        }
        cout << lo << "\n";
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}
