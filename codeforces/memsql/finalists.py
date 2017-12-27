def solve(ranks):
    result = 0
    for i in range(0, len(ranks)-1):
        curr, nxt = ranks[i], ranks[i+1]
        if nxt <= 25: continue
        else: result = result + (nxt - curr)
    return result

if __name__ == "__main__":
    k = int(raw_input())
    ranks = map(int, raw_input().split())
    ranks.sort()
    result = solve(ranks)
    print result
