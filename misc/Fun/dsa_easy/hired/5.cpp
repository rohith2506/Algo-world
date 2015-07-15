#include <iostream>
#include <list>
#include <vector>
#include <stack>
using namespace std;

class Graph
{
int V;    
list<int> *adj;
void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int V); 
    void addEdge(int v, int w);
    void topologicalSort(int n);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); 
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);
    Stack.push(v);
}

void Graph::topologicalSort(int n)
{
    stack<int> Stack;
 //   cout<<V<<endl;
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++)
      if (visited[i] == false)
        topologicalSortUtil(i, visited, Stack);
    
    bool check[n];
    for(int i=1;i<=n;i++) check[i] = false;

    while(!Stack.empty()){
        if(Stack.top()!=0){
            cout<< Stack.top()<<" ";
            check[Stack.top()] = true;
        }
        Stack.pop();
    }

    for(int i=1;i<=n;i++){
        if(check[i] == false)
            cout<<i<<" ";
    }
    cout<<endl;
}


void order_tasks(const vector<int> &frst,const vector<int> &second,int n){
    Graph g(n);
    for(int i=0;i<frst.size();i++){
        int u = frst[i];
        int v = second[i];
        g.addEdge(u,v);
  //      cout<<"iam"<<endl;
    }
    g.topologicalSort(n);
}
 
int main(){
    vector<int> a(3);
    vector<int> b(3);
    for(int i=0;i<3;i++) cin >> a[i];
    for(int j=0;j<3;j++) cin >> b[j];
    int n;
    cin >> n;
    order_tasks(a,b,n);
    return 0;
}