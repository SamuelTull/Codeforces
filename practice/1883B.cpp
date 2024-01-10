#include <bits/stdc++.h>
using namespace std;

#define int long long

// const int INF = 1e9;
const int INF = 1e18;

bool solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    for (int i = 0; i < n; i++)
    {
        cnt[s[i] - 'a']++;
    }
    int odd_cnt = 0;
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] % 2 == 1)
        {
            odd_cnt++;
        }
    }
    return odd_cnt <= k + 1;
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
        cout << (solve() ? "YES" : "NO") << endl;
    }

    return 0;
}
