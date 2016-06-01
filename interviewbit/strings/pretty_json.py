'''
not complete code
'''

class Solution:
	def print_until_comma(self, A, index):
		result = ""
		for i in range(index, len(A)):
			if A[i] != ',': result = result + A[i]
		return result
	
	def print_bracket(self, num_tabs):
		result = ""
		for i in range(num_tabs): result = result + "\t"
		return result

	def prettyJSON(self, A):
		num_tabs = 0
		i, res = 0, []
		while i < len(A):
			if A[i] == '{' or A[i] == '[': 
				num_tabs = num_tabs + 1
				x = print_until_comma(A, i+1)
				res.append(x)
				y = print_bracket(num_tabs)
				res.append(y)
			if A[i] == '}' or A[i] == ']':
				num_tabs = num_tabs - 1
				x = print_until_comma(A, i+1)
				res.append(x)
				y = print_bracket(num_tabs)
				res.append(y)
			i = i + 1		
		return res	

if __name__ == "__main__":
	A = raw_input()
	result = Solution().prettyJSON(A)
	for res in result:
		print res
