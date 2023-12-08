03/12/23
Educational contest 159

First codeforces contest 

https://codeforces.com/contest/1902

Completed A, B and C

Solution for D worked on tests but time limit for python3 and pypy 

Could not optimise D in time

Solution works by using os.read and os.write instead of input() and print() so will start using these 


Takeaways:

os for read/write saves >1s

max x st num congruent (mod x) for all num in nums = gcd(num-num0 for num in nums), ie the gcd of the differences 

reduce() for applying same function to all elements in list 
eg sum(nums) = reduce(lambda x,y: x+y, nums )

optimisation in D also required only checking whether X is in S rather than checking each S are equal to X 

In E - quickly found the solution - keeping track of the prefixes and suffixes and subtracting any overlap however got TLE.

Used rolling hash to avoid the creation of substrings

hash = 0 
for s in S:
    hash = hash * BASE + s 

BASE match characters, for lowercase letters use 27 and s = ord(s) - ord(a) + 1 (otherwise "" = "a" = "aaa")

MOD used to stop getting too large. Picked as big prime to reduce chance of hash collisions. Common: 10^9 + 7  however this got wrong answer 10^18 + 3 worked. using multiple hashes getting lots of MLE TLE, think my go to should be 10^18. use a random base so unhackable. 
