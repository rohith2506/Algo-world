class Solution:
	def removeDuplicates(self, A):
		index = 0
		for i in range(len(A) - 1):
			x, y = A[i], A[i+1]
			if x != y:
				A[index] = x
				index += 1
		A[index] = A[len(A) - 1]
		index += 1
		return index

A = raw_input().split(",")
for i in range(len(A)): A[i] = int(A[i])
print Solution().removeDuplicates(A)
