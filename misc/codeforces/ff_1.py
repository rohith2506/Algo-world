import math
p,n = raw_input().split()
p = int(p)
n = int(n)
lst = []
inp = []
while n:
	x = raw_input()
	x = int(x)
	inp.append(x)
	n = n - 1
res = -1
for i in range(0, len(inp)):
	if inp[i]%p not in lst:
		lst.append(inp[i]%p)
	else:
		res = i+1
		break
print res