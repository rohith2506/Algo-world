import math
MOD = long(10e9+7)

n, k = raw_input().split()
n, k = int(n), int(k)
elements = raw_input().split()
for i in range(0, len(elements)): elements[i] = int(elements[i])

for i in range(0, n-k+1):
	result = 0
	for j in range(0, k):
		result = (result%MOD + ((j+1)%MOD*(j+1)%MOD*elements[i+j]%MOD)%MOD)%MOD
	print result,