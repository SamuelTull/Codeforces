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
    int minSizeSubarray(vector<int> &nums, int target)
    {
        int n = nums.size();
        long long S = 0;
        for (long long i : nums)
            S += i;

        long long cps = target / S; // copies of entire array
        long long rem = target % S; // remainder
        if (rem == 0LL)
            return cps * n;
        // try to find rem in smallest subarr of arr + arr:
        int best = 1e9;
        unordered_map<long long, int> seen;
        seen[0] = -1;
        int s = 0;
        for (int i = 0; i < 2 * n; i++)
        {
            s += nums[i % n];
            seen[s] = i;
            if (seen.find(s - rem) != seen.end())
                best = min(best, i - seen[s - rem]);
        }
        if (best == 1e9)
            return -1;
        long long ans = cps * n + best;
        return ans;
    }

    int lengthOfLongestSubstring(string s)
    {
        // Given a string s, find the length of the longest substring without repeating characters.
        int n = s.size();
        if (n == 0)
            return 0;
        map<char, int> seen;
        int l = 0, r = 1, best = 1;
        seen[s[0]]++;
        while (r < n)
        {
            seen[s[r]]++;
            while (seen[s[r]] > 1)
            {
                seen[s[l]]--;
                l++;
            }
            best = max(best, r - l + 1);
            r++;
        }
        return best;
    }

    const int INF = 1e9 + 7;
    array<int, 2> get_key(vector<int> &a, vector<int> &b)
    {
        int x1 = a[0], y1 = a[1], x2 = b[0], y2 = b[1];
        array<int, 2> key;

        if (x1 == x2)
            return key = {INF, 0};
        if (y1 == y2)
            return key = {0, INF};

        int m_num = y2 - y1, m_den = x2 - x1;
        if (m_den < 0)
        {
            m_num *= -1;
            m_den *= -1;
        }
        // reduce the fraction
        int g = __gcd(m_num, m_den);
        m_num /= g;
        m_den /= g;
        int c = y1 * m_den - m_num * x1;
        // y = mx + c
        // c = y - mx
        // c*m_den = y*m_den - m_num*x
        return key = {m_num, m_den};
    }

    int maxPoints(vector<vector<int>> &points)
    {

        int n = points.size();
        if (n <= 2)
            return n;
        int best = -1;
        map<array<int, 2>, int> m;
        for (int i = 0; i < n; i++)
        {
            m.clear();
            for (int j = i + 1; j < n; j++)
            {
                auto key = get_key(points[i], points[j]);
                m[key]++;
                best = max(best, m[key] + 1);
            }
        }
        return best;
    }
};

int main()
{
    Solution solution;
    int n, x, y, m;
    string word;
    cin >> n >> x;
    vector<int> nums1(n), nums2(n);
    for (int i = 0; i < n; i++)
        cin >> nums1[i];
    cout << solution.minSizeSubarray(nums1, x) << endl;
    return 0;
}