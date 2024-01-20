#include <bits/stdc++.h>
using namespace std;
#define int long long

// clang-format off
#define dbv(x) cout << (#x) << ": " << x << "\n";
#define dbc(x) cout << (#x) << ": "; for (auto i : x) cout << i << " "; cout << "\n";
// clang-format on

void solve()
{
    int n, L, R, damage;
    cin >> n;
    vector<int> a(n), d(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> d[i];
    vector<array<int, 4>> monsters; // atk,def,L,R
    for (int i = 0; i < n; i++)
        monsters.push_back({a[i], d[i], i - 1, i + 1});
    monsters[n - 1][3] = -1;

    vector<int> tocheck, died;
    for (int i = 0; i < n; i++)
        tocheck.push_back(i);

    while (n--)
    {
        died.clear();
        for (int i : tocheck)
        {
            if (i == -1)
                continue;
            damage = 0;
            L = monsters[i][2];
            R = monsters[i][3];
            damage += (L != -1) ? monsters[L][0] : 0;
            damage += (R != -1) ? monsters[R][0] : 0;
            if (damage > monsters[i][1])
                died.insert(i);
        }
        cout << died.size() << " ";

        tocheck.clear();
        for (int i : died)
        {
            L = monsters[i][2];
            R = monsters[i][3];
            if (L != -1)
            {
                monsters[L][3] = R;
                if (died.find(L) == died.end())
                    tocheck.insert(L);
            }
            if (R != -1)
            {
                monsters[R][2] = L;
                if (died.find(R) == died.end())
                    tocheck.insert(R);
            }
        }
    }

    cout << "\n";
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