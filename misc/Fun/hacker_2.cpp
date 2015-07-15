#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;



bool check(vector<vector<int> >v,int index){
	
	for(int i=0;v[index].size();i++){
		if(v[index][i] !=-1)
			return true;
	}

	return false;
}

int dfs(vector<vector<int> > &v,int index,vector<int> &visited){
	stack<int> stk;
	int count = 0;

	stk.push(index);

	while(!stk.empty()){
		int x = stk.top();
		stk.pop();
		if(visited[x] == 0){
			count++;
			visited[x] = 1;
			for(int i=0;i<v[x].size();i++){
				if(visited[v[x][i]]==0)
					stk.push(v[x][i]);		
				}
			}
		}
	
//	cout<<count<<endl;
//	cout<<"#######"<<endl;	
	return count;
}


int main(){
	int n,l;
	cin>>n>>l;	
	vector<vector<int> > v;

	for(int i=0;i<n;i++){
		vector<int> temp;
		v.push_back(temp);
		}

	for(int i=0;i<l;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
		}

	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++){
			cout<<v[i][j]<<" ";
			}
		cout<<endl;
		}

	vector<int> visited;

	for(int i=0;i<n;i++)
		visited.push_back(0);
		
	vector<int> res;
	for(int i=0;i<n;i++){
		int sum = dfs(v,i,visited);
		res.push_back(sum);
	}

	long int cnt = 1;
	int flag = 0;
	for(int i=0;i<res.size();i++){
		if(res[i]!=0)
			cnt = cnt * res[i];
		else
			flag ++;
		}

	if(flag == res.size()-1)
		cout<<"0"<<endl;
	else
		cout<<cnt<<endl;	
	return 0;
}	
			
			
