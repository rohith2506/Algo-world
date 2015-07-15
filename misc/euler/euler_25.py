import math
fibonacci = []

def cal_digits(num):
	count = 0
	while num>0:
		count = count + 1
		num = num/10
	return count

def go():
	fibonacci.append(1)
	fibonacci.append(1)

	counter = 2

	digits = 3
	start = 12

	while digits<1000:
		digits = digits+1
		start = start + 5

	print digits,start

	while counter < 5000:
		fibonacci.append(fibonacci[counter-1]+fibonacci[counter-2])
		counter = counter + 1

	print cal_digits(fibonacci[4782])

if __name__ == "__main__":
	go()
