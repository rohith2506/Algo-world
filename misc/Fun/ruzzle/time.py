import time
import math
words = []
	
def convert_and_print(tm):
	minutes = tm/60
	seconds = tm%60
	print "Count Down" ,minutes,":",seconds

def timer():
	start_time = time.time()
	end_time = start_time + 120
	while int(end_time-start_time)>=0:
		convert_and_print(int(end_time - start_time))
		print "Enter a word"
		s = raw_input()
		words.append(s)	
		start_time = time.time()
	
	print "Count Down ends"
	print "Number of words",len(words)
	
if __name__ == "__main__":
	timer()
