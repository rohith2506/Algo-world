'''
Given m, n find the pairs of numbers which are divisible by 5 for each 1 <= i <= n and 1 <= j <= m

Iterate through each i in n
	Find the start point of pair in m - sequence: 5 - (i%5)
	Then, count the number of pairs: (m - start) / 5

@Author: Rohith Uppala
'''

def solve(n, m):
	cnt = 0
	for i in xrange(1, n+1):
		start = 5 - (i%5)
		cnt = cnt + 1
		cnt = cnt + (m - start) / 5
	return cnt

if __name__ == "__main__":
	n, m = map(int, raw_input().split())
	print solve(n, m)
