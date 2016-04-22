#include <iostream>
#include <vector>
#include <string>

using namespace std;

int strStr(const string &haystack, const string &needle) {
	int index =  -1;
	if(needle.length() == 0) return -1;
	else if(haystack.length() == 0 && needle.length() == 0) return -1;
	else if(needle.length() > haystack.length()) return -1;
	else {
		for(int i=0; i <= haystack.length() - needle.length(); i++) {
			int cnt = 0;
			for(int j=0; j<needle.length(); j++) {
				if(haystack[i+j] == needle[j]) cnt++;
			}
			if(cnt == needle.length()) return i;
		}
		return index;
	}
}

int main() {
	string a,b;
	cin >> a;
	cin >> b;
	cout << strStr(a, b) << endl;
	return 0;
}
