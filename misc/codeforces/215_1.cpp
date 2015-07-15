#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
	int n,d;
	cin>>n>>d;

	vector<int> hook(n);
	for(int i=0;i<n;i++) cin>>hook[i];
	sort(hook.begin(),hook.end());

	int m;
	cin >> m;

	if(m <= hook.size()){
		int sum = 0;
		for(int i=0;i<m;i++)
			sum+=hook[i];
		cout<<sum<<endl;
	}
	else{
		int sum = 0;
		for(int i=0;i<hook.size();i++)sum+=hook[i];
		m = m - hook.size();
		cout << sum - (m * d) <<endl;
	}
	return 0;
}
