# editorial link
# http://apps.topcoder.com/wiki/display/tc/SRM+621
# key words: bits, guassian elimination, basis 

class mixinglcolors(self,colors):
	colors = list(colors)
	n = len(colors)
	j = 0
	for i in range(0,31):
		k = j
		while (k < n && (colors[k] & (1 << k) != 0))
			k = k + 1
		if k != n:
			colors[k],colors[j] = colors[j],colors[k]
			for k in range(j+1,n):
				if colors[k] & (1 << i) != 0:
					colors[k] = colors[k] ^ colors[j]
			j = j + 1
	return sum(c for c in colors)
