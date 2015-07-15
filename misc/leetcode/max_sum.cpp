/*
maximum sub sequence in an array(dp solution)

@author:rohit
*/

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
vector<int> v;

int dp(int n){
	int Min[n];
	for(int i=0;i<n;i++)
	   Min[i]=0;

	if(v[0]>Min[0])
		Min[0]=v[0];
	else
		Min[0]=0;
	
	for(int i=1;i<n;i++){
		if(Min[i-1]+v[i]>0)
			Min[i]=Min[i-1]+v[i];
		else
			Min[i]=0;
		}
        int max=0;
	for(int i=0;i<n;i++){
		if(Min[i]>max)
			max=Min[i];
		}

        return max;
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v.push_back(x);
		}
	cout<<dp(n)<<endl;
	return 0;
	}
