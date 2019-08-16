def find_diff(num):
    diff = ""
    for i in range(len(num)):
        if num[i] == '4':
            diff += '3'
        else:
            diff += num[i]
    return int(diff)

def solve(num):
    diff = find_diff(str(num))
    a = num - diff
    b = diff
    return a, b

t = int(raw_input())
for i in range(1, t+1):
    n = int(raw_input())
    a, b = solve(n)
    print "Case #%d: %d %d" %(i, a, b)

