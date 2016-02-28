#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int> > &A) {
	int n = A.size(), m = A[0].size();
	bool isFirstrow = false;
	bool isFirstcol = false;
	for(int i=0; i<A.size(); i++) {
		if(A[i][0] == 0) {
			isFirstrow = true;
			break;
		}
	}
	for(int j=0; j<A[0].size(); j++) {
		if(A[0][j] == 0) {
			isFirstcol = true;
			break;
		}
	}
	for(int i=1; i<A.size(); i++) {
		for(int j=1; j<A[i].size(); j++) {
			if(A[i][j] == 0) {
				A[i][0] = 0;
				A[0][j] = 0;
			}
		}
	}
	for(int i=1; i<A.size(); i++) {
		for(int j=1; j<A[i].size(); j++) {
			if(A[i][0] == 0 || A[0][j] == 0) {
				A[i][j] = 0;
			}
		}
	}
	if(isFirstrow) {
		for(int i=0; i<A.size(); i++) {
			A[i][0] = 0;
		}
	}
	if(isFirstcol) {
		for(int j=0; j<A[0].size(); j++) {
			A[0][j] = 0;
		}
	}
	for(int i=0; i<A.size(); i++) {
		for(int j=0; j<A[i].size(); j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int> > v(n, vector<int>(m));
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> v[i][j];
		}
	}
	setZeroes(v);
	return 0;
}
