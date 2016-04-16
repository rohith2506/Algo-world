class Solution:
	def maxPoints(self, A, B):
		max_cnt = 0
		INF = 10001
		if len(A) <= 2: return len(A)
		for i in range(len(A)):
			x1, y1, dup = A[i], B[i], 1
			slope_dict = {}
			for j in range(i+1, len(A)):
				x2, y2 = A[j], B[j]
				if y2 == y1 and x2 == x1:
					dup = dup + 1
					continue
				try:
					slope = (y2 - y1) * 1.0 / (x2 - x1)
				except:
					slope = INF
				if slope not in slope_dict: slope_dict[slope] = 1
				else: slope_dict[slope] += 1
			max_cnt = max(dup, max_cnt)
			for k,v in slope_dict.items():
				max_cnt = max(max_cnt, v+dup)
		return max_cnt    

A = map(int, raw_input().split())
B = map(int, raw_input().split())
print Solution().maxPoints(A, B)
