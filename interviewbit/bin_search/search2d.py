'''
Start at top-right
1) top - bottom by checking with the last element of each row in the array
2) Then go right - left until you find the element

elegant solution
'''

class Solution:
	def searchMatrix(self, A, B):
		m, n = len(A), len(A[0])
		i, j = 0, n - 1
		while i < m and j >= 0:
			if A[i][j] == B: return 1
			if A[i][j] > B: j = j - 1
			else: i = i + 1
		return 0
