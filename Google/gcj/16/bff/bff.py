'''
The question is ambiguous
'''

res = []
def dfs(graph, src, cnt, visited):
	if visited[src] == True:
		res.append(cnt)
		return 
	print src
	visited[src] = True
	for i in range(0, len(graph[src])):
		if graph[src][i] == 1:
			dfs(graph, i, cnt+1, visited)
	
if __name__ == "__main__":
	t = int(raw_input())
	for tst in range(1, t+1):
		n = int(raw_input())
		bffs = map(int, raw_input().split())
		graph = [[0 for i in range(n)] for j in range(n)]
		for i in range(0, len(bffs)):
			src, dest = i, bffs[i] - 1
			graph[src][dest] = 1
		print graph
		result = 0
		for node in range(n):
			visited, res = [False for i in range(n)], []
			dfs(graph, node, 0, visited)
			print res
			result = max(result, max(res))
		print "Case #%d: %d" %(tst, result)
