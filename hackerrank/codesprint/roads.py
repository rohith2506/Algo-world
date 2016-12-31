def make_set(vertice, parent, rank):
    parent[vertice] = vertice
    rank[vertice] = 0

def find(vertice, parent):
    if parent[vertice] != vertice:
        parent[vertice] = find(parent[vertice], parent)
    return parent[vertice]

def union(vertice1, vertice2, parent, rank):
    root1 = find(vertice1, parent)
    root2 = find(vertice2, parent)
    if root1 != root2:
        if rank[root1] > rank[root2]:
            parent[root2] = root1
        else:
            parent[root1] = root2
            if rank[root1] == rank[root2]: rank[root2] += 1

def kruskal(graph):
    parent, rank = dict(), dict()
    for vertice in graph['vertices']:
        make_set(vertice, parent, rank)
    minimum_spanning_tree = set()
    edges = list(graph['edges'])
    edges.sort()
    for edge in edges:
        weight, vertice1, vertice2 = edge
        if find(vertice1, parent) != find(vertice2, parent):
            union(vertice1, vertice2, parent, rank)
            minimum_spanning_tree.add(edge)
    return minimum_spanning_tree

def find_root(arr, i):
    while arr[i] != i:
        arr[i] = arr[arr[i]]
        i = arr[i]
    return i

def connected_components(min_graph, n):
    root, count = [i for i in range(n+1)], n
    for weight, u, v in min_graph:
        xr = find_root(root, u)
        yr = find_root(root, v)
        if xr != yr:
            count = count - 1
            root[xr] = yr
    return count

queries = int(raw_input())
for i in range(queries):
    n, m, clib, croad = map(int, raw_input().split())
    graph = {}
    graph['vertices'] = [i+1 for i in range(n)]
    edges = []
    for j in range(m):
        u, v = map(int, raw_input().split())
        edges.append((croad, u, v))
    graph['edges'] = set(edges)
    min_graph = kruskal(graph)
    count = connected_components(min_graph, n)
    s1 = (clib * count) + (croad * len(min_graph))
    s2 = n * clib
    result = min(s1, s2)
    print result