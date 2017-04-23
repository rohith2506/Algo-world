import math

INF = int(10e10)

def solve(horses, d):
    maximum = 0
    for horse in horses:
        k, s = horse
        maximum = max(maximum, ((d - k) * 1.0 / s))
    return d / maximum

if __name__ == "__main__":
    t = int(raw_input())
    for tst in range(1, t+1):
        d, n = map(int, raw_input().split())
        horses = []
        for j in range(n):
            k, s = map(int, raw_input().split())
            horses.append((k, s))
        result = solve(horses, d)
        print "Case #%d: %f" %(tst, result)
