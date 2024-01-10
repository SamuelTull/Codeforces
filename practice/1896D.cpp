#include <bits/stdc++.h>
using namespace std;

#define int long long

bool query1(int &x, int &n, set<int> &ones)
{
    int n_ones = ones.size();
    int M = 2 * n - n_ones;
    if (n_ones % 2 == x % 2) // same parity
    {
        return (x <= M);
    }
    if (n_ones == 0) // all twos
        return false;
    // biggest s with different parity: first/last one
    int s1 = M - (2 * (*ones.begin()) + 1);          // prefsum up to and including first one
    int s2 = M - (2 * (n - 1 - *ones.rbegin()) + 1); // suffsum up to and including last one
    return (x <= s1 || x <= s2);
}

void solve()
{
    int n, q, num;
    cin >> n >> q;
    set<int> ones;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (num == 1)
        {
            ones.insert(i);
        }
    }

    int op, x;
    while (q--)
    {
        cin >> op >> x;
        if (op == 1)
        {
            cout << (query1(x, n, ones) ? "YES" : "NO") << endl;
        }
        else
        {
            x--;
            cin >> num;
            if (num == 1)
                ones.insert(x);
            else
                ones.erase(x);
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
