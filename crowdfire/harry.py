MAX = 1000001
MINI = -1000000001

def find_solution(n, attacks):
    dp = []
    dp.append(0)
    dp.append(max(attacks[1], 0))
    for i in range(2, n+1):
        dp.append(max(attacks[i] + dp[i-2], dp[i-1]))
    result = dp[n]
    if result <= 0: return "DANGER"
    else: return result

t = int(raw_input())
while t:
    n = int(raw_input())
    attacks = []
    attacks.append(0)
    inp = map(long, raw_input().split())
    for i in inp: attacks.append(i)
    print find_solution(n, attacks)
    t = t - 1    
