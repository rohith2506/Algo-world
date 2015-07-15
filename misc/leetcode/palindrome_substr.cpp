/*
Longest palindromic substring (DP approach)
time complexity :- O(n^2)
space complexity:- O(n^2)
@Author : rohit
*/

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <stack>
#include <stdlib.h>
using namespace std;


string palindrome(string s){
	int n = s.length();
	bool l[1000][1000]={false};
	int maxlen=1;
	int start;

	for(int i=0;i<n;i++)
		l[i][i]=true;


	for(int i=0;i<n-1;i++){
		if(s[i]==s[i+1]){
			l[i][i+1]=true;
			start=i;
			maxlen=2;
		}
	}

	for(int k=3;k<=n;k++){
		for(int i=0;i<n-k+1;i++){
			int j=i+k-1;
			if(s[i]==s[j] && l[i+1][j-1]){
				l[i][j]=true;
				start=i;
				maxlen=k;
			}
		}
	}


	for(int i=0;i<s.length();i++)
			cout<<s[i]<<" ";
			cout<<endl;

	return s.substr(start,maxlen);
}



int main(){
	string s;
	cout<<"Enter the string\n";
	cin>>s;
	cout<<"Longest palindrome length substring is :  "<<palindrome(s)<<endl;
	return 0;
}