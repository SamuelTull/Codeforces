#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool solve()
{
    int n, m;
    cin >> n >> m;
    string temp_s, temp_t;
    cin >> temp_s >> temp_t;
    vector<int> s(n), t(m);
    for (int i = 0; i < n; i++)
    {
        s[i] = temp_s[i] - '0';
    }
    for (int i = 0; i < m; i++)
    {
        t[i] = temp_t[i] - '0';
    }

    bool oo = false, ii = false;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == 0 && s[i + 1] == 0)
        {
            oo = true;
        }
        else if (s[i] == 1 && s[i + 1] == 1)
        {
            ii = true;
        }
    }

    if (!oo && !ii)
    {
        return true;
    }
    if (oo && ii || t[0] != t[m - 1])
    {
        return false;
    }

    for (int i = 0; i < m - 1; i++)
    {
        if (t[i] == t[i + 1])
        {
            return false;
        }
    }

    return oo && t[0] == 1 || ii && t[0] == 0;
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
        cout << (solve() ? "YES\n" : "NO\n");
    }

    return 0;
}
