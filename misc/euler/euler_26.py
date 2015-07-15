import math
import time

def go():
	maxi = 0
	for i in range(1001,1,-1):
		if maxi >= i:
			break
		vec = [0 for i in range(i)]
		value = 1
		pos = 0
		while vec[value] == 0 and value!=0:
			vec[value] = pos
			value = value * 10
			value = value % i
			pos = pos + 1
		if pos - vec[value] > maxi:
			maxi = pos - vec[value]
	return maxi

if __name__ == "__main__":
	print go()
