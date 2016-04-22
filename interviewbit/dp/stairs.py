class Solution:
    def climbStairs(self, A):
        if A <= 1: return A
        dp = [1 for i in range(A)]
        dp[0] = 1
        if A == 1: return 1
        dp[1] = 2
        for i in range(2, A):
            dp[i] = dp[i-1] + dp[i-2]
        return dp[A-1]

A = int(raw_input())
print Solution().climbStairs(A)
