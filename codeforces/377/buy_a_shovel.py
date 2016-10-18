k, r = map(int, raw_input().split())
result = 1
while True:
    total_cost = result * k
    reminder = total_cost % 10
    if reminder == r or reminder == 0: break
    result = result + 1
print result
