#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

int solve()
{
    int a, b, c, ans;
    cin >> a >> b >> c;
    if (a < b)
        swap(a, b);
    ans = (a - b) / 2 / c;
    a -= ans * c;
    b += ans * c;
    ans += (a != b);
    return ans;
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
