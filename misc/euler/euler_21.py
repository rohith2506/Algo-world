import math

def check2(x,y):
	cnt = 0
	for i in range(1,x-1):
		if(x%i == 0):
			cnt = cnt + i

	if(cnt <= 10000):
		if(cnt == y):
			return True
		else:
			return False
	else:
		return False

def check(x):

	cnt = 0
	for i in range(1,x-1):
		if(x%i == 0):
			cnt = cnt + i


	if(cnt <= 10000):
	  if(check2(cnt,x)):
			return True
	  else:
	  		return False
	else:
		return False


def visited(a,i):
	if(a[i] == 0):
		return True
	else:
		return False

def amicable(x,y):
	count = 0

	a = []

	for i in range(0,10001):
		a.append(0)

	for i in range(x,y):
		if(visited(a,i)):
			if check(i): 
				print i
				a[i]=1
				count = count+i

	return count

print amicable(1,10000)
