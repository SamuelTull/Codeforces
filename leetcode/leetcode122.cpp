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
    long long minimumCost(vector<int> &nums, int k, int dist)
    {
        // https://leetcode.com/contest/biweekly-contest-122/problems/divide-an-array-into-subarrays-with-minimum-cost-ii/
        // 2 multisets, one for first k, one for rest
        multiset<int> a, b;
        int n = nums.size();
        long long ans = nums[0];
        k--;
        int i = 1;
        while (i < k + 1)
        {
            a.insert(nums[i]);
            ans += nums[i];
            i++;
        }
        while (i < dist + 2)
        {
            a.insert(nums[i]);
            ans += nums[i];
            int last = *a.rbegin();
            ans -= last;
            b.insert(last);
            a.erase(last);
            i++;
        }
        long long best = ans;
        while (i < n)
        {
            // remove
            if (b.find(nums[i - dist - 1]) != b.end())
                b.erase(nums[i - dist - 1]);
            else
            {
                ans -= nums[i - dist - 1];
                // a.erase(nums[i - dist - 1]);
            }

            // add
            if (*a.rbegin() > nums[i])
            {
                ans += nums[i];
                a.insert(nums[i]);
            }
            else
            {
                b.insert(nums[i]);
            }
            cout << "before\n";
            dbg(a);
            dbg(b);
            if (a.size() > k)
            {
                int last = *a.rbegin();
                ans -= last;
                b.insert(last);
                a.erase(last);
                dbg(a);
                dbg(b);
            }
            else if (a.size() < k)
            {
                int first = *b.begin();
                ans += first;
                a.insert(first);
                b.erase(first);
                dbg(a);
                dbg(b);
            }
            best = min(best, ans);
            i++;
        }
        return best;
    }

    long long minimumCost1(vector<int> &nums, int k, int dist)
    {
        // https://leetcode.com/contest/biweekly-contest-122/problems/divide-an-array-into-subarrays-with-minimum-cost-ii/
        // have to have nums[0]
        // now need to pick the smallest k-1 numbers, from nums[1] to nums[k-1]
        // but first and last picked must be within dist of eachother

        // iterate over the start of the window
        // keep an ordered set of k-1 numbers
        // when we move the window, see if dist-1 is in the set,
        // if so, remove it. add the new kth element to the count
        int n = nums.size(), idx;
        long long ans = nums[0];
        k--;
        ordered_set window;
        int i = 1;
        while (i < dist + 2)
        {
            window.insert({nums[i], i});
            i++;
        }
        // get sum of first k elements
        auto it = window.begin();
        for (int j = 0; j < k; j++)
        {
            ans += (*it)[0];
            it++;
        }

        // now we have k elements in the window
        long long best = ans;
        while (i < n)
        {
            // remove
            array<int, 2> toRemove = {nums[i - dist - 1], i - dist - 1}, toAdd = {nums[i], i};
            idx = window.order_of_key(toRemove);
            window.erase(toRemove);
            if (idx < k)
                ans -= toRemove[0];
            else
                ans -= (*window.find_by_order(k - 1))[0];

            window.insert(toAdd);
            idx = window.order_of_key(toAdd);
            if (idx < k)
                ans += toAdd[0];
            else
                ans += (*window.find_by_order(k - 1))[0];
            best = min(best, ans);
            i++;
        }
        return best;
    }
    int minimumArrayLength(vector<int> &nums)
    {
        // https://leetcode.com/contest/biweekly-contest-122/problems/minimize-length-of-array-using-operations/
        // Q: remove i,j != 0 add i%j, smallest length of array
        // i<j then i%j = i. So keep picking i as the smallest - removes any bigger.
        // once left with all i's 2 is will become a 0.
        // upper bound of solution is ceil(count(x)/2) where x is the smallest number in nums
        // can we beat this by making a different smaller number?
        // yes, do everything %x (if a numbr isnt multiple of x then wll become new smallest)

        int n = nums.size();
        int min = *min_element(nums.begin(), nums.end());
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % min != 0)
            {
                return 1;
            }
            if (nums[i] == min)
            {
                count++;
            }
        }
        return (count + 1) / 2;
    }
};

int main()
{
    Solution solution;
    int n, k, dist;
    cin >> n >> k >> dist;
    vector<int> nums(n);
    for (auto &num : nums)
        cin >> num;
    // cout << solution.minimumArrayLength(nums) << endl;
    cout << solution.minimumCost(nums, k, dist) << endl;
    return 0;
}