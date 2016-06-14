n = input()
r = map(int, raw_input().strip().split())
m = map(int, raw_input().strip().split())

indices = [[] for i in xrange(10**5+1)]
for i in xrange(n):
    indices[r[i]].append(i)

for row in indices:
	for i in row:
		for j in xrange(i-10,i+10+1):
			if 0 <= j < n and r[i] > r[j]: m[i] = max(m[i], m[j]+1)

print sum(m)
