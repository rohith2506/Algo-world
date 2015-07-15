import math
MOD = 1000000007
MAX = 30
v = [0 for i in range(0,30)]


def power(a,b):
	if b == 0:
		return 1
	elif b == 1:
		return a
	else:
		if b%2 == 0:
			return power(((a%MOD) * (a%MOD))%MOD,b/2)
		else:
			return (a%MOD * power(((a%MOD) * (a%MOD))%MOD,(b-1)/2))%MOD


def precompute():
	v[0]=2
	for i in range(1,MAX):
		v[i] = power(v[i-1],10)
#	print v

t = raw_input()
t = int(t)
precompute()

while t:
	n = raw_input()
	n = long(n)
	n = long(bin(n)[2:])
	res = 1
	cnt = 0
	while n>0:
		b = n%10
		if b == 1:
			res = (res%MOD * v[cnt]%MOD)%MOD
		cnt = cnt + 1
		n = n/10
	
	res = ((res%MOD) * (res%MOD))%MOD
	print "%ld" %(res)
	t = t - 1
