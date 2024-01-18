#include <bits/stdc++.h>
using namespace std;
// clang-format off
#define print(x) cout << (#x) << ": "; for (auto i : x) cout << i << " "; cout << "\n";
// clang-format on
#define int long long
// const int INF = 1e9;

// a:    1 2 3 4
// diff:  1 1 1
// l = 1, they mean 0,
// r = 3 they mean 2

void query1(vector<int> &diff, set<int> &p, set<int> &p1, int &n)
{
    int l, r, x;
    cin >> l >> r >> x;
    l--, r--;
    if (l > 0)
    {
        diff[l - 1] = (diff[l - 1] + x) % 26;
    }

    if (r < n - 1)
    {
        diff[r] = (diff[r] - x + 26) % 26;
    }
    if (l > 0)
    {
        if ((diff[l - 1]) % 26 == 0)
            p.insert(l - 1);
        else
            p.erase(l - 1);

        if ((diff[l - 1] + diff[l]) % 26 == 0)
            p1.insert(l - 1);
        else
            p1.erase(l - 1);
        if (l > 1)
            if ((diff[l - 2] + diff[l - 1]) % 26 == 0)
                p1.insert(l - 2);
            else
                p1.erase(l - 2);
    }

    if (r < n - 1)
    {
        if ((diff[r]) % 26 == 0)
            p.insert(r);
        else
            p.erase(r);
        if (r < n - 2)
            if ((diff[r] + diff[r + 1]) % 26 == 0)
                p1.insert(r);
            else
                p1.erase(r);
        if (r > 0)
            if ((diff[r - 1] + diff[r]) % 26 == 0)
                p1.insert(r - 1);
            else
                p1.erase(r - 1);
    }
}

bool query2(set<int> &p, set<int> &p1)
{
    int l, r;
    cin >> l >> r;
    l--, r--;
    // if (l == r)
    //     return true;
    auto it = p.lower_bound(l);
    if (it != p.end() && *it <= r - 1)
        return false;

    auto it_1 = p1.lower_bound(l);
    if (it_1 != p1.end() && *it_1 <= r - 2)
        return false;

    return true;
}

void solve()
{
    int n, q, op;
    string s;
    cin >> n >> q >> s;
    vector<int> a(n), diff(n - 1);
    for (int i = 0; i < n; i++)
        a[i] = (s[i] - 'a');
    for (int i = 0; i < n - 1; i++)
        diff[i] = (a[i + 1] - a[i] + 26) % 26;

    set<int> p, p1;
    for (int i = 0; i < n - 1; i++)
        if (diff[i] == 0)
            p.insert(i);
    for (int i = 0; i < n - 2; i++)
        if ((diff[i] + diff[i + 1]) % 26 == 0)
            p1.insert(i);
    // print(diff);
    // print(p);
    // print(p1);
    while (q--)
    {
        cin >> op;
        if (op == 1)
        {
            query1(diff, p, p1, n);
            // print(diff);
            // print(p);
            // print(p1);
        }
        else
        {
            cout << (query2(p, p1) ? "YES" : "NO") << "\n";
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
        solve();
    return 0;
}