class Solution:
	def intersect(self, A, B):
		result = []
		i, j = 0, 0
		while i < len(A) and j < len(B):
			if A[i] == B[j]: 
				result.append(A[i])
				i = i + 1
				j = j + 1
			elif A[i] > B[j]:
				j = j + 1
			else:
				i = i + 1
		return result

A = raw_input().split()
for i in range(len(A)): A[i] = int(A[i])
B = raw_input().split()
for i in range(len(B)): B[i] = int(B[i])
print Solution().intersect(A, B)
