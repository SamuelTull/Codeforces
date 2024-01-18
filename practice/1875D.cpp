#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

int solve()
{
    int n, num;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (num < n)
            a[num]++;
    }
    vector<int> nodes = {0};
    int mex = 0;
    int m = INF;
    while (a[mex] > 0)
    {
        mex++;
        if (a[mex] < m)
        {
            m = a[mex];
            nodes.push_back(mex);
        }
    }
    int N = nodes.size();
    vector<int> dp(N, INF);
    dp[N - 1] = 0;
    for (int i = N - 1; i >= 0; i--)
        for (int j = 0; j < i; j++)
        { // i -> j
            dp[j] = min(dp[j], dp[i] + a[nodes[j]] * nodes[i]);
        }
    return dp[0] - mex;
}

// remove then add score

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        cout << solve() << endl;
    return 0;
}