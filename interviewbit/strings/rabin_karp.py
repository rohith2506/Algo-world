import math
MOD = 101

def calc_hash(inp):
    value = 0
    cnt = len(inp) - 1
    for i in range(len(inp)):
        value = value + (pow(MOD, cnt) * ord(inp[i]))
        cnt = cnt - 1
    return value

def is_substring(s1, s2):
    h1, h2 = calc_hash(s1[:len(s2)]), calc_hash(s2)
    print h1, h2
    if h1 == h2: return True
    for i in range(len(s2), len(s1)):
        prev_index = i - len(s2)
        h1 = (MOD * (h1 - (ord(s1[prev_index]) * pow(MOD, len(s2) - 1)))) + ord(s1[i])
        print h1, h2
        if h1 == h2: return True
    return False

s1, s2 = raw_input().split()
print is_substring(s1, s2)
