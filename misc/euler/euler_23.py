import math
import os
MAX = 28123
# array with sum of abundant divisors
def get(num):
	sum = 0
	if num == 0 or num == 1:
		return False
	else:
		for i in range(1,num):
			if num % i == 0:
				sum = sum + i
		if sum > num:
			return True
		else:
			return False

def bin_search(num,arr,low,high):
	
	flag = 0
	while low<=high:
		if(arr[low]+arr[high] == num):
			flag = 1
			break
		elif(arr[low] +arr[high] < num):
			low = low + 1
		elif (arr[low] + arr[high] > num):
			high = high - 1
		else:
			low =low
			high = high

	if flag == 1:
		return True
	else:
		return False

def check(i,abundant_divisiors):
	num = i
	if (bin_search(num,abundant_divisiors,0,len(abundant_divisiors)-1)):
		return False
	else:
		return True

abundant_divisiors = []
for i in range(0,MAX):
	if get(i):
		abundant_divisiors.append(i)

print abundant_divisiors

sum = 0
for i in range(1,MAX):
	if check(i,abundant_divisiors):
		sum = sum + i
print sum
