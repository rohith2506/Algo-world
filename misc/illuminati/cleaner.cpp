#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define INF 100001
using namespace std;

struct point{
	int xco;
	int yco;
};

int main(){
	int w,h;
	scanf("%d%d",&w,&h);
	vector<vector<char> > v;

	for(int i=0;i<h;i++){
		vector<char> temp;
		for(int j=0;j<w;j++){
			char x;
			cin>>x;
			temp.push_back(x);
		}
		v.push_back(temp);
	}

	int xpos,ypos;

	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++){
			if(v[i][j] == 'o'){
				xpos = i;
				ypos = j;
			}
		}
	}

	vector<point> pt;

	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++){
			if(v[i][j] == '*'){
				point p;
				p.xco = i;
				p.yco = j;
				pt.push_back(p);
			}
		}
	}


	int adj[w*h][w*h];

	for(int i=0;i<h*w;i++){
		for(int j=0;j<w*h;j++){
			adj[i][j]=-1;
		}
	}

	for(int i=0;i<w*h;i++){
		int xco = i/w;
		int yco = i%w;
		if(v[xco][yco]!='x'){
			adj[i][i] = 0;		
			if(xco+1>=0 && xco+1<h && yco>=0 && yco<w){
				int vertex = (xco+1)*w + yco;
				if(v[xco+1][yco]=='x'){
					adj[i][vertex]=INF;
					adj[vertex][i]=INF;
				}
				else{
					adj[i][vertex]=1;
					adj[vertex][i]=1;
				}
			}

			if(xco-1>=0 && xco-1<h && yco>=0 && yco<w){
				int vertex = (xco-1)*w + yco;
				if(v[xco-1][yco] =='x'){
					adj[i][vertex]=INF;
					adj[vertex][i]=INF;
				}
				else{
					adj[i][vertex]=1;
					adj[vertex][i]=1;
				}
			}

			if(xco>=0 && xco<h && yco+1>=0 && yco+1<w){
				int vertex = (xco*w) + (yco+1);
				if(v[xco][yco+1] =='x'){
					adj[i][vertex]=INF;
					adj[vertex][i]=INF;
				}
				else{
					adj[i][vertex]=1;
					adj[vertex][i]=1;
				}
			}

			if(xco>=0 && xco<h && yco-1>=0 && yco-1<w){
				int vertex = (xco*w) + (yco-1);
				if(v[xco][yco-1] =='x'){
					adj[i][vertex]=INF;
					adj[vertex][i]=INF;
				}
				else{
					adj[i][vertex]=1;
					adj[vertex][i]=1;
				}
			}
		}

		else{
			adj[i][i] = INF;

			if(xco+1>=0 && xco+1<h && yco>=0 &&yco<w){
				int vertex = (xco+1)*w + yco;
					adj[i][vertex]=INF;
					adj[vertex][i]=INF;
			}

			if(xco-1>=0 && xco-1<h && yco>=0 &&yco<w){
				int vertex = (xco-1)*w + yco;
					adj[i][vertex]=INF;
					adj[vertex][i]=INF;
			}

			if(xco>=0 && xco<h && yco+1>=0 && yco+1<w){
				int vertex = (xco*w) + (yco+1);
					adj[i][vertex]=INF;
					adj[vertex][i]=INF;
			}

			if(xco>=0 && xco<h && yco-1>=0 && yco-1<w){
				int vertex = (xco*w) + (yco-1);
					adj[i][vertex]=INF;
					adj[vertex][i]=INF;
			}
		}
	}

	for(int i=0;i<w*h;i++){
		for(int j=0;j<w*h;j++){
			if(adj[i][j] == -1)
				adj[i][j] = INF;
		}
	}

	for(int k=0;k<w*h;k++){
		for(int i=0;i<w*h;i++){
			for(int j=0;j<w*h;j++){
				if(adj[i][k]+adj[k][j] < adj[i][j])
					adj[i][j] = adj[i][k]+adj[k][j];
			}
		}
	}


	vector<int> index;

	for(int i=0;i<pt.size();i++)
		index.push_back(i);

	if(pt.size()>0){
		int total_cost = INF;
		do{
			int temp_cost = 0;
			for(int i=0;i<index.size()-1;i++){
				int vx = pt[index[i]].xco * w + pt[index[i]].yco;
				int vy = pt[index[i+1]].xco * w + pt[index[i+1]].yco;

				if(adj[vx][vy] == INF){
					printf("-1\n");
					return 0;
				}
				else
					temp_cost = temp_cost + adj[vx][vy];
			}

			int vx = xpos * w + ypos;
			int vy = pt[index[0]].xco * w + pt[index[0]].yco;

			if(adj[vx][vy] == INF){
				printf("-1\n");
				return 0;
			}
			else
				temp_cost = temp_cost + adj[vx][vy];

			total_cost = std::min(total_cost,temp_cost);
		}while(next_permutation(index.begin(),index.end()));		
	printf("%d\n",total_cost);
		}

	else
		printf("0\n");
	return 0;
}
