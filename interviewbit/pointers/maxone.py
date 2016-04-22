'''
Find maximum continuous series of 1's with at max m flips of 0's
'''

class Solution:
	def maxone(self, A, B):
		n, left, right, zero_count = len(A), 0, 0, 0
		bl, br = 0, 0
		if A[right] == 0: zero_count += 1
		while right < n:
			if zero_count <= B:
				right = right + 1
				if right < n and A[right] == 0:
					zero_count += 1
			if zero_count > B:
				if A[left] == 0:
					zero_count -= 1
				left = left + 1
			if right >= n:
				if n - 1 - left > br - bl:
					bl, br = left, n - 1
			elif right - left > br - bl:
				bl, br = left, right
		if br > n - 1: br = n - 1
		result = []
		for i in range(bl, br+1): result.append(i)
		return result

A = raw_input().split(',')
for i in range(len(A)): A[i] = int(A[i])
B = int(raw_input())
print Solution().maxone(A, B)
