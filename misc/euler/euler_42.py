import math
import os

def check(sum,low,high):
	for i in range(low,high+1):
		if ((i*(i+1)) == (2*sum)):
			return True
	return False

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

cnt = 0
for word in words:
    sum = go(word)
    if(check(sum,1,1000)):
		cnt = cnt + 1 

print cnt
