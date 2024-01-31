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
const int MAXN = 1e9 + 5;
int choose2(int n)
{
    if (n < 2)
        return 0;
    return n * (n - 1) / 2;
}

void solve()
{
    int n, num, q, b, c;
    cin >> n;
    array<int, MAXN> m;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        m[num]++;
    }
    cin >> q;
    while (q--)
    {
        cin >> b >> c;
        // i + j = b
        // i * j = c
        // x^2 - bx + c
        // x = (b +- sqrt(b^2 - 4c)) / 2
        int D = b * b - 4 * c;
        if (D < 0)
        {
            cout << "0 ";
            continue;
        }
        // else if (D == 0)
        //     if (b % 2 != 0 || b / 2 >= MAXN)
        //     {
        //         cout << "0 ";
        //         continue;
        //     }
        //     else
        //     {
        //         cout << choose2(m[b / 2]) << " ";
        //         continue;
        //     }
        // else
        // {
        //     int x1 = (b + sqrt(D)) / 2;
        //     int x2 = (b - sqrt(D)) / 2;
        //     if ((x1 + x2 != b) || (x1 * x2 != c) || x1 < 0 || x1 >= MAXN || x2 < 0 || x2 >= MAXN)
        //     {
        //         cout << "0 ";
        //         continue;
        //     }
        //     else
        //     {
        //         cout << m[x1] * m[x2] << " ";
        //         continue;
        //     }
        // }
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