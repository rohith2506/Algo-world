import math
from fractions import gcd

def count():
	cnt = 0
	for i in range(1,12001):
		for j in range(1,i):
			if gcd(i,j) == 1:
				if (j*3) > i and (j*2) < i:
					print j,i
					cnt = cnt + 1
	print cnt

count()
