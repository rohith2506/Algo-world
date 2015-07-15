import math
Max = 1000000
mainsum = 0
cnt = 0
vec = [True for i in range(0,Max)]
vec[0] = False
vec[1] = False

for i in range(2,Max):
	if vec[i] == True:
		for j in range(i+i,Max,i):
			vec[j] = False


def split_1(num):
	v = []
	n = str(num)
	for i in range(1,len(n)):
		temp = n[i:len(n)]
		t = int(temp)
		v.append(t)
	return v

def split_2(num):
	v = []
	n = str(num)
	start = 0
	for i in range(1,len(n)):
		temp = n[0:i]
		t = int(temp)
		v.append(t)
	return v

def check(v):
	for p in v:
		if not vec[p]:
			return False
	return True

for i in range(len(vec)):
	if vec[i]:
		num = i
		vec1 = split_1(num)
		vec2 = split_2(num)
		if check(vec1) and check(vec2):
			cnt = cnt + 1
			print num
			mainsum = mainsum + num
	if cnt >= 15:
		break
print "iam",mainsum - 17
