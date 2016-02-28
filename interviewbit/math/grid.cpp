#include <iostream>
#include <vector>

using namespace std;

int uniquePaths(int A, int B) {
	vector<vector<long int> > v(A, vector<long int>(B));
	for(int i=0; i<v.size(); i++) v[i][0] = 1;
	for(int j=0; j<v[0].size(); j++) v[0][j] = 1;
	for(int i=1; i<v.size(); i++) {
		for(int j=1; j<v[i].size(); j++) {
			v[i][j] = v[i-1][j] + v[i][j-1];
		}
	}
	return v[A-1][B-1];
}

int main() {
	int A, B;
	cin >> A >> B;
	cout << uniquePaths(A, B) << endl;
	return 0;
}
