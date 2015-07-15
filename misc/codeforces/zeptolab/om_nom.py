import math

count,initial_height = raw_input().split()
count = int(count)
initial_height = int(initial_height)

lst1 = []
lst2 = []

for i in range(0,count):
	t,h,m = raw_input().split()
	t = int(t)
	h = int(h)
	m = int(m)
	if t == 0:
		lst1.append((h,m))
	else:
		lst2.append((h,m))

lst1.sort()
lst2.sort()

if len(lst1) > len(lst2):
	flag = 1
else:
	flag = 2

for j in range(0,count):
	flag2 = 0
	flag3 = 0
	if flag & 1:
		for i in range(0,len(lst1)):
			if initial_height >= lst1[i][0]:
				initial_height = initial_height + lst1[i][1]
				lst1.remove((lst1[i][0],lst1[i][1]))
				flag2 = 1
				break
	else:
		for i in range(0,len(lst2)):
			if initial_height >= lst2[i][0]:
				initial_height = initial_height + lst2[i][1]
				lst2.remove((lst2[i][0],lst2[i][1]))
				flag3 = 1
				break
	flag = flag + 1
	if (flag2 == 0 and flag3 == 1) or (flag2 == 1 and flag3 == 0):
		continue
	else:
		break

result = len(lst1) + len(lst2)
print count - result