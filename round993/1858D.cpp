// clang-format off
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define int long long
const int MOD = 998244353;
const int INF = 1e18; // 1e9
const int MAXBIT = 62;//30

#define dbg(x)cout<<(#x)<<": [";for(auto i=x.begin();i!=x.end();++i)cout<<*i<<(next(i)!=x.end()?", ":"");cout<<"]\n"; // container 
#define dbgm(x)cout<<(#x)<<": [";for(auto i=x.begin();i!=x.end();++i)cout<<"("<<i->first<<", " << i->second <<(next(i)!=x.end()?"), ":")");cout<<"]\n"; // map or container<pair>
#define dbgv(x,n)cout<<(#x)<<": [";for(auto i=x.begin();i!=x.end();++i){cout<<"(";int j=n;while(j--){cout<<(*i)[j]<<(j==0?"":", ");};cout<<(next(i)!=x.end()?"), ":")");};cout<<"]\n"; // vector of vectors
#define dbgvar(x)cout<<(#x)<<": "<<x<<"\n"; // for variables 
#define dbgpair(x)cout<<(#x)<<": ("<<x.first<<", "<<x.second<<")\n"; // for pairs
template <typename T>
vector<pair<T,int>>getStreaks(vector<T> a){vector<pair<T,int>>streaks;int n=a.size();int i=0;while(i<n){int j=i;while(j<n&&a[j]==a[i])j++;streaks.push_back({a[i],j-i});i=j;}return streaks;}
vector<pair<char,int>>getStreaks(string s){return getStreaks(vector<char>(s.begin(),s.end()));}
using ordered_set = __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>; // order_of_key(a);find_by_order(n)
//broken keyboard: (9oOLl>.q
// clang-format on
void solve()
{
    int n, k, num;
    cin >> n >> k;
    string a;
    cin >> a;
    vector<int> p0(n + 1), p1(n + 1), s0(n), s1(n), e0(n), e1(n);
    for (int i = 0; i < n; i++)
    {
        p0[i + 1] = p0[i] + (a[i] == '0');
        p1[i + 1] = p1[i] + (a[i] == '1');
    }
    dbg(a);
    dbg(p0);
    dbg(p1);
    vector<pair<char, int>> streaks = getStreaks(a);
    // prefix sum 0
    // prefix sum 1
    // prefix big streak 0
    // prefix big streak 1
    // suffix big streak 0
    // suffix big streak 1
    dbgm(streaks);
    int l = 0;

    for (auto [c, len] : streaks)
    {
        if (l > 0)
        {
            s0[l] = s0[l - 1];
            s1[l] = s1[l - 1];
        }
        for (int i = 0; i < len; i++)
        {
            if (c == '0')
            {
                s0[l + i] = max(s0[l], i + 1);
                s1[l + i] = s1[l];
            }
            else
            {
                s1[l + i] = max(s1[l], i + 1);
                s0[l + i] = s0[l];
            }
        }
        l += len;
    }

    int r = n - 1;
    for (auto it = streaks.rbegin(); it != streaks.rend(); ++it)
    {

        auto [c, len] = *it;
        if (r < n - 1)
        {
            e0[r] = e0[r + 1];
            e1[r] = e1[r + 1];
        }
        for (int i = 0; i < len; i++)
        {
            if (c == '0')
            {
                e0[r - i] = max(e0[r], i + 1);
                e1[r - i] = e1[r];
            }
            else
            {
                e1[r - i] = max(e1[r], i + 1);
                e0[r - i] = e0[r];
            }
        }
        r -= len;
    }

    // best strategy to maximise streak of 0s
    // for each s

    dbg(s0);
    dbg(s1);
    dbg(e0);
    dbg(e1);
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