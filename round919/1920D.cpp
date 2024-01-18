#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18 + 10;

int get(int N, vector<pair<int, int>> &a)
{
    auto it = upper_bound(a.begin(), a.end(), make_pair(N, INF));
    it--;

    if (it->second == -1)
    {
        int prev_N = it->first - 1;
        N %= prev_N;
        if (N == 0)
            return get(prev_N, a);
        else
            return get(N, a);
    }
    else
        return it->second;
}

void solve()
{
    int n, q, b, x, N = 0;
    bool clipped = false;
    cin >> n >> q;

    vector<pair<int, int>> a; // N,x or N+1 -1
    while (n--)
    {
        cin >> b >> x;
        if (clipped)
            continue;
        if (b == 1)
        {
            N++;
            a.push_back({N, x});
        }
        else
        {
            a.push_back({N + 1, -1});
            x++;
            if (x > INF / N)
            {
                clipped = true;
            }
            else
            {
                N *= x;
            }
        }
    }

    while (q--)
    {
        cin >> N;
        cout << get(N, a) << " ";
    }
    cout << "\n";
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
