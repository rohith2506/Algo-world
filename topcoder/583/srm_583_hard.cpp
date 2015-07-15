/*
clean implementation of dijsktra algorithm
*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1065;
const int px[] = {1,-1,0,0};
const int py[] = {0,0,1,-1};
;
int lab[41][41];
vector< pair<int,int> > g[N];
int dis[N], c[N];
bool visit[N];

class GameOnBoard{
	public:
		int n;
		void spfa(int s){
			queue<int> q;
			int u;
			pair<int,int> v;
			memset(dis,-1,sizeof(dis));
			memset(visit,false,sizeof(visit));
			dis[s]=0;
			q.push(s);

			while(!q.empty()){
					u=q.front();
					q.pop();
					visit[u]=false;

					int len = g[u].size();

					for(int i=0;i<len;i++){
						v=g[u][i];
						if(dis[v.first]==-1 || dis[v.first]>dis[u]+v.second){
								dis[v.first] = dis[u]+v.second;
								if(!visit[v.first]){
									q.push(v.first);
									visit[v.first]=true;
								}
						}
					}
			}
		}


		int optimalchoice(vector<string> cost){
			n=0;
			int row = cost.length();
			int col = cost[0].length();

			for(int i=0;i<row;i++){
				for(int j=0;j<col;j++){
						lab[i][j]=++n;
						c[n]=cost[i][j]-'0';
				}
			}

			for(int i=0;i<row;i++){
				for(int j=0;j<col;j++){
					int tx,ty,u,v;
					u=lab[i][j];
					for(int p=0;p<4;p++){
						tx=i+px[p];ty=j+py[p];
						if(tx<0 || tx>=row || ty<0 || ty>=col) continue;
						v = lab[tx][ty];
						g[u].push_back(make_pair(v,cost[tx][ty]-'0'));
						g[v].push_back(make_pair(u,cost[i][j]-'0'));
					}
				}
			}


			int ans = -1;

			for(int i=1;i<=n;i++){
				spfa(i);
				int mm = 0;
				for(int j=1;j<=n;j++){
					if(j!=i && dis[j]!=1)
						mm = max(mm,dis[j]);
				}
				if(ans == -1 || ans>mm+c[i])  ans = mm + c[i];
			}
			return ans;
		}

}