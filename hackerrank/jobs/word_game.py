'''
As the data structure is well explained, the obvious solution is trie.
But i really liked the test cases presented. Optimising the time and
space complexities at every each iteration was really fun.:)

@Author: Rohith Uppala
'''

import math
import sys
import pdb

def add_to_trie(trie, word):
    current_dict = trie
    for letter in word:
        if letter not in current_dict:
            current_dict[letter] = [0, {}]
        else:
            current_dict[letter][0] += 1
        current_dict = current_dict[letter][1]
    return trie

def get_result_from_trie(trie, word, size):
    result, size = 0, 1
    for ch in word:
        result = result + (size * trie[ch][0])
        size = size + 1
        trie = trie[ch][1]
    return result

def remove_word_from_trie(trie, word):
    current_dict = trie
    for letter in word:
        if letter in current_dict:
            current_dict[letter][0] -= 1
        current_dict = current_dict[letter][1]
    return trie

if __name__ == "__main__":
    n = int(raw_input())
    trie = {}
    for i in range(n):
        sign, word = raw_input().split()
        if sign == '+':
            trie = add_to_trie(trie, word)
            result = get_result_from_trie(trie, word, 0)
            print result
        else:
            remove_word_from_trie(trie, word)
