numbs = {'2':'abc', '3':'def', '4':'ghi', '5':'jkl', '6':'mno', '7':'pqrs', '8':'tuv', '9':'wxyz', '0': '0', '1': '1'}

class Solution:
    def combo(self, phnum):
        if len(phnum) == 1: return list(numbs[phnum[0]])
        else: result = self.combo(phnum[:-1])
        return [(ch1+ch2) for ch1 in result for ch2 in numbs[phnum[-1]]]

phnum = raw_input()
print Solution().combo(phnum)
