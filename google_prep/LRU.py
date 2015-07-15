'''
Implementing LRU Cache
@Author: Rohit
'''
LruCache = []
HashLru  = []

def DriverFunction(num):
	if len(LruCache) < 3:
		LruCache.append(num)
		HashLru.append(num)
		return LruCache
	else:
		if num in LruCache:
			index = 0
			for i in range(0, len(LruCache)):
				if LruCache[i] == num:
					index = i
					break
			for i in range(index, len(LruCache) - 1):
				LruCache[i] =LruCache[i+1]
			LruCache[len(LruCache) - 1] = num	
		else:
			LruCache.pop(0)
			LruCache.append(num)
		return LruCache


def LeastRecentlyUsedPageAlgorithm():
	while True:
		n = raw_input()
		n = int(n)
		result = DriverFunction(n)
		print result


if __name__ == "__main__":
	LeastRecentlyUsedPageAlgorithm()
