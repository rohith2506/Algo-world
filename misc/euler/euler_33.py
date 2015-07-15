import math
import time
from fractions import gcd

def split(i):
	temp = []
	while i>0:
		temp.append(i%10)
		i = i/10
	return temp

def check(x,y):
	common = []
	if x[0] == y[0] or x[0] == y[1]:
		common.append(x[0])
	if x[1] == y[0] or x[1] == y[1]:
		if x[1] not in common:
			common.append(x[1])
	return common

def go():
	prod = 1
	for i in range(10,100,1):
		for j in range(i+1,100,1):
			if i!=j:
				numerator = i
				denominator = j
				num = split(numerator)
				den = split(denominator)
				num.sort()
				den.sort()
				common = check(num,den)
				if len(common) == 0 or common[0] == 0:
					pass
				else:
					mnum = 0
					mden = 0
					for k in range(len(num)):
						if num[k]!=common[0]:
							mnum = num[k]
					for k in range(len(den)):
						if den[k]!=common[0]:
							mden = den[k]
					gcda = gcd(numerator,denominator)
					gcdb = gcd(mnum,mden)
					if numerator == 49 and denominator == 98:
						print numerator,denominator,num,den,common,mnum,mden,gcda,gcdb
					if gcda!=0:
						numerator,denominator = numerator/gcda,denominator/gcda
					if gcdb!=0:
						mnum,mden = mnum/gcdb,mden/gcdb
					if numerator == mnum and denominator == mden:
							prod = prod * denominator
	return prod

if __name__ == "__main__":
	print go()