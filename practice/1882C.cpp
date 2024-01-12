#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

void solve()
{
    // Pick a card, if odd add value to score and remove, else just remove
    // Can pick all cards we want below first picked card - call this i0:
    //  -pick (all +ve) with odd index from bottom to top
    //  -pick card i0
    //  -pick (all +ve) now with odd index from bottom to top (those that were even before i0)
    // should we pick first card or second card?
    // if first card +ve then pick it (and we get second too)
    // if first card + second card >= 0 then pick both
    // else just pick second card, adding score of 0.
    int n, ans = 0, prev = -INF, num, num2;
    bool found = false;

    cin >> n;
    if (n == 1LL)
    {
        cin >> num;
        cout << max(0LL, num) << endl;
        return;
    }

    cin >> num >> num2;
    if (num >= 0)
    {
        ans += num + max(0LL, num2);
    }
    else
    {
        ans += max(0LL, num + num2);
    }

    for (int i = 2; i < n; i++)
    {

        cin >> num;
        ans += max(0LL, num);
    }
    cout << ans << endl;
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
