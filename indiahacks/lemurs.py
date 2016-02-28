def minutes(n, k, step):
	if n == 0 or n%k == 0 or n <= k:
		return step
	else:
		x = minutes(n-1, k, step+1)
		y = minutes(n+1, k, step+1)
		if k >= 2: z = minutes(n, k-1, step+1)
		w = minutes(n, k+1, step+1)
		return min(x,min(y,min(w,z)))

if __name__ == "__main__":
	n, k = raw_input().split()
	n, k = int(n), int(k)
	print minutes(n, k, 0)
