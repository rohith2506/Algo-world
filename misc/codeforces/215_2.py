import math

n,m = raw_input().split()
n = int(n)
m = int(m)

lst = []
lst = raw_input().split()

Dict = {}
for i in range(0,len(lst)):
	Dict[lst[i]]=0

res = [0 for i in range(0,n)]
j = 1
res[0] = 1
Dict[lst[n-1]] = 1

for i in range(n-2,-1,-1):
	res[j] = res[j-1]
	if Dict[lst[i]] == 0:
		res[j] = res[j] + 1
		Dict[lst[i]] = 1
	j = j + 1
res = res[::-1]
for i in range(0,m):
	x = raw_input()
	x = int(x)
	x = x -1
	print res[x]
