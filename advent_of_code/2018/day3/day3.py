values = [line.strip() for line in open("day3.txt", "r").readlines()]

fabric = [[0 for i in range(1000)] for i in range(1000)]

def fill_fabric(y1, x1, y2, x2):
    for i in range(x1, x1 + x2):
        for j in range(y1, y1 + y2):
            fabric[i][j] += 1
    return fabric

for value in values:
    first, second = value.split(':')
    elm_id, delimiter, position = first.split()
    width, height = second.strip().split('x')
    a, b = position.strip().split(',')
    fabric = fill_fabric(int(a), int(b), int(width), int(height))

result = 0
for i in range(len(fabric)):
    for j in range(len(fabric[i])):
        if fabric[i][j] >= 2: result += 1

for i in range(len(fabric)):
    for j in range(len(fabric[i])):
        print fabric[i][j],
    print

print result
