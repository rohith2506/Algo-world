def find_reduction(inp):
    stk = []
    stk.append(inp[0])
    for i in range(1, len(inp)):
        if not stk:
            stk.append(inp[i])
        else:
            prev, present = stk.pop(), inp[i]
            if present != prev:
                stk.append(prev)
                stk.append(present)
    result = ""
    for s in stk: result = result + s
    return result

def is_not_reducible(inp):
    for i in range(0, len(inp) - 1):
        if inp[i] == inp[i+1]:
            return False
    return True

inp = raw_input()
while True:
    if is_not_reducible(inp):
        break
    else:
        inp = find_reduction(inp)
print inp
