03/12/23
Educational contest 159
https://codeforces.com/contest/1902
(my first codeforces contest) 

Completed A, B and C during contest 
Solution for D worked on tests but time limit for python3 and pypy and could not optimise in time
Solution works by using os.read and os.write instead of input() and print() so will start using these 


Takeaways:
os for read/write saves >1s
max x st num congruent (mod x) for all num in nums = gcd(num-num0 for num in nums), ie the gcd of the differences 
reduce() for applying same function to all elements in list 
eg sum(nums) = reduce(lambda x,y: x+y, nums )
