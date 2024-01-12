#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

void solve()
{
    int n;
    cin >> n;
    vector<string> S(n);
    for (int i = 0; i < n; i++)
        cin >> S[i];
    vector<vector<int>> S1(n, vector<int>(n)), S2(n, vector<int>(n)), S3(n, vector<int>(n)), S4(n, vector<int>(n));
    int M, a, b, c, d, ans = 0;
    for (int i = 0; i < (n + 1) / 2; i++)
    {
        for (int j = 0; j < (n + 1) / 2; j++)
        {
            a = S[i][j];
            b = S[j][n - i - 1];
            c = S[n - i - 1][n - j - 1];
            d = S[n - j - 1][i];

            M = max(max(a, b), max(c, d));
            ans += 4 * M - a - b - c - d;
        }
    }

       cout << ans << endl;
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
    }

    return 0;
}
