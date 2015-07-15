#include <stdio.h>
#include <algorithm>
#define MAX_EDGES 10000000
#define MAX_VERTICES 200001
using namespace std;
int num_edges,num_vertices;
int total_cost=0;

struct edge{
    int v1,v2;
    int cost;
};

struct comp{
    bool operator()(const edge& e1,const edge& e2){
        return e1.cost<e2.cost;
    }
};

edge edges[MAX_EDGES];
int parent[MAX_VERTICES];
int rank[MAX_VERTICES];

int findset(int x){
    if(x!=parent[x]){
        parent[x]=findset(parent[x]);
    }
    return parent[x];
}

void merge(int x,int y){
    int px=findset(x),py=findset(y);
    if(rank[px]>rank[py]){
        parent[py]=px;
    }else{
        parent[px]=py;
    }
    if(rank[px]==rank[py]){
        ++rank[py];
    }
}

int main(){
    scanf("%d %d\n",&num_vertices,&num_edges);
    for(int i=1;i<=num_vertices;++i){
        parent[i]=i;
        rank[i]=0;
    }
    for(int i=0;i<num_edges;++i){
        scanf("%d %d %d\n",&edges[i].v1,&edges[i].v2,&edges[i].cost);
    }
    sort(edges,edges+num_edges,comp());
    for(int i=0;i<num_edges;++i){
        int s1=findset(edges[i].v1),s2=findset(edges[i].v2);
        if(s1!=s2){
            merge(s1,s2);
            total_cost+=edges[i].cost;
        }
    }
    printf("%d\n",total_cost);
}
