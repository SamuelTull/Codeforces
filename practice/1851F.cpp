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
    int n, k, num;
    cin >> n >> k;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0];
        a[i][1] = i + 1;
    }
    sort(begin(a), end(a));
    // maximise (i^x)&(j^x)
    //  bit is off in i and j: then on in x -> will end on
    //  bit is on in i and j: then off in x -> will end on
    //  bit is on in i and off in j: then will end off
    // pick i and j to minimise i ^ j
    // pick x to be not i and not j

    // 3 9  0011 1001 : 2  14 1110     1101 & 0111 = 0101 = 5
    // 9 13 1001 1101 : 1  6  0110     1111 & 10
    array<int, 3> best = {INF, -1, -1};
    for (int i = 0; i < n - 1; i++)
    {
        int x = a[i][0] ^ a[i + 1][0];
        if (x < best[0])
            best = {x, i, i + 1};
    }
    int i = best[1], j = best[2];
    int x = ((1 << k) - 1) ^ (a[i][0] & a[j][0]);
    cout << a[i][1] << " " << a[j][1] << " " << x << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}