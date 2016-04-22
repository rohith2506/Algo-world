#include <vector>
#include <iostream>

using namespace std;

int reach(vector<int> x, vector<int> y) {
	int output = 0;
	for(int i=0; i<x.size()-1; i++) {
		int sx = x[i], ex = x[i+1];
		int sy = y[i], ey = y[i+1];
		output +=  max(abs(sx - ex), abs(sy - ey));
	}
	return output;
}

int main() {
	int m;
	cin >> m;
	vector<int> x(m);
	vector<int> y(m);
	for(int i=0; i<m; i++) cin >> x[i];
	for(int i=0; i<m; i++) cin >> y[i];
	int result = reach(x, y);
	cout << result << endl;
	return 0;
}