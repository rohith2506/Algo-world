#include <iostream>
#include <vector>
#include <string>

using namespace std;

int titleToNumber(string A) {
	int result = 0;
	for(int i=0; i<A.length(); i++) {
		char ch = A[i];
		result = (result * 26) + ((int)(A[i] - 'A') + 1) ;
	}
	return result;
}

int main() {
	string str;
	cin >> str;
	cout << titleToNumber(str) << endl;
	return 0;
}
