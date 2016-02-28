class Solution:
    def maxcoin(self, A):
        dp = [[0 for j in range(len(A)+1)] for i in range(len(A)+1)]
        for i in range(0, len(A)):
            m, n = 0, i
            while n < len(A):
                a,b,c = 0, 0, 0
                if m+2 <= len(A) - 1: a = dp[m+2][n]
                if m+1 <= len(A) - 1 and n - 1 >= 0: b = dp[m+1][n-1]
                if m <= len(A) - 1 and n - 2 >= 0: c = dp[m][n-2]
                dp[m][n] = max((A[m] + min(a,b)), (A[n] + min(b,c)))
                n = n + 1
                m = m + 1
        return dp[0][n-1]
            
A = map(int, raw_input().split())
print Solution().maxcoin(A)