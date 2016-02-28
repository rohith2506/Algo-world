class Solution:
    def convert(self, binary):
        num, index = 0, 0
        for i in range(len(binary) - 1, -1, -1):
            if binary[i] == '1': num = num + pow(2, index)
            index = index + 1 
        return num

    def grayCode(self, A):
        A = 1 << A
        result = []
        for x in range(A):
            binary = bin(A+x^x/2)[3:]
            result.append(self.convert(binary))
        return result

n = int(raw_input())
print Solution().grayCode(n)
