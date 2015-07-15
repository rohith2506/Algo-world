import math
t = raw_input()
t = int(t)

def isperfect(p):
	x = math.sqrt(p)
	return (x*x == p)

def isfibo(n):
	return isperfect((5*n*n) - 4) or isperfect((5*n*n)+4)

while t:
	n = raw_input()
	n = int(n)
	if isfibo(n):
		print "IsFibo"
	else:
		print "IsNotFibo"
	t = t - 1