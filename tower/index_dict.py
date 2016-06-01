def get_indexes(arr, inp):
	indexes = []
	for i in range(0, len(arr)):
		a1, a2 = arr[i], inp
		if a1[0:len(inp)] == inp: indexes.append(i)
	return indexes

if __name__ == "__main__":
	arr = raw_input().split(",")
	inp = raw_input()
	result = get_indexes(arr, inp)
	if len(result) == 0: print "-1,-1"
	else: print str(result[0]) + "," + str(result[len(result) - 1])
