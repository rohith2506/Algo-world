#include <iostream>
#include <vector>

using namespace std;

vector<int> plus_one(vector<int> A) {
	vector<int> res;
	int quotient = 1, reminder, index = 0;
	for(int i=0; i<A.size(); i++) {
		if(A[i] != 0) {
			index = i;
			break;
		}
	}
	for(int i=A.size() - 1; i >= index; i--) {
		int value = A[i] + quotient;
		quotient = value / 10;
		reminder = value % 10;
		res.push_back(reminder);
	}
	if(quotient != 0) res.push_back(quotient);
	reverse(res.begin(), res.end());
	return res;
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	vector<int> res = plus_one(v);
	for(int i=0; i<res.size(); i++) cout << res[i] << " ";
	cout << endl;
	return 0;
}
