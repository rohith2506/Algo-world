class Solution:
	def solve(self, xs, low=0):
	    if low + 1 >= len(xs):
	        yield xs
	    else:
	        for p in self.solve(xs, low + 1):
	            yield p        
	        for i in range(low + 1, len(xs)):        
	            xs[low], xs[i] = xs[i], xs[low]
	            for p in self.solve(xs, low + 1):
	                yield p        
	            xs[low], xs[i] = xs[i], xs[low]

	def permute(self, A):
		res = []
		for x in self.solve(A):
			res.append([val for val in x])
		return res

A = raw_input().split()
print Solution().permute(A)
