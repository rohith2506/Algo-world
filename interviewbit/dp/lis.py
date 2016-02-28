class Solution:
    def lis(self, A):
        dp = [1 for i in range(len(A))]
        for i in range(1, len(A)):
            for j in range(0, i):
                if A[i] > A[j]:
	                   dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)

A = map(int, raw_input().split())
print Solution().lis(A)
