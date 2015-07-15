import math
from fractions import gcd

n = raw_input()
n = int(n)
while n:
	a,b = raw_input().split()
	a,b = int(a), int(b)

	if gcd(a,b) == 1:
		if a <= 1 and b <= 1:
			print "Draw"
		elif a >= b:
			print "Arjit"
		else:
			print "Chandu Don"
	else:
		lcm_val = (a*b) / gcd(a,b)
		a = a / lcm_val
		b = b / lcm_val
		if a >= b:
			print "Arjit"
		else:
			print "Chandu Don"
	n = n - 1
