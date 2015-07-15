#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <cmath>


using namespace std;

int main(){
	int t,k,n;
	scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d%d",&n,&k);
		vector<int> v;
		for(int i=0;i<n;i++){
			int x;
			scanf("%d",&x);
			v.push_back(x);
		}

		sort(v.begin(),v.end());

		int diff1=0;
		int diff2=0;

		for(int i=0;i<k;i++)
			diff1+=v[i];

		for(int i=k;i<v.size();i++)
			diff2+=v[i];

		int sum1=abs(diff1-diff2);

		sort(v.begin(),v.end(),greater<int>());

		int diff3=0;
		int diff4=0;
		for(int i=0;i<k;i++)
			diff3+=v[i];

		for(int i=k;i<v.size();i++)
			diff4+=v[i];

		int sum2=abs(diff3-diff4);

		cout<<std::max(sum1,sum2)<<endl;


	}
	return 0;
} 