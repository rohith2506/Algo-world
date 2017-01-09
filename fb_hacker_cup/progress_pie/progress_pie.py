import math

def is_inside(a1, x, y):
    radius = math.sqrt(((x - 50) * (x - 50)) + ((y - 50) * (y - 50)))
    x = math.atan2(y - 50 , x - 50)
    arcangle = 180 * x / math.pi
    if arcangle < 0: arcangle = arcangle + 360.0
    if arcangle >= 0 and arcangle <= a1 and radius >= 0 and radius <= 50:
        return True
    else:
        return False

t = int(raw_input())
for i in range(1, t+1):
    p, x, y = map(int, raw_input().split())
    angle = (90.0 / 25) * p
    if is_inside(angle, x, y):
        print "Case #%d: black" %(i)
    else:
        print "Case #%d: white" %(i) 
