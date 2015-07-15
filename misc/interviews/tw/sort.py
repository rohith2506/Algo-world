INF = 10e9 + 1
import math
tc = raw_input()
tc = int(tc)

while tc:
	n,k = raw_input().split()
	n,k = int(n),int(k)
	s = raw_input().split()
	for i in range(0, len(s)):
		s[i] = int(s[i])
	for i in range(0, len(s)):
		pos = i
		for j in range(i+1, len(s)):
			if (j-i) > k: break
			if s[j] <= s[pos]: pos = j
		for j in range(pos, i, -1):
			s[j],s[j-1] = s[j-1],s[j]
		k = k - (pos - i)
	for i in range(0, len(s)):
		print s[i],
	print
	tc = tc - 1




