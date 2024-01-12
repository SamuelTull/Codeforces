#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

int solve()
{
    int n, m, k, num, mn = INF, Mn = -INF, mm = INF, Mm = -INF, sn = 0;
    cin >> n >> m >> k;
    while (n--)
    {
        cin >> num;
        mn = min(mn, num);
        Mn = max(Mn, num);
        sn += num;
    }
    while (m--)
    {
        cin >> num;
        mm = min(mm, num);
        Mm = max(Mm, num);
    }
    // 1 take Mm give mn or do nothing
    // 2 take big(Mn,Mm) give smallest(mm,mn)
    // 3 take big(Mn,Mm) give smallest(mm,mn)
    
    sn += max(Mm, mn) - mn;
    if (k % 2 == 0)
        sn += min(mm, mn) - max(Mn, Mm);
    return sn;
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
        cout << solve() << endl;
    }

    return 0;
}
