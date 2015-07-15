'''
Shuffle an array with equal probability of generating any of possible permutations
@Author: Rohit
'''
import random
MAX = 10e10

def ShuffleArray(arr):
	for i in range(0, len(arr)):
		first = i
		last  = random.randrange(1,MAX) % (len(arr) - 1)
		temp = arr[first]
		arr[first] = arr[last]
		arr[last] = temp
	return arr


if __name__ == "__main__":
	arr = [int(n) for n in raw_input().split()]
	print ShuffleArray(arr)	
