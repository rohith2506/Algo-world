'''
Given N, find number of ways that no 2 chords will intersect.
It's as easy as finding catalan numbers.
'''

class Solution:
    def chordCnt(self, A):
        MOD = 1000000007
        dp = [0 for i in range(A+1)]
        dp[0], dp[1] = 1, 1
        for i in range(2, A+1):
            for j in range(0, i):
                dp[i] = (dp[i] % MOD + (dp[j] % MOD* dp[i - 1 - j] % MOD) % MOD) % MOD
        return dp[A]

n = int(raw_input())
print Solution().chordCnt(n)    
