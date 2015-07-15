#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

#define rep(i,n) for(i=0;i<(n);i++)
#define min(a,b) (((a)<(b))?(a):(b))
#define MAXN 3001

struct Node {
 int level;
 int low;
 int noChildren;
 vector<int> adj;
}nd[MAXN];

int res;
bool isArtic[MAXN];


void dfs(int x) {
 nd[x].low = nd[x].level;

 int i, y;
 rep(i, nd[x].adj.size()) {
  y = nd[x].adj[i];
  if( nd[y].level == -1) { //unvisited
   nd[y].level = nd[x].level + 1;
   nd[x].noChildren++;
   dfs(y);
   nd[x].low = min(nd[x].low, nd[y].low);

   if(nd[x].level > 0 && nd[y].low >= nd[x].level) { // x is a non-root node and there's no way from y to any upper level of x
    isArtic[x] = 1;
   }
  }
  else if (nd[y].level < nd[x].level - 1) { //y's depth is lower than x's parent....so its a back edge
   nd[x].low = min(nd[x].low, nd[y].level);
  }
 }

 if(nd[x].level == 0) { //root node
  if(nd[x].noChildren >= 2) isArtic[x] = 1;
 }
}

int main() {
 int i;
 int t;
 scanf("%d",&t);
 while(t--){ 
     int n,m;
     long int k;
    scanf("%d%d%ld",&n,&m,&k);
    rep(i,n) nd[i].adj.clear(), nd[i].noChildren = 0,  nd[i].low = nd[i].level = -1;
    rep(i,m){
    int u,v;
    scanf("%d%d",&u,&v);
    nd[u].adj.push_back(v);
    nd[v].adj.push_back(u);
   }

  memset(isArtic, 0, sizeof(isArtic));
  nd[0].level = 0;
  dfs(0);
  res = 0;
  rep(i,n) if(isArtic[i]) res++;
  printf("%ld\n",(res*k));
 }
 return 0;
}
