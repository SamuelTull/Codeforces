#include <bits/stdc++.h>
using namespace std;
#include <cmath>

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

// prev * 2^prev_ans <= num * 2^this_ans
// log(prev) + prev_ans * log(2) <= log(num) + this_ans * log(2)
// log(prev) + prev_ans - log(num) <=  this_ans

void solve()
{
    int n, num, ans = 0, prev = 1, prev_ans = 0, this_ans;
    cin >> n >> prev;
    for (int i = 1; i < n; i++)
    {
        cin >> num;
        if (num == prev)
            this_ans = prev_ans;
        else
        {
            this_ans = ceil(log2(prev) + prev_ans - log2(num));
            this_ans = max(this_ans, 0LL);
        }
        ans += this_ans;
        prev = num;
        prev_ans = this_ans;
    }
    cout << ans << "\n";
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
