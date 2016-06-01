#include <iostream>
#include <string>

using namespace std;

void remove_duplicates(string str) {
	int check = 0;
	for(int i=0; i<str.length(); i++) {
		int val = str[i] - 'a';
		check = check | (1 << val);
		cout << str[i] << " " << check << endl;
	}
}

int main() {
	string str;
	cin >> str;
	remove_duplicates(str);
	return 0;
}
