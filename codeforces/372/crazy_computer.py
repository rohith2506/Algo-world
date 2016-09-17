n, c = map(int, raw_input().split())
delays = map(int, raw_input().split())
prev, cnt = delays[0], 1
for i in range(1, len(delays)):
    present = delays[i]
    if present - prev > c:
        cnt = 1
    else:
        cnt = cnt + 1
    prev = present
print cnt
