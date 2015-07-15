import math
Max = 1000000
glob = []

def convert(vec):
	num = 0
	for i in range(0,len(vec)):
		num = num*10 + vec[i]
	return num

def ispalindrome(num,binary):
	temp = binary[::-1]
	if temp == binary:
		print num,binary,temp
		glob.append(num)
		return True
	else:
		return False

def check(vec):
	num = convert(vec)
	binary = bin(num)[2:]
	if(ispalindrome(num,binary)):
		return True
	else:
		return False

def go2(vec,first,last,mainsum):
	if first == last or first+1 == last:
		if first == last:
			while vec[first] < 10:
				if(check(vec)):
					num = convert(vec)
					mainsum = mainsum + num
				vec[first] = vec[first] + 1
		elif first +1 == last:
			while vec[first] < 10:
				if(check(vec)):
					num = convert(vec)
					mainsum = mainsum + num 
				vec[first] = vec[first] + 1
				vec[last]  = vec[last]  + 1
		return None
	else:
		for i in range(1,10):
			temp = first +1
			while temp < last:
				vec[temp] = 0
				temp = temp + 1
			vec[first] = i
			vec[last]  = i
			go2(vec,first+1,last-1,mainsum)

def split(num):
	vec = []
	num = num + 1
	while num > 0:
		vec.append(num%10)
		num = num/10
	return vec

def go1(vec,num,size):
	first = 0
	last  = len(vec) - 1
	mainsum = 0
	go2(vec,first,last,mainsum)
	xsum = 0
	for p in glob:
		xsum = xsum + p
	print xsum


def go():
	vec = []
	num = 1
	size = 1
	while(num < Max):
		vec = split(num)
		go1(vec,num,size)
		num = num * 10
		size = size + 1

go()
