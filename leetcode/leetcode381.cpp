#include <bits/stdc++.h>
using namespace std;
// clang-format off
    #define dbg(x)cout<<(#x)<<": [";for(auto i=x.begin();i!=x.end();++i)cout<<*i<<(next(i)!=x.end()?", ":"");cout<<"]\n"; // container 
    #define dbgm(x)cout<<(#x)<<": [";for(auto i=x.begin();i!=x.end();++i)cout<<"("<<i->first<<", " << i->second <<(next(i)!=x.end()?"), ":")");cout<<"]\n"; // map or container<pair>
    #define dbgv(x,n)cout<<(#x)<<": [";for(auto i=x.begin();i!=x.end();++i){cout<<"(";int j=n;while(j--){cout<<(*i)[j]<<(j==0?"":", ");};cout<<(next(i)!=x.end()?"), ":")");};cout<<"]\n"; // vector of vectors
    #define dbgvar(x)cout<<(#x)<<": "<<x<<"\n"; // for variables 
    #define dbgpair(x)cout<<(#x)<<": ("<<x.first<<", "<<x.second<<")\n"; // for pairs
    #include <ext/pb_ds/assoc_container.hpp> 
    #include <ext/pb_ds/tree_policy.hpp>
    using ordered_set = __gnu_pbds::tree<array<int,2>, __gnu_pbds::null_type, less<array<int,2>>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
// clang-format on
// order_of_key(a);find_by_order(n)

class Solution
{
public:
    int minimumPushes(string word)
    {
        array<int, 26> m = {0};
        for (int i = 0; i < word.size(); i++)
            m[word[i] - 'a']++;
        sort(m.begin(), m.end(), greater<int>());

        vector<int> cost;
        for (int i = 0; i < 26; i++)
            cost.push_back(i / 8 + 1);

        int ans = 0;
        for (int i = 0; i < 26; i++)
            ans += m[i] * cost[i];
        return ans;
    }

    vector<int>
    countOfPairsFW(int n, int x, int y)
    {

        // floyd warshall
        vector<vector<int>> D(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; i++)
        {
            D[i][i] = 0;
            if (i < n - 1)
                D[i][i + 1] = 1;
            if (i > 0)
                D[i][i - 1] = 1;
        }
        D[x - 1][y - 1] = 1;
        D[y - 1][x - 1] = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    D[j][k] = min(D[j][k], D[j][i] + D[i][k]);

        vector<int> ans(n);
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                ans[D[i][j] - 1] += 2;
        return ans;
    }
    vector<long long> countOfPairsN2(int n, int x, int y)
    {
        x--;
        y--;
        if (x > y)
            swap(x, y);
        vector<long long> ans(n);
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
            {
                int d1 = j - i;
                int d2 = abs(x - i) + 1 + abs(y - j);
                // abs(x-i) +1 + abs(y-j)  < j-i
                //
                ans[min(d1, d2) - 1] += 2;
            }
        return ans;
    }

    vector<long long> countOfPairs(int n)
    {
        vector<long long> a(n), ans(n);
        for (int i = 0; i < n; i++)
        {
            a[0] += 2; // add 2 for each node (left and right)
            a[i]--;    // -1 when reach either end
            a[n - 1 - i]--;
        }
        ans[0] = a[0];
        for (int i = 1; i < n; i++)
            ans[i] = ans[i - 1] + a[i];
        return ans;
    }

    vector<long long> countOfPairs(int n, int x, int y)
    {
        x--;
        y--;
        if (x > y)
            swap(x, y);
        if (y - x < 2)
            return countOfPairs(n); // no point using the tunnel if too short

        vector<long long> a(n), ans(n);
        for (int i = 0; i < n; i++)
        {
            a[0] += 2;                                       // add 2 for each node (left and right)
            a[min(i, abs(i - y) + 1 + x)]--;                 // -1 when reach left end
            a[min(n - 1 - i, abs(i - x) + 1 + n - 1 - y)]--; // -1 when reach right end

            if (x <= i && i <= y && abs((i - x) - (y - i)) < 2)
                // no point using the tunnel if right in the middle
                continue;

            int d = min(abs(i - x), abs(i - y)); // dist to x/y
            a[d]++;                              // +1 when reach x (or y) and branches
            a[d + 1]++;                          // +1 when reach y (or x) and branches

            // -2 when middle of loop meet (floor and ceil)
            if (i <= x || y <= i) // left or right of tunnel
            {
                a[d + (y - x + 1) / 2]--;
                a[d + (y - x) / 2]--;
            }
            else // in between tunnel ends
            {
                a[(y - x) / 2]--;
                a[(y - x + 1) / 2]--;
            }
        }
        ans[0] = a[0];
        for (int i = 1; i < n; i++)
            ans[i] = ans[i - 1] + a[i];
        return ans;
    }
};

int main()
{
    Solution solution;
    int n, x, y;
    string word;
    cin >> n >> x >> y;

    array<int, 3> nxy = {n, x, y};
    dbg(nxy);
    vector<long long> ans;
    ans = solution.countOfPairsN2(n, x, y);
    dbg(ans);
    ans = solution.countOfPairs(n, x, y);
    dbg(ans);
    return 0;
}