#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;
void solve()
{
    int n, q, s, d, k, ans;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<pair<int, int>, vector<int>> pref, pref2;
    int MIN_D = 50;
    int MAX_K = 1000;
    while (q--)
    {

        cin >> s >> d >> k;
        s--;
        if (d > MIN_D || k < MAX_K)
        {
            ans = 0;
            for (int i = 0; i < k; i++)
            {
                ans += (i + 1) * a[s + i * d];
            }
        }
        else
        {
            if (pref.find({d, s % d}) == pref.end())
            {
                pref[{d, s % d}] = vector<int>(n / d + 2, 0); // only allocate as much as needed s
                pref2[{d, s % d}] = vector<int>(n / d + 2, 0);
                for (int i = 0; (s % d) + i * d < n; i++)
                {
                    pref[{d, s % d}][i + 1] = pref[{d, s % d}][i] + a[(s % d) + i * d];
                    pref2[{d, s % d}][i + 1] = pref2[{d, s % d}][i] + a[(s % d) + i * d] * (i + 1);
                }
            }
            ans = (pref2[{d, s % d}][s / d + k] - pref2[{d, s % d}][s / d]) - (s / d) * (pref[{d, s % d}][s / d + k] - pref[{d, s % d}][s / d]);
        }
        cout << ans << " ";
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
    {
        solve();
        // cout << solve() << "\n";
        // cout << (solve() ? "YES" : "NO") << "\n";
    }

    return 0;
}
