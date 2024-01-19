#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
// const int INF = 1e9;

// clang-format off
#define dbv(x) cout << (#x) << ": " << x << "\n";
#define dbc(x) cout << (#x) << ": "; for (auto i : x) cout << i << " "; cout << "\n";
// clang-format on

bool solve()
{
    array<int, 3> arr;
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr.begin(), arr.end());
    int c = arr[0], b = arr[1], a = arr[2];
    if (a == b && (c % 2 == 0))
        return true;
    if (b == c && (a % 2 == 0))
        return true;
    if (a == b + c)
        return true;
    return false;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        cout << (solve() ? "YES" : "NO") << "\n";
    return 0;
}