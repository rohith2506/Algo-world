MOD = 1000000007

def go(m,n):
	if m == 1 or n == 1:
		return 1
	else:
		return (go(m-1,n)%MOD + go(m,n-1)%MOD)%MOD

t = raw_input()
t = int(t)
while t:
    m,n = raw_input().split()
    m = int(m)
    n = int(n)
    print go(m,n)
    t = t - 1