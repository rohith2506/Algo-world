import math

MAX = 2540160
visited = []

def check(number, visited):
	temp = number
	sum = 0
	while temp > 0:
		b = temp % 10
	#	print b
	#	print visited[b]
		sum = sum + visited[b]
		#print sum
		temp = temp/10
	return sum

visited.append(1)
visited.append(1)
visited.append(2)

for i in range(3,10):
	visited.append(visited[i-1] * i) 

print visited
sum = 0
for i in range(10,MAX):
	number = i
	number2 = check(number,visited)
	if number == number2:
		print number
		sum = sum + number

print sum