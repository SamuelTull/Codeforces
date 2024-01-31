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
int solve()
{
    int n, num, m, m1, m2;
    cin >> n;
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        m1 = INF, m2 = INF;
        while (m--)
        {
            cin >> num;
            if (num < m1)
            {
                m2 = m1;
                m1 = num;
            }
            else if (num < m2)
                m2 = num;
        }
        ans.push_back({m1, m2});
    }
    int s = 0;
    m1 = INF, m2 = INF;
    for (int i = 0; i < n; i++)
    {
        m1 = min(m1, ans[i].first);
        m2 = min(m2, ans[i].second);
        s += ans[i].second;
    }
    return s - m2 + m1;
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