from pprint import pprint

def fix_culprit_node(cnode, tree_dict):
    child_sum_dict = {}
    for child in tree_dict.get(cnode, {}).get('child', []):
        total = fix_culprit_node(child, tree_dict)
        if total not in child_sum_dict:
            child_sum_dict[total] = {}
            child_sum_dict[total]['cnt'] = 1
            child_sum_dict[total]['nodes'] = [child]
        else:
            child_sum_dict[total]['cnt'] += 1
            child_sum_dict[total]['nodes'].append(child)
    if len(child_sum_dict.keys()) > 1:
        for k, v in child_sum_dict.items():
            if v.get('cnt') == 1:
                proper_culprit_node = v.get('nodes')[0]
                print "proper weight: ", tree_dict.get(proper_culprit_node).get('weight', 0)
    weight, total = tree_dict.get(cnode, {}).get('weight', 0), tree_dict.get(cnode, {}).get('sum', 0)
    return weight + total

def build_sum_tree(root, tree_dict):
    children = tree_dict.get(root,{}).get('child', [])
    weight = tree_dict.get(root,{}).get('weight', 0)
    for child in children:
            tree_dict[root]['sum'] += build_sum_tree(child, tree_dict)
    total = tree_dict.get(root, {}).get('sum', 0)
    return weight + total

def get_culprit_node(root, tree_dict):
    queue = []
    queue.append(root)
    while queue:
        temp = queue.pop(0)
        total = tree_dict.get(temp, {}).get('sum', 0)
        child_sum_dict = {}
        for child in tree_dict.get(temp, {}).get('child', []):
            total, weight = tree_dict.get(child, {}).get('sum', 0), tree_dict.get(child, {}).get('weight', 0)
            weight = weight + total
            if weight not in child_sum_dict:
                child_sum_dict[weight] = {}
                child_sum_dict[weight]['cnt'] = 1
                child_sum_dict[weight]['nodes'] = [child]
            else:
                child_sum_dict[weight]['cnt'] += 1
                child_sum_dict[weight]['nodes'].append(child)
            queue.append(child)
        print child_sum_dict
        if len(child_sum_dict.keys()) == 1: continue
        else:
            for k, v in child_sum_dict.items():
                if v.get('cnt') == 1:
                    culprit_node = v.get('nodes')[0]
                    return culprit_node
    return None

def is_root(tree_dict, node):
    all_nodes = {}
    for nde in tree_dict.keys():
        all_nodes[nde] = False
    stck, visited = [], {}
    stck.append(node)
    while stck:
        temp = stck.pop()
        if temp in visited: continue
        visited[temp] = True
        all_nodes[temp] = True
        for child in tree_dict.get(temp, {}).get('child', []):
            stck.append(child)
    for k, v in all_nodes.items():
        if v == False: return False
    return True

lines = open("in.txt").readlines()
tree_dict = {}
for line in lines:
    parent, children = "", []
    if "->" in line:
        parent, children = line.split("->")
        children = children.strip().split(",")
        for i in range(len(children)): children[i] = children[i].strip()
    else:
        parent = line
    root, weight = parent.strip().split()
    weight = weight.strip("(")
    weight = weight.strip(")")
    weight = int(weight)
    if root not in tree_dict:
        tree_dict[root] = {}
        tree_dict[root]['child'] = children
        tree_dict[root]['weight'] = weight
        tree_dict[root]['sum'] = 0

for node in tree_dict.keys():
    if is_root(tree_dict, node):
        root = node

print "root: ", root
build_sum_tree(root, tree_dict)
culprit_node = get_culprit_node(root, tree_dict)
print "culprit node: ", culprit_node
result = fix_culprit_node(culprit_node, tree_dict)
