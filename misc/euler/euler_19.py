import time
import math
first = [0,2,4,6,7,9,11]
second = [3,5,8,10]

def go():
	start = 0
	num = 0	
	for i in range(0,101):
			if i%400 == 0:
				for j in range(0,12):
					if j == 1:
						for k in range(1,30):
							start = (start + 1)%7
					elif j in first:
						if j == 0 and start%7 == 5:
							print i
							num = num + 1
						for k in range(1,32):
							start = (start + 1)%7
					else:
						for k in range(1,31):
							start = (start + 1)%7
			else:
				if i%4 == 0:
					for j in range(0,12):
						if j == 1:
							for k in range(1,30):
								start = (start + 1)%7
						elif j in first:
							if j == 0 and start%7 == 5:
								print i
								num = num + 1
							for k in range(1,32):
								start = (start + 1)%7
						else:
							for k in range(1,31):
								start = (start + 1)%7
				else:
					for j in range(0,12):
						if j == 1:
							for k in range(1,29):
								start = (start + 1)%7
						elif j in first:
							if j == 0 and start%7 == 5:
								print i
								num = num + 1
							for k in range(1,32):
								start = (start + 1)%7
						else:
							for k in range(1,31):
								start = (start + 1)%7
	print start,num
	return num

if __name__ == "__main__":
	print go()