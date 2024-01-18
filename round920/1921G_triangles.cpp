#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

int solve(int &n, int &m, int &k, vector<vector<bool>> &a)
{

    vector<vector<int>> pref_hor(n + 1, vector<int>(m + 1, 0)), pref_ver(n + 1, vector<int>(m + 1, 0)), pref_diag(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            pref_hor[i][j + 1] = pref_hor[i][j];
            pref_ver[i + 1][j] = pref_ver[i][j];
            pref_diag[i + 1][j] = pref_diag[i][j + 1];
            if (a[i][j])
            {
                pref_hor[i][j + 1]++;
                pref_ver[i + 1][j]++;
                pref_diag[i + 1][j]++;
            }
        }
    }

    vector<vector<int>> hor(n, vector<int>(m, 0)), ver(n, vector<int>(m, 0)), diag(n + k + 1, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            hor[i][j] = pref_hor[i][min(m, j + k)] - pref_hor[i][j];
            ver[i][j] = pref_ver[min(n, i + k)][j] - pref_ver[i][j];
            diag[i][j] = pref_diag[i + 1][j] - pref_diag[max(0LL, i - k)][min(m, j + k + 1)];
        }
    }
    for (int i = n; i < n + k; i++)
        for (int j = 0; j < m - 1; j++)
            diag[i][j] = pref_diag[i - 1][j + 1];

    // vector<vector<int>> dp(n, vector<int>(m, 0));
    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < m; j++)
    //         if (i + j < k)
    //             dp[0][0] += a[i][j];

    // for (int i = 0; i < n; i++)
    // {
    //     if (i > 0)
    //         dp[i][0] = dp[i - 1][0] - hor[i - 1][0] + diag[i + k][0];
    //     for (int j = 1; j < m; j++)
    //         dp[i][j] = dp[i][j] - ver[i][j] + diag[i + k - 1][j + 1];
    // }
    // int best = dp[0][0];
    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < m; j++)
    //         best = max(best, dp[i][j]);
    // return best;
}

void rotate(vector<vector<bool>> &a)
{
    int n = a.size(), m = a[0].size();
    vector<vector<bool>> b(m, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            b[j][n - i - 1] = a[i][j];
    a = b;
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
        int n, m, k;
        string s;
        cin >> n >> m >> k;
        vector<vector<bool>> a(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            for (int j = 0; j < m; j++)
                if (s[j] == '#')
                    a[i][j] = true;
        }
        int ans = solve(n, m, k, a);
        // rotate(a);
        // ans = max(ans, solve(n, m, k, a));
        // rotate(a);
        // ans = max(ans, solve(n, m, k, a));
        // rotate(a);
        // ans = max(ans, solve(n, m, k, a));
        cout << ans << "\n";
    }

    return 0;
}
