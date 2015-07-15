import math

def count_triangles():
	cnt = 0
	for i in range(0,51):
		for j in range(i,51):
			for k in range(0,51):
				for l in range(k,51):
					if i == 0 and j == 0: continue
					if k == 0 and l == 0: continue
					if i == k and j == l: continue
					a = ((j*j) + (i*i))
					b = (((l-j)*(l-j)) + ((k-i)*(k-i)))
					c = ((k*k) + (l*l))
					if (a == b + c) or (b == c + a) or (c == a + b):
						print i,j,k,l
						cnt = cnt + 1  
	print cnt	

if __name__ == "__main__":
	count_triangles()
