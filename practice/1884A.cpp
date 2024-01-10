#include <bits/stdc++.h>
using namespace std;

#define int long long

// const int INF = 1e9;
const int INF = 1e18;

int dig_sum(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

void solve()
{
    int x, k;
    cin >> x >> k;
    for (int i = x; i <= x + 100; i++)
    {

        if (dig_sum(i) % k == 0)
        {
            cout << i << endl;
            return;
        }
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
        solve();
    }

    return 0;
}
