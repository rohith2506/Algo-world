#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int check_palindrome(string str){
	int remove = string::npos;
	int len = str.length();
	for(int first=0, last=len-1; first<last; ++first, --last){
		if(str[first] != str[last]){
			if(remove != string::npos)
				return string::npos;
			bool t1 = str[first+1] == str[last];
			bool t2 = str[first] == str[last-1];
			if(t1 && t2){}
			else if(t1) remove = first++;
			else if(t2) remove = last--;
			else return string::npos;
		}
	}
	if(remove == string::npos) remove = len/2;
	return remove;
}

int main(){
	int tst;
	cin >> tst;
	for(int t=0; t<tst; t++){
		string str;
		cin >> str;
		int val = check_palindrome(str);
		if(val == -1) cout << "NO" << endl;
		else cout << "YES" << endl;	
	}
	return 0;
}
