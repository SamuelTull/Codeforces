#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

void solve()
{
    int n, k, q, x;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> L(k), R(k);
    vector<bool> F(n + 1);

    for (int i = 0; i < k; i++)
    {
        cin >> L[i];
    }
    for (int i = 0; i < k; i++)
    {
        cin >> R[i];
    }
    cin >> q;
    while (q--)
    {
        cin >> x;
        F[x] = !F[x];
    }
    for (int idx = 0; idx < k; idx++)
    {
        bool flip = false;
        for (int a = L[idx]; a <= (R[idx] + L[idx]) / 2; a++)
        {

            int b = R[idx] + L[idx] - a;
            flip ^= F[a];
            flip ^= F[b];
            if (flip)
            {
                swap(s[a - 1], s[b - 1]);
            }
        }
    }
    cout << s << endl;
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
