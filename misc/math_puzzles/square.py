import math
t = (int(raw_input()))
while t:
	l, b = [int(x) for x in raw_input().split()]
	prod = l*b
	maxi = 0
	#print res
	for i in range (1, l+1):
	#print "iam here"
		temp = i * i
		if prod % temp == 0:
			maxi = prod / temp	
	print "%d" %(maxi)
	t = t - 1
