'''
Division without division operator
@Author: Rohit
'''

def DivisionWithoutDivision(n1, n2):
	quotient, remainder = 0, 0
	temp = n1
	while temp >= n2:
		temp = temp - n2
		quotient = quotient + 1	
	remainder = n1 - (quotient * n2)
	return (quotient, remainder)

if __name__ == "__main__":
	n1, n2 = raw_input().split()
	n1, n2 = int(n1), int(n2)
	(q, r) = DivisionWithoutDivision(n1, n2)
	print q,r
