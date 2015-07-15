import math
tc = raw_input()
tc = int(tc)

while tc:
	n,k = raw_input().split()
	n,k = int(n),int(k)
	arr = raw_input().split()
	for i in range(0, len(arr)):
		arr[i] = int(arr[i])
	indexes  = []
	for i in range(0, len(arr)-1):
		if arr[i] < arr[i+1]:
			indexes.append(i)
	diff = k - len(indexes)
	result = []
	for i in range(0, len(arr)):
		if i not in indexes:
			result.append(arr[i]) 
	indexes = []
	for i in range(0, len(result)-1):
		if result[i] < result[i+1]:
			indexes.append(i)
	diff2 = diff - len(indexes) 
	for i in range(0, min(diff, len(indexes))):
		result.remove(result[indexes[i]])
	if diff2 > 0:
		result = result[0: len(result) - diff2 - 1]
	for i in range(0, len(result)):
		print result[i],
	print 
	tc = tc - 1



