import sys

def get_delta(numbers):
    res = []
    res.append(numbers[0])
    for i in range(1, len(numbers)):
        prev, now = numbers[i-1], numbers[i]
        diff = now - prev
        if diff > 127 or diff < -127: res.append(-128)
        res.append(diff)
    return res
    
numbers = map(int, raw_input().split())
result = get_delta(numbers)

for res in result:
    print res,
