#include <bits/stdc++.h>
using namespace std;

#define int long long

// const int INF = 1e9;
const int INF = 1e18;
const int MOD = 998244353;

void solve()
{

    int n, no = 0, ne, num;
    cin >> n;
    vector<bool> odd(n);
    bool valid_3 = false;
    int when_valid_3, type_valid_3;
    vector<bool> valid_3_vector;
    vector<bool> EOO = {0, 1, 1}, OOE = {1, 1, 0}, OEO = {1, 0, 1};
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (num % 2 == 1)
        {
            odd[i] = true;
            no++;
            if (!valid_3 && no <= 2)
            {
                valid_3_vector.push_back(true);
            }
        }
        else if (!valid_3 && i + 1 - no == 1)
            valid_3_vector.push_back(false);

        if (!valid_3 && valid_3_vector.size() == 3)
        {
            valid_3 = true;
            when_valid_3 = i;
            type_valid_3 = (EOO == valid_3_vector ? 0 : (OOE == valid_3_vector ? 1 : 2));
        }
    }

    // even only
    ne = n - no;
    int ans = (1 << ne) % MOD;         // all subsqs
    ans -= 1 + ne + ne * (ne - 1) / 2; // subtract subsqs length 0+1+2
    ans %= MOD;

    // OOEOOEOOEOOEOO
    // dp[i][end] represents number of subsqs ending <=i with end 0/1/2
    // end 0: EOO, 1: OOE, 2: OEO

    // if we are at O
    // dp[i][0] = dp[i-1][0] + dp[i-1][2]   // dont add - do add
    // dp[i][1] = dp[i-1][1] + 0            // dont add - do add
    // dp[i][2] = dp[i-1][2] + dp[i-1][1]   // dont add - do add

    // if we are at E
    // dp[i][1] = dp[i-1][0] + 0                            // dont add - do add
    // dp[i][1] = dp[i-1][1] + (dp[i-1][0] + dp[i-1][2])    // dont add - do add
    // dp[i][2] = dp[i-1][2] + 0// dont add - do add

    if (!valid_3)
    {
        cout << ans << endl;
        return;
    }

    vector<vector<int>> dp(n, vector<int>(3));
    dp[when_valid_3][type_valid_3] = 1;

    for (int i = when_valid_3 + 1; i < n; i++)
    {
        if (odd[i])
        {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
            dp[i][1] = dp[i - 1][1];
            dp[i][2] = (dp[i - 1][2] + dp[i - 1][1]) % MOD;
        }
        else
        {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
            dp[i][2] = dp[i - 1][2];
        }
    }
    ans = (ans + dp[n - 1][0]) % MOD;
    ans = (ans + dp[n - 1][1]) % MOD;
    ans = (ans + dp[n - 1][2]) % MOD;
    cout << ans << endl;
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
