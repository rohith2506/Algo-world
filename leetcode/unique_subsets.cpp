#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#define INV 10e5
using namespace std;

class Solution{
	public:
		void susbets(vector<int> &s, vector<int> v, int i){
			if(i == s.size()){
				sort(v.begin(), v.end());
				result.push_back(v);
				return ;
			}
			if(n == 0 || v.empty() || (s[i] != v.back()))
				subsets(s,v,i+1);
			v.push_back(s[i]);
			subsets(s,v,i+1);
		}
	private:
		vector<vector<int> > result;
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
