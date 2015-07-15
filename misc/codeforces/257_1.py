import math
a1,a2,a3 = raw_input().split()
b1,b2,b3 = raw_input().split()
a1,a2,a3 = int(a1), int(a2), int(a3)
b1,b2,b3 = int(b1), int(b2), int(b3)
n = raw_input()
n = int(n)
a = a1 + a2 + a3
b = b1 + b2 + b3

while n > 0:
	if a > 0:
		a = a - 5
	elif b > 0:
		b = b - 10
	else:
		pass
	n = n - 1

if a<=0 and b<=0: print "YES"
else: print "NO"
