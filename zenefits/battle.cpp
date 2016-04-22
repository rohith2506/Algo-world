#include <iostream>
#include <stdio.h>
#include <cassert>
#include <vector>
#define N 1000000
using namespace std;

int P[N], Q[N];
vector<int> adj[N];
long long int ans = 0, nd = 0; 

long long int solve(int node, int p) {
    nd++;
    assert(adj[node].size() <= 3);
    long long int net = P[node] - Q[node];
    for(int c: adj[node]) {
        if(c == p) continue;
        long long int def = solve(c, node);
        net += def;
        ans += abs(def);
    }
    return net;
}

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) 
        scanf("%d%d", &P[i], &Q[i]);
    for(int i=0; i<n-1; i++) {
        int u,v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    assert(solve(0, -1) == 0 && nd == n);
    printf("%lld\n", ans);
    return 0;
}
