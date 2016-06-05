'''
binary search
@Author: Rohith Uppala
'''

def calc(persons, value):
	result = 0
	for person in persons: result = result + (value / person)
	return result

def bin_search(low, high, n, persons):
	mid = (low + high) / 2
	value = calc(persons, mid)
	if value == n: return mid
	elif value > n: return bin_search(low, mid-1, n, persons)
	else: return bin_search(mid+1, high, n, persons)
	
if __name__ == "__main__":
	n, m = map(int, raw_input().split())
	persons = map(int, raw_input().split())
	mini, maxi = min(persons), min(persons) * n
	print bin_search(mini, maxi, n, persons)
