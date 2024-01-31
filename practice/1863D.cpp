// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;
const int INF = 1e18; // 1e9
const int MAXBIT = 62; //30

#define dbg(x)cout<<(#x)<<": [";for(auto qq=x.begin();qq!=x.end();++qq)cout<<*qq<<(next(qq)!=x.end()?", ":"");cout<<"]\n"; // container 
#define mbg(x)cout<<(#x)<<": [";for(auto qq=x.begin();qq!=x.end();++qq)cout<<"("<<qq->first<<", "<<qq->second<<(next(qq)!=x.end()?"), ":")");cout<<"]\n"; // map or container<pair>
#define vbg(x)cout<<(#x)<<": [";for(auto qq=x.begin();qq!=x.end();++qq){cout<<"(";for(auto qqq=qq->begin();qqq!=qq->end();qqq++){cout<<*qqq<<(next(qqq)!=qq->end()?", ":"");};cout<<(next(qq)!=x.end()?"), ":")");};cout<<"]\n"; // vector of vectors
#define xbg(x)cout<<(#x)<<": "<<x<<"\n"; // for variables 
#define pbg(x)cout<<(#x)<<": ("<<x.first<<", "<<x.second<<")\n"; // for pairs
// clang-format on
void solve()
{
    int n, m, num;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // rows
    int cntB, cntW, cntU;
    for (int r = 0; r < n; r++)
    {
        cntB = 0, cntW = 0, cntU = 0;
        for (int c = 0; c < m; c++)
        {
            if (a[r][c] == 'B')
                cntB++;
            else if (a[r][c] == 'W')
                cntW++;
            else if (a[r][c] == 'U')
                cntU++;
        }
        int d = cntB - cntW;
        if ((cntB + cntW + cntU) % 2 != 0 || abs(d) > cntU)
        {
            cout << "-1\n";
            return;
        }
        cntU -= abs(d);
        cntW = max(0LL, d) + cntU / 2;
        cntB = max(0LL, -d) + cntU / 2;
        for (int c = 0; c < m; c++)
        {
            if (a[r][c] == 'U')
            {
                if (cntW > 0)
                {
                    a[r][c] = 'W';
                    a[r + 1][c] = 'B';
                    cntW--;
                }
                else
                {
                    a[r][c] = 'B';
                    a[r + 1][c] = 'W';
                    cntB--;
                }
            }
        }
    }
    // cols
    int cntL;
    for (int c = 0; c < m; c++)
    {
        cntB = 0, cntW = 0, cntL = 0;
        for (int r = 0; r < n; r++)
        {
            if (a[r][c] == 'B')
                cntB++;
            else if (a[r][c] == 'W')
                cntW++;
            else if (a[r][c] == 'L')
                cntL++;
        }
        int d = cntB - cntW;
        if ((cntB + cntW + cntL) % 2 != 0 || abs(d) > cntL)
        {
            cout << "-1\n";
            return;
        }
        cntL -= abs(d);
        cntW = max(0LL, d) + cntL / 2;
        cntB = max(0LL, -d) + cntL / 2;
        for (int r = 0; r < n; r++)
        {
            if (a[r][c] == 'L')
            {
                if (cntW > 0)
                {
                    a[r][c] = 'W';
                    a[r][c + 1] = 'B';
                    cntW--;
                }
                else
                {
                    a[r][c] = 'B';
                    a[r][c + 1] = 'W';
                    cntB--;
                }
            }
        }
    }

    for (string s : a)
        cout << s << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        // cout << solve() << "\n";
        // cout << (solve() ? "YES" : "NO") << "\n";
        solve();
    return 0;
}