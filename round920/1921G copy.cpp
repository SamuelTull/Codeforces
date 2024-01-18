#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;


 // O(4 * N^2 * k)
void solve()
{
    int n, m, k;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<int>> pref_rl(n + 1, vector<int>(m + 1, 0)), pref_ud(n + 1, vector<int>(m + 1, 0)), U(n + 1, vector<int>(m + 1, 0)), D(n + 1, vector<int>(m + 1, 0)), R(n + 1, vector<int>(m + 1, 0)), L(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            pref_rl[i + 1][j] = pref_rl[i][j];
            pref_ud[i][j + 1] = pref_ud[i][j];
            if (a[i][j] == '#')
            {
                pref_rl[i + 1][j]++;
                pref_ud[i][j + 1]++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            pref_rl[i + 1][j] = pref_rl[i][j];
            pref_ud[i][j + 1] = pref_ud[i][j];
            if (a[i][j] == '#')
            {
                pref_rl[i + 1][j]++;
                pref_ud[i][j + 1]++;
            }
        }
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
        // cout << solve() << "\n";
        // cout << (solve() ? "YES" : "NO") << "\n";
    }

    return 0;
}
