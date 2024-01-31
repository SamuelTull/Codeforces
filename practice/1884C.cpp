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
    vector<array<int, 2>> a(n);
    map<int, int> mp;
    map<int, int, greater<int>> mp2;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1];
        if (a[i][0] > 1)
        {
            mp[a[i][0]]++;
            mp[a[i][1] + 1]--;
        }
        if (a[i][1] < m)
        {
            mp2[a[i][1]]++;
            mp2[a[i][0] - 1]--;
        }
    }
    // minumum is either 1 or m;
    // turn on all that dont contain 1- find best
    // turn on all that dont contain m- find best
    int best = 0, cur = 0;
    for (auto p : mp)
    {
        cur += p.second;
        best = max(best, cur);
    }
    cur = 0;
    for (auto p : mp2)
    {
        cur += p.second;
        best = max(best, cur);
    }
    cout << best << "\n";
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