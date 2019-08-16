def solve(path):
    result = ""
    for i in range(len(path)):
        if path[i] == 'E': result += 'S'
        else: result += 'E'
    return result

if __name__ == "__main__":
    t = int(raw_input())
    for i in range(1, t+1):
        n = int(raw_input())
        path = raw_input()
        result = solve(path)
        print "Case #%d: %s" %(i, result)
