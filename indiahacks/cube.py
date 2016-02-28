t = int(raw_input())
while t:
	n = int(raw_input())
	if n == 1:
		print n
	else:
		print n * n * n - ((n-2) * (n-2) * (n-2))
	t = t - 1