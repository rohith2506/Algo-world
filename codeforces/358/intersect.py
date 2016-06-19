'''
Check whether two line segments intersect each other
@Author: Rohith Uppala

Solution: Based on orientation
'''

def is_segment(p1, p2, p3):
	if p2[0] >= min(p1[0], p3[0]) and p2[0] <= max(p1[0], p3[0]) and \
		p2[1] >= min(p1[1], p3[1]) and p2[1] <= max(p1[1], p3[1]):
		return True
	else:
		return False

def find_orientation(p1, p2, p3):
	x1, y1 = p1
	x2, y2 = p2
	x3, y3 = p3
	val = (y2 - y1)*(x3 - x2) - (y3 - y2)*(x2 - x1)
	if val == 0: return 0
	elif val > 0: return 1
	else: return 2

def is_intersect(p1, q1, p2, q2):
	o1 = find_orientation(p1, q1, p2)
	o2 = find_orientation(p1, q1, q2)
	o3 = find_orientation(p2, q2, q1)
	o4 = find_orientation(p2, q2, p1)
	if o1 != o2 and o3 != o4: return True
	if o1 == 0 and is_segment(p1, p2, q1): return True
	if o2 == 0 and is_segment(p1, q2, q1): return True
	if o3 == 0 and is_segment(p2, q1, q2): return True
	if o4 == 0 and is_segment(p2, p1, q2): return True
	return False

if __name__ == "__main__":
	x1,y1,x2,y2 = map(int, raw_input().split())
	x3,y3,x4,y4 = map(int, raw_input().split())
	p1, q1, p2, q2 = [x1, y1], [x2, y2], [x3, y3], [x4, y4]
	if is_intersect(p1, q1, p2, q2): print "yes"
	else: print "no"
