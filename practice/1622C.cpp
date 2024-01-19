#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
// const int INF = 1e9;

// clang-format off
#define dbv(x) cout << (#x) << ": " << x << "\n";
#define dbc(x) cout << (#x) << ": "; for (auto i : x) cout << i << " "; cout << "\n";
// clang-format on

int solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int s = accumulate(a.begin(), a.end(), 0LL);
    if (s <= k)
        return 0LL;
    int best = s - k;
    sort(a.begin(), a.end());
    int d = 0;
    for (int op2 = 1; op2 < n; op2++)
    {
        d += a[n - op2] - a[0];
        if (s - d <= k) // only do op2
            best = min(best, op2);
        else                                                       // do op2 and op1 (on a[0] before any op2 - hence why remainder divided by op2 + 1)
            best = min(best, op2 + (s - d - k + op2) / (op2 + 1)); // ceil((s - d - k) / (op2 + 1))
    }
    return best;
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