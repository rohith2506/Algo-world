'''
Find the number of words in a string
@Author: Rohit
'''

def CountNumberOfWords(string):
	list_of_words = string.split()
	return len(list_of_words)

if __name__ == "__main__":
	string = raw_input()
	print CountNumberOfWords(string)
