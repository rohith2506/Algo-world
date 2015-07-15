#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <ctime>
#include <vector>
#include <stdlib.h>
#define gc getchar_unlocked
using namespace std;
//vector<int> v;

inline int fast_io() 
{
	register int N = 0, C;
	while ((C = gc()) < '0');
 
	do {
		N = (N<<3) + (N<<1) + C - '0';
	}while ((C = gc()) >= '0');
	return N;
}


int main(){
	int n,m;
	
	n=fast_io();
	m=fast_io();

	vector<vector <int> > v;

	for(int i = 0; i < m; i++)
	{
         vector<int> row;
         v.push_back(row);
    }


	for(int i=0;i<m;i++){
		int j,k;
		j=fast_io();
		k=fast_io();
		v[j].push_back(k);
		v[k].push_back(j);
	}


	bool check[n];

	for(int i=0;i<n;i++)
		check[i]=0;

	vector<int> res;

	do{
		int maxi=0,index=0;
		for(int i=0;i<v.size();i++){
			if(check[i]==0){
				int len = v[i].size();
				if(len>maxi){
					maxi=len;
					index = i;
				}
			}
		}

		if(maxi==0)
			break;

//		cout<<index<<endl;
		res.push_back(index);

		check[index]=1;
		for(int j=0;j<v[index].size();j++)
				check[v[index][j]]=1;
	
	}while(1);

		cout<<res.size()<<endl;
		for(int i=0;i<res.size();i++)
			cout<<res[i]<<" ";
			cout<<endl;

		return 0;
	}	

