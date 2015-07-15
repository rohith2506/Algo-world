import math
MOD = int(1000000007)
t = raw_input()
t = int(t)

def factorial(n):
	res = 1
	for i in range(1,n):
		res = ((res%MOD) * (i%MOD))%MOD
	print res
	return res

def C(n,k):
	return (factorial(n) / (factorial(n-k) * factorial(k)))

while t:
	n,k = raw_input().split()
	values = raw_input().split()

	n = int(n)
	k = int(k)

	for i in range(0,len(values)):
		values[i] = int(values[i])
	values.sort()

	res = C(n,k)
	members = (res%MOD * k%MOD)%MOD
	repeat  = members / n

	cnt = res
	ans = 0
	for i in range(0,len(values)):
		if cnt <= 0:
			break
		ans = ans + ((cnt % MOD) * (values[i]%MOD))%MOD
		cnt = cnt - repeat

	print ans
	t = t - 1
