def max_possible_string(inp, i1, i2):
    temp = ""
    for i in inp:
        if i == i1 or i == i2: temp = temp + i
    for i in range(0, len(temp) - 1):
        if temp[i] == temp[i+1]:
            return 0
    return len(temp)

length = int(raw_input())
inp = raw_input()
chars, result = "abcdefghijklmnopqrstuvwxyz", 0
for i in range(0, len(chars)):
    for j in range(0, len(chars)):
        if i == j: continue
        result = max(result, max_possible_string(inp, chars[i], chars[j]))
if len(inp) == 1:
    print 1
else:
    print result
