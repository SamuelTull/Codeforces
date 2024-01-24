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
    int maxFrequencyElements(vector<int> &nums)
    {
        unordered_map<int, int> m;
        for (int i : nums)
            m[i]++;
        // max freq
        int max_freq = 0;
        for (auto i : m)
            max_freq = max(max_freq, i.second);
        // elems with max freq
        int ans = 0;
        for (auto i : m)
            if (i.second == max_freq)
                ans++;
        return ans * max_freq;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k)
    {
        vector<int> A, B, ans;
        for (int i = 0; i < s.size(); i++)
        {
            if (s.substr(i, a.size()) == a)
                A.push_back(i);
            if (s.substr(i, b.size()) == b)
                B.push_back(i);
        }
        for (int i : A)
        {
            auto j = lower_bound(B.begin(), B.end(), i);
            if (j != B.end() && abs(*j - i) <= k)
                ans.push_back(i);
            else if (j != B.begin() && abs(*prev(j) - i) <= k)
                ans.push_back(i);
        }
        return ans;
    }

    long long f_slow(long long n, int x)
    {
        bitset<64> b(n);
        int ans = 0;
        for (int i = x; i < 64; i += x)
            if (b[i - 1])
                ans++;
        return ans;
    }

    long long S_slow(long long n, int x)
    {

        long long ans = 0;
        for (long long i = 1; i <= n; i++)
            ans += f_slow(i, x);
        return ans;
    }

    long long S(long long n, int x)
    {
        long long ans = 0;
        for (int bit = x; bit <= 62; bit += x)
        {
            long long s = 1LL << bit; // size of block (half are 1s)
            long long blocks = n / s; // number of blocks
            long long rem = n % s;    // remainder
            ans += blocks * s / 2;
            ans += max(0LL, rem - s / 2 + 1);
        }
        return ans;
    }

    long long findMaximumNumber(long long k, int x)
    {
        long long l = 0, m, r = 1e15;
        while (l < r)
        {
            m = (l + r + 1) / 2;
            if (S(m, x) > k)
                r = m - 1;
            else
                l = m;
        }
        return l;
    }

    int maxArea(vector<int> &height)
    {
        int n = height.size();
        vector<int> v(n);
        iota(v.begin(), v.end(), 0);
        sort(v.begin(), v.end(), [&](int i, int j)
             { return height[i] > height[j]; });

        int ans = 0;
        set<int> s;
        for (int i : v)
        {
            s.insert(i);
            int l = *s.begin(), r = *s.rbegin();
            int w = r - l, h = min(height[l], height[r]);
            ans = max(ans, w * h);
        }
        return ans;
    }

    int maxArea2(vector<int> &height)
    {
        int i = 0, j = height.size() - 1, ans = INT_MIN;
        while (i < j)
        {
            ans = max(ans, min(height[i], height[j]) * (j - i));
            (height[i] < height[j]) ? i++ : j--;
        }
        return ans;
    }

    string convert(string s, int numRows)
    {

        if (numRows == 1)
            return s;
        vector<string> rows(numRows);

        int n = s.size();
        int row = 0, dr;
        for (char c : s)
        {
            rows[row] += c;
            if (row == 0)
            {
                dr = 1;
            }
            else if (row == numRows - 1)
            {
                dr = -1;
            }
            row += dr;
        }
        string ans = rows[0];
        for (int row = 1; row < numRows; row++)
        {
            ans += rows[row];
        }
        return ans;
    }
};

int main()
{
    Solution solution;

    int t, n, x, y;
    string s;
    cin >> s >> n;
    cout << solution.convert(s, n);
    return 0;
}