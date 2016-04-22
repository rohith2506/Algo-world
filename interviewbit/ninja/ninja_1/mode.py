class Solution:
    # @param A : list of integers
    # @param B : list of list of integers
    # @return a list of integers
    def getMode(self, A, B):
        number_dict = {}
        for i in range(0, len(A)):
            if A[i] not in number_dict:
                number_dict[A[i]] = 1
            else:
                number_dict[A[i]] += 1
        mode, maxi = 0, 0
        for k,v in number_dict.items():
            if v > maxi:
                maxi = v
                mode = k
        result = []
        print number_dict
        print mode
        for i in range(0, len(B)):
            index, number = B[i]
            old, new = A[index - 1], number
            A[index - 1] = number
            number_dict[old] = number_dict[old] - 1
            if new not in number_dict: number_dict[new] = 1
            else: number_dict[new] = number_dict[new] + 1
            if number_dict[old] > number_dict[new]: mode = old
            elif number_dict[old] == number_dict[new] and old <= new: mode = old
            else: mode = new
            print A
            result.append(mode)
        return result

A = map(int, raw_input().split())
n = int(raw_input())
B = []
for i in range(n):
    x, y = raw_input().split()
    x, y = int(x), int(y)
    B.append([x,y])
print Solution().getMode(A, B)
