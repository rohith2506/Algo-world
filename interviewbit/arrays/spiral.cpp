#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(const vector<vector<int> > &A) {
	vector<int> results;
	int m = A.size(), n = A[0].size();
	int top = 0, down = m-1, left = 0, right = n-1;
	while(true) {
		for(int j = left; j <= right; j++) results.push_back(A[top][j]);
		top++;
		if(top > down || left > right) break;
		for(int i = top; i <= down; i++) results.push_back(A[i][right]);
		right--;
		if(top > down || left > right) break;
		for(int j = right; j >= left; j--) results.push_back(A[down][j]);
		down--;
		if(top > down || left > right) break;
		for(int i = down; i >= top; i--) results.push_back(A[i][left]);
		left++;
		if(top > down || left > right) break;
	}
	return results;
}

int main() {
	int m,n;
	cin >> m >> n;
	vector<vector<int> > A(m, vector<int>(n));
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin >> A[i][j];
		}
	}
	vector<int> res = spiralOrder(A);
	for(int i=0; i<res.size(); i++) cout << res[i] << " ";
	cout << endl;
}
