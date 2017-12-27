lines = open("in.txt").readlines()
cnt = 0
for line in lines:
    words = line.strip().split()
    word_dict, is_valid = {}, True
    for word in words:
        word = ''.join(sorted(word))
        if word not in word_dict: word_dict[word] = 1
        else: word_dict[word] += 1
    for k, v in word_dict.items():
        if v > 1:
            is_valid = False
    if is_valid: cnt = cnt + 1
print cnt
