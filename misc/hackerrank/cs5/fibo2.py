def fibPlus((a,b),(c,d)):
    bd = b*d
    return (bd-(b-a)*(d-c), a*c+bd)
 
def unFib((a,b),n):
    if n<a:
        return (0,0,1)
    else:
        (k,c,d) = unFib(fibPlus((a,b),(a,b)),n)
        (e,f) = fibPlus((a,b),(c,d))
        if n<e:
            return (2*k, c, d)
        else:
            return (2*k+1,e,f)
 
def isfib(n):
    (k,a,b) = unFib((1,1),n)
    return n==a

t = raw_input()
t = int(t)
while t:
    n = raw_input()
    n = int(n)
    if isfib(n):
        print "IsFibo"
    else:
        print "IsNotFibo"
    t = t - 1