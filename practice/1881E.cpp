    #include <bits/stdc++.h>
    using namespace std;

    #define int long long
    // const int INF = 1e9;
    const int INF = 1e18;

    int solve() // solve(i,a) = min cost to make beautiful
    {
        int n;
        cin >> n;
        vector<int> a(n), dp(n + 1);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = n - 1; i >= 0; i--)
        {
            if (i + a[i] + 1 <= n)
                dp[i] = min(1 + dp[i + 1], dp[i + a[i] + 1]);
            else
                dp[i] = 1 + dp[i + 1];
        }
        return dp[0];
    }

    signed main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int t = 1;
        cin >> t;
        while (t--)
            cout << solve() << "\n";
        return 0;
    }