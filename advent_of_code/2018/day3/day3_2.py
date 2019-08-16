values = [line.strip() for line in open("day3.txt", "r").readlines()]

fabric = [[None for i in range(1000)] for i in range(1000)]

def fill_fabric(y1, x1, y2, x2, elm_id):
    for i in range(x1, x1 + x2):
        for j in range(y1, y1 + y2):
            if not fabric[i][j]: fabric[i][j] = elm_id
            else: fabric[i][j] = 'X'
    return fabric

def contains_overlap(y1, x1, y2, x2):
    for i in range(x1, x1 + x2):
        for j in range(y1, y1 + y2):
            if fabric[i][j] == 'X': return False
    return True

elm_ids = {}
for value in values:
    first, second = value.split(':')
    elm_id, delimiter, position = first.split()
    elm_id = elm_id.strip().split('#')[1]
    width, height = second.strip().split('x')
    a, b = position.strip().split(',')
    fabric = fill_fabric(int(a), int(b), int(width), int(height), elm_id)
    elm_ids[elm_id] = (int(a), int(b), int(width), int(height))

for elm_id, elm_claim in elm_ids.items():
    a, b, width, height = elm_claim
    if contains_overlap(a, b, width, height):
        print elm_id
