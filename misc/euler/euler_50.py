import math
primes = []
Prime = []
Sum = []
max = 1000000


def pre_process():
	for i in range(0,max):
		primes.append(False)
	
	primes[0]=True
	primes[1]=True
	
	for i in range(2,max):
		if primes[i] == False:
			k = 2*i
			while k<max:
				primes[k] = True
				k = k+i
	
	for j in range(0,len(primes)):
		if primes[j] == False:
			Prime.append(j)
	
def prefix_sum():
	print len(Prime)
	Sum.append(Prime[0])
	for i in range(1,len(Prime)):
		Sum.append(Prime[i] + Sum[i-1])	
			
	print len(Sum)


def calc():
	glob_diff = 0
	for i in range(0,len(Prime)):
		for j in range(i+1,len(Prime)):
			temp_sum = Sum[j]-Sum[i]
			if temp_sum < max:
				if primes[temp_sum] == False:
					diff = j-i
					if diff > glob_diff:
						glob_diff = diff
						glob_prime = temp_sum
						print glob_diff,glob_prime			
					
	return glob_prime
	
if __name__ == "__main__":
	pre_process()
	prefix_sum()
	print calc()



