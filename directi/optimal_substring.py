def find_sol(string):
    index = 0
    while index < len(string):
        if string[index] == 'b':
            break
        index = index + 1
    if index == len(string): return [0, 0]
    val, a_count, end = -index, 0, index
    for j in range(index+1, len(string)):
        if string[j] == 'a':
            a_count = a_count + 1
        else:
            a_count = a_count - 1
        if a_count > val:
            val = a_count
            end = j
    if end == index: return [0, 0]
    else:  return [index, end]

if __name__ == "__main__":
    t = int(raw_input())
    while t:
        string = raw_input()
        res = find_sol(string)
        print str(res[0]) + "," + str(res[1])
        t = t - 1