import math

def ispentagonal(x):
	pen = (1 + math.sqrt(1+24*x))/6.0
#	print pen,int(pen)
	if pen == int(pen):
		return True
	else:
		return False

def calc():
	notFound = True
	i=1
	while notFound:
		i = i+1
		n = i*((3*i)-1)/2
		for j in range(i-1,0,-1):
	#		if i == 2167 and j == 1020:
				m = j*((3*j)-1)/2
        #				print n,m
				if ispentagonal(n-m) and ispentagonal(n+m):
					print n,m
					diff = n-m	
					notFound = False		
					break
	return diff	
				

if __name__ == "__main__":
	print calc()

