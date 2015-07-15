def C(b,i,j,n):
	for x in range(0,9):
		if(x!=j and b[x][j]==n):
			return False
	for x in range(0,9):
		if(x!=i and b[i][x]==n):
			return False
	for q in range(3*(i/3),3*(i/3)+3):
		for r in range(3*(j/3),3*(j/3)+3):
			if(q!=i and r!=j and b[q][r]==n):
				return False
	return True
def d(b):
	for i in range(0,9):
		for j in range(0,9):
			if b[i][j]==0:
				return (i,j)
def c(b):
	for i in range(0,9):
		for j in range(0,9):
			if b[i][j]!=0:
				return False
	return True
def g(b):
	if c(b):
		for i in range(0,9):
			for j in range(0,9):
				print b[i][j],
		return
	else:
		i,j=d(b)
		for n in range(1,10):
			if C(b,i,j,n):
				for i in range(0,9):
					for j in range(0,9):
						print b[i][j],
				b[i][j]=n
				g(b)
n = input()
for i in range(n):
    b=[]
    for j in range(0,9):
        b.append([int(k) for k in raw_input().split()])
    g(b)
