// clang-format off
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define int long long
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

const int MOD = 998244353;
const int nbits = 32;

int f(int l, int r, vector<array<int, nbits>> &pref)
{
    int ans = 0;
    for (int i = 0; i < nbits; i++)
        if ((pref[r + 1][i] - pref[l][i]) % 2 == 1)
            ans += (1 << i);
    return ans % MOD;
}

int fslow(int l, int r, vector<int> &a)
{
    int ans = a[l];
    for (int i = l + 1; i <= r; i++)
        ans = ans ^ a[i];
    return ans;
}

int solve()
{
    int n, num;
    cin >> n;
    int ans = 0;
    vector<int> a(n);
    vector<bitset<nbits>> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = bitset<nbits>(a[i]);
    }

    for (int bit = 0; bit < nbits; bit++)
    {
        // for new
        int seen = 0;
        array<int, 2> cnt = {1, 0}, sum = {0, 0};
        for (int r = 1; r <= n; r++)
        {
            seen += b[r - 1][bit];
            if (seen % 2 == 0)
            {
                ans += (cnt[1] * r - sum[1]) * (1 << bit);
                ans %= MOD;
                cnt[0]++;
                sum[0] += r;
            }
            else
            {
                ans += (cnt[0] * r - sum[0]) * (1 << bit);
                ans %= MOD;
                cnt[1]++;
                sum[1] += r;
            }
        }
    }
    return ans % MOD;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << solve() << "\n";
}