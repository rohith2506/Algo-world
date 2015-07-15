/*
number of ways will be number of ways of its children can be arranged consecutively excluding
its root
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#define MAX 64
typedef long long int lint;
lint visit[MAX];
vector<vector<int>> ar;
using namespace std;


lint go(int u){
	visit[u]=1;
	lint ans=1;
	for(int i=0;i<(int)ar[u].size();i++){
		int v=ar[u][i];
		if(!visit[i])
			ans*=(go(v)+1);
		}
	if(u!=1)
		cur+=ans;
	return ans;
}

class centaurCompany{
	public:
		int count(vector<int> a,vector<int> b){
			for(int i=1;i<=a.size();i++){
				a[i].clear();
				v[i]=0;
				}

			for(int i=0;i<a.size();i++){
				ar[a[i]].push_back(b[i]);
				ar[b[i]].push_back(a[i]);
				}
			
			lint curr=0;
			lint res=go(1);
			return curr+res+1;
			}
		};
								
