import math

def distance(a, b):
	dist = math.pow((a[0] - b[0]) , 2) + math.pow((a[1] - b[1]), 2)
	return math.sqrt(dist)

def form_triangle(a,b,c):
	a_len, b_len, c_len = distance(a, b), distance(b, c), distance(a, c)
	if a_len + b_len < c_len:
		return False
	if a_len + c_len < b_len:
		return False
	if b_len + c_len < a_len:
		return False
	return True

def get_mid_point(x1, y1, x2, y2):
	return (x1 + x2) / 2.0, (y1+y2) / 2.0

x1, y1 = map(int, raw_input().split())
x2, y2 = map(int, raw_input().split())
x3, y3 = map(int, raw_input().split())



result = []

m1, m2 = get_mid_point(x1, y1, x2, y2)
x4, y4 = (2*m1) - x3, (2*m2) - y3

if form_triangle((x1, y1), (x2, y2), (x4, y4)) and \
   form_triangle((x1, y1), (x3, y3), (x4, y4)) and \
   form_triangle((x2, y2), (x3, y3), (x4, y4)):
	result.append((x4, y4))	

m1, m2 = get_mid_point(x1, y1, x3, y3)
x4, y4 = (2*m1) - x2, (2*m2) - y2

if form_triangle((x1, y1), (x2, y2), (x4, y4)) and \
   form_triangle((x1, y1), (x3, y3), (x4, y4)) and \
   form_triangle((x2, y2), (x3, y3), (x4, y4)):
	result.append((x4, y4))	

m1, m2 = get_mid_point(x2, y2, x3, y3)
x4, y4 = (2*m1) - x1, (2*m2) - y1

if form_triangle((x1, y1), (x2, y2), (x4, y4)) and \
   form_triangle((x1, y1), (x3, y3), (x4, y4)) and \
   form_triangle((x2, y2), (x3, y3), (x4, y4)):
	result.append((x4, y4))	

print len(result)
for res in result:
	print int(res[0]), int(res[1])
