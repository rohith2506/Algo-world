/*
 * Max Flow Implementation using Ford Fulkerson Algorithm
 * @Author: Rohith Uppala
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bfs(vector<vector<int> > rgraph, int s, int t, vector<int> &parent) {
    int n = rgraph.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(s);
    parent[s] = -1;
    visited[s] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v=0; v < rgraph[u].size(); v++) {
            if(visited[v] == false && rgraph[u][v] > 0) {
                q.push(v);
                visited[v] = true;
                parent[v] = u;
            }
        }
    }
    if(visited[t] == true) return true;
    else return false;
}


int max_flow(vector<vector<int> > graph, int source, int sink) {
    int n = graph.size();
    vector<vector<int> > rgraph(n, vector<int>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            rgraph[i][j] = graph[i][j];
        }
    }
    vector<int> parent(n);
    int max_flow = 0;
    while(bfs(rgraph, source, sink, parent)) {
        int path_flow = INT_MAX;
        for(int v=sink; v!=source; v=parent[v]) {
            int u = parent[v];
            path_flow = min(path_flow, rgraph[u][v]);
        }
        for(int v=sink; v!=source; v=parent[v]) {
            int u = parent[v];
            rgraph[u][v] -= path_flow;
            rgraph[v][u] += path_flow;
        }
        max_flow = max_flow + path_flow;
    }
    return max_flow;
}

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    vector<vector<int> > graph(n, vector<int>(n, 0));
    int num_weights;
    cin >> num_weights;
    for(int i=0; i<num_weights; i++) {
        int u,v,weight;
        cin >> u >> v >> weight;
        graph[u][v] = weight;
    }
    int s, t;
    cin >> s >> t;
    int maximum_flow = max_flow(graph, s, t);
    cout << "Maximum flow: " << maximum_flow << endl;
    return 0;
}
