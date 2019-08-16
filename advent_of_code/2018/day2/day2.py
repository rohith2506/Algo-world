def find_count(val):
    letter_hash = {}
    for v in val:
        if v not in letter_hash:
            letter_hash[v] = 1
        else:
            letter_hash[v] += 1
    count_2, count_3 = 0, 0
    for k, v in letter_hash.items():
        if v == 2: count_2 = 1
        if v == 3: count_3 = 1
    return count_2, count_3

values = [line.strip() for line in open("day2.txt", "r").readlines()]

count_2, count_3 = 0, 0

for inp in values:
    x, y  = find_count(inp)
    print x, y
    count_2 += x
    count_3 += y

print count_2 * count_3
