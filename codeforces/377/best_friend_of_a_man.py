n, k = map(int, raw_input().split())
walks = map(int, raw_input().split())
original = []
for i in range(len(walks)): original.append(walks[i])
walks.append(k)
for i in range(0, len(walks) - 1):
    today, next_day = walks[i], walks[i+1]
    if today + next_day < k:
        walks[i+1] = walks[i+1] + (k - (today + next_day))
result = 0
for i in range(len(walks)-1):
    result = result + abs(walks[i] - original[i])
print result
for res in walks[:len(walks) -1]: print res,
