#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve()
{
    string s;
    cin >> s;

    int n = s.size();

    while (s[n - 1] == '0')
    {
        n--;
    }

    n--;
    for (int i = 0; i < n; i++)
    {
        cout << s[i];
    }
    cout << "\n";
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
