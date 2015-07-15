import math


def Get_Rotations(Number):
    Rotations = []
    x = 0
    while x < len(Number):
        Number.insert(0,Number.pop())
        j = len(Number)-1
        sum = 0
        while j>=0:
        	sum = sum*10 + Number[j]
        	j = j-1
        Rotations.append(sum)
        x += 1
   # print Rotations
    return Rotations  


def go(x,primes):

	temp = x
	arr = []
	while temp>0:
		arr.append(temp%10)
		temp = temp/10

	length = len(arr)
	cnt = 0
	rotations = []
	rotations = Get_Rotations(arr)

	for x in rotations:
		if(primes[x] == 1):
			cnt = cnt+1

	if cnt == length:
		return True
	else:
		return False

primes = []
MAX = 1000001

for i in range(0,MAX):
	primes.append(1)
 
for i in range(2,int(math.sqrt(MAX))+1): 
         if(primes[i] == 1):
           	   j=i
           	   while ((j*i)<MAX):
           		 primes[i*j] = 0 
           		 j = j+1

primes[0] = 0
primes[1] = 0

a = []
for i in range(0,len(primes)):
	if(primes[i] == 1):
			a.append(i)


cnt = 0

for i in range(0,len(a)):
	if(go(a[i],primes)):
		cnt = cnt + 1

print cnt
