import math

count  = 0
def change_coin(arr):
	target = 200
	ways = []
	ways.append(1)
	for i in range(1,target+1):
		ways.append(0)

	for i in range(0,len(arr)):
		for j in range(arr[i],target+1):
			ways[j] = ways[j] + ways[j-arr[i]]

	return ways[target]

if __name__ == "__main__":
	arr = [1,2,5,10,20,50,100,200]
	print change_coin(arr)
