def is_substring(st):
	flag = 0
	if len(st) >= 10: return True
	for i in range(0, len(st)):
		for j in range(i+1, len(st)):
			for k in range(j+1, len(st)):
				for l in range(k+1, len(st)):
					a,b,c,d = st[i:j], st[j:k], st[k:l], st[l:]
					if a == b or a == c or a == d or b == c or b == d or c == d: continue
					flag = 1
	if flag == 1: return True
	else: return False

if __name__ == "__main__":
	t = int(raw_input())
	while t:
		st = raw_input()
		if is_substring(st):
			print "YES"
		else:
			print "NO"
		t = t - 1
