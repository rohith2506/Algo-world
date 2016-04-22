import math
INF = 1000000
money = []

def LSOne(k):
	return (k & (-k))

def update(k, v):
	while k <= len(money):
		money[k] += v
		k += LSOne(k)

def range_update(i, j, v):	
	update(i, v)
	update(j + 1, -v)

def construct_array(l,r,c,p,q,s,n,m):
	for i in range(0,m):
		l_val = ((prev_l * p) + prev_r)%n + 1 if i > 0 else l
		r_val = ((prev_r * q) + prev_l)%n + 1 if i > 0 else r
		c_val = (prev_c * s) % 1000000 + 1 if i > 0 else c
		if (l_val > r_val): l_val, r_val = r_val, l_val
		range_update(l_val+1, r_val+1, c_val)
		prev_l, prev_r, prev_c = l_val, r_val, c_val

if __name__ == "__main__":
	t = int(raw_input())
	while t:
		n,m = raw_input().split()
		n,m = long(n), long(m)
		l,r,c,p,q,s = raw_input().split()
		money = [0 for i in range(INF+1)]
		construct_array(long(l), long(r), long(c), long(p), long(q), long(s),n,m)
		maximum, index = 0, -1
		for i in range(0, len(money)):
			if money[i] > maximum:
				maximum = money[i]
				index = i
		print index-1, maximum
		t = t - 1