class Solution:
	def longestPalindrome(self, A):
		n = len(A)
		start, max_len = 0, 1
		dp = [[False for i in range(n)] for i in range(n)]
		for i in range(len(dp)):
			dp[i][i] = True
		for i in range(len(dp) - 1):
			if A[i] == A[i+1]:
				dp[i][i+1] = True
				start = i
				max_len = 2
		for k in range(3, n+1):
			for i in range(0, n-k+1):
				j = i+k-1
				if A[i] == A[j] and dp[i+1][j-1] == True:
					dp[i][j] = True
					if k > max_len:
						start, max_len = i, k
		return A[start:start+max_len]

A = raw_input()
print Solution().longestPalindrome(A)
