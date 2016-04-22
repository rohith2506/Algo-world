class Solution:
	def diffPossible(self, A, B):
		i,j = 0,1
		while i < len(A) and j < len(A):
			if i != j and A[j] - A[i] == B: return 1
			elif A[j] - A[i] < B: j = j + 1
			else: i = i + 1
		return 0

A = raw_input().split()
for i in range(len(A)): A[i] = int(A[i])
B = int(raw_input())
print Solution().diffPossible(A, B)
