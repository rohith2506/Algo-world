#include <iostream>
#include <vector>
#include <string>

using namespace std;

string titleToNumber(int A) {
	string result = "";
	while(A > 0) {
		int b = (A - 1) % 26;
		char ch = (char)(65 + b);
		result = result + ch;
		A = (A - 1) / 26;
	}
	reverse(result.begin(), result.end());
	return result;
}

int main() {
	int num;
	cin >> num;
	cout << titleToNumber(num) << endl;
	return 0;
}
