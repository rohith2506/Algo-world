from itertools import cycle
lst = []
alphabets = "abcdefghijklmnopqrstuvwxyz"
for s in alphabets: lst.append(s) 

def distance(a, b):
    pool, flag, dist = cycle(lst), 0, 0
    for item in pool:
        if flag == 1: dist = dist + 1
        if item == a: flag = 1
        if flag == 1 and item == b: break
    pool, flag2, dist2 = cycle(lst), 0, 0
    for item in pool:
        if flag2 == 1: dist2 = dist2 + 1
        if item == b: flag2 = 1
        if flag2 == 1 and item == a: break
    return min(dist, dist2)


inp = raw_input()
dist = 0
inp = "a" + inp
for i in range(0, len(inp) - 1):
    a, b = inp[i], inp[i+1]
    dist = dist + distance(a, b)
print dist
