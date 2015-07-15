/*
Simple DP
@Author: Rohit
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#define pb push_back
typedef long long int LL;
#define INF 1000000001
#define MAX 1000001
LL v[MAX][4];
LL dp[MAX][4];
using namespace std;

int main(){
	LL n;
	LL test=1;
	cin >> n;	
	while(1){
		if(n == 0)
			break;
		
		for(LL i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>v[i][j];
				dp[i][j] = INF;
			}
		}
	
		for(LL j=0;j<3;j++)
			dp[0][j] = v[0][j];
		
   		dp[1][0]=v[0][1]+v[1][0];
   		dp[1][1]=min((v[0][1]+v[1][1]),(v[0][1]+v[0][2]+v[1][1]));
   		dp[1][2]=min((v[0][1]+v[1][2]),(v[0][1]+v[0][2]+v[1][2]));

		 for(int i=1;i<n;i++){
        		for(int j=0;j<3;j++){
            			if(j==0){
                			dp[i][j+1]=min(dp[i][j+1],dp[i][j]+v[i][j+1]);
                			dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+v[i+1][j+1]);
                			dp[i+1][j]=min(dp[i+1][j],dp[i][j]+v[i+1][j]);
            			}
            			else if(j==1){
                			dp[i+1][j-1]=min(dp[i+1][j-1],dp[i][j]+v[i+1][j-1]);
                			dp[i+1][j]=min(dp[i+1][j],dp[i][j]+v[i+1][j]);
                			dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+v[i+1][j+1]);
                			dp[i][j+1]=min(dp[i][j+1],dp[i][j]+v[i][j+1]);
            			}
            			else{
                			dp[i+1][j-1]=min(dp[i+1][j-1],dp[i][j]+v[i+1][j-1]);
                			dp[i+1][j]=min(dp[i+1][j],dp[i][j]+v[i+1][j]);
           			}
        		}
    		}
		
		cout<<test<<"."<<" "<<dp[n-1][1]<<endl;
		cin >> n;
		test++;
	}
	
	return 0;
}
	
		
						
		
