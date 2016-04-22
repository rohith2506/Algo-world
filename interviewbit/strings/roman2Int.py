class Solution:
	def romanToInt(self, A):
		roman_dict = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
		numeric_value = roman_dict[A[0]]
		for i in range(1, len(A)):
			cur, prev = A[i], A[i-1]
			if roman_dict[cur] > roman_dict[prev]:
				numeric_value = numeric_value - roman_dict[prev]
				temp_value = roman_dict[cur] - roman_dict[prev]
				numeric_value = numeric_value + temp_value
			else:
				numeric_value = numeric_value + roman_dict[cur]
		return numeric_value


s = raw_input()
print Solution().romanToInt(s)
