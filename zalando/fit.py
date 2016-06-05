'''
Check whether items fit or not
@Author: Rohith Uppala
'''

def check_fit_for_rectangle(w, h, w1, h1):
	if w1 <= w and h1 <= h: return True
	else: return False

def check_fit_for_circle(w, h, r):
	d = 2*r
	if d <= w and d <= h: return True
	else: return False

if __name__ == "__main__":
	w, h = map(int, raw_input().split())
	n = int(raw_input())
	for i in range(n):
		values = raw_input().split()
		if len(values) == 3:
			w1, h1 = int(values[1]), int(values[2])
			if check_fit_for_rectangle(w,h,w1,h1): print "YES"
			else: print "NO"
		else:
			r = int(values[1])
			if check_fit_for_circle(w,h,r): print "YES"
			else: print "NO"
