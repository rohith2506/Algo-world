'''
Highly confusing problem. Took me almost 90 minutes to solve this. But Yayyy!!!!!
'''

class Solution:
	def fullJustify(self, A, B):
		if len(A) ==  0: return []
		new_words = []
		new_sentence = A[0]
		for i in range(1, len(A)):
			word = A[i]
			if len(new_sentence + " " + word) <= B: 
				new_sentence = new_sentence + " " + word
			else:
				words = new_sentence.split()
				letters_length = sum(len(w) for w in words)
				spaces_needed = B - letters_length
				n, k = spaces_needed, len(words) - 1
				if k == 0:
					spaces = ""
					for i in range(n): spaces += " "
					new_sentence = new_sentence + spaces
					new_words.append(new_sentence)
					new_sentence = word
				else:
					space_list = []
					for i in range(k): space_list.append(n/k)
					for i in range(n%k): space_list[i] += 1
					new_sent = ""
					for i in range(len(words) - 1):
						new_sent += words[i]
						spaces = ""
						for i in range(space_list[i]): spaces += " "
						new_sent = new_sent + spaces
					new_sent += words[len(words) - 1]
					new_words.append(new_sent)
					new_sentence = word
		if len(new_sentence) == 0:
			return new_words
		else:
			spaces = ""
			for i in range((B - len(new_sentence))): spaces += " "
			new_sentence = new_sentence + spaces
			new_words.append(new_sentence)
			return new_words

A = raw_input().split()
B = int(raw_input())
print Solution().fullJustify(A, B)
