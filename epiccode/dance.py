import math, re

N,K = raw_input().split()
N,K = int(N), int(K)

boys  = raw_input().split()
girls = raw_input().split()

for i in range(0, len(boys)):
    boys[i]  = int(boys[i])
    girls[i] = int(girls[i])

boys.sort()
girls.sort()

l1, l2 = [], []

if(boys[N-1] < girls[N-1]):
    l1 = boys
    l2 = girls
else:
    l1 = girls
    l2 = boys

j = N-1
result = 0
for i in range(N-1, -1, -1):
    number = l1[i]
    flag = 0
    while j >= 0:
        if abs(number - l2[j]) <= K:
            flag = 1
            j = j - 1
            break
        else:
            j = j - 1
    if flag:
        result = result + 1

print result
