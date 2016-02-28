#include <iostream>
#include <vector>

using namespace std;

vector<int> wave(vector<int> A) {
	sort(A.begin(), A.end());
	for(int i=0; i<A.size()-1; i=i+2) {
		int temp = A[i];
		A[i] = A[i+1];
		A[i+1] = temp;
	}
	return A;
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	vector<int> res = wave(v);
	for(int i=0; i<res.size(); i++) cout << res[i] << " ";
	cout << endl;
	return 0;
}
