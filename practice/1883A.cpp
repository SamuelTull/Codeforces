#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

void solve()
{
    string s, nums = "1234567890";
    cin >> s;
    int curr = 0;
    int i = 0, ans = 4, next;
    for (int i = 0; i < 4; i++)
    {
        next = nums.find(s[i]);
        ans += abs(next - curr);
        curr = next;
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
