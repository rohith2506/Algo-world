#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	int t;
	cin >> t;
	for(int tst=0; tst<t; tst++){
		string str1,str2;
		cin >> str1 >> str2;
		vector<int> letters(26,1);
		for(int i=0;i<str1.length();i++){
			int val = (int)(str1[i] - 'a');
			letters[val] = 0;
		}
		int cnt = 0;
		for(int i=0;i<str2.length();i++){
			int val = (int)(str2[i] - 'a');
			if(letters[val] == 0){
				cnt = cnt + 1;
				letters[val] = 1;
			} 
		}
		cout << cnt << endl;
	}
	return 0;
}		
