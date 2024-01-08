#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve()
{
    int x, y, k;
    cin >> x >> y >> k;

    if (x > y)
        cout << x << '\n';
    else if (y <= x + k)
        cout << y << '\n';
    else
    {
        cout << y + (y - (x + k)) << '\n';
    }
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
