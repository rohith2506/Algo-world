#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <ctime>
#include <vector>
#define gc getchar_unlocked

using namespace std;

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
	int n;
	n = fast_io();

	int root[n];

	for(int i=0;i<n-1;i++){
		cin>>root[i];
	}

	int m;
	m = fast_io();
	int nodes[m];
	for(int i=0;i<m;i++){
		cin>>nodes[i];
	}

	//cout<<"iam here"<<endl;
	vector<int> res;
	for(int i=0;i<m;i++){
			int temp = nodes[i];
			res.push_back(temp);
			while(temp!=0){
					res.push_back(root[temp-1]);
					temp=root[temp-1];
			}	
	}
	//cout<<"iam here"<<endl;
	
	int hash[n];

	for(int i=0;i<n;i++){
		hash[i]=0;
	}

	for(int i=0;i<res.size();i++){
		hash[res[i]]++;
	}

	int temp=0;

	for(int i=n-1;i>=0;i--){
		if(hash[i]==m){
			temp=i;
			break;
		}
	}
	cout<<temp<<endl;
	return 0;
}
