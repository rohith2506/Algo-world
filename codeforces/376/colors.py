'''
Connected components
'''

current, maxi = 0, 0

def dfs(graph, i, visited, colors, color_map):
    global current, maxi
    visited[i] = True
    current = current + 1
    color_map[colors[i]] = color_map.get(colors[i], 0) + 1
    maxi = max(maxi, color_map[colors[i]])
    for j in graph[i]:
            if visited[j] == False:
                dfs(graph, j, visited, colors, color_map)

n,m,k = map(int, raw_input().split())
colors = map(int, raw_input().split())
graph = [[] for i in range(n)]

for i in range(m):
    l,r = map(int, raw_input().split())
    graph[l-1].append(r-1)
    graph[r-1].append(l-1)
color_map, visited, result = {}, {}, 0
for i in range(n): visited[i] = False

for i in range(0, n):
    if visited[i] == False:
        dfs(graph, i, visited, colors, color_map)
        result = result + (current - maxi)
        current, maxi = 0, 0
        color_map = {}

print result
