import pdb

t = int(raw_input())
for i in range(1, t+1):
    items = int(raw_input())
    weights = []
    for item in range(items):
        weight = int(raw_input())
        weights.append(weight)
    weights.sort()
    cnt = 0
    while weights:
        highest_weight = weights[-1]
        if len(weights) * highest_weight < 50: break
        num_of_items = (50 / highest_weight)
        if 50 % highest_weight > 0: num_of_items = num_of_items + 1
        weights = weights[num_of_items-1:len(weights) - 1]
        cnt = cnt + 1
    print "Case #%d: %d" %(i, cnt)
