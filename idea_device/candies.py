import math

def calc(elements, n, amount):
	all_combinations = []
	for i in range(1, 2**n):
		bin_string = bin(i)[2:]
		temp_sum, temp_index = 0, ""
		for i in range(len(bin_string)):
			if bin_string[i] == '1': 
				temp_sum += elements[i]
				temp_index += str(i)
		if temp_sum == amount: all_combinations.append(temp_index)
	all_combinations.sort()
	sorted(all_combinations, key=len)
	return all_combinations[0]

if __name__ == "__main__":
	n, amount = raw_input().split()
	n, amount = int(n), int(amount)	
	elements = raw_input().split()
	for i in range(len(elements)):
		elements[i] = int(elements[i])
	result = calc(elements, n, amount)
	for i in range(len(result)):
		print int(result[i])+1,