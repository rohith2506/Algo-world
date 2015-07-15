#include <iostream>
#include <stdio.h>
#include <stack>
#include <cstring>
#include <string>

using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		string str;
		cin >> str;
		stack<char> stk;
		stk.push(str[0]);
		int len = 0;
		int index = 1;
		while(!stk.empty() && index < str.length()){
			char x = stk.top();
//			cout << "iam here: "  << x << endl;
			if(str[index] == '>' && x == '<'){
				stk.pop();
				len = len + 2;
				if(index+1 < str.length() && str[index+1] == '<')
					stk.push(str[index+1]);
			}
			else if(str[index] == '<' && x == '<')
				stk.push(str[index]);
			else
				break;
			index = index + 1;
		}
		if(stk.empty())
			cout << len << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}