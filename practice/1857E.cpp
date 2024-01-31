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
// clang-format on  ()>ol
void solve()
{
    int n, num;
    cin >> n;
    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0];
        a[i][1] = i;
    }
    // cacutate ans fr smaest
    // t get t next d*)s-be)
    sort(begin(a), end(a));
    map<int, int> cnt;
    cnt[a[0][0]] = n;
    for (int i = 0; i < n; i++)
        cnt[a[i][0] + 1]--;
    int ans = 0, cur = 0;
    for (auto it = cnt.begin(); it != cnt.end(); it++)
    {
        cur += it->second;
        if (next(it) != cnt.end())
            ans += (next(it)->first - it->first) * cur;
    }
    a[0][2] = ans; 
    for (int i = 1; i < n; i++)
    {
        if (a[i][0] == a[i - 1][0])
            a[i][2] = a[i - 1][2];
        else
        {
            int d = a[i][0] - a[i - 1][0];
            a[i][2] = a[i - 1][2] + d * ( 2 * i - n);
        } 
    }
    sort(begin(a), end(a), [](array<int, 3> x, array<int, 3> y) { return x[1] < y[1]; });
    for (int i = 0; i < n; i++)
        cout << a[i][2] << " ";
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