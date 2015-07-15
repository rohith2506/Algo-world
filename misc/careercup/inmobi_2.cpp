#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <ctime>
#include <vector>
#define gc getchar_unlocked

double globalmax ;
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
	int n,l,d;
	n= fast_io();
	l= fast_io();
	d= fast_io();

	double prob[n+2];
	vector<int> dist;
	prob[0]=1.0;
	for(int i=1;i<=n;i++){
	   cin>>prob[i];
	}
	prob[n+1]=1.0;
	
	dist.push_back(0);
	for(int i=0;i<n;i++){
		int x;
		x=fast_io();
		dist.push_back(x);
	}
	dist.push_back(d);
	
	
	int flag = 0;


	for(int i=0;i<dist.size()-1;i++){
		int diff = dist[i+1]-dist[i];
		if(diff>l)
			flag = 1;
	}

	if(flag == 1)
		cout<<"IMPOSSIBLE"<<endl;
	else{
			//find best way ot reach using dp

			double res[n+2];
			res[0]=1.0;

			for(int i=1;i<dist.size();i++){	
						res[i]=0.0;
					for(int j=i-1;j>=0;j--){
						if(dist[i]-dist[j]<=l){
						double temp = prob[i]*res[j];
						res[i] = res[i] > temp ? res[i]:temp;
						} 
					}
				}
			printf("%.6f\n",res[n+1]);
		}


	return 0;
}