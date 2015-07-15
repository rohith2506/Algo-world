import math
import os
num = 100000000
dct = {}

for i in range(1,num):
    dct[str(i)]=0

def go(num):
    if dct[num]!=0:
        return dct[num]
    else:
        num = int(num)
        Sum = 0
        while(num!=0):
            b = num%10
            Sum = Sum + (b*b)
            num = num/10
        if Sum == 1 or Sum == 89:
            dct[num] = Sum
            return Sum
        Sum = str(Sum)
        if len(Sum) == 1:
            dct[num] = int(Sum)
            return int(Sum)
        else:
            return go(Sum)
        
cnt = 0
for i in range(1,num):
    i = str(i)
    res = go(i)
    if res == 1 or res == 89:
        cnt = cnt + 1
for k,v in dct.items():
    print k,dct[k]
print cnt
