import math

def is_cycle(graph, src, walk_nodes):
	if walk_nodes[src] == 1: return True
	stck = []
	stck.append(src)
	source_node = src
	visited = [False for i in range(n)]
	while stck:
		int_node = stck.pop()
		if visited[int_node] == True: continue
		visited[src] = True
		for i in range(0, len(graph)):
			if graph[int_node][i] == 1:
				stck.append(i)
				
if __name__ == "__main__":
	n, m = raw_input().split()
	n, m = int(n), int(m)
	graph = [[0 for i in range(n)] for j in range(n)]
	for i in range(m):
		e1, e2 = raw_input().split()
		e1, e2 = int(e1), int(e2)
		graph[e1][e2] = 1
		graph[e2][e1] = 1
	walk_nodes = [0 for i in range(n)]
	for i in range(n):
		if(is_cycle(graph, i, walk_nodes)): walk_nodes[i] = 1
	print walk_nodes


