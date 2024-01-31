// clang-format off
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define int long long
const int MOD = 998244353;
const int INF = 1e18;
// const int INF = 1e9;
#define dbg(x)cout<<(#x)<<": [";for(auto i=x.begin();i!=x.end();++i)cout<<*i<<(next(i)!=x.end()?", ":"");cout<<"]\n"; // container 
#define dbgm(x)cout<<(#x)<<": [";for(auto i=x.begin();i!=x.end();++i)cout<<"("<<i->first<<", " << i->second <<(next(i)!=x.end()?"), ":")");cout<<"]\n"; // map or container<pair>
#define dbgv(x,n)cout<<(#x)<<": [";for(auto i=x.begin();i!=x.end();++i){cout<<"(";int j=-1;while(++j<n){cout<<(*i)[j]<<(j==n-1?"":", ");};cout<<(next(i)!=x.end()?"), ":")");};cout<<"]\n"; // vector of vectors
#define dbgvar(x)cout<<(#x)<<": "<<x<<"\n"; // for variables 
#define dbgpair(x)cout<<(#x)<<": ("<<x.first<<", "<<x.second<<")\n"; // for pairs
template <typename T>
vector<pair<T,int>>getStreaks(vector<T> a){vector<pair<T,int>>streaks;int n=a.size();int i=0;while(i<n){int j=i;while(j<n&&a[j]==a[i])j++;streaks.push_back({a[i],j-i});i=j;}return streaks;}
vector<pair<char,int>>getStreaks(string s){return getStreaks(vector<char>(s.begin(),s.end()));}
// ordered_set
using ordered_set = __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>; // order_of_key(a);find_by_order(n)
// clang-format on

void solve()
{
    // L,R,A,B (can teleport any L<=x<=R to any A<=y<=B)
    // never go backwards so dont care about R
    // always make as big as possible, so dont care about A
    int n, num, q;
    cin >> n;
    vector<array<int, 2>> a(n, {0, 0});
    for (int i = 0; i < n; i++)
        cin >> a[i][0] >> num >> num >> a[i][1];
    sort(a.begin(), a.end());
    vector<array<int, 2>> b;
    b.push_back({0, 0});
    for (int i = 0; i < n; i++)
        if (a[i][0] <= b.back()[1])
            b.back()[1] = max(b.back()[1], a[i][1]);
        else
            b.push_back(a[i]);
    cin >> q;
    while (q--)
    {
        cin >> num;
        int i = lower_bound(b.begin(), b.end(), array<int, 2>{num, INF}) - b.begin() - 1;
        cout << max(num, b[i][1]) << " ";
    }
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
        solve();
    return 0;
}