#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#include <string>
#define MAX 1000
using namespace std;

struct gridinfo{
	int xco;
	int yco;
	vector<vector<bool> > visited;	
}gd;


bool check(vector<vector<bool> > visit, vector<vector<int> > grid){
	for(int i=0;i<grid.size();i++){
		for(int j=0;j<grid[i].size();j++){
			if(grid[i][j] == 0){
				if(visit[i][j]!=true)
					return false;
			}
		}
	}
	return true;	
}

int go(vector<vector<int> > grid,int h,int w,int startx,int starty){

	queue<gridinfo> q;

	gridinfo g;
	g.xco = startx;
	g.yco = starty;
	
	for(int i=0;i<h;i++){
		vector<bool> temp;
		for(int j=0;j<w;j++){
			temp.push_back(false);
			}
		g.visited.push_back(temp);
	}

	q.push(g);
	int cnt = 0;	
	
	while(!q.empty()){
		gridinfo g = q.front();
		q.pop();
	
		if(g.xco>=0 && g.xco<h && g.yco>=0 && g.yco<w && grid[g.xco][g.yco] == 3 && check(g.visited,grid))
                             cnt++;

		else{
		if(g.xco>=0 && g.xco<h && g.yco>=0 && g.yco<w && g.visited[g.xco][g.yco] == false && grid[g.xco][g.yco]!=1){
			g.visited[g.xco][g.yco] = true;
		
			cout<<g.xco<<" "<<g.yco<<endl;
	
			gridinfo g1;
			g1.xco = g.xco+1;
			g1.yco = g.yco;
			g1.visited = g.visited;
			q.push(g1);
			
			gridinfo g2;
			g2.xco = g.xco-1;
			g2.yco = g.yco;
			g2.visited = g.visited;
			q.push(g2);
			
			gridinfo g3;
			g3.xco = g.xco;
			g3.yco = g.yco-1;
			g3.visited = g.visited;
			q.push(g3);
			
			gridinfo g4;
			g4.xco = g.xco;
			g4.yco = g.yco+1;
			g4.visited = g.visited;
			q.push(g4);
			}
		}
	}
	return cnt;
}

int main(){
	int w,h;
	scanf("%d%d",&w,&h);
	vector<vector<int> > grid(h,vector<int> (w));

	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin >> grid[i][j];
		}
	}

	//precompute the total number of open ducts;

	int cnt = 0,startx,starty;
	
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(grid[i][j] == 0)
				cnt++;
		}
	}
	
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(grid[i][j] == 2){
				startx = i;
				starty = j;
			}
		}
	}

	cout<<cnt<<" "<<startx<<" "<<starty<<endl;

	cout<<go(grid,h,w,startx,starty)<<endl;
	return 0;
}
