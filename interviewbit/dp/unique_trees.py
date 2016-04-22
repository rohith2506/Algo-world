class Solution:
    def numTrees(self, A):
        dp = [0 for i in range(A+1)]
        dp[0] = 1
        dp[1] = 1
        for level in range(2, A+1):
            for root in range(1, level+1):
                dp[level] += dp[level - root] * dp[root - 1]
        return dp[A]

A = int(raw_input())
print Solution().numTrees(A)
