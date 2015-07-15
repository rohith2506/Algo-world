import math

def is_prime(n):
	j = n-1
	while j>0:
		if n%j==0:
			return False
		j = j-1
	if n<0:
	   return False
	else:
	   return True

def calc():
	glob_max = 0
	for i in range(-1000,1001):
		for j in range(i,1001):
			n=0
			NotPrime = True
			print i,j
			while NotPrime:
				 m = n*n + i*n + j
				 if not is_prime(m):
					NotPrime = False
				 n = n+1	
			if  n > glob_max:
				glob_max = n
				print i,j,glob_max
				prod = i*j
	return prod

if __name__ == "__main__":
	print calc()
