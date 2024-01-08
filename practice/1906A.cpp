#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool adj(int i, int j)
{
    return (abs(i / 3 - j / 3) <= 1 && abs(i % 3 - j % 3) <= 1);
}
void solve()
{
    const int n = 9;
    char G[n];
    for (int i = 0; i < n; i++)
    {
        cin >> G[i];
    }
    string ans = "CCC", curr;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {

                if (i == j || i == k || j == k || !adj(i, j) || !adj(j, k))
                    continue;

                curr = G[i];
                curr += G[j];
                curr += G[k];
                ans = min(ans, curr);
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}
