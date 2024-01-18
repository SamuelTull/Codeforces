// Description: Useful functions and macros
#include <bits/stdc++.h>
using namespace std;

// ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using ordered_set = __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
// order_of_key(a);find_by_order(n)
// greater<int> for descending order, less_equal for multiset

// priority_queue
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> Q;


//primes
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