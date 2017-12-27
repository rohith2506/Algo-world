if __name__ == "__main__":
    t = int(raw_input())
    for test in range(t):
        n = int(raw_input())
        houses = map(int, raw_input().split())
        houses.sort()
        res = 0
        for i in range(0, len(houses)-1):
            res = res + (houses[i+1] - houses[i])
        print res
