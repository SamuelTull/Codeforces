#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int INF = 1e9;
const int INF = 1e18;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end(), greater<pair<int, int>>()); // O(nlogn)
    set<int> s;
    map<int, int> ans;

    int i = 0, curr;
    while (i < n)
    {
        curr = a[i].first;
        while (i < n && a[i].first == curr)
        {
            s.insert(a[i].second); // O(logn)
            i++;
        }
        ans[curr] = 2 * (*s.rbegin() - *s.begin() + 1);
    }
    for (int i = 1; i <= k; i++)
    {
        cout << ans[i] << " ";
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
        solve();
    return 0;
}