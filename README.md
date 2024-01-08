# Codeforces
Attempting contests and past problems to get better at coding. Initially in Python, plan to incorporate C++ and C#

## Lessons Learnt 

### Round 918 (1915F)  
Count number of intervals entirely within another interval: #[a1,b1], [a2,b2] s.t. a1<a2 < b2 < a1.  
Iterate through pairs in order of increasing b:
        1. find number of as already in list that are bigger than current a.    
        2. add a to list.   
Could not find O(nlogn) solution:  
        Python  
            idx = bisect.bisect_left(seen, a)  
            seen.insert(idx, a)  
            ans += len(seen) - idx.  
        although bisect is O(logn), insert is O(n).  
        C++  
        set<int> seen;  
        ans += distance(seen.upper_bound(a), seen.end());  
        seen.insert(a);  
        Although set is sorted, with O(1) insert, and O(logn) upper_bound, distance iterates from x to y, so is O(n).  
Both cases have O(n^2) solutions.  
Eventually found:  
#include <ext/pb_ds/assoc_container.hpp>  
#include <ext/pb_ds/tree_policy.hpp>  
using namespace std;  
typedef __gnu_pbds::tree<  
    int,  
    __gnu_pbds::null_type,  
    less<int>, //greater<int>,  
    __gnu_pbds::rb_tree_tag,  
    __gnu_pbds::tree_order_statistics_node_update>  
    ordered_set;  
// s.order_of_key(a);  
// s.find_by_order(n);  
which is O(1) insert and O(logn) order_of_key, hence giving desired O(nlogn) solution.  

### C++
Care for integer overflow, even if all numbers are well within limits, sums of subsets can overflow so use long long.  
Weird bug where nothing is cout when a vector is initialised.  

### Round 918
Storing prefixes, TLE error when ^random_seed removed. Sets are implemented as hash tables. If two elements have the same hash value, Python needs to check if they are actually the same element, which takes extra time. ^random_seed effectively randomizing the hash values of the prefix sums. This makes it less likely that two different prefix sums will have the same hash value, which can speed up the operation of adding an element to the set and checking if an element is in the set.

### Round 916 (F)
Recursion dfs approach was giving stack-overload error. An iterative approach where we only explore a node after all its children have been explored gives the same time and memory complexity but no recursion.  

### Round 915 (B) 
I wrongly assumed the nodes of a tree were given as [parent, child], so I was finding leaves by those that were never "parents". Wrong approach, they were given in either order so need to count occurrences, leaves are those with count == 1.  

### Round 913 (B,C,D)
Creating new strings is extremely slow in python, better to use lists when possible.  
C = [0] * 26 and iterating over string is faster than Counter.  
If x is true -> x1 > x is also true then use binary search.  

### Educational 159 
os for read/write saves >1s.  
Rolling hash for prefixes.  


