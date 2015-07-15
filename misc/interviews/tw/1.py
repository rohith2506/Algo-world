import math

n = raw_input()
n = int(n)

while n:
	Str = raw_input()
	cnt2 = len(Str)
	Str = Str.split('www.')[1]
	Str = Str.split('.com')[0]
	lst = ['a','e','i','o','u','.']
	cnt = 0
	for x in Str:
		if x not in lst:
			cnt = cnt + 1
	print str(cnt + 4) + "/" + str(cnt2)
	n = n - 1
