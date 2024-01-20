#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
// const int INF = 1e9;

// clang-format off
#define dbv(x) cout << (#x) << ": " << x << "\n";
#define dbc(x) cout << (#x) << ": "; for (auto i : x) cout << i << " "; cout << "\n";
// clang-format on

bool solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    string goal = "vika";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int goal_idx = 0;

    for (int col = 0; col < m; col++)
    {
        for (int row = 0; row < n; row++)
        {
            if (a[row][col] == goal[goal_idx])
            {
                goal_idx++;
                if (goal_idx == 4)
                    return true;
                break;
            }
        }
    }
    return false;
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