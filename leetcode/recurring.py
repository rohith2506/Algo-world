import math

def fraction(a,b):
	lst = [0 for i in range(0,10)]
	res = ""
	if(a < b):
		res = res + "."
	terminate = 0
	while a > 0:
		if(a < b):
			a = a*10
			while(a < b):
				a = a*10
				res = res + "0"
				lst[0] = lst[0] + 1
				if(lst[0] > 1):
					terminate = 1
					break
			if terminate == 1:
				break		
		else:
			temp = a/b
			a = a%b
			res = res + str(temp)
			lst[temp] = lst[temp] + 1
			if(lst[temp] > 1):
				break
	# split it into decimal and non decimal part
	print res
	main_res = ""
	result = res.split('.')
	if not result[0]:
		if('.' in res):
			main_res = main_res + "0."
	else:
		if('.' in res):
			main_res = main_res + result[0] + "."
		else:
			main_res = main_res + result[0]

	if len(result) > 1:
		second = result[1]
		last = second[len(second)-1]
		idx = -1
		for i in range(0, len(second)-1):
			if second[i] == last:
				idx = i
				break
		if idx != -1:
			main_res = main_res + second[0:i]
			main_res = main_res + "("
			main_res = main_res + second[i:len(second)-1]
			main_res = main_res + ")"
		else:
			main_res = main_res + second
	return  main_res	

	
if __name__ == "__main__":
	a = raw_input()
	b = raw_input()
	print fraction(int(a),int(b))	
