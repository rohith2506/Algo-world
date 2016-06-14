'''
a*x + b*y + c*z = n
@Author: Rohith Uppala
'''

def solve(n):
	a, b, c = 1234567, 123456, 1234
	max_a, max_b = n / a, n / b
	for i in range(0, max_a+1):
		for j in range(0, max_b + 1):
			temp_sum = (a * i) + (b * j)
			remaining_sum = n - temp_sum
			if remaining_sum < 0: continue
			if remaining_sum % c == 0: return True
	return False

if __name__ == "__main__":
	n = int(raw_input())
	if solve(n): print "YES"
	else: print "NO"
