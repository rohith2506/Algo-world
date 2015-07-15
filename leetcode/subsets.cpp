#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#define INV 10e5
using namespace std;

void print(vector<int> v){
	for(int i=0;i<v.size();i++){
		if(v[i] != INV)
			cout << v[i] << " ";
	}
	cout << endl;
}


void subset(vector<int> s, vector<int> v, int n, int i){
	if(i == n){
		print(v);
		return ;
	}
	v[i] = s[i];
	subset(s,v,n,i+1);
	v[i] = INV;
	subset(s,v,n,i+1);
}


int main(){
	int n;
	cin >> n;
	vector<int> set(n);
	for(int i=0;i<n;i++) cin >> set[i];
	vector<int> v(n);
	subset(set,v,n,0);
	return 0;
}
