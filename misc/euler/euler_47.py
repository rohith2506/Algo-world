import math
primes = []
Prime = []
Sum = []
Number = 0
max = 1000000

def divisors(num):
	lst = []
	while num%2==0:
		if 2 not in lst:
			lst.append(2)
		num = num/2
	i=3
	while i<=math.sqrt(num):
		while num%i == 0:
			if i not in lst:
				lst.append(i)
			num = num/i
		i = i+2
	if num > 2:
		if num not in lst:
			lst.append(num)
	return len(lst)	

def calc():
	targetpf = 4
	targetconsec = 4
	consec = 1
	result = 2*3*5*7
	
	while consec < targetconsec:
		result = result + 1
		if divisors(result) >= targetpf:
			consec = consec + 1
		else:
			consec = 0
	
	return result

	
if __name__ == "__main__":
	print calc()

