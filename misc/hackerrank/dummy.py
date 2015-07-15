import os
def r(a):
  i = a.find('0')
  if i==-1:
    for i in range(0,len(a)):
      if i%9==0 and i!=0:
        print 
      print a[i],
  for m in '3814697265625':
    o=True
    for j in range(81):
      if (i-j)%9==0 or (i/9==j/9) or (i/27==j/27 and i%9/3==j%9/3):
        if a[j]==m:
          o=False
          break
    if o:
      r(a[:i]+m+a[i+1:])
n = input()
for i in range(n):
    board = []
    a=""
    for j in range(9):
      x=raw_input().split()
      for p in x:
        a=a+p
    if r(a): pass

