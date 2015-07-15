#include <iostream>
#include <stdio.h>
#include <vector>

struct vertex{
	int v1;
	int v2;
	int cst;
};

using namespace std;

int main(){
	int n;
	cin  >> n;
	vector<vertex> adj(n);

	for(int i=0;i<n;i++){
		vertex v;
		cin >> v.v1;
		cin >> v.v2;
		cin >> v.cst;
		adj.push_back(v);
	} 

	




}