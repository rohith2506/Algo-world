'''
Time limit exceeded
Need to write c++ implmenetation of this code
'''

import sys
from collections import deque

def power(a, b):
    if b == 0: return 1
    elif b == 1: return a
    elif b % 2 == 0: return power(a * a, b / 2)
    else: return b * power(a * a, (b - 1) / 2)

def getMagicNumber(s, k, b, m):
    q, total, result = deque([]), 0, 0
    for i in range(0, k):
        value = int(s[i]) * power(b, k - i - 1)
        q.append(int(s[i]))
        result = result + value
    sindex = k
    while sindex < len(s):
        total = total + (result % m)
        last_val = q.popleft()
        result = result - (last_val * power(b, k-1))
        result = result * b
        result = result + int(s[sindex])
        q.append(int(s[sindex]))
        sindex = sindex + 1
    total = total + (result % m)
    return total

s = raw_input().strip()
k, b, m = raw_input().strip().split(' ')
k, b, m = int(k), int(b), int(m)
result = getMagicNumber(s, k, b, m)
print result
