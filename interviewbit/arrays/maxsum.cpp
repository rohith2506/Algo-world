#include <iostream>
#include <vector>

using namespace std;

int maxsum(vector<int> A) {
	int curmax = A[0], max_so_far = A[0];
	for(int i = 1; i < A.size(); i++) {
		curmax = max(A[i], curmax + A[i]);
		max_so_far = max(curmax, max_so_far);
	}
	return max_so_far;
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	int res = maxsum(v);
	cout << res << endl;
	return 0;
}
