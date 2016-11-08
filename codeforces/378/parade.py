cols = int(raw_input())
lefts, rights = [], []
for col in range(cols):
    l, r = map(int, raw_input().split())
    lefts.append(l)
    rights.append(r)
result = []
for l, r in zip(lefts, rights):
    result.append(l - r)
maxi, max_index, mini, min_index = 0, -1, 1001, -1
for i in range(0, len(result)):
    if result[i] > maxi:
        maxi = result[i]
        max_index = i
for i in range(0, len(result)):
    if result[i] < mini:
        mini = result[i]
        min_index = i
total_sum = sum(result)
r1 = abs((total_sum - maxi) + (-maxi))
r2 = abs((total_sum - mini) + (-mini))
if max(r1, r2) == total_sum:
    print 0
else:
    if r1 > r2:
        print max_index + 1
    else:
        print min_index + 1
