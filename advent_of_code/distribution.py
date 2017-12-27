def get_highest_index(numbers):
    idx, maxi = 0, 0
    for i in range(len(numbers)):
        if numbers[i] > maxi:
            maxi = max(numbers[i], maxi)
            idx = i
    return idx

def update_data(numbers, val, sindex):
    while True:
        if sindex >= len(numbers): sindex = 0
        numbers[sindex] = numbers[sindex] + 1
        val = val - 1
        if val == 0: break
        sindex = sindex + 1
    return numbers

def solve(numbers):
    step, visited_dict, result = 0, {}, 0
    while True:
        highest_index = get_highest_index(numbers)
        blocks = numbers[highest_index]
        numbers[highest_index] = numbers[highest_index] - blocks
        numbers = update_data(numbers, blocks, highest_index+1)
        step = step + 1
        visited = ''.join(str(numbers))
        if visited not in visited_dict:
            visited_dict[visited] = step
        else:
            ifFound = 1
            result = step - visited_dict.get(visited)
            break
    return result

lines = open("in.txt").readlines()
numbers = map(int, lines[0].strip().split())

result = solve(numbers)
print result
