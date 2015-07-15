a=[]
while True:
	try:
		v=raw_input()
		a.append(v[::-1]) 
	except(EOFError):
		break
for i in reversed(a):
	print a[i]+"\n"