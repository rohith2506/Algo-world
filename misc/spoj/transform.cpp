/*
transforming the expression
infix to postfix
@Author : Rohit
*/

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
using namespace std;

void go(string s){
	stack<char> st;
	string res;
	for(int i=0;i<s.length();i++){
		if((int)(s[i])>=97 && (int)(s[i])<=122)
			res=res+s[i];
		else{
			if(s[i]=='(')
				st.push(s[i]);
			else if(s[i]=='*' || s[i]== '+' || s[i]== '-' || s[i] == '/' || s[i]=='^')
				st.push(s[i]);
			else{
				res=res+st.top();
				st.pop();
				st.pop();
			}
		}
	}
	cout<<res<<endl;
}


int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		string s;
		cin>>s;
		go(s);
	}
	return 0;
}
