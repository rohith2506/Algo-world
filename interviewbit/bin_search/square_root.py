class Solution:
	def sqrt(self, A):
		if A == 1: return 1
		low, high = 0, A
		threshold, mid, prev_mid = 0.001, (low + high) / 2, 0
		while abs(prev_mid - mid) > threshold:
			if mid * mid > A: high = mid
			else:  low = mid
			prev_mid = mid
			mid = (low + high) / 2
		return mid

A = int(raw_input())
print Solution().sqrt(A)
