def check(val,x1,y1):
	if val >= x1 and val <= y1:
		return True
	else:
		return False
 
n,k,p = raw_input().split()
n = int(n)
k = int(k)
p = int(p)
lst = raw_input().split()
lst2 = []
for i in range(0, len(lst)):
	lst2.append(int(lst[i]))
lst2.sort()
 
startx = lst2[0]
starty = lst2[0]
res = []
 
for i in range(1, len(lst2)):
	if (lst2[i] - starty) > k:
		starty = starty + k
		res.append((startx, starty))
		startx = starty + 1
		starty = lst2[i]
	else:
		starty = lst2[i]

res.append((startx, starty))

for i in range(0,p):
	flag = 0
	xval,yval = raw_input().split()
	x_idx = int(xval) - 1
	y_idx = int(yval) - 1
	for x,y in res:
		if check(int(lst[x_idx]),x,y) and check(int(lst[y_idx]),x,y):
			flag = 1
			break
	if flag == 1:
		print "Yes"
	else:
		print "No"