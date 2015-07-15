#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#define pb(x) push_back(x)
#define MAX 10e9 
using namespace std;

void print(vector<vector<int> > v){
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v[i].size(); j++){
			cout <<v[i][j] << " ";
		}
		cout << endl;
	}
}
// END OF CONSTANTS


int num_of_conn_comp(vector<vector<int> > v){
	set<int> s;
	int n = v.size();
	vector<int> b(n);
	for(int i=0; i<n; i++) b[i] = i;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(v[i][j] == 1){
				int key = b[i];
				for(int v=0; v<n; v++){
					if(b[v] == key) b[v] = b[j];
				}
			}
		}
	}
	s.clear();
	for(int i=0; i<n; i++) s.insert(b[i]);
	return s.size();
}

int main(){
	int n;
	cin >> n;
	vector<vector<int> > v(n, vector<int>(n));
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> v[i][j];
		}
	}
	int res = num_of_conn_comp(v);
	cout << res << endl;
	return 0;
}

