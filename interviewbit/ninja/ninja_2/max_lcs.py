class Solution:
	def maxLCS(self, A):
		print len(A)
		end = len(A) - 1
		max_match, max_index, cur_match = 0, -1, 0
		for i in range(0, len(A) - 1):
			if i > end: continue
			if A[i] == A[end]:
				print i, end
				cur_match = cur_match + 1
				end = end - 1
				if end > (len(A) - (i+1)): continue
			if cur_match > max_match:
				max_match = cur_match
				max_index = i + 1
		return [max_index, max_match]