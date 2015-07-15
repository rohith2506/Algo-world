/*
dijsktra variation
*/

#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cmath>

using namespace std;
typedef long long LL;
const int maxn = 100000 + 5;
const LL INF = 1000000000000000ll;
const int Mod = 1000000007;
typedef pair<LL, int> P;

int n, m, k;
struct Edge{
    int to;
    LL dis;
    Edge(int to=0, LL dis=0){
        this -> to = to;
        this -> dis = dis;
    }
};
vector<Edge> G[maxn];

LL dist[maxn];
int use[maxn];
int vis[maxn];

void bfs(){
    memset(vis, 0, sizeof vis);
    priority_queue<P> q;
    for(int i = 1;i <= n;i++){
        if(dist[i] < INF){
            q.push(P(-dist[i], i));
        }
    }

    while(!q.empty()){
        P p = q.top();q.pop();
        int len = -p.first;
        int pos = p.second;

        if(vis[pos]==1) continue;
        //cout << pos << ':' << len << endl;
        vis[pos] = 1;
        for(int i = 0;i < G[pos].size();i++){
            Edge& tem = G[pos][i];
            int to = tem.to;
            LL der = tem.dis;
            if(der+dist[pos] <= dist[to] && vis[to]==0){
                dist[to] = der+dist[pos];
                use[to] = 0;
                q.push(P(-dist[to], to));
            }
        }
    }
}

int main(){
    while(scanf("%d%d%d", &n, &m, &k) != EOF){
        for(int i = 1;i <= n;i++){
            G[i].clear();
            dist[i] = INF;
        }
        dist[1] = 0;
        for(int i = 0;i < m;i++){
            int u, v, x;
            scanf("%d%d%d", &u, &v, &x);
            G[u].push_back(Edge(v, x));
            G[v].push_back(Edge(u, x));
        }
        memset(use, 0, sizeof use);
        for(int i = 0;i < k;i++){
            int s;
            LL y;
            scanf("%d%I64d", &s, &y);
            dist[s] = min(dist[s], y);
            use[s] = 1;
        }

        bfs();

        int ans = 0;
        for(int i = 1;i <= n;i++){
            if(use[i]==1)
                ans++;
        }
        printf("%d\n", k-ans);
    }
    return 0;
}