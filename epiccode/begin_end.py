import math, re

N = int(raw_input())
text = raw_input()

result = N
hash_table = [0 for i in range(0, 26)]

for i in range(0, len(text)):
    hash_table[ord(text[i]) - 97] = hash_table[ord(text[i]) - 97] + 1

for i in range(0, len(hash_table)):
    temp = hash_table[i]
    result = result + ((temp * (temp - 1)) / 2)

print result
