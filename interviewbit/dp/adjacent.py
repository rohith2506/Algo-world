class Solution:
    def solve(self, dp, arr, c):
        if c < 0: return 0
        if dp[c] != -1: return dp[c]   
        return dp[c] = max((max(arr[0][c], arr[1][c]) + solve(dp, arr, c - 2)), solve(dp, arr, c-1))       

    def adjacent(self, A):
        m, n = len(A), len(A[0])
        dp = [-1 for j in range(n)]
        return solve(dp, A, n - 1)
