'''
FInding the top 3 spending rates 
@Author: Rohith Uppala
'''

def subset_sum(numbers, target, partial=[]):
	s = sum(partial)
	if s == target:
		print partial
	elif s >= target:
		return
	for i in range(0, len(numbers)):
		n = numbers[i]
		remaining = numbers[i+1:]
		subset_sum(remaining, target, partial + [n])

if __name__ == "__main__":
	n = int(raw_input())
	numbers = map(int, raw_input().split())
	subset_sum(numbers, n, [])
