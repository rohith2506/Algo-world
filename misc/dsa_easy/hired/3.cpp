#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

#define MAX 100001
#define INF (1<<20)
#define DEBUG if(0)
#define pii pair< int, int >
#define pb(x) push_back(x)

struct comp {
    bool operator() (const pii &a, const pii &b) {
        return a.second > b.second;
    }
};

priority_queue< pii, vector< pii >, comp > Q;
vector< pii > G[MAX];
int D[MAX];
bool F[MAX];

void go(int nodes,int src,int dest, const vector<int> &hm,const vector<int> &dst){
	 for(int i=0; i<hm.size(); i++) {
      	int u = hm[i];
      	int v = dst[i];
      	int w = 1;
        G[u].pb(pii(v, w));
        G[v].pb(pii(u, w)); 
    }

	for(int i=1; i<=nodes; i++) D[i] = INF;
    D[src] = 0;
    Q.push(pii(src, 0));

    while(!Q.empty()) {
        int u = Q.top().first;
        Q.pop();
        if(F[u]) continue;
        int sz = G[u].size();
//        DEBUG printf("visiting from %d:", u);
        for(int i=0; i<sz; i++) {
            int v = G[u][i].first;
            int w = G[u][i].second;
            if(!F[v] && D[u]+w < D[v]) {
  //              DEBUG printf(" %d,", v);
                D[v] = D[u] + w;
                Q.push(pii(v, D[v]));
            }
        }
        F[u] = 1;
    }
    printf("%d\n",D[dest]);
}

int main(){
	int n;
	cin >> n;
	vector<int> a(5);
	vector<int> b(5);
	for(int i=0;i<5;i++) cin >> a[i];
	for(int j=0;j<5;j++) cin >> b[j];
	int src,dest;
	cin >> src >> dest;
	go(n,src,dest,a,b);
	return 0;
}