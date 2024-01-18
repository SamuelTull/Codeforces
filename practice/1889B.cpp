#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

// can do in O(n)
// if 1-j is added, all i<j can be added
// solution using pref sums
// could have made easier by dividing all by c
bool solve()
{
    int n, c, C, a1, ai;
    cin >> n >> c >> a1;
    vector<pair<int, int>> a(n);

    for (int i = 1; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(a.begin(), a.end(), [c](pair<int, int> a, pair<int, int> b)
         { return a.first - a.second * c > b.first - b.second * c; });

    if (a[0].first + a1 < a[0].second * c)
        return false;

    C = a1 + a[0].first;
    for (int i = 1; i < n; i++)
    {
        if (C + a[i].first < a[i].second * c)
            return false;
        C += a[i].first;
    }
    return true;
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
        cout << (solve() ? "Yes\n" : "No\n");
    }

    return 0;
}
