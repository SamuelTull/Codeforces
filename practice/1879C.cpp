#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;
const int MOD = 998244353;

int factorial(int n)
{
    if (n == 0)
        return 1;
    return (n * factorial(n - 1)) % MOD;
}
void solve()
{
    string s;
    cin >> s;
    int ans1 = 0, ans2 = 1, curr = 1;
    char prev = s[0];
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == prev)
        {
            curr += 1;
        }
        else
        {
            ans1 += curr - 1;           // block lenght n, need to remove n-1
            ans2 = (ans2 * curr) % MOD; // block length n - choose n-1 to remove (n choices)
            prev = s[i];
            curr = 1;
        }
    }
    ans1 += curr - 1;
    ans2 = (ans2 * curr) % MOD;
    ans2 = (ans2 * factorial(ans1)) % MOD; // removing N numbers - N! options

    cout << ans1 << " " << ans2 << endl;
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
