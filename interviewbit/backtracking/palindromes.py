class Solution:
    def is_palindrome(self, string):
        return string == string[::-1]

    def find_sol(self, string):
        if len(string) == 0:
            return [[]]
        else:
            result = []
            for j in range(len(string)):
                first, last = string[:j+1], string[j+1:]
                if self.is_palindrome(first):
                    for l in self.find_sol(last):
                        result.append([first] + l)
            return result       

    def partition(self, A):
        return self.find_sol(A)

A = raw_input()
print Solution().partition(A)
