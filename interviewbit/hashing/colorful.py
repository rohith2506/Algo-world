class Solution:
    def colorful(self, A):
        A = str(A)
        hash_dict = {}
        for i in range(0, len(A)):
            for j in range(i, len(A)):
                prod = 1
                for k in range(i, j+1): prod = prod * int(A[k])
                if prod not in hash_dict:
                    hash_dict[prod] = 1
                else:
                    return 0
        return 1

A = int(raw_input())
print Solution().colorful(A)
