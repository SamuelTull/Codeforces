#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

string solve()
{
    int R, C, ra, ca, rb, cb;
    cin >> R >> C >> ra >> ca >> rb >> cb;

    if (ra >= rb)
        return "Draw";
    if ((rb - ra) % 2 == 1)
    {
        // alice or draw
        if (cb > ca)
        {
            // reflect
            cb = C - cb + 1;
            ca = C - ca + 1;
        }
        // 0 < cb < ca
        cb = max(1LL, cb - (rb - ra) / 2); // bob goes as far left as possible
        ca = max(cb, ca - (rb - ra) / 2 - 1); // alice goes as far left as possible (1 extra move)
        if (cb < ca)
            return "Draw";
        else
            return "Alice";
    }
    else
    {
        // bob or draw
        if (ca > cb)
        {
            cb = C - cb + 1;
            ca = C - ca + 1;
        }
        // 0 < ca < cb
        ca = max(1LL, ca - (rb - ra) / 2);
        cb = max(ca, cb - (rb - ra) / 2);
        if (ca < cb)
            return "Draw";
        else
            return "Bob";
    }
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
        cout << solve() << "\n";
    }

    return 0;
}
