#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <stdio.h>

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<int> inp(n);
	for(int i=0;i<n;i++)
		cin >> inp[i];

	queue<int> q;
	queue<int> q2;
	for(int i=0;i<inp.size();i++){
		q.push(inp[i]);
		q2.push(i);
	}

	vector<int> res;
	while(!q.empty() && !q2.empty()){
		int ele = q.front();
		int idx = q2.front();
		q.pop();
		q2.pop();
		if(ele > m){
			int diff = ele - m;
			q.push(diff);
			q2.push(idx);
		}
		else
			res.push_back(idx);
	}
	cout << res[res.size()-1] + 1 << endl;
	return 0;
}