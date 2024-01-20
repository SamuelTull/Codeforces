#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
// const int INF = 1e9;

// clang-format off
#define dbv(x) cout << (#x) << ": " << x << "\n";
#define dbc(x) cout << (#x) << ": "; for (auto i : x) cout << i << " "; cout << "\n";
// clang-format on

int score(int i, int j)
{
    return min(min(i, 9 - i), min(j, 9 - j)) + 1;
}

void solve()
{
    int ans = 0;
    string s;

    for (int i = 0; i < 10; i++)
    {
        cin >> s;
        for (int j = 0; j < 10; j++)
        {
            if (s[j] == 'X')
                ans += score(i, j);
        }
    }
    cout << ans << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}