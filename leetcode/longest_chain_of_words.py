'''
Variation of toplogical sorting to find longest chain of words in a given dictionary.
@Author: Rohith
'''

import sys
import math

lengths = []
def recurse(word, dict_words, length):
	if not dict_words[word]:
		lengths.append(length)
	else:
		lst = dict_words[word]
		for i in range(0, len(lst)):
			recurse(lst[i], dict_words, length+1)	


def print_longest_chain_of_words(words):
	dict_words = {}
	visited = {}
	edges = []
	for i in range(0, len(words)):
		dict_words[words[i]] = []
		for j in range(0, len(words[i])):
			temp_word = words[i][:j] + words[i][j+1:]
			if temp_word and temp_word in words:
				dict_words[words[i]].append(temp_word)
				edges.append(temp_word)

	max_len = 0
	for k,v in dict_words.items():
		print k
		if k not in edges:
			del lengths[:]
			recurse(k, dict_words, 1)
			lengths.sort()
			if lengths[len(lengths)-1] > max_len:
				max_len = lengths[len(lengths)-1]
	print max_len	
	

if __name__ == "__main__":
	words = open("/usr/share/dict/words","r").readlines()
	for i in range(0, len(words)):
		words[i] = words[i].strip()
	print_longest_chain_of_words(words)
