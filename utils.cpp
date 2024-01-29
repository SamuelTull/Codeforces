// Description: Useful functions and macros
#include <bits/stdc++.h>
using namespace std;

// ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using ordered_set = __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>; // order_of_key(a);find_by_order(n)

template <typename T>
vector<pair<T,int>>getStreaks(vector<T> a){vector<pair<T,int>>streaks;int n=a.size();int i=0;while(i<n){int j=i;while(j<n&&a[j]==a[i])j++;streaks.push_back({a[i],j-i});i=j;}return streaks;}
vector<pair<char,int>>getStreaks(string s){return getStreaks(vector<char>(s.begin(),s.end()));}
using ordered_set = __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>; // order_of_key(a);find_by_order(n)

// priority_queue
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> Q;

// primes
vector<int> sieveOfEratosthenes(int N)
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

    vector<int> primes;
    for (int p = 2; p <= N; p++)
        if (prime[p])
            primes.push_back(p);

    return primes;
}

/// modular arithemtic
// a / b  = a * inverse(b) % MOD

int power(int a, int b)
// The power function uses the binary exponentiation algorithm to efficiently calculate a^b % MOD. It represents b in binary and multiplies res by a whenever it encounters a 1 in the binary representation of b. It also squares a in each iteration. This allows it to calculate a^b % MOD in O(log b) time.
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
// The inverse function is using Fermat's Little Theorem, which states that if p is a prime number and a is an integer that is not divisible by p, then a^(p-1) ≡ 1 (mod p). If we multiply both sides by a^-1, we get a^(p-2) ≡ a^-1 (mod p). This means that a^(p-2) is the multiplicative inverse of a under modulo p.
// The inverse function calculates a^(MOD - 2) % MOD, which is the multiplicative inverse of a under modulo MOD, using the power function.

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