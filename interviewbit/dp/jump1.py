class Solution:
    def canJump(self, A):
        maxi = 0
        for i in range(len(A)):
            if maxi >= len(A) - 1: return True
            maxi = max(i + A[i], maxi)
        return False

A = raw_input().split()
for i in range(len(A)): A[i] = int(A[i])
print Solution().canJump(A)             
