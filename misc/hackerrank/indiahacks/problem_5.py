M=1000000
m=1000000007
r=[]
r.append(1)
r.append(1)
for i in range(2,int(M)):
	r.append(((2014*r[i-1])%m+(69*r[i-2])%m)%m)
t=raw_input()
t=int(t)
while t:
	n=raw_input()
	n=int(n)
	print int(r[n-1])
	t=t-1