# 1)Generate a random board using a dictionary set
# 2)start the timer
# 		a)type the word and check whether the word is present in board or not
# 		b)count the number of words 
# 		c)to implement a counter
# 3)End timer
# 		a)calculate the number of words and their lengths perspectively

import time
import os
import math
board = [['*' for x in xrange(MAX)] for x in xrange(MAX)] 



def gen_board():
	file f = open("dict.txt","rb")
	str = f.readlines()
	dictionary_words = []	
	dictionary_words = str.split(" ")

def welcome():
	print "###############################################################"
	print "###           Welcome to command line Ruzzle            #######"
	print "###############################################################"


def Game():
	

	
def start_play():
	welcome()
	gen_board()
	Game()	



if __name__ == '__main__'
	start_play()

