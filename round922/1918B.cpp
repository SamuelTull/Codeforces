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
    int n, num;
    cin >> n;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i][0];
    for (int i = 0; i < n; i++)
        cin >> a[i][1];

    sort(a.begin(), a.end(), [](array<int, 2> a, array<int, 2> b)
         { return a[0] + a[1] < b[0] + b[1]; });
    for (int i = 0; i < n; i++)
        cout << a[i][0] << " ";
    cout << "\n";
    for (int i = 0; i < n; i++)
        cout << a[i][1] << " ";
    cout << "\n";
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