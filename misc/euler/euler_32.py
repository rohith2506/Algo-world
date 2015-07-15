import math
import time

def mix(i,j,prod):
	temp = []
	while i>0:
		temp.append(i%10)
		i = i/10
	while j>0:
		temp.append(j%10)
		j = j/10
	while prod>0:
		temp.append(prod%10)
		prod = prod/10
	return temp

def check(temp):
	vec = [0 for i in range(1,11)]
	for i in range(0,len(temp)):
		if temp[i]!=0:
#			print temp[i]
			vec[temp[i]] = 1
	for i in range(1,10):
		if vec[i] == 0:
			return False
	return True

def go():
	# 1-4
	maintemp = []
	mainprod = 0
	for i in range(1000,10000):
		for j in range(1,10):
			prod = i*j
			temp = mix(i,j,prod)
			flag = 0
			if len(temp) != 9 or not check(temp):
				flag = 1
			if flag == 0:
				if prod not in maintemp:
					maintemp.append(prod)
					mainprod = mainprod + prod

	#2-3
	for i in range(10,100):
		for j in range(100,1000):
			prod = i*j
			temp = mix(i,j,prod)
			flag = 0
			if len(temp) != 9 or not check(temp):
				flag = 1
			if flag == 0:
				if prod not in maintemp:
					maintemp.append(prod)
					print i,j,prod
					mainprod = mainprod + prod

	#3-2
	for i in range(100,1000):
		for j in range(10,100):
			prod = i*j
			temp = mix(i,j,prod)
			flag = 0
			if len(temp) != 9 or not check(temp):
				flag = 1
			if flag == 0:
				if prod not in maintemp:
					maintemp.append(prod)
					print i,j,prod
					mainprod = mainprod + prod

	#4-1
	for i in range(1,10):
		for j in range(1000,10000):
			prod = i*j
			temp = mix(i,j,prod)
			flag = 0
			if len(temp) != 9 or not check(temp):
				flag = 1
			if flag == 0:
				if prod not in maintemp:
					maintemp.append(prod)
					mainprod = mainprod + prod

	#1-3
	for i in range(1,10):
		for j in range(100,1000):
			prod = i*j
			temp = mix(i,j,prod)
			flag = 0
			if len(temp) != 9 or not check(temp):
				flag = 1
			if flag == 0:
				if prod not in maintemp:
					maintemp.append(prod)
					mainprod = mainprod + prod

	#3-1
	for i in range(100,1000):
		for j in range(1,10):
			prod = i*j
			temp = mix(i,j,prod)
			flag = 0
			if len(temp) != 9 or not check(temp):
				flag = 1
			if flag == 0:
				if prod not in maintemp:
					maintemp.append(prod)
					mainprod = mainprod + prod

#	print maintemp
	return mainprod

if __name__ == "__main__":
	print go()