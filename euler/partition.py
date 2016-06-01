result = []

def num_partitions(n, lst):
	if n <= 1:
		lst.append(n)
		result.append(lst)
		lst = []
	else:
		for i in range(1, n):
			lst.append(i)
			num_partitions(n-i, lst)

if __name__ == "__main__":
	for num in range(1, 5):
		num_partitions(num, [])
		print num, result
