#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int k;
	cin >> k;
	vector<int> v(k);
	for(int i=0;i<k;i++) cin >> v[i];
	sort(v.begin(),v.end());
	vector<int> v2;
	for(int i=v.size()-1;i>=0;i--)v2.push_back(v[i]);
	int res = v2[0]+2;
	for(int i=1;i<v2.size();i++){
		int temp = i + v2[i] + 2;
		res = std::max(temp,res); 
	}
	cout << res << endl;
	return 0;
}