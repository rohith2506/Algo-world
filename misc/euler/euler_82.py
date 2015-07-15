# incomplete


rows = [[int(n) for n in s.split(',')] for s in open('in.txt').readlines()]
nrows = len(rows)-1

for col1 in range(0,len(path)):
	for col2 in range(0,len(path)):

		endx = col2
		endy = len(rows) - 1

		startx = col1
		starty = 0

		path = [[0 for x in xrange(len(rows))] for x in xrange(len(rows))]
		dp   = [[0 for x in xrange(len(rows))] for x in xrange(len(rows))]

		for i in range(0,len(path)):
			for j in range(0,len(path)):
				path[i][j] = rows[i][j]

		for i in range(endx, -1, -1):
		  for j in range(endy, -1, -1):
		  		if i == endx and j == endy:
		  			continue
		  		elif 