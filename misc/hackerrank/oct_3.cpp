#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define INF 1e18+1
using namespace std;

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	vector<long int> v;
	for(int i=0;i<n;i++){
		long int x;
		scanf("%ld",&x);
		v.push_back(x);
		}
	sort(v.begin(),v.end());
	
	long long int minimum = INF;

	for(int i=0;i<n-k+1;i++){
		int first = i;
		int last  = i+k-1;
	
		long long int sum = 0;
		int add = k-1;
		int sub = 0;

		for(int j=last;j>=first;j--){
			sum = sum + (v[j]*add) - (v[j]*sub);
			add--;
			sub++;
			}
		
		minimum = std::min(minimum,sum);
		}
		
	cout<<minimum<<endl;
	return 0;
}

			

