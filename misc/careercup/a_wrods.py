import math

s = raw_input()

words = s.split()
res=0
for i in range(0,len(words)):
	if words[i]=="a":
		res+=1
print res
