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

vector<int> primes;
void sieveOfEratosthenes(int N)
{
    vector<bool> prime(N + 1, true);
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= N; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }

    for (int p = 2; p <= N; p++)
        if (prime[p])
            primes.push_back(p);
}

bool solve()
{
    int n, num;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int M = *max_element(a.begin(), a.end());
    map<int, int> cnt;
    for (int &x : a)
    {
        for (int p : primes)
        {
            while (x % p == 0)
            {
                x /= p;
                cnt[p]++;
            }
            if (p * p > x)
                break;
        }
        if (x > 1)
            cnt[x]++;
    }
    for (auto [p, c] : cnt)
    {
        if (c % n != 0)
            return false;
    }
    return true;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    sieveOfEratosthenes(sqrt(1e6) + 1);
    while (t--)
        cout << (solve() ? "YES" : "NO") << "\n";
    return 0;
}