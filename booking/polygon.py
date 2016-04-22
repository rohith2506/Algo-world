import sys

def count(a,b,c,d):
    x, y, z = 0, 0, 0
    if a == b and b == c and c == d and a > 0 and b > 0 and c > 0 and d > 0: x = x + 1
    elif a == c and b == d and a > 0 and b > 0 and c > 0 and d > 0: y = y + 1
    else: z = z + 1
    return x,y,z

tx, ty, tz = 0, 0, 0
while True:
    data = sys.stdin.readline()
    if data == '': break
    a,b,c,d = map(int,data.split())
    x,y,z = count(a,b,c,d)
    tx = tx + x
    ty = ty + y
    tz = tz + z    

print tx, ty, tz    
