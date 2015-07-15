import math
import itertools

def calc(lis):
	elements = list(itertools.permutations(lis))
	Sum = 0
	for num in elements:
		num2  = int(num[1])*100+int(num[2])*10+int(num[3])
		num3  = int(num[2])*100+int(num[3])*10+int(num[4])
		num5  = int(num[3])*100+int(num[4])*10+int(num[5])
		num7  = int(num[4])*100+int(num[5])*10+int(num[6])
		num11 = int(num[5])*100+int(num[6])*10+int(num[7])
		num13 = int(num[6])*100+int(num[7])*10+int(num[8])
		num17 = int(num[7])*100+int(num[8])*10+int(num[9])
		
		if num2%2 == 0 and num3%3 == 0 and num5%5 == 0 and num7%7 == 0 and num11%11 == 0 and num13%13 == 0 and num17%17 == 0:
			Count = 0
			for i in num:
				Count = Count *10 + int(i)
			print Count
			Sum = Sum + Count
	return Sum				 

if __name__ == "__main__":
	lis = [0,1,2,3,4,5,6,7,8,9]
	print calc(lis)
