class Solution:
    def isPalindrome(self, A):
	    B = ""
	    for i in range(len(A)):
	        if (ord(A[i]) >= 65 and ord(A[i]) <= 90) or (ord(A[i]) >= 48 and ord(A[i]) <= 57) or \
	        											(ord(A[i]) >= 97 and ord(A[i]) <= 122):
	            B += A[i]
	    B = B.lower()
	    if B == B[::-1]: return True
	    else: return False

A = raw_input()
print Solution().isPalindrome(A)