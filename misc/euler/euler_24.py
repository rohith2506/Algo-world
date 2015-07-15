import time
num = 1000000
arr = [0,1,2,3,4,5,6,7,8,9]
res = []
num = num -1

def fact(n):
	prod = 1
	for i in range(1,n+1):
		prod = prod * i
	return prod

length = len(arr)

numbers = []
for i in range(0,len(arr)):
	numbers.append(i)

for i in range(1,len(arr)):
	b = num/fact(length-i)
	num = num%fact(length-i)
	res.append(numbers[b])
	numbers.pop(b)
	if num == 0:
		break

for i in range(0,len(numbers)):
	res.append(numbers[i])

result = ""

for x in res:
	result = result + str(x)
print result