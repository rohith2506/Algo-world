class Solution:
    # @return an integer
    def lengthOfLongestSubstring(self, s):
        prev_length = 0
        max_len = 0
        char_dict = {}
        for i,c in enumerate(s):
            if c in char_dict.keys() and (i - char_dict[c] <= prev_length):
                prev_length = (i - char_dict[c])
            else:
                prev_length = prev_length + 1
                if prev_length > max_len:
                    max_len = prev_length
            char_dict[c] = i
        return max_len