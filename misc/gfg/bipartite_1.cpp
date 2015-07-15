/*
check whether a graph is bipartite or not

if it is print that two parts

@author : rohit
*/

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
vector<vector<int> > edges;
vector<int> vertices;
int num;

class queue{
	private:
		struct node{
			int data;
			node *link;
			}*head;
	public:
		queue();
		void push(int data);
		int top();
		void pop();
		bool empty();
		};

queue::queue(){
	head = NULL;
	}

void queue :: push(int num){
	if(head == NULL){
		head = new node;
		head -> data = num;
		head -> link = NULL;
		}
	else{
		node * temp = head;
		while(temp->link!=NULL)
			temp = temp -> link;
		node * r = new node;
		r->data = num;
		temp -> link = r;
		r->link = NULL;
	    }
}


int queue :: top(){
	node * temp = head;
	int num = temp -> data;
	return num;
	}



void queue :: pop(){
	node * temp = head;
	head = head -> link;
	delete temp;
	}


bool queue :: empty(){
	if(head == NULL)
		return true;
	else
		return false;
	}


bool bipartite(int src){
	for(int i=0;i<num;i++)
		vertices.push_back(-1);

		vertices[src]=1;

	queue q;
	q.push(src);

	while(!q.empty()){
		int  u = q.top();
		for(int v = 0;v < num ; v++){
			 	if(edges[u][v] && vertices[v]==-1){
					vertices[v] = 1-vertices[u];
					q.push(v);
					}
	
				else if(edges[u][v] && vertices[v] == vertices[u])
					return false;
				
				else{}
				}
		q.pop();
		}
	return true;
}


int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		cout<<"number of vertices"<<endl;
		cin>>num;
		
		for(int i=0;i<num;i++){
		      vector<int> temp;
		      for(int j=0;j<num;j++){
				int x;
				cin>>x;
				temp.push_back(x);
				}
		edges.push_back(temp);
		}

/*		cout<<"Graph structure with edges"<<endl;
		for(int i=0;i<edges.size();i++){
			for(int j=0;j<edges[i].size();j++){
				cout<<edges[i][j]<<" ";
				}
			cout<<endl;
			}
*/		
		if(bipartite(0)){
			cout<<"Yes,Graph is bipartite"<<endl;

		cout<<"Two parts of a graph are "<<endl;
			for(int i=0;i<vertices.size();i++){
				if(vertices[i] == 1)
					cout<<i+1<<" ";
					}
				cout<<endl;
			cout<<"########################"<<endl;
			for(int i=0;i<vertices.size();i++){
				if(vertices[i] == 0)
					cout<<i+1<<" ";
					}
				cout<<endl;
		}
		else
			cout<<"No, Graph is not bipartite"<<endl;
	
	}
	return 0;
	}

			


