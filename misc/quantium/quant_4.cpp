#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define INT_MAX 10000
using namespace std;

int minKey(int key[], bool mstSet[], int V)
{
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < V; v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;
 
   return min_index;
}
 
int printMST(int parent[], int V, vector<vector<int> > &graph)
{
   int cost = 0;
   for (int i = 1; i < V; i++)
      cost+=graph[i][parent[i]];

   return cost;
}

int primMST(vector<vector<int> > &graph,int V)
{
     int parent[V]; 
     int key[V];   
     bool mstSet[V];  
     
     for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
      
     key[0] = 0;     
     parent[0] = -1; 

     for (int count = 0; count < V-1; count++)
     {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
          if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
             parent[v]  = u, key[v] = graph[u][v];
     }

     return printMST(parent, V, graph);
}
 
int main()
{
   int V;
   cin>>V;

   vector<vector<int> > graph;
   vector<vector<int> > graph2;
   vector<vector<int> > graph3;

   for(int i=0;i<V;i++){
      vector<int> temp;
      for(int j=0;j<V;j++){
          int cost;
          cin>>cost;
          temp.push_back(cost);
      }
      graph2.push_back(temp);
   }

   for(int i=0;i<V;i++){
    	vector<int> temp;
      for(int j=0;j<V;j++){
          int cost;
          cin>>cost;
          temp.push_back(cost);
      }
      graph3.push_back(temp);
   }

   for(int i=0;i<V;i++){
      vector<int> maintemp;
      for(int j=0;j<V;j++){
          int temp;
          if(i==j)
             temp = 0;
          else{
             vector<int> mini;
	           mini.push_back(graph2[i][j] + graph3[j][i]);
	           mini.push_back(graph2[i][j] + graph3[i][j]);
	           mini.push_back(graph2[j][i] + graph3[j][i]);
	           mini.push_back(graph2[j][i] + graph3[i][j]);
             sort(mini.begin(),mini.end());
             temp = mini[0];
 	          }
       maintemp.push_back(temp);
  	 }
     graph.push_back(maintemp);
  }


   for(int i=0;i<V;i++){
      for(int j=i;j<V;j++){
          cout<<graph[i][j]<<" ";
      }
      cout<<endl;
   }

    cout<<primMST(graph,V)<<endl;
 
    return 0;
}
