def factorial(n):
    res = 1
    for i in range(1, n+1):
      res = res * i
    return res

n,m,c = map(int, raw_input().split())
print factorial(n+m-c-1)
