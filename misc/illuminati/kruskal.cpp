#include <stdio.h>
#include <algorithm>
#define MAX_EDGES 10000000
#define MAX_VERTICES 200001
using namespace std;

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
int Rank[MAX_VERTICES];

int findset(int x){
    if(x!=parent[x]){
        parent[x]=findset(parent[x]);
    }
    return parent[x];
}

void merge(int x,int y){
    int px=findset(x),py=findset(y);
    if(Rank[px]>Rank[py]){
        parent[py]=px;
    }else{
        parent[px]=py;
    }
    if(Rank[px]==Rank[py]){
        ++Rank[py];
    }
}

int main(){
    int num_edges,num_vertices;
    int total_cost=0;
    scanf("%d %d",&num_vertices,&num_edges);
    for(int i=0;i<num_vertices;++i){
        parent[i]=i;
        Rank[i]=0;
    }
    for(int i=0;i<num_edges;++i){
        scanf("%d %d %d",&edges[i].v1,&edges[i].v2,&edges[i].cost);
    }

    int t1,t2;
    scanf("%d %d",&t1,&t2);
    sort(edges,edges+num_edges,comp());
    for(int i=0;i<num_edges;++i){
        int s1=findset(edges[i].v1),s2=findset(edges[i].v2);
        if(s1!=s2){
            merge(s1,s2);
            total_cost+=edges[i].cost;
        }
    }

    int Time = t1;
    int glob_max = 0;

    for(int i=t1;i<=t2;i++){
        int Max = total_cost * t1;
        if(Max>glob_max){
            glob_max = Max;
            Time = t1;
        }
    }

    printf("%d\n",Time);
    return 0;
}
