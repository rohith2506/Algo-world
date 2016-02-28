import pdb

class Solution:
	def bin_search(self, A, low, high, key):
		if high < low: return -1
		mid = (low + high) / 2
		if A[mid] == key: return mid
		elif A[mid] < key: return self.bin_search(A, mid+1, high, key)
		else: return self.bin_search(A, low, mid-1, key)

	def find_pivot(self, A, low, high):
		if high < low: return -1
		if high == low: return low
		mid = (low + high) / 2
		if mid < high and A[mid] > A[mid+1]: return mid
		if mid > low  and A[mid] < A[mid-1]: return mid - 1
		if A[low] >= A[mid]: return self.find_pivot(A, low, mid-1)
		else: return self.find_pivot(A, mid+1, high)
	
	def search(self, A, B):
		n = len(A)
		pivot = self.find_pivot(A, 0, n - 1)
		if pivot == -1:
			result = self.bin_search(A, 0, n - 1, B)
		else:
			result = self.bin_search(A, 0, pivot, B)
			if result == -1:
				result = self.bin_search(A, pivot+1, len(A)-1, B)
		return result

A = raw_input().split(",")
for i in range(len(A)): A[i] = int(A[i])
B = int(raw_input())
print Solution().search(A, B)
