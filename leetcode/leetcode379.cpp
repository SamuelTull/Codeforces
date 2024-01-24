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
    int areaOfMaxDiagonal(vector<vector<int>> &dimensions)
    {
        int best = 0, d, maxd = 0, n = dimensions.size();
        for (int i = 0; i < n; i++)
        {
            d = dimensions[i][0] * dimensions[i][0] + dimensions[i][1] * dimensions[i][1];
            if (d > maxd)
            {
                maxd = d;
                best = dimensions[i][0] * dimensions[i][1];
            }
            else if (d == maxd)
            {
                best = max(best, dimensions[i][0] * dimensions[i][1]);
            }
        }
        return best;
    }

    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f)
    {
        // most of time is 2 moves for rook
        // less if already on same row AND bishop is not in the way
        if (a == e)
            if (c != a)
                return 1;
            else if (((b < d) && (d < f)) || ((b > d) && (d > f)))
                return 2;
            else
                return 1;

        if (b == f)
            if (d != b)
                return 1;
            else if (((a < c) && (c < e)) || ((a > c) && (c > e)))
                return 2;
            else
                return 1;

        // bishop on same diagonal and rook not in way
        // move bishop until hit edge or queen or rook
        int x = c, y = d;

        for (int i : {1, -1})
            for (int j : {1, -1})

            {
                x = c;
                y = d;
                while (x > 0 && x < 9 && y > 0 && y < 9)
                {
                    x += i;
                    y += j;
                    if (x == e && y == f)
                        return 1;
                    if (x == a && y == b)
                        break;
                }
            }

        return 2;
    }
    int maximumSetSize(vector<int> &a, vector<int> &b)
    {
        int n = a.size(); // lose n/2 from both
        unordered_set<int> sa = unordered_set<int>(a.begin(), a.end()), sb = unordered_set<int>(b.begin(), b.end());
        int a_and_b = 0, a_not_b = 0, b_not_a = 0;
        for (int i : sa)
            if (sb.find(i) != sb.end())
                a_and_b++;
            else
                a_not_b++;
        for (int i : sb)
            if (sa.find(i) == sa.end())
                b_not_a++;
        a_not_b = min(n / 2, a_not_b);
        b_not_a = min(n / 2, b_not_a);
        return min(n, a_not_b + b_not_a + a_and_b);
    }
};

int main()
{
    Solution solution;

    int t, n, x, y;
    string s;
    cin >> s >> n;
    vector<vector<int>> dimensions = {{9, 3}, {8, 6}};
    cout << solution.areaOfMaxDiagonal(dimensions);
    return 0;
}