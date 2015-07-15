import math

t = raw_input()
t = int(t)

while t:
	k,n = raw_input().split()
	n = int(n)
	k = int(k)
	res = ((pow(k,n+1) - 1) / (k-1))
	val = 0
	while res > 0:
		val = val + res%10
		res = res/10
	print val
	t = t - 1