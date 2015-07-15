import math
Max = 1000000

def main():
	Primes = [False for i in range(Max)]
	Primes[0] = True
	Primes[1] = True

	for i in range(2,Max):
		val = i+i
		while val < Max:
			if Primes[val] == False:
				Primes[val] = True
			val = val + i

	primes = []
	for i in range(0,len(Primes)):
		if not Primes[i]:
			primes.append(i)

	res = []
	for i in range(0,len(primes)):
		val = primes[i]
		val2 = str(val)
		val2 = val2[::-1]
		val2 = int(val2)
		if val2 in primes and val2 != val:
			print val
	
if __name__ == "__main__":
	main()