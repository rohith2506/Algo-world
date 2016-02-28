class Solution:
	def compareVersion(self, A, B):
		v1_list = A.split('.')
		v2_list = B.split('.')
		v1, v2 = [], []
		for i in range(len(v1_list)):
			if int(v1_list[i]) > 0:
				v1.append(int(v1_list[i]))
		for i in range(len(v2_list)):
			if int(v2_list[i]) > 0:
				v2.append(int(v2_list[i]))
		for i in range(0, min(len(v1), len(v2))):
			x, y = v1[i], v2[i]
			if x > y: return 1
			elif x < y: return -1
			else: continue
		if len(v1) > len(v2): return 1
		elif len(v1) == len(v2): return 0
		else: return -1
	
A = raw_input()
B = raw_input()
print Solution().compareVersion(A, B)
