#include <bits/stdc++.h>
using namespace std;

#define int long long

int solve()
{
    int n, ans = 0;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (b[i] < a[i])
        {
            swap(a[i], b[i]);
        }
        ans += b[i] - a[i];
    }

    ans += max(0LL, 2 * (*max_element(a.begin(), a.end()) - *min_element(b.begin(), b.end())));
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        cout << solve() << "\n";
    return 0;
}