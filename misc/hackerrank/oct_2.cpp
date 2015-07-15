#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#define INF 10000000001
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
	long int minimum = INF;
	for(int i=0;i<n-k;i++){
		long int Min = v[i];
		long int Max = v[i+k-1];
		minimum = std::min(minimum,Max-Min);
		}
	cout<<minimum<<endl;
	return 0;
}
