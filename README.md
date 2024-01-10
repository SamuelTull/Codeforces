# Codeforces
Attempting contests and past problems to get better at coding. Initially in Python, C++, plan to incorporate C#.  
Times using int instead of long long gave wrong answer 4. 
## C++ Tips 

## Order of Operations
```a==b==c``` is NOT as expected. Is checking ```(a==b)==c```. Use ```a == b && b == c```.  

## Priority Queue  
For shortest path, use ```priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> Q;```.  The arguments are Type, ContainerType and the Compare, Less is used by default, but greater ensures the smallest is on the top of the heap. Use std::vector(n,llinf) rather than map if we know all the states, huge speed up due to faster access time O(1) vs O(log n).  

### Modulus % 
The modulus operator % does not work as expected with negative numbers. It does not return the remainder of the division, but the signed remainder, which can be negative. To ensure that the result is always positive, add N before taking the modulus.  

### Initialising  
When you declare an instance of a class (e.g. ```set s;```), the class's default constructor is called. However when initialise a variable without initialising (e.g. ```int ans;```), it contains a "garbage value". This value could be anything and is generally not predictable. So we need ```int ans = 0;``` but do not require the same for classes. 

### Integer overflow
int ~ (-10^9 to +10^9).  
long long ~ (-10^18 to +10^18).  
Estimate the largest possible value, eg if counting sum of 10^5 values in range [0,10^8] the sum could be up to 10^13, requiring long long.  

## Lessons Learnt 
### Round 918 (1915F)-  Ordered_set 
Count number of intervals entirely within another interval: that is to count the number of pairs of intervals [a1,b1], [a2,b2] such that a1 < a2 < b2 < b1. 
```
Initialise list A = [], int ans = 0   
Iterate through [a,b] := interval in order of increasing b, count inversions:  
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


