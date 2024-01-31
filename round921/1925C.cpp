#include <bits/stdc++.h>
using namespace std;

array<bool, 26> seen;
void solve()
{
    int n, k, m;
    cin >> n >> k >> m;
    string s;
    cin >> s;
    seen.fill(false);
    int cnt = 0;
    string ans = "";
    for (int i = 0; i < m; i++)
    {
        if (!seen[s[i] - 'a'])
        {
            cnt++;
            seen[s[i] - 'a'] = true;
            if (cnt == k)
            {
                ans += s[i];
                seen.fill(false);
                cnt = 0;
                if (ans.size() == n)
                {
                    cout << "YES\n";
                    return;
                }
            }
        }
    }
    for (int i = 0; i < k; i++)
        if (!seen[i])
            while (ans.size() < n)
                ans += (char)(i + 'a');
    cout << "NO\n" + ans + "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        // cout << solve() << "\n";
        // cout << (solve() ? "YES" : "NO") << "\n";
        solve();
    return 0;
}