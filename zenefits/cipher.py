'''
pretty straight forward problem.
Run through all shift sizes and make comparisons and find minimum change
@Author: Rohith
'''

import math
alphabet = ["a", "b", "c", "d", "e", "f", "g", \
            "h", "i", "j", "k", "l", "m", "n", \
            "o", "p", "q", "r", "s", "t", "u", \
            "v", "w", "x", "y", "z"]

def minimum_change(p, e_dash):
    global_mismatch = len(p)
    for shift_length in range(0, 26):
        e = ""
        for i in range(0, len(p)):
            x_pos = alphabet.index(p[i])
            x_pos = (x_pos + shift_length) % 26
            e += alphabet[x_pos]
        local_mismatch = sum(c1 != c2 for c1, c2 in zip(e, e_dash))
        if local_mismatch < global_mismatch:
            global_mismatch = local_mismatch
    return global_mismatch

if __name__ == "__main__":
    test_cases = int(raw_input())
    while test_cases:
        p, e_dash = raw_input().split()
        result = minimum_change(p, e_dash)
        print result
        test_cases -= 1
