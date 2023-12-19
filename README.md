# Codeforces
Attempting contests and past problems to get better at coding. Initially in Python, plan to incorporate C++ and C#

# Lessons Learnt 

### Round 916 (F)
dfs function and recursion - was giving stack-overload error, iterative approach where we only explore node after all children have been explored - same time complexity but no recursion.  

### Round 915 (B) 
Wrongly assumed the nodes of a tree were given as [parent, child], so was finding leaves from those that were never parents. Wrong approach - they were given in either order. Instead add count to A and B and find those with count == 1.  

### Round 913 (B,C,D)
Creating new strings is extremely slow in python, better to use lists when possible.  
C = [0] * 26 and iterating over string is faster than Counter.  
If x is true -> x1 > x is also true then use binary search.  

### Educational 159 
os for read/write saves >1s.  
Rolling hash for prefixes.  
