/*
This is not complete solution
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

int main(){
	int n,k;
	cin >> n >> k;

	vector<int> taste(n);
	vector<int> calories(n);
	
	for(int i=0;i<n;i++)
		cin >> taste[i];

	for(int i=0;i<n;i++)
		cin >> calories[i];

	vector<int> dp(n);

	if(taste[0]/calories[0] == k) dp[0]=1;
	else dp[0]=0;

	for(int i=1;i<n;i++){
		int t = taste[i];
		int c = calories[i];
		for(int j=0;j<i;j++){
			int t1 = t+taste[j];
			int c1 = c+calories[j];
			cout << t1<<" "<<c1<<endl;
			if(t1/c1 == k) dp[i] = 2 + max(dp[i],dp[j]);
			else dp[i] = dp[i-1];
		}
	}

	if(dp[n-1] == 0)cout<<"-1"<<endl;
	else cout<<dp[n-1]<<endl;

	return 0;
}