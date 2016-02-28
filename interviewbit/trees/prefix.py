class Solution:
    def make_words(self, words):
        root = [0, dict()]
        for word in words:
            cur_dict = root
            cur_dict[0] += 1
            for letter in word:
                cur_dict = cur_dict[1].setdefault(letter, [0, {}])
                cur_dict[0] += 1
        return root
    
    def prefix(self, A):
        trie_words = self.make_words(A)
        res = []
        for word in A:
            prefix = ""
            cur_dict = trie_words
            for char in word:
                if cur_dict[0] <= 1:
                    res.append(prefix)
                    break
                prefix = prefix + char
                cur_dict = cur_dict[1][char]
            else:
                res.append(word)
        return res

words = raw_input().split()
print Solution().prefix(words)
