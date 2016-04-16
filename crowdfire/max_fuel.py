from math import ceil, floor

def maximum(speed, fuel, amount):
	maxi = -1
	for i in range(0, len(fuel)):
		temp = (amount * 1.0 / fuel[i]) * speed[i]
		maxi = max(temp, maxi)
	result = str(maxi)
	number, decimal = result.split(".")
	return number + "." + decimal[0:3]
	
n = int(raw_input())
speed = map(long, raw_input().split())
fuel  = map(long, raw_input().split())
amount = int(raw_input())

print maximum(speed, fuel, amount)