// clang-format off
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define int long long
const int MOD = 998244353;
const int INF = 1e18;
const int MAXBIT = 62; 
// const int INF = 1e9;
#define dbg(x)cout<<(#x)<<": [";for(auto i=x.begin();i!=x.end();++i)cout<<*i<<(next(i)!=x.end()?", ":"");cout<<"]\n"; // container 
#define dbgm(x)cout<<(#x)<<": [";for(auto i=x.begin();i!=x.end();++i)cout<<"("<<i->first<<", " << i->second <<(next(i)!=x.end()?"), ":")");cout<<"]\n"; // map or container<pair>
#define dbgv(x,n)cout<<(#x)<<": [";for(auto i=x.begin();i!=x.end();++i){cout<<"(";int j=n;while(j--){cout<<(*i)[j]<<(j==0?"":", ");};cout<<(next(i)!=x.end()?"), ":")");};cout<<"]\n"; // vector of vectors
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
    int n, num;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n - 1; i++)
        cin >> a[i];

    vector<int> T(MAXBIT);
    for (int x = 1; x < n; x++)
        for (int bit = 0; bit < MAXBIT; bit++)
            if (x & (1LL << bit))
                T[bit]++;

    vector<int> b(n), S(MAXBIT);
    for (int i = 0; i < n - 1; i++)
    {
        b[i + 1] = b[i] ^ a[i];
        for (int bit = 0; bit < MAXBIT; bit++)
            if (b[i + 1] & (1LL << bit))
                S[bit]++;
    }

    int x = 0;
    for (int bit = 0; bit < MAXBIT; bit++)
    {
        if (S[bit] != T[bit])
            x ^= (1LL << bit);
    }

    for (int i = 0; i < n; i++)
        cout << (b[i] ^ x) << " ";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    while (t--)
        solve();
    return 0;
}