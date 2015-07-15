'''
Continued fractions
diophantine equation
pells equation

need some background
'''

import math
MAX = 10000000

def check(num):
	val = math.sqrt(num)
	val = int(val)
	if val * val == num:
		return True
	else:
		return False 

def go():
	count =  1
	Sum = 0
	for i in range(1,MAX):
		val = 5*i*i + 14*i + 1
		if check(val):
			p = int(math.sqrt(val))
			temp = (p - (i+1))/(2*(i+3)*1.0)
			Sum  =  Sum + temp
			print i,temp
			count = count + 1	
			if count == 30:
				break
	return Sum	

if __name__ == "__main__":
	go()

