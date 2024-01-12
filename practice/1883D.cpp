#include <bits/stdc++.h>
using namespace std;

void set_add(map<int, int> &L, map<int, int> &R)
{
    int l, r;
    cin >> l >> r;

    R[r]++;
    L[l]++;
}

void set_rem(map<int, int> &L, map<int, int> &R)
{
    int l, r;
    cin >> l >> r;

    R[r]--;
    if (R[r] == 0)
        R.erase(r);
    L[l]--;
    if (L[l] == 0)
        L.erase(l);
}

void set_print(map<int, int> &L, map<int, int> &R)
{
    cout << "L: ";
    for (auto i : L)
        for (int j = 0; j < i.second; j++)
            cout << i.first << " ";
    cout << endl;
    cout << "R: ";
    for (auto i : R)
        for (int j = 0; j < i.second; j++)
            cout << i.first << " ";
    cout << endl;
}

void set_query(map<int, int> &L, map<int, int> &R)
{
    if (L.empty())
    {
        cout << "NO" << endl;
        return;
    }
    int l, r;
    r = R.begin()->first;
    l = L.rbegin()->first;

    cout << (r < l ? "YES" : "NO") << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    map<int, int> L, R;
    int t = 1;
    cin >> t;
    char c;
    while (t--)
    {
        cin >> c;
        if (c == '+')
            set_add(L, R);
        else
            set_rem(L, R);
        // set_print(L, R);
        set_query(L, R);
    }

    return 0;
}
