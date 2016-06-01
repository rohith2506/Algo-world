'''
Generate primes until limit and try to iterate based on it.
@Author: Rohith
'''

import math

def primes_upto(limit):
    is_prime = [False] * 2 + [True] * (limit - 1) 
    for n in range(int(limit**0.5 + 1.5)):
        if is_prime[n]:
            for i in range(n*n, limit+1, n):
                is_prime[i] = False
    return [i for i, prime in enumerate(is_prime) if prime]

if __name__ == "__main__":
    limit = int(raw_input())
    arr = raw_input().split()
    arr = [int(num) for num in arr]
    primes = primes_upto(limit+5)
    result = 0
    for prime in primes:
        for i in range(0, len(arr)):
            if (i - prime) >= 0:
                result += arr[i] - arr[i - prime]
    print result