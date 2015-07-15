import math
import time
start_time = time.time()
def power(a,b):
	if b == 0:
		return 1
	elif b == 1:
		return a
	temp = power(a,b/2)
	if b%2==0:
		return temp * temp
	else:
		return temp * temp * a

st = []

for i in range(2,101):
	for j in range(2,101):
		res = power(i,j)
		if res not in st:
			st.append(res)

print len(st)
print time.time() - start_time, "seconds"
