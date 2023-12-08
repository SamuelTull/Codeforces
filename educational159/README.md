### 3/12/23
### Educational contest 159

First codeforces contest 

https://codeforces.com/contest/1902

Completed A, B and C

Solution for D worked on tests but time limit for python3 and pypy 

Could not optimise D in time

Solution works by using os.read and os.write instead of input() and print() so will start using these 


## Takeaways:

os for read/write saves >1s

max x st num congruent (mod x) for all num in nums = gcd(num-num0 for num in nums), ie the gcd of the differences 

reduce() for applying same function to all elements in list 
eg sum(nums) = reduce(lambda x,y: x+y, nums )

optimisation in D also required only checking whether X is in S rather than checking each S are equal to X 

In E - quickly found the solution - keeping track of the prefixes and suffixes and subtracting any overlap however got TLE.


### Hashing 
Used rolling hash to avoid the creation of substrings  

hash = 0   
for s in S:  
    hash = hash * BASE + s   

BASE match characters, for lowercase letters use 27 and s = ord(s) - ord(a) + 1 (otherwise "" = "a" = "aaa")  

MOD used to stop getting too large. Picked as big prime to reduce chance of hash collisions. Common: 10^9 + 7  however this got wrong answer 10^18 + 3 worked.  

Can do a pair of hashes with two different (BASE, MOD) pairs. HASH = HASH1 * MOD2 + HASH2  

The hashes take values [0, MOD). Birthday paradox says need around sqrt(MOD) values for 50/50 chance of collision.  
If we take 2 mods then hashes take values MOD1*MOD2 different values.  
Max 10^6 prefixes So need > 10^12 for expected collisions <1.  Apparently 10^18 gives smaller than 10^-6 chance of collision.   
Found better to use two 10^9 than one big 10^18 mod for both time and memory.  


