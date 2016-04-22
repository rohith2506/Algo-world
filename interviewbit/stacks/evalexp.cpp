#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int evalRPN(vector<string> &A) {
	stack<int> stck;
	for(int i=0; i<A.size(); i++) {
		if(A[i] != "+" && A[i] != "-" && A[i] != "*" && A[i] != "/") {
			stck.push(stoi(A[i]));
		}
		else {
			int val1 = stck.top();
			stck.pop();
			int val2 = stck.top();
			stck.pop();
			if(A[i] == "+") stck.push(val1 + val2);
			else if(A[i] == "-") stck.push(val2 - val1);
			else if(A[i] == "*") stck.push(val1 * val2);
			else if(A[i] == "/") stck.push(val2 / val1);
		}
	}
	return stck.top();
}

int main() {
	int n;
	cin >> n;
	vector<string> v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	cout << evalRPN(v) << endl;
	return 0;
}
