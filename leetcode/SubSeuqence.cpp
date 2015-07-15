#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int main(){
	int tst;
	cin >> tst;
	for(int t=0; t<tst; t++){
		string str;
		cin >> str;
		vector<bool>hash(26,false);
		for(int i=0;i<str.length();i++){
			int val = (int)(str[i] - 'a');
			hash[val] = true;
		}
		int result = 0;
		for(int i=0;i<hash.size();i++){
			if(hash[i]) result = result + 1;
		}
		cout << result << endl;
	}
	return 0;
}
