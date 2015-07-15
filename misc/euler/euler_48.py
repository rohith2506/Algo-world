import math

def power(x,y):
	if(y == 0):
		return 1
	elif(y==1):
		return x
	temp = power(x,y/2)

	if(y%2==0):
		return temp*temp
	else:
		return temp*temp*x

sum = 0
for i in range(1,1000):
	sum = sum + power(i,i)
print sum
