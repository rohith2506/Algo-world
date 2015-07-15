import math
import os

def go (s):
	sum = 0
	print s
	for i in range(1,len(s)-1):
		sum = sum + ord(s[i]) - 65
		sum = sum + 1
	return sum

f = open("in.txt","rb")
str = f.read()
words = []
words = str.split(",")

words.sort()

sum = 0
cnt = 1
for word in words:
	sum = sum + (cnt * go(word))
	cnt = cnt + 1 

print sum
