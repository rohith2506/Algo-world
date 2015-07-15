import math
import os
MAX = 1001
a = [[0 for x in xrange(MAX)] for x in xrange(MAX)] 

level = 1
row = MAX/2
col = MAX/2
num = 1
a[row][col] = num
num = num +1

start =  0
end   =  1

while level<=MAX/2:
	for i in range(row+start,row+level):
		a[i][col+end] = num
		num = num + 1

	for i in range(col+level,col-level,-1):
		a[row+level][i] = num
		num = num + 1

	for i in range(row+level,row-level,-1):
		a[i][col-level] = num
		num = num + 1

	for i in range(col-level,col+level):
		a[row-level][i] = num
		num = num + 1
	
	a[row-level][col+level] = num
	num = num + 1

	level = level + 1
	start = start - 1
	end   = end   + 1

row = 0
col = 0
sum = 0
for i in range(0,MAX):
	sum = sum + a[row+i][col+i]

start = 0
for i in range(MAX-1,-1,-1):
	sum = sum + a[start][i]
	start = start + 1

print sum - a[MAX/2][MAX/2]













