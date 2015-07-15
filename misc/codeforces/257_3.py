import math

n = raw_input()
n = int(n)
arr = list(map(int, raw_input().split()))
dp = [1 for i in range(n)]
max_height = arr[0]

for i in range(1,n):
	if arr[i] > max_height:
		max_height = arr[i]
	dp[i] = min(dp[i-1] + 1, max_height)
print dp[n-1]
