import math
n = int(raw_input())
a = [-1] + list(map(int, raw_input().split())) + [10e9 + 7]

up = [0 for i in range(0,n+2)]
down = [0 for i in range(0,n+2)]

for i in range(1,n+1):
	up[i] = up[i-1] + 1 if a[i] > a[i-1] else 1

for i in range(n,0,-1):
	down[i] = down[i+1] + 1 if a[i] < a[i+1] else 1

maxi = 0
for i in range(1, n+1):
	maxi = max(maxi, up[i-1] + ((a[i-1] + 1 < a[i+1])*down[i+1]) + 1)
	maxi = max(maxi, (up[i-1]*(a[i+1] - 1 > a[i-1])) + down[i+1] + 1)

print maxi