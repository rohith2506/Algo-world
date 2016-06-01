'''
Number of ways to make "n" amount
@Author: Rohith
f(n,k) = f(n-1, k) + f(n - coins[k], k)
'''

import math
coins = [1,2,5,10,20,50,100]

def num_of_ways(n):
    result = [0 for i in range(0, n+2)]
    result[0] = 1
    for i in range(0, len(coins)):
        for j in range(coins[i], n+1):
            result[j] += result[j - coins[i]]
    return result[n]

if __name__ == "__main__":
    n = int(raw_input())
    result = num_of_ways(n)
    print result
