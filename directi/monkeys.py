'''
Given a sorted array, we need to find minimum number of swaps to be the original array
ans = number + 1

But how to find minimum number of swaps?????

BFS may help????
'''

def modify(monkeys):
    res = [0 for i in range(len(monkeys))]
    for i in range(0, len(monkeys)):
        res[monkeys[i]] = monkeys[i]
    return res

def check(t1, t2):
    for i in range(len(t1)):
        if t1[i] != t2[i]: return False
    return True

def danceTime(monkeys):
    initial_state = monkeys
    print initial_state, monkeys
    monkeys = modify(monkeys)
    result = 1
    print monkeys
    while not check(initial_state, monkeys):
       result = result + 1
       monkeys = modify(monkeys)
       print monkeys
    return result

monkeys = map(int, raw_input().split())
monkeys = [num - 1 for num in monkeys]
print danceTime(monkeys)
