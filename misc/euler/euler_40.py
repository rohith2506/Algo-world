import math
arr = [9,180,2700,36000,450000,5400000,63000000]
arr2 = [9,180,2700,36000,450000,5400000,63000000]
add = [9,99,999,9999,99999,999999,9999999]
def precompute():
	for i in range(1,len(arr)):
		arr[i] = arr[i] + arr[i-1]

def compute(x,idx):
	index = 0
	for i in range(0,len(arr2)-1):
		if x>arr2[i] and x<=arr2[i+1]:
			index = i
			break
	print arr2
	print index
	result = x - arr[index]
	result = result + (index+2)*add[idx]
	print result
	remainder = result % (index+2)
	quotient  = result / (index+2)
	print remainder,quotient
	num = []
	while quotient>0:
		num.append(quotient%10)
		quotient=quotient/10

	print num
	length = len(num)
	num2 = []
	for i in range(length-1,-1,-1):
		num2.append(num[i])
	print num2
	print num2[remainder-1]
	return num2[remainder-1]

precompute()
res = [100,1000,10000,100000,1000000]
ans = 1
for i in range(0,len(res)):
		ans = ans * compute(res[i],i)
print ans

