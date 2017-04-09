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

def solve(tree, k):
    value, result = tree[k-1]
    return result

def build_tree(n):
    tree = []
    que = Queue()
    if n%2 == 0:
        que.enqueue((n, (n/2-1, n/2)))
    else:
        que.enqueue((n, (n/2, n/2)))
    while not que.isEmpty():
        value, result = que.dequeue()
        tree.append((value, result))
        for num in result:
            if num <= 0: continue
            if num % 2 == 0:
                que.enqueue((num, (num/2-1, num/2)))
            else:
                que.enqueue((num, (num/2, num/2)))
    return tree

if __name__ == "__main__":
    test = int(raw_input())
    for t in range(1, test+1):
        n, k = map(int, raw_input().split())
        tree = build_tree(n)
        result = solve(tree, k)
        print "Case #%d: %d %d" %(t, max(result), min(result))
