'''
Brute Force apporach
Still incomplete
'''

import math
triangles = []
squares = []
pentagonals = []
hexagonals = []
heptagonals = []
octagonals = []


def check(result):
    for i in range(2,21,4):
	if str(result[i] + result[i+1]) != str(result[i+2] + result[i+3]):
           return False
    if str(result[len(result)-2] + result[len(result)-1]) != str(result[0] + result[1]):
	   return False
    return True


def all_perms(elements):
	if len(elements) <= 1:
		yield elements
	else:
		for perm in all_perms(elements[1:]):
			for i in range(len(elements)):
				yield perm[:i] + elements[0:1] + perm[i:]


def calc_val(n,switch):
	if switch == 1:
		return n*(n+1)/2
	elif switch == 2:
		return n*n
	elif switch == 3:
		return n*((3*n)-1)/2
	elif switch == 4:
		return n*((2*n)-1)
	elif switch == 5:
		return n*((5*n)-3)/2
	elif switch == 6:
		return n*((3*n)-2)
	else:
		pass


def count_figurate_numbers():
	for i in range(1,7):
		for j in range(1, 200):
			if i == 1:
				if calc_val(j,i) >= 1000 and calc_val(j,i) < 10000:
					triangles.append(calc_val(j,i))
			elif i == 2:
				if calc_val(j,i) >= 1000 and calc_val(j,i) < 10000:
					squares.append(calc_val(j,i))
			elif i == 3:
				if calc_val(j,i) >= 1000 and calc_val(j,i) < 10000:
					pentagonals.append(calc_val(j,i))
			elif i == 4:
				if calc_val(j,i) >= 1000 and calc_val(j,i) < 10000:	
					hexagonals.append(calc_val(j,i))
			elif i == 5:
				if calc_val(j,i) >= 1000 and calc_val(j,i) < 10000:
					heptagonals.append(calc_val(j,i))
			elif i == 6:
				if calc_val(j,i) >= 1000 and calc_val(j,i) < 10000:
					octagonals.append(calc_val(j,i))
			else: pass		

	print len(triangles)
	print len(squares)
	print len(pentagonals)
	print len(hexagonals)
	print len(heptagonals)
	print len(octagonals)


if __name__ == "__main__":
	count_figurate_numbers()
