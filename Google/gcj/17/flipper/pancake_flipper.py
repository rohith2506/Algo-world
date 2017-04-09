import pdb

class Queue:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def enqueue(self, item):
        self.items.insert(0,item)

    def dequeue(self):
        return self.items.pop()

    def size(self):
        return len(self.items)

    def get(self):
        return self.items

def find_flips(pancakes):
    indices = []
    for i in range(0, len(pancakes)):
        if pancakes[i] == '-': indices.append(i)
    return indices

def no_more_flips(pancakes):
    for i in range(0, len(pancakes)):
        if pancakes[i] == '-': return False
    return True

def is_again_same_thing(pancakes, res):
    res1 = ''.join(pancakes)
    if res1 == res: return True
    return False

def flip_pancakes(pancakes, pos):
    for value in pos:
        if value < 0 or value >= len(pancakes): return pancakes
    new_pancakes = []
    for i in range(0, len(pancakes)):
        if i not in pos: new_pancakes.append(pancakes[i])
        else:
            if pancakes[i] == '+': new_pancakes.append('-')
            else: new_pancakes.append('+')
    return new_pancakes

def get_positions(index, window):
	positions = []
	sindex = index - (window - 1)
	for win in range(0, window):
		positions.append([i for i in range(sindex, sindex+window)])
		sindex = sindex + 1
	return positions

def solve(pancakes, result, window):
	que = Queue()
	que.enqueue((pancakes, 0, []))
	visited = {}
        while not que.isEmpty():
		temp, steps, pos = que.dequeue()
                if visited.get(''.join(temp), False): continue
		if no_more_flips(temp): return steps
		flips = find_flips(temp)
		for flip in flips:
			positions = get_positions(flip, window)
			for pos in positions:
				changed_pancakes = flip_pancakes(temp, pos)
				if is_again_same_thing(changed_pancakes, result): continue
				que.enqueue((changed_pancakes, steps+1, pos))
                visited[''.join(temp)] = True
        return -1

if __name__ == "__main__":
    testcases = int(raw_input())
    for t in range(1, testcases+1):
        pancakes, window = raw_input().split()
        pancakes, window = list(pancakes), int(window)
        result = solve(pancakes, ''.join(pancakes), window)
        if result != -1:
        	print "Case #%d: %d" %(t, result)
        else:
        	print "Case #%d: %s" %(t, "IMPOSSIBLE")
