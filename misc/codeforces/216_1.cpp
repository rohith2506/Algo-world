#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int main(){
	int n,m,k;
	cin >> n >> m >> k;

	vector<int> v(n);
	for(int i=0;i<n;i++) cin >> v[i];

	for(int i=0;i<v.size();i++){
		if(v[i] == 1) m--;
		else{
			if(m > k) m--;
			else k--;
		}
	}

	int sum = 0;
	if(m<=0)sum-=m;
	if(k<=0)sum-=k;

	cout << "testing for rsync" << endl;

	cout << sum <<endl;
	return 0;
}
