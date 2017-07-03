def findMax(n, tree):
    values = tree.split()
    for i in range(len(values)):
        if values[i] == '#': values[i] = 0
        values[i] = long(values[i])
    l1, l2, flag, s1, s2 = [], [], 0, 0, 0 
    if len(values) > 0:
        l1.append((0, values[0]))
    while l1 or l2:
        if flag == 0:
            while l1:
                index, value = l1.pop()
                s1 += value
                if 2 * index + 1 < len(values): l2.append((2 * index + 1, values[2 * index + 1]))
                if 2 * index + 2 < len(values): l2.append((2 * index + 2, values[2 * index + 2]))
            flag = 1
        else:
            while l2:
                index, value = l2.pop()
                s2 += value
                if 2 * index + 1 < len(values): l1.append((2 * index + 1, values[2 * index + 1])) 
                if 2 * index + 2 < len(values): l1.append((2 * index + 2, values[2 * index + 2]))
            flag = 0
    return max(s1, s2)

if __name__ == "__main__":
    n = int(raw_input())
    tree = raw_input()
    res = findMax(n, tree)
    print res