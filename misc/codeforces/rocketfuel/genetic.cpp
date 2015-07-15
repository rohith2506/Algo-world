#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>

using namespace std;


int main(){
	string s;
	cin >> s;
	char x = s[0];
	int cnt = 1;
	int res = 0;
	for(int i=1;i<s.length();i++){
		char temp = s[i];
		if(temp == x){
			cnt++;
		}
		else{
			x = s[i];
			if (cnt%2 == 0)
				res = res + 1;
			cnt = 1;
		}
	}
	if(cnt%2 == 0)
		res = res + 1;
	cout<<res<<endl;
	return 0;
}
