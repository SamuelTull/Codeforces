#include <bits/stdc++.h>
using namespace std;
#include <cmath>

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

// prev * 2^prev_ans <= num * 2^this_ans
// log(prev) + prev_ans * log(2) <= log(num) + this_ans * log(2)
// log(prev) + prev_ans - log(num) <=  this_ans

// ai = b* 2^ci
void get_ab(int &a, int &b)
{
    cin >> a;
    b = 0;
    while (a % 2 == 0)
    {
        a /= 2;
        b++;
    }
}

int bin_search(int &a_prev, int &b_prev, int &a_now, int &b_now)
{
    int l = b_now, r = b_prev, m;
    while (l < r)
    {
        m = (l + r) / 2;
        if (a_prev * pow(2, b_prev - m) > a_now) // divide both sides by 2^(m)
            l = m + 1;
        else
            r = m;
    }
    return l - b_now;
}

void solve()
{
    int n, a_prev, b_prev, a_now, b_now, b_temp, ans = 0, d;
    cin >> n;
    get_ab(a_now, b_now);
    for (int i = 1; i < n; i++)
    {
        a_prev = a_now;
        b_prev = b_now;
        get_ab(a_now, b_now);

        if (a_now == a_prev)
            d = max(0LL, b_prev - b_now);
        else if (a_prev > a_now)
        {
            b_temp = max(b_prev, b_now);
            while (a_prev > a_now * pow(2, b_temp - b_prev)) // divide both sides by 2^(b_prev)
                b_temp++;
            d = max(0LL, b_temp - b_now);
        }
        else // a_prev < a_now
        {
            if (b_prev <= b_now)
                d = 0LL;
            else
            { // b_prev > b_now
                d = bin_search(a_prev, b_prev, a_now, b_now);
            }
        }
        ans += d;
        b_now += d;
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
