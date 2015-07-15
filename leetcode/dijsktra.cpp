#include "headers.h"

#define MAX 10001
#define pii pair<int, int>

struct comp{
	bool operator() (const pii &a, const pii &b){
		return a.second > b.second;
	}
};

priority_queue<pii, vector<pii> , comp> Q;   // use this for ascending comparison
vector<pii> G[MAX];  //This is the most default representation for graphs (adjacency list)
vector<int> dist(MAX,INF);
vector<bool> visited(MAX,false);

int main(){
	int nodes,edges;
	cin >> nodes >> edges;
	for(int i=0; i<edges; i++){
		int u,v,w;
		cin >> u >> v >> w;
		G[u].pb(pii(v,w));
		G[v].pb(pii(u,w));
	}
	int src,dest;
	cin >> src >> dest;
	
	dist[src] = 0;
	Q.push(pii(src,0));
	
	while(!Q.empty()){
		int u = Q.top().first;
		Q.pop();
		if(visited[u] == true) continue;
		for(int i=0; i<G[u].size(); i++){
			int v = G[u][i].first;
			int w = G[u][i].second;
			if(!visited[v] && dist[u] + w < dist[v]){
				dist[v] = dist[u] + w;
				Q.push(pii(v,dist[v]));
			}
		}
		visited[u] = true;
	}
	for(int i=0; i<nodes; i++)
		cout << i << ":" << dist[i] << endl;
	return 0;
}
