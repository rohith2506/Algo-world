'''
This is very interesting solution:
Finding Longest Palindromic Substring: 0(n^2) time complexity and 0(n^2) space complexity
But this is the solution with 0(1) space

How??
We fix a center in the string and try to generate all types of palindromes around that center
There are two types of palindromes:
	odd palindromes, even palindromes.
So, iterate through them and find which one is greater.
'''

class Solution:
	def longestPalindrome(self, A):
		n, low, high = len(A), 0, 0
		start, max_len = 0, 1
		for i in range(1, len(A)):
			low, high = i - 1, i
			# Even Palindromes
			while low >= 0 and high < n and A[low] == A[high]:
				if high - low + 1 > max_len:
					start, max_len = low, high - low + 1
				low -= 1
				high += 1
			# Odd Palindromes
			low, high = i - 1, i + 1
			while low >= 0 and high < n and A[low] == A[high]:
				if high - low + 1 > max_len:
					start, max_len = low, high - low + 1
				low -= 1
				high += 1
		return A[start:start+max_len]

A = raw_input()
print Solution().longestPalindrome(A)
