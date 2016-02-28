class Solution:
    def minpathSum(self, A):
        m, n = len(A), len(A[0])
        dp = [[0 for j in range(n)] for i in range(m)]
        dp[0][0] = A[0][0]
        for j in range(0, n):
            dp[0][j] = dp[0][j-1] + A[0][j]
        for i in range(0, m):
            dp[i][0] = dp[i-1][0] + A[i][0]
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + A[i][j]
        return dp[m-1][n-1]

A = [[1,3,2],[4,3,1],[5,6,1]]
print Solution().minpathSum(A)
