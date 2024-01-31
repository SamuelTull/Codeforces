// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;
const int INF = 1e18; // 1e9
const int MAXBIT = 62; //30

#define dbg(x)cout<<(#x)<<": [";for(auto qq=x.begin();qq!=x.end();++qq)cout<<*qq<<(next(qq)!=x.end()?", ":"");cout<<"]\n"; // container 
#define mbg(x)cout<<(#x)<<": [";for(auto qq=x.begin();qq!=x.end();++qq)cout<<"("<<qq->first<<", "<<qq->second<<(next(qq)!=x.end()?"), ":")");cout<<"]\n"; // map or container<pair>
#define nbg(x,n)cout<<(#x)<<": [";for(auto qq=x.begin();qq!=x.end();++qq){cout<<"(";for(auto qqq=qq->begin();qqq!=qq->end();qqq++){cout<<*qqq<<(next(qqq)!=qq->end()?", ":"");};cout<<(next(qq)!=x.end()?"), ":")");};cout<<"]\n"; // vector of vectors
#define vbg(x)cout<<(#x)<<": "<<x<<"\n"; // for variables 
#define pbg(x)cout<<(#x)<<": ("<<x.first<<", "<<x.second<<")\n"; // for pairs
// clang-format on
bool solve()
{
    int n, k, num;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int i = 0;
    int cnt = 0;
    while (i < n && cnt < k)
    {
        if (a[i] == a[0])
            cnt++;
        i++;
    }
    if (cnt < k)
        return false;
    if (a[0] == a[n - 1])
        return true;
    cnt = 0;
    while (i < n && cnt < k)
    {
        if (a[i] == a[n - 1])
            cnt++;
        i++;
    }
    return cnt == k;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        cout << (solve() ? "YES" : "NO") << "\n";
    return 0;
}