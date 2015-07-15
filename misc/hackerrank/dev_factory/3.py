import math

def func(res,k):
	lst = []
	for i in range(0,res):
		val = bin(i)[2:]
		cnt = 0
		for v in val:
			if v == "1":
				cnt = cnt + 1
		if cnt == k:
			lst.append(val)
	return lst

t = raw_input()
t = int(t)

while t:
	n,k = raw_input().split()
	values = raw_input().split()

	for i in range(0,len(values)):
		values[i] = int(values[i])

	n = int(n)
	k = int(k)
	res = pow(2,n)
	temp_vals = func(res,k)

	sz = 0
	for i in range(0,len(temp_vals)):
		sz = max(len(temp_vals[i]),sz)


	for i in range(0,len(temp_vals)):
		diff = sz - len(temp_vals[i])
		temp2 = "0"
		temp3 = ""
		for j in range(0,diff):
			temp3 = temp3 + temp2
		temp_vals[i] = temp3 + temp_vals[i]

#	print temp_vals  

	main_ans = 0
	for i in range(0,len(temp_vals)):
		indexes = []
		for j in range(0,len(temp_vals[i])):
			if(temp_vals[i][j] == "1"):
				indexes.append(j)
#		print indexes
		result = []
		for j in range(0,len(indexes)):
			result.append(values[indexes[j]])
		main_ans = main_ans + min(result)
	print main_ans
	t = t - 1
