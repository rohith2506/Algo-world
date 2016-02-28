class Solution:
	def fast_exp(self, x, n, d):
		if n == 0:
			return 1
		elif n == 1:
			return x % d
		else:
			result = 1
			while n > 0:
				if n % 2 == 1:
					result = ((result % d) * (x % d)) % d
				x = (x%d * x%d) % d
				n = n/2
			return result

	def pow(self, x, n, d):
		if x == 0: return 0
		result = self.fast_exp(x, n, d)
		return result

x,n,d = raw_input().split()
x,n,d = int(x), int(n), int(d)
print Solution().pow(x,n,d)
