#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_EDGES 50000000
#define MAX_VERTICES 6667
#define MOD 747474747
using namespace std;
int num_edges,num_vertices,d;


struct edge{
    int v1;
    int v2;
    long long int cost;
};

struct comp{
    bool operator()(const edge& e1,const edge& e2){
        return e1.cost<e2.cost;
    }
};

int *parent = new int[MAX_VERTICES];
int *rank   = new int[MAX_VERTICES];
edge *edges = new edge[MAX_EDGES];


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

long long int func(vector<long int> x,vector<long int> y){
    long long int sum=0;
    for(int i=0;i<x.size();i++){
            int prod=abs(x[i]-y[i]);
            sum=((sum%MOD)+(((prod%MOD)*(prod%MOD))%MOD))%MOD;
    }
    return sum;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
    scanf("%d%d\n",&num_vertices,&d);

    for(int i=1;i<=num_vertices;++i){
        parent[i]=i;
        rank[i]=0;
    }

    long long int num_edges = (num_vertices*(num_vertices-1))/2;

    vector<vector<long int> > data;

    for(int i=0;i<num_vertices;++i){
        vector<long int> temp;
        for(int j=0;j<d;j++){
            long  int x;
            scanf("%ld",&x);
            temp.push_back(x);
       }
       data.push_back(temp);
    }

    //cout<<data.size()<<endl;
    long long int cnt=0;

    for(int i=0;i<data.size();i++){
        for(int j=i+1;j<data.size();j++){
            edges[cnt].v1=i+1;
            edges[cnt].v2=j+1;
            long long int dist=-func(data[i],data[j]);
            edges[cnt].cost=dist;
            cnt++;
        }
    }

    /*for(int i=0;i<num_edges;i++){
        cout<<edges[i].v1<<" "<<edges[i].v2<<" "<<edges[i].cost<<endl;
    }*/




    sort(edges,edges+num_edges,comp());
    long long int total_cost=1;
    for(long long int i=0;i<num_edges;++i){
        int s1=findset(edges[i].v1),s2=findset(edges[i].v2);
        if(s1!=s2){
            merge(s1,s2);
            long long int val=0-edges[i].cost;
            total_cost=((total_cost%MOD)*(val%MOD))%MOD;;
        }
    }
    printf("%lld\n",total_cost);
}
return 0;
}