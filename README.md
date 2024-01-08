# Codeforces
Attempting contests and past problems to get better at coding. Initially in Python, C++, plan to incorporate C#

## Lessons Learnt 

### Round 918 (1915F)  
Count number of intervals entirely within another interval: that is to count the number of pairs of intervals [a1,b1], [a2,b2] such that a1 < a2 < b2 < b1. 
```
Initialise list A = [], int ans = 0   
Iterate through [a,b] := interval in order of increasing b:  
(1) ans += num(i in A st A[i]>a)  
(2) add a to A   
``` 
The initial sort is O(nlogn). Keep A ordered to allow (1) in log(n) using binary search.  However I could not find O(nlogn) solution:  
Python: 
```
idx = bisect.bisect_left(seen, a)  
seen.insert(idx, a)  
ans += len(seen) - idx.
```
although bisect is O(logn), insert is O(n).  
C++: 
```
set<int> seen;  
seen.insert(a);
ans += distance(seen.upper_bound(a), seen.end());  
```
Although set is sorted, with O(1) insert, and O(logn) upper_bound, distance iterates from x to y, so is O(n).  
Both cases have O(n^2) solutions.  

Eventually I found ordered_set, which is O(1) insert and O(logn) order_of_key, hence giving desired O(nlogn) solution.
```
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
// s.order_of_key(a);  // returns index of a (not necessarily in list).  
// s.find_by_order(n);  // returns s[n] (value at position n, according to ordering).  
// s.insert(a); // add a to set s.   
```
  

### C++
Care for integer overflow:    
int ~ (10^9 to +10^9).  
long long ~ (—10^18 to +10^18).  
Estimate largest possible value, eg if counting sum of 10^5 values in range [0,10^8] the sum could be up to 10^13, requiring long long.  


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


