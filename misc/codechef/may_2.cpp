#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
long int INF = 4*10e9;
using namespace std;

long int MAXI(long int a,long int b){
	if( a > b)
		return a;
	else
		return b;
}

int main(){
	long int n,k;
	cin >> n >> k;
	vector<int> v(n);

	for(int i=0;i<n;i++) cin >> v[i];
	long int MAX = -INF;
	for(int i=0;i<n;i++)
		MAX = MAXI(v[i],MAX);

	if(k%2 == 1){
		for(int i=0;i<n;i++)
			v[i] = MAX - v[i];
		for(int i=0;i<n;i++)
			cout << v[i] << " ";
	}
	else{
		for(int i=0;i<n;i++)
			v[i] = MAX - v[i];
		long int MAX2 = 0;
		for(int i=0;i<n;i++)
			MAX2 = MAXI(v[i],MAX2);
		for(int i=0;i<n;i++)
			v[i] = MAX2 - v[i];
		for(int i=0;i<n;i++)
			cout << v[i] << " ";
	}
	return 0;
}
