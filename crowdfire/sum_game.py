def count(n):
	hash_table = {}
	for a in range(1, n+1):
		for b in range(a, n+1):
			for c in range(b, n+1):
				temp_value = (n - (a + b + c))
				if temp_value >= c:
					if temp_value not in hash_table:
						hash_table[temp_value] = 0
					hash_table[temp_value] += 1
	return len(hash_table.keys())
	
for n in range(1, 100): 
	print n, count(n)
