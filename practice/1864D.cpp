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
#define dbgv(x,n)cout<<(#x)<<": [";for(auto i=x.begin();i!=x.end();++i){cout<<"(";int j=n;while(j--){cout<<(*i)[j]<<(j==0?"":", ");};cout<<(next(i)!=x.end()?"), ":")");};cout<<"]\n"; // vector of vectors
#define dbgvar(x)cout<<(#x)<<": "<<x<<"\n"; // for variables 
#define dbgpair(x)cout<<(#x)<<": ("<<x.first<<", "<<x.second<<")\n"; // for pairs
template <typename T>
vector<pair<T,int>>getStreaks(vector<T> a){vector<pair<T,int>>streaks;int n=a.size();int i=0;while(i<n){int j=i;while(j<n&&a[j]==a[i])j++;streaks.push_back({a[i],j-i});i=j;}return streaks;}
vector<pair<char,int>>getStreaks(string s){return getStreaks(vector<char>(s.begin(),s.end()));}
// ordered_set
using ordered_set = __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>; // order_of_key(a);find_by_order(n)
// clang-format on

int solve()
{
    int n, num, ans = 0;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<bool> op(n), L(n), R(n), D(n);
    // row 1
    for (int c = 0; c < n; c++)
    {
        if (a[0][c] == '1')
        {
            op[c] = true;
            ans++;
        }
    }

    for (int r = 1; r < n; r++)
    {
        // cout << "Before\n";
        // dbgvar(ans);
        // dbg(a[r]);
        // dbg(op);
        // dbg(L);
        // dbg(R);
        // dbg(D);
        for (int c = 0; c < n - 1; c++)
        {
            L[c] = op[c + 1] ^ L[c + 1];
            R[n - c - 1] = op[n - c - 2] ^ R[n - c - 2];
        }
        for (int c = 0; c < n; c++)
        {
            D[c] = L[c] ^ R[c] ^ D[c] ^ op[c];
        }

        for (int c = 0; c < n; c++)
        {
            if (D[c] ^ (a[r][c] == '1'))
            {
                op[c] = true;
                ans++;
            }
            else
                op[c] = false;
        }

        // cout << "After\n";
        // dbgvar(ans);
        // dbg(L);
        // dbg(R);
        // dbg(D);
        // dbg(op);
    }
    return ans;
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