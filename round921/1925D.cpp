// clang-format off
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
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
int power(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int inverse(int a)
{
    return power(a, MOD - 2);
}

const int N = 200005;
int fact[N], inv[N];
void pre()
{
    fact[0] = 1;
    inv[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = (i * fact[i - 1]) % MOD;
    for (int i = 1; i < N; i++)
        inv[i] = power(fact[i], MOD - 2);
}

int nCr(int n, int r)
{
    if (r > n || r < 0)
        return 0;
    if (n == r)
        return 1;
    if (r == 0)
        return 1;
    return (((fact[n] * inv[r]) % MOD) * inv[n - r]) % MOD;
}

int solve()
{
    int n, m, k, num;
    cin >> n >> m >> k;
    int p = n * (n - 1) / 2 % MOD; // num pairs
    int res = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> num >> num >> num;
        res = (res + num) % MOD;
    }
    // initial contribution is k*m/d * E[f]}
    // E[f] is expected value of f- (average)
    // k * m/d * sum(a)/m = k * sum(a)/d
    res = res * k % MOD;
    res = res * inverse(p) % MOD;

    vector<int> powers(k + 1), powers2(k + 1);
    int v1 = inverse(p);
    int v2 = (p - 1) * inverse(p) % MOD;
    powers[0] = 1;
    powers2[0] = 1;
    for (int i = 1; i <= k; i++)
    {
        powers[i] = powers[i - 1] * v1 % MOD;
        powers2[i] = powers2[i - 1] * v2 % MOD;
    }
    for (int x = 2; x <= k; x++)
    {
        int cur = x * (x - 1) / 2 % MOD;
        cur = cur * nCr(k, x) % MOD;
        cur = cur * powers[x] % MOD;
        cur = cur * powers2[k - x] % MOD;
        cur = cur * m % MOD;
        res = (res + cur) % MOD;
    }
    return res;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    pre();
    int t = 1;
    cin >> t;
    while (t--)
        cout << solve() << "\n";
    return 0;
}