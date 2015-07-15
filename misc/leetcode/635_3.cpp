const long INF = 4000000000000LL;
int n;
// Storing the graph. Each g[i] is a list of edges adjacent to vertex i
// each edge is a pair (j,e), where j is the other vertex connected to i
// and e is the id of the edge. So L[e] is the weight of the edge.
vector<list<tuple<int, int>>> g;
vector<int> L;
 
 
long dist[2000];
 
// Calculate the distance from x to all other vertices in the tree, assumes
// edge # ignoredEdge has been deleted.
void bfs(int x, int ignoredEdge)
{
    fill(dist, dist + n, INF);
    queue<int> Q;
    dist[x] = 0;
    Q.push(x);
     
    while (! Q.empty() ) {
        int x = Q.front();
        Q.pop();
        for (auto p: g[x]) {
            int y, e;
            tie(y,e) = p;
            if ( e != ignoredEdge) {
                long d = dist[x] + L[e];
                if (d < dist[y]) {
                    dist[y] = d;
                    Q.push(y);
                }
            }    
        }
    }
}
 
// calculate the diameter of tree containing vertex x, ignores vertices
// not connected to it. Assumes edge # ignoredEdge has been removed
long diameter(int x, int ignoredEdge)
{
    // find the diameter of the tree that contains vertex x
     
    // A BFS from x
    bfs(x, ignoredEdge);
    // find the furthest y from x:
    int y = -1;
    for (int j = 0; j < n; j++) {
        if ( (dist[j] < INF) && ( (y == -1) || (dist[y] < dist[j]) ) ) {
            y = j;
        }
    }
     
    // A BFS from y:
    bfs(y, ignoredEdge);
    long dia = 0; 
    for (int j = 0; j < n; j++) {
        if (dist[j] < INF) {
            dia = max(dia, dist[j]);
        }
    }
    return dia;
}
 
 
long getLength(vector<int> A, vector<int> B, vector<int> L)
{
    int n = A.size() + 1;
    this->L = L;
    this->n = n;
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
        g[A[i]].push_back( make_tuple(B[i],i) );
        g[B[i]].push_back( make_tuple(A[i],i) );
    }
    long res = 0;
    for (int i = 0; i < n - 1; i++) {
        // We know A[i] is in one of the trees and B[i] in the other.
        res = std::max(res, diameter(A[i],i) + diameter(B[i],i) + L[i] );
    }
    return res;
}