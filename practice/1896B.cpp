#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<char> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int ans = n;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'B')
        {
            ans -= 1;
        }
        else
        {
            break;
        }
    }
    for (int i = n - 1; ans >= 0 && i >= 0; i--)
    {
        if (s[i] == 'A')
        {
            ans -= 1;
        }
        else
        {
            break;
        }
    }
    cout << max(0, ans - 1) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
