
lines = open("in.txt").readlines()
reg_dict, maxi = {}, 0
for line in lines:
    words = line.strip().split()
    reg, op, val, blah, reg2, cond, val2 = words
    if reg not in reg_dict:
        reg_dict[reg] = 0
    if reg2 not in reg_dict:
        reg_dict[reg2] = 0
    val, val2 = int(val), int(val2)
    if cond == ">":
        if op == "inc":
            if reg_dict[reg2] > val2:
                reg_dict[reg] = reg_dict[reg] + val
        else:
            if reg_dict[reg2] > val2:
                reg_dict[reg] = reg_dict[reg] - val
    elif cond == "<":
        if op == "inc":
            if reg_dict[reg2] < val2:
                reg_dict[reg] += val
        else:
            if reg_dict[reg2] < val2:
                reg_dict[reg] -= val
    elif cond == ">=":
        if op == "inc":
            if reg_dict[reg2] >= val2:
                reg_dict[reg] += val
        else:
            if reg_dict[reg2] >= val2:
                reg_dict[reg] -= val
    elif cond == "<=":
        if op == "inc":
            if reg_dict[reg2] <= val2:
                reg_dict[reg] += val
        else:
            if reg_dict[reg2] <= val2:
                reg_dict[reg] -= val
    elif cond == "==":
        if op == "inc":
            if reg_dict[reg2] == val2:
                reg_dict[reg] += val
        else:
            if reg_dict[reg2] == val2:
                reg_dict[reg] -= val
    elif cond == "!=":
        if op == "inc":
            if reg_dict[reg2] != val2:
                reg_dict[reg] += val
        else:
            if reg_dict[reg2] != val2:
                reg_dict[reg] -= val
    maxi = max(maxi, max(reg_dict.values()))

print maxi
