#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int mycompare(string x, string y) {
	string xy = x.append(y);
	string yx = y.append(x);
	return xy.compare(yx) > 0 ? 1: 0;
}

string Solution::largestNumber(const vector<int> &A) {
	vector<string> B(A.size());
	for(int i=0; i<B.size(); i++) B[i] = to_string(A[i]);
	sort(B.begin(), B.end(), mycompare);
	string result;
	int cnt = 0;
	for(int i=0; i<B.size(); i++) {
		if(B[i] == "0") cnt++;
		result = result + B[i];
	}
	if(cnt == B.size()) return "0";
	else return result;
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	string result = largestNumber(v);
	cout << result << endl;
	return 0;
}
