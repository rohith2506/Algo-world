'''
It is possible to show that if p is prime, choose(m, n) is not divisible by p if and only if the addition n + (m-n) when written in base p has no carries.  This means that the number of entries in the mth row of Pascal's triangle that are not divisible by p is equal to the product over all digits d of m written in base p of 1+d.

For example...

10 base 2 is 1001, which means that the number of odd entries in the 10th row of PT is 2*1*1*2=4.

10 base 5 is 20 --> number of entries in 10th row not divisible by 5 is 3*1=3.

This can be extended as follows.  The number of entries in rows 0 through p^n-1 that are not divisible by p is ((p(p+1))/2)^n. 

This leads to a recursive formulation...

Let n have k digits when written in base p, and let d be the most significant digit.  Let f(n) denote the number of entries in rows 0-n of PT not divisible by p.  Then...

f(n) = (d(d+1)/2)(p(p+1)/2)^(k-1) + (d+1)f(n/p)

Using p=7, and n=999999999 gives us our answer.  (Note that the first billion rows of PT are rows 0-999999999.)

http://projecteuler.net/thread=148
Above is the recurrence relation
But there is another approach to solve It: Serpinski triangle
'''
from time import time; t=time()
M = 10**9
def int2(n, base):
    ret = []
    while n != 0:
        n, k = n//base, n%base
        ret.insert(0, k)
    return ret
def f(l, base):
    if not l: return 0
    r = l[0]
    s = base*(base+1)/2
    return r*(r+1)/2*s**(len(l)-1)+(r+1)*f(l[1:], base)
print(f(int2(M, 7), 7))