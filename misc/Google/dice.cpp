#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cmath>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep2(i,m,n) for(int i=m;i<(int)n;i++)
using namespace std;

int numways(int S,int A,int N){
	vector<vector<int> > sum;
	sum.resize(S+1);
	
	rep(i,S+1)	
	sum[i].assign(N+1,0);
	
	rep(i,min(A+1,S+1))
	sum[i][1] = 1;
	
	rep2(n,2,N+1)
	  rep2(i,1,S+1)
	   rep2(j,1,A+1)
		if ((i-j)>0)
			sum[i][n] = sum[i][n] + sum[i-j][n-1];
	
	return sum[S][N];
}


int main(){
	cout<<numways(6,6,3)<<endl;
	return 0;
	}	


