#include <iostream>
#include <string>
#include <vector>

using namespace std;

string invert(string pancakes, int i, int j) {
	for(int k=i; k<j; k++) {
		if(pancakes[k] == '+') pancakes[k] = '-';
		else pancakes[k] = '+';
	}
	return pancakes;
}

int count_inversions(string pancakes) {
	int cnt = 0, j = pancakes.length() - 1;
	while(j >= 0) {
		if(pancakes[j] == '-') {
			pancakes = invert(pancakes, 0, j);
			cnt = cnt + 1;
			pancakes[j] = '+';
		}
		j = j - 1;
	}
	return cnt;
}

int main() {
	int t;
	cin >> t;
	for(int i=1; i<=t; i++) {
		string str;
		cin >> str;
		int result = count_inversions(str);
		cout << "Case #" << i << ": " << result << endl;
	}
	return 0;
}
