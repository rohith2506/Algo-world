def max_length(words):
    maxi = 0
    for word, length in words:
        maxi = max(length, maxi)
    return maxi

def longest_chain(words):
    words.sort(key=len)
    word_dict, chain_dict, res = {}, {}, 0
    for word in words: word_dict[word] = None
    for word in words:
        chain_dict[word] = []
        for i in range(len(word)):
            new_word = word[0:i] + word[i+1:len(word)]
            if new_word in word_dict: 
                length = max_length(chain_dict[new_word])
                chain_dict[word].append([new_word, length+1])
    for k,v in chain_dict.items():
        for word, length in v:
            res = max(length, res)        
    return res + 1

words = raw_input().split()
print longest_chain(words)
