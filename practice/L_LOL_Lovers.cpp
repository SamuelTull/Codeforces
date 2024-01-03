#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    pair<int, int> cnt = {0, 0};
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
            cnt.first++;
        else
            cnt.second++;
    }

    pair<int, int> curr = {0, 0};

    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == 'L')
            curr.first++;
        else
            curr.second++;

        if (curr.first != cnt.first - curr.first && curr.second != cnt.second - curr.second)
        {
            cout << i + 1 << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
