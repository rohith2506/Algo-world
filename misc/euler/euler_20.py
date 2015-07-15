import math

n = 100

count = 1

while n>0:
	count = count *n
	n = n-1

print count

cnt = 0

while count > 0:
	b = count%10
	cnt = cnt+b
	count = count/10

print cnt
