// currentSum = max{A[i], max{A[i-2] + A[i], A[i-2]}, max{A[i-3] + A[i], A[i-3]}, } 


#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];

	vector<int> v;
	v.push_back(a[0]);
	v.push_back(max(a[0],a[1]));

	int tempmax;
	for(int i=2;i<n;i++){
		tempmax = max(v[i-2],v[i-2]+a[i]);
		v[i] = max(tempmax,a[i]);

		tempmax = max(v[i-3],v[i-3]+a[i]);
		v[i]=max(tempmax,a[i]);
	}

	tempmax = -999999;
	for(int i=0;i<v.size();i++){
		if(v[i]>tempmax)
			tempmax=v[i];
	}

	cout<<tempmax<<endl;
	return 0;
}
