'''
Find an element which appears more than once
@Author: Rohit
'''

def UniqueElement(lst):
	lst.sort()
	for i in range(0, len(lst) - 1):
		if lst[i] == lst[i+1]:
			return lst[i]

if __name__ == "__main__":
	lst = raw_input().split()
	for i in range(0, len(lst)):
		lst[i] = int(lst[i])
	print UniqueElement(lst)
