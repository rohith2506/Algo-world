#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
#define MAX 10000
using namespace std;

bool prime[MAX+1];
int arr[MAX+1];


void process(){
	for(int i=0;i<MAX+1;i++)
		prime[i]=true;
		prime[0]=false;
		prime[1]=false;

	int m = sqrt(MAX);
	for(int i=2;i<=m;i++){
		if(prime[i]){
			for(int k=(i*i);k<=MAX;k+=i)
				prime[k]=false;
		}
	}
}

void calculate(){
	arr[0]=0;
	arr[1]=0;
	arr[2]=0;

	for(int i=3;i<=MAX;i++){
		int res=0;
		for(int k=1;k<=(i/2);k++){
			int p=(i-(2*k));
			int q=k;
			if(prime[p]==true && prime[q]==true)
				res++;
		}
		arr[i]=res;
	}
}


int main(){
	int t;
	scanf("%d",&t);
	process();
	calculate();
	while(t--){
		int n;
		scanf("%d",&n);
		cout<<arr[n]<<endl;
	}
	return 0;
}