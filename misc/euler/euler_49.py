import math
primes = []
Prime = []
Sum = []
max = 1000000
const = 3330

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
			if j>=1000 and j<=10000:
				Prime.append(j)
	

def check(i,j,k):
	i = str(i)
	j = str(j)
	k = str(k)
	
	i = sorted(i)
	j = sorted(j)
	k = sorted(k)

	if i == j and j == k:
		return True
	else:
		return False


def calc():
	l = []
	for i in range(0,len(Prime)):
		for j in range(i+1,len(Prime)):
			k = Prime[j] + (Prime[j] - Prime[i])
			if k < max and  primes[k] == False and check(Prime[i],Prime[j],k):
				print Prime[i],Prime[j],k
				s = str(Prime[i])+str(Prime[j])+str(k)
				print s
				l.append(s)

	return l						  
	

if __name__ == "__main__":
	pre_process()
	print calc()

