import math

n = math.pow(2,1000)

print n
n = int(n)
print n
count = 0

while n>0:
	b = n%10
	count = count+b
	n = n/10

print count
