# 15/12/2023
Virtual contest for practice 

### lessons learnt  
B: I tried optimising by breaking a into 2**n * m to simply check if x is bigger than n.  
This doesnt change the complexity though!  
The optimisation was to use the fact that after we process x any x2 >= x  is pointless.  
Since x < 30, this gives complexity O(30n).  
lesson: look for optimisation that reduces complexity, not just minor speedup.  