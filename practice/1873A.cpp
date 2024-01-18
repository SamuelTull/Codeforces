#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

bool solve()
{
    string s, t = "abc";
    cin >> s;
    int wrong = 0;
    for (int i = 0; i < 3; i++)
    {
        if (s[i] != t[i])
            wrong++;
    }
    return wrong <= 2;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        cout << (solve() ? "YES" : "NO") << "\n";
    return 0;
}