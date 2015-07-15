import math

str = raw_input()
n = raw_input()
n = int(n)
wc = raw_input().split()
for i in range(0, len(wc)):
	wc[i] = int(wc[i])

val = []
for i in range(0, len(str)):
	index = ord(str[i]) - 97
	val.append(wc[index])

wc.sort()
maxi = wc[len(wc)-1]
for i in range(0,n):
	val.append(maxi)

res = 0
for i in range(0, len(val)):
	res = res + (val[i] * (i+1))
print res 