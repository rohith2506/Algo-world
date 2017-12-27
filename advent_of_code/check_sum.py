def solve(values):
    total2 = 0
    for i in range(0, len(values)):
        temp = values[i]
        print temp
        for j in range(0, len(temp)):
            for k in range(j+1, len(temp)):
                if(temp[k] % temp[j] == 0 or temp[j] % temp[k] == 0):
                    if temp[k] % temp[j] == 0: total2 = total2 + (temp[k] / temp[j])
                    else: total2 = total2 + (temp[j] / temp[k])
    return total2

ifile = open("in.txt", "r")
lines = ifile.readlines()
total = 0
result = []
for line in lines:
    values = line.strip().split()
    values = [int(value) for value in values]
    result.append(values)
    total = total + max(values) - min(values)
total2 = solve(result)
print "Total: ", total
print "Total 2: ", total2
