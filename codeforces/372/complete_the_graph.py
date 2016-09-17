import heapq
INF = int(10e18)

def dijsktra(graph, start, end):
    dist = []
    for i in range(len(graph)):
        dist.append({'dist': INF, 'unknown': []})
    visited = [False for i in range(len(graph))]
    dist[start]['dist'] = 0
    q = [(0, start)]
    heapq.heapify(q)
    while len(q):
        distance, u = heapq.heappop(q)
        visited[u] = True
        for v in range(0, len(graph[u])):
            if graph[u][v] != -1 and visited[v] == False and distance + graph[u][v] < dist[v]['dist']:
                if graph[u][v] == 0:
                    for temp in range(len(dist[u]['unknown'])): 
                        dist[v]['unknown'].append(temp)
                    dist[v]['unknown'].append((u,v))
                dist[v]['dist'] = distance + graph[u][v]
                heapq.heappush(q, (dist[v]['dist'], v))
    return dist

n,m,length,start,end = map(int, raw_input().split())
edges = {}
graph = [[-1 for i in range(n)]  for j in range(n)]
for i in range(n):
    x,y,distance = map(int, raw_input().split())
    edges[str(x) + "_" + str(y)] = False
    graph[x][y] = graph[y][x] = distance
print graph

distances = dijsktra(graph, start, end)
remaining = length - distances[end]['dist']
if remaining < 0:
    print "NO"
else:
    unknown_nodes = distances[end]['unknown']
    for i in range(0, len(unknown_nodes) - 1):
        print "i am here"
        u, v = unknown_nodes[i]
        if str(u) + "_" + str(v) in edges:
            graph[u][v] = 1
            edges[str(u) + "_" + str(v)] = True
            remaining = remaining - 1
    if str(unknown_nodes[len(unknown_nodes) - 1][0]) + "_" + str(unknown_nodes[len(unknown_nodes) - 1][1]) in edges:
        graph[unknown_nodes[len(unknown_nodes) - 1][0]][unknown_nodes[len(unknown_nodes) - 1][1]] = remaining
        edges[str(unknown_nodes[len(unknown_nodes) - 1][0]) + "_" + str(unknown_nodes[len(unknown_nodes) - 1][1])] = True
    for i in range(0, len(distances)):
        unknown_nodes = distances[i]['unknown']
        for i in range(len(unknown_nodes)):
            u, v = unknown_nodes[i]
            if str(u) + "_" + str(v) in edges:
                edges[str(u) + "_" + str(v)] = length - remaining + 1
    for value in edges:
        u,v = value.split("_")
        u,v = int(u), int(v)
        print u,v,graph[u][v]
