#its  slow...i have to code this problem in c++

import math

t = (int(raw_input()))
#SQUARE = dict([(c, int(c)**2) for c in "0123456789"])

SQUARE = dict([(c, int(c)**2) for c in "0123456789"])
def is_happy(n):
	s = set()
	res = 0
	while (n > 1) and (n not in s):
		s.add(n)
		res+=1
		n = sum(SQUARE[d] for d in str(n))
	if n == 1:
		return res
	else:
		return -1

while t:
		n = (int(raw_input()))
		print "%d" %(is_happy(n))
		t -= 1
