# 05/12/23  
# Codeforces round 913 (div 3)  
Attempted in real time.    
Solved A-C in time and got TLE on D and G. Finished F just after deadline.  
Still not good at giving fair time to each question.  

## Lessons learnt  
### b
Much faster to save in list (or even better, list of indices) than to build new strings  
### c  
C = [0] * 26 and iterating over string is faster than Counter  
### d
Managed to calculate analytically by doing all the pairs of segments and finding min jump between. But this is O(n!).  
We know if k is possible then k2>k is always possible.  
Easier to think of and easier to implement binary search.  
### e  
Triplet only good if no "carrying over"  
Goal = 13, (2,7,4) is not good because digits were "carried over",  
But (11,1,1) is good.
So can treat each digit seperately.  
Obvious after but not sure how to think of this- perhaps try different triples.  
### f  
Had the logic, just overcomplicated the cases.   
Best solution I have seen counts the number of times it strongly inc/dec.  
If either of these is exactly 1, then this is the "cut" point, if more then cant be solved.  

