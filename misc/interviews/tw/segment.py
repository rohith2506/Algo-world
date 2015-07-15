import math
INF = 10e9 + 1
n = raw_input()
n = int(n)

lst = raw_input().split()
for i in range(0, len(lst)):
	lst[i] = int(lst[i])

q = raw_input()
q = int(q)

while q:
	l,r,x = raw_input().split()
	l,r,x = int(l), int(r), int(x)

	lst2 = lst[l-1:r-1]

	mini = INF
	maxi = 0

	for l in lst2:
		mini = min(l,mini)
		maxi = max(l,maxi)

	for z in lst2:
		temp_lst = []
		for x1 in lst2:
			if z != x1:
				temp_lst.append(z ^ x1)
		cnt = 0
		for x1 in temp_lst:
			if x1 < mini:
				cnt = cnt + 1
		if cnt == len(temp_lst):
			print z, 


	