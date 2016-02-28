#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<int> prevSmaller(vector<int> &A) {
	stack<int> stck;
	vector<int> result;
	for(int i=0; i<A.size(); i++) {
		while(!stck.empty() && stck.top() >= A[i]) stck.pop();
		if(stck.empty()) result.push_back(-1);
		else result.push_back(s.top());
		stck.push(A[i]);
	}
	return result;
}
