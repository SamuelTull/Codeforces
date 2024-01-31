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
array<bool, 1 << 8> S;

bool can(int &x, vector<int> &a)
{
    S.fill(false);
    S[0] = true;
    int cur = 0;

    for (int i = 0; i < a.size(); i++)
    {
        cur ^= a[i];
        if (S[cur ^ x])
        {
            return true;
        }
        S[cur] = true;
    }
    return false;
}

void solve()
{
    int n, num;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // find windw with biggest X0R
    // use binary search?
    int s = *max_element(begin(a), end(a));
    int b = 0;
    for (int i = 0; i < n; i++)
        b |= a[i];
    b++;
    while (s < b)
    {
        int m = (s + b + 1) / 2;
        if (can(m, a))
            s = m;
        else
            b = m - 1;
    }
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