import math
import time
import pdb

pascal = []

def build_pascal_triangle():
    MAX = 20001
    global pascal
    pascal = [[0 for i in range(MAX)] for j in range(MAX)]
    pascal[0][0] = 1
    for i in range(1, MAX):
        for j in range(0, i+1):
            pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j]

def get_prob_dice(n, k, p, s):
    return math.pow(-1, k) * pascal[n][k] * pascal[(p - (s*k) - 1)][(p - (s*k) - n)]

def get_prob(n, s, total):
    result = 0
    for p in range(0, total):
        kmax, temp = (p-n)/s, 0
        for k in range(0, kmax+1):
            temp = temp + get_prob_dice(n, k, p, s)
        result = result + temp
    return result * 1.0 / math.pow(s, n)

stime = time.time()
build_pascal_triangle()
print "total seconds: ", time.time() - stime
t = int(raw_input())
for i in range(1, t+1):
    h, s = map(int, raw_input().split())
    dices = raw_input().split()
    res = 0.0
    for dice in dices:
        x, y, z, flag = -1, -1, 0, 0
        x, y = dice.split('d')
        x = int(x)
        if '+' in y:
            y, z = y.split('+')
            y, z = int(y), int(z)
            flag = 1
        elif '-' in y:
            y, z = y.split('-')
            y, z = int(y), int(z)
            flag = -1
        else:
            y = int(y)
        dice_sum = h - (flag * z)
        prob = get_prob(x, y, dice_sum)
        res = max(res, 1 - prob)
    print "Case #%d: %.6f"  %(i, res)
