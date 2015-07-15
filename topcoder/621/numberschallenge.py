'''
The idea behind the algorithm is to sort the array and then ask the following question: 
what is the smallest positive integer you cannot make using the first k elements of the array? 
You then scan forward through the array from left to right, updating your answer to this question, 
until you find the smallest number you can't make.

Here's how it works. Initially, the smallest number you can't make is 1. Then, going from left to right, do the following:

If the current number is bigger than the smallest number you can't make so far, then you know the 
smallest number you can't make - it's the one you've got recorded, and you're done.
Otherwise, the current number is smaller than the smallest number you can't make.
 The claim is that you can indeed make this number. Right now, you know the smallest number you can't make with
 the first k elements of the array (call it candidate) and are now looking at value A[k]. 
 The number candidate - A[k] therefore must be some number that you can indeed make with the first k elements of the array
 , since otherwise candidate - A[k] would be a smaller number than the smallest number you allegedly can't make
  with the first k numbers in the array. Moreover, you can make any number in the range candidate to candidate + A[k], 
  inclusive, because you can start with any number in the range from 1 to A[k], inclusive, and then add candidate - 1 to it.
   Therefore, set candidate to candidate + A[k] and increment k.

'''
import math
MAX = 20*100000
MAX = int(MAX)

class NumbersChallenge:
	def MinNumber(self, S):
		S.sort()
		candidate = 1
		for i in range(0,len(S)):
			if S[i] > candidate: 
				return candidate
			else:
				candidate = candidate + S[i]
		return candidate

cl = NumbersChallenge()
S = raw_input().split()
for i in range(0,len(S)):
	S[i] = int(S[i])
print S
print cl.MinNumber(S)


