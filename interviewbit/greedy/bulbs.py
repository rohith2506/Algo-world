class Solution:
    def bulbs(self, A):
        cnt, state = 0, 0
        for i in range(0, len(A)):
            if A[i] == state:
                cnt = cnt + 1
                state = 1 - state
        return cnt

A = map(int, raw_input().split())
print Solution().bulbs(A)
