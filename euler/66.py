'''
Chakravaka method for solving diophantine equations.
for Reference see wikipedia and project euler 66 thread
@Author: Rohit
'''
import math

def firstTriplet(N,b):
	kvalues = []
	for a in range(1, int(math.sqrt(N)+1)):
		kval = abs(a**2 - N*b**2)
		kvalues.append(kval)
	kmin = min(kvalues)
	return (a,b,kmin)


def hypsolver(a,N,b):
	if a == 1:
		triplet = firstTriplet(N,b)
		(a,b,k) = triplet
	for m in range(1,N):
		k = a**2 - N*b**2
		t1 = a*m + N*b
		t2 = a + b*m
		t3 = m**2 - N
		if t1%k == 0 and t2%k == 0:
			return (t1/k,t2/k,t3/k)


def solve(i):
	a,b = 1,1
	while True:
		(p1,p2,p3) = hypsolver(a,i,b)
		a,b = p1,p2
		if p3 == 1:
			print abs(p1),abs(p2),abs(p3)
			break


if __name__ == "__main__":
	n = raw_input()
	n = int(n)
	solve(n)
