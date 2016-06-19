/*
Given a list of vertices, we need to find the vertices where d[v,u] > w[u]
Now, when iterating through path, find the bas vertices using dfs and do the children count too.
Now, do a simple bfs, find the number of bad children and return the count
*/

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;

ll a[100001];

map< pair<int, int>, ll > w;
vector<int> adj[100001];
bool bad[100001];
bool visited[100001];
bool visited_bfs[100001];
ll  mdist[100001];
ll  children[100001];

ll dfs(int v) {
	if (visited[v]) return 0;
	visited[v] = true;
	int cnt = 1;
	for (int adj_v : adj[v]) {
		if (!visited[adj_v]) {
			mdist[adj_v] = max(mdist[v] + w[{v, adj_v}], 0ll);
			if (mdist[v] + w[{v, adj_v}] > a[adj_v]) bad[adj_v] = true;
			cnt += dfs(adj_v);
		}
	}
	children[v] = cnt;
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 2; i <= n; i++) {
		int p, c;
		cin >> p >> c;
		w[{i, p}] = w[{p, i}] = c;
		adj[i].push_back(p);
		adj[p].push_back(i);
	}
	dfs(1);
	queue<int> q;
	q.push(1);
	int total = 0;
	while (!q.empty()) {
		int v = q.front();
		visited_bfs[v] = true;
		q.pop();
		if (bad[v]) {
			total += children[v];
			continue;
		}
		for (auto adj_v : adj[v])
			if (!visited_bfs[adj_v]) {
				q.push(adj_v);
			}
	}
	cout << total << endl;
}
