class Solution:
    def dNums(self, A, B):
        slide_dict = {}
        cnt = 0
        res = []
        for i in range(B):
            if A[i] not in slide_dict:
                slide_dict[A[i]] = 1
            else:
                slide_dict[A[i]] += 1
            if slide_dict[A[i]] == 1:
                cnt = cnt + 1
        res.append(cnt)
        for i in range(B, len(A)):
            prev_val = A[i - B]
            if slide_dict[prev_val] <= 1:
                cnt = cnt - 1
            slide_dict[prev_val] -= 1
            if A[i] not in slide_dict:
                slide_dict[A[i]] = 1
            else:
                slide_dict[A[i]] += 1
            if slide_dict[A[i]] == 1:
                cnt = cnt + 1
            res.append(cnt)
        return res

A = raw_input().split()
for i in range(len(A)): A[i] = int(A[i])
B = int(raw_input())
print Solution().dNums(A, B)
