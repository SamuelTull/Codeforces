#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
// const int INF = 1e9;

// clang-format off
#define dbv(x) cout << (#x) << ": " << x << "\n";
#define dbc(x) cout << (#x) << ": "; for (auto i : x) cout << i << " "; cout << "\n";
// clang-format on

int solve()
{
    string s;
    cin >> s;
    int n = s.size();
    if (s[0] == 'B' || s[n - 1] == 'B' || s.find("BB") != string::npos)
        // get all As
        return count(s.begin(), s.end(), 'A');
    // else get all As but smallest group
    if (s.find("B") == string::npos)
        return 0;

    vector<int> grps;
    int As = 0;
    int cnt = 0;
    int i = 0;
    while (i < n)
    {
        while (i < n && s[i] == 'A')
        {
            As++;
            cnt++;
            i++;
        }
        if (cnt)
            grps.push_back(cnt);
        cnt = 0;
        i++;
    }
    // min value of grps
    int min_val = *min_element(grps.begin(), grps.end());
    return As - min_val;
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
