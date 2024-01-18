#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
// const int INF = 1e9;

// clang-format off
#define dbv(x) cout << (#x) << ": " << x << "\n";
#define dbc(x) cout << (#x) << ": "; for (auto i : x) cout << i << " "; cout << "\n";
// clang-format on

string solve()
{
    int n, a, q;
    string s;
    cin >> n >> a >> q >> s;
    if (a == n)
        return "YES";
    if (a + count(s.begin(), s.end(), '+') < n)
        return "NO";
    for (int i = 0; i < q; i++)
    {
        if (s[i] == '+')
        {
            a++;
            if (a == n)
                return "YES";
        }
        else
            a--;
    }
    return "MAYBE";
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