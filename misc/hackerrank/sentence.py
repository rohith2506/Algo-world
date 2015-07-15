'''
Bayesian spam filtering model in order to determine whether given message contains 
spam or ham or not
'''
import math
import os
import string
import re
import time
spam = {}
ham  = {}

prob_s = 0.5
prob_h = 0.5
s = 3
threshold_limit = 0.9
e = 2.71828

def spam_learn():
	f1 = open("apple-computers.txt","rb")
	lines = f1.readlines()
	for line in lines:
		for ch in string.punctuation:
			if ch == '[' or ch == ']':
				line = line.replace(ch," ")
			if ch!= '#':
				line = line.replace(ch,"")
		lst = line.split()
#		print lst

		for i in range(0,len(lst)):
			lst[i] = lst[i].lower()

		for word in lst:
			try: 
				spam[word] = spam[word] + 1
			except: 
				spam[word] = 1
#	print spam


def ham_learn():
	f1 = open("apple-fruit.txt","rb")
	lines = f1.readlines()
	for line in lines:
		for ch in string.punctuation:
			if ch == '[' or ch == ']':
				line = line.replace(ch," ")
			if ch!= '#':
				line = line.replace(ch,"")
		lst = line.split()
		
		for i in range(0,len(lst)):
			lst[i] = lst[i].lower()

		for word in lst:
			try: 
				ham[word] = ham[word] + 1
			except: 
				ham[word] = 1
#	print ham


def prune(Str):
	for ch in string.punctuation:
		if ch!='#':
			Str = Str.replace(ch,"")
	return Str.split()


if __name__ == "__main__":
	spam_learn()
	ham_learn()

	t = raw_input()
	t = int(t)

	while t:
		input_string = raw_input()
		words = prune(input_string)

		for i in range(0,len(words)):
			words[i] = words[i].lower()
#		print words

		cnt1 = 0
		cnt2 = 0
		for wrd in words:
			if wrd in spam.keys():
				cnt1 = cnt1 + 1
			if wrd in ham.keys():
				cnt2 = cnt2 + 1

		if cnt1 > cnt2:
			print "computer-company"
		else:
			print "fruit"