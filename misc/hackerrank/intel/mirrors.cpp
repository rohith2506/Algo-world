#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int main(){
	int t;
	cin >> t;
	for(int tst=0; tst<t; tst++){
		long long int n;
		cin >> n;
		vector<int> v(n+1);
		v[0] = -1;
		for(int i=1;i<=n;i++) cin >> v[i];
		vector<int> left;
		vector<int> right;
		vector<int> res;
		res.push_back(v[1]);
		long long int move_right = 3, move_left = 2;
		for(int x=move_right; x<=n; x=x*2+1) right.push_back(v[x]);
		for(int x=move_left; x<n; x=x*2) left.push_back(v[x]);
		for(int i=0;i<right.size();i++){
			if(right[i] != 0) res.push_back(right[i]);
			if(left[i]  != 0) res.push_back(left[i]);
		}		
		for(int i=0;i<res.size(); i++) cout << res[i] << endl;
	}
	return 0;
}		
