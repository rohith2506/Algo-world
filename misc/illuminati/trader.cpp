#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#define INT_MAX 100001.000
#define max_vertices 100
using namespace std;

struct edge{
  string citya;
  string cityb;
  int time;
  int cost;
  double prob;
};

struct Distance{
  double CostA;
  double CostB;
  double Cost;
  int Time;
};

struct Graph{
  int cst;
  int tm;
  double prb;
};

double calc(int x, double y, double a ,double b){
     double val1 = a + x;
     double val2 = b * (1 - ((0.1 * y)/10));
     return val1+val2;
}

int minDistance(Distance dist[], bool sptSet[], int num_vertices)
{
   double min = INT_MAX;
   int min_index;
   for (int v = 0; v < num_vertices; v++)
     if (sptSet[v] == false && dist[v].Cost <= min)
         min = dist[v].Cost, min_index = v;
 
   return min_index;
}
 
double dijkstra(vector<vector<Graph> > graph, int num_vertices, int src, int dest, int maxtime, int cst_oil)
{
     Distance dist[num_vertices];                  
     bool sptSet[num_vertices];

     for (int i = 0; i < num_vertices; i++)
        dist[i].Cost = INT_MAX, dist[i].Time = 0, sptSet[i] = false;
 
     dist[src].Cost = 0;
     dist[src].CostA = cst_oil;
     dist[src].CostB = -cst_oil;

     for (int count = 0; count < num_vertices-1; count++){
       int u = minDistance(dist, sptSet, num_vertices);
       sptSet[u] = true;
       for (int v = 0; v < num_vertices; v++)
        if(!sptSet[v] && graph[u][v].cst!=-1 && dist[u].Cost!= INT_MAX && (dist[u].Cost+ calc(graph[u][v].cst, graph[u][v].prb, dist[u].CostA, dist[u].CostB) <= dist[v].Cost) && dist[u].Time + graph[u][v].tm <= maxtime){
              dist[v].CostA = dist[u].CostA + graph[u][v].cst;
              dist[v].CostB = dist[u].CostB * (1 - ((0.1 * graph[u][v].prb)/10));
              dist[v].Cost  = dist[v].CostA + dist[v].CostB;
              dist[v].Time  = dist[u].Time  + graph[u][v].tm;
//              cout<<v<<" "<<dist[v].CostA<<" "<<dist[v].CostB<<" "<<dist[v].Cost<<" "<<dist[v].Time<<endl;
            }
      }

     return dist[dest].Cost;
}

bool check(string x,vector<string> cities){
  for(int i=0;i<cities.size();i++){
      if(cities[i] == x)
        return true;
  }
  return false;
}

int Find(string x,vector<string> cities){
  for(int i=0;i<cities.size();i++){
      if(cities[i] == x)
        return i;
  }
}

// driver program to test above function
int main()
{
  int num_vertices;
  scanf("%d",&num_vertices);
  vector<edge> v;

  for(int i=0;i<num_vertices;i++){
    edge e;
    cin>>e.citya>>e.cityb;
    scanf("%d%d",&e.time,&e.cost);
    cin>>e.prob;
    v.push_back(e);
  }

  string src,dest;
  cin>>src>>dest;

  int maxtime,cst_oil;
  scanf("%d%d",&maxtime,&cst_oil);

  vector<string> cities;

  for(int i=0;i<v.size();i++){
    string x = v[i].citya;
    string y = v[i].cityb;

    if(!check(x,cities))
      cities.push_back(x);

    if(!check(y,cities))
      cities.push_back(y);
  }

 // for(int i=0;i<cities.size();i++)
 //  cout<<cities[i]<<" ";
 //   cout<<endl;

  vector<vector<Graph> > graph;

  for(int i=0;i<num_vertices;i++){
    vector<Graph> temp;
    for(int j=0;j<num_vertices;j++){
      Graph g;
      temp.push_back(g);
    }
    graph.push_back(temp);
  } 


  for(int i=0;i<num_vertices;i++){
    for(int j=0;j<num_vertices;j++){
      graph[i][j].cst = -1;
    }
  }

  for(int i=0;i<num_vertices;i++){
      Graph g;
      string x = v[i].citya;
      string y = v[i].cityb;

      int v1 = Find(x,cities);
      int v2 = Find(y,cities);

      g.cst = v[i].cost;
      g.prb = v[i].prob;
      g.tm  = v[i].time;
//      cout<<v1<<" "<<v2<<" "<<x<<" "<<y<<" "<<g.cst<<" "<<g.prb<<" "<<g.tm<<endl;
      
      graph[v1][v2] = g;
  }

  int Src  = Find(src,cities);
  int Dest = Find(dest,cities);
  
//  cout<<Src<<" "<<Dest<<" "<<maxtime<<" "<<cst_oil<<endl;
  double total_cost = dijkstra(graph, num_vertices, Src, Dest, maxtime, cst_oil);
  printf("%.12f\n",total_cost);
  return 0;
}