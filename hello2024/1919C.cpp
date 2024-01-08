#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
const int inf = 2e5 + 1;
void solve()
{
    int n;
    cin >> n;
    int ans = 0, b = inf, c = inf, a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a <= b)
        {
            b = a;
        }
        else if (a <= c)
        {

            c = a;
        }
        else
        {
            b = min(a, c);
            c = max(a, c);
            ans++;
        }
    }
    cout << ans << "\n";
}

int main()
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
