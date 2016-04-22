class Solution:
	def generate(self, A):
		result = []
		if A == 0: return result
		temp_lst = [1]
		result.append(temp_lst)
		for i in range(1, A):
			new_lst = []
			new_lst.append(1)
			for i in range(0, len(temp_lst) - 1):
				new_lst.append(temp_lst[i] + temp_lst[i+1])
			new_lst.append(1)
			result.append(new_lst)
			temp_lst = new_lst
		return result

if __name__ == "__main__":
	n = int(raw_input())
	print Solution().generate(n)