#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

void me(int &i, vector<bool> &seen)
{
    while (seen[i])
        i++;
    cout << i + 1 << "\n";
    cout.flush();
    seen[i] = true;
}

void them(vector<bool> &seen)
{
    int x;
    cin >> x;
    if (x == -1)
        exit(0);
    seen[x - 1] = true;
}

void solve()
{
    int n, sx, sy, x, y, no = 0;
    cin >> n >> sx >> sy;
    vector<bool> odd(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        if ((abs(sx - x) + abs(sy - y)) % 2 == 1)
        {
            no++;
            odd[i] = true;
        }
    }
    vector<bool> seen(n);
    int turn = 0;
    bool my_turn = true;
    if (no % 2 == 1)
    {
        cout << "Second\n";
        cout.flush();
        my_turn = false;
    }
    else
    {
        cout << "First\n";
        cout.flush();
    }
    while (n--)
    {
        if (my_turn)
            me(turn, seen);
        else
            them(seen);
        my_turn = !my_turn;
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
        solve();
    // cout << solve() << "\n";
    // cout << (solve() ? "YES" : "NO") << "\n";
    return 0;
}