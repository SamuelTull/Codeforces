// clang-format off
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
// const int INF = 1e9;
#define dbg(x)cout<<(#x)<<": [";for(auto i=x.begin();i!=x.end();++i)cout<<*i<<(next(i)!=x.end()?", ":"");cout<<"]\n"; // container 
#define dbgm(x)cout<<(#x)<<": [";for(auto i=x.begin();i!=x.end();++i)cout<<"("<<i->first<<", " << i->second <<(next(i)!=x.end()?"), ":")");cout<<"]\n"; // map or container<pair>
#define dbgv(x,n)cout<<(#x)<<": [";for(auto i=x.begin();i!=x.end();++i){cout<<"(";j=n;while(j--){cout<<(*i)[j]<<(j==0?"":", ");};cout<<(next(i)!=x.end()?"), ":")");};cout<<"]\n"; // vector of vectors
#define dbgvar(x)cout<<(#x)<<": "<<x<<"\n"; // for variables 
#define dbgpair(x)cout<<(#x)<<": ("<<x.first<<", "<<x.second<<")\n"; // for pairs
template <typename T>
vector<pair<T,int>>getStreaks(vector<T> a){vector<pair<T,int>>streaks;int n=a.size();int i=0;while(i<n){int j=i;while(j<n&&a[j]==a[i])j++;streaks.push_back({a[i],j-i});i=j;}return streaks;}
vector<pair<char,int>>getStreaks(string s){return getStreaks(vector<char>(s.begin(),s.end()));}
// clang-format on

bool solve()
{
    int n, i, j;
    cin >> n;
    vector<int> a(n), b;
    for (i = 0; i < n; i++)
        cin >> a[i];
    if (a[0] != n)
        return false;
    for (int i = n - 1; i >= 0; i--)
        while (b.size() < a[i])
            b.push_back(a[i]);

    dbgm(getStreaks(a));
    dbgm(getStreaks("AAAABBBBBBBBBC"));

    // check a = b rversered
    for (i = 0; i < n; i++)
        if (a[i] != b[n - i - 1])
            return false;

    return true;
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