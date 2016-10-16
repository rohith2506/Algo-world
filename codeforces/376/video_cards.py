n = int(raw_input())
arr = map(int, raw_input().split())
arr.sort()
ans = 0
dp = [0 for i in range(max(arr) + 1)]
for i in range(max(arr)+1): dp[i] = dp[i] + 1
for i in range(1, max(arr) + 1):
    if dp[i] != dp[i-1]:
        temp = 0
        for j in range(i, max(arr) + 1, i):
            temp = temp + (j * (dp[min(max(arr), j+i-1)] - dp[j-1]))
        ans = max(temp, ans)
print ans
