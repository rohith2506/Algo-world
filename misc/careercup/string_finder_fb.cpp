/*
Problem statement:-
if a=1 ,b=2,z=26
Given string,find all possible codes that string can generate
for example 1123
->aabc(1,1,2,3)
-->(11,2,3)
-->(1,12,3)
-->(11,23)
and so on...

recursive method:some problems...:-(
*/


#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#define gc getchar_unlocked
using namespace std;
vector<string> v;

inline int FAST_IO(){
	register int N=0,C;
	while((C=gc())<'0');
	do{
		N = (N<<1)+(N<<3)+C-'0';
	}while((C=gc())>='0');
	return N;
}


void go(string str,string gen_str,int start,int depth){
	if((gen_str.length()<=str.length()) && (start+depth<=str.length())){
		string temp = str.substr(start,depth);
		int num=0;
		for(int i=0;i<temp.length();i++)
			num=(num*10)+((int)(temp[i]-48));
		char x = (char)(num+96);
		gen_str+=x;
	}
	else{
		cout<<gen_str<<endl;
		v.push_back(gen_str);
		gen_str="";
		return ;
	}
	 
	 go(str,gen_str,start+1,1);
	 go(str,gen_str,start+1,2);
}


int main(){
	string str;
	cin>>str;
	string gen_str="";
	go(str,gen_str,0,1);

	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
		cout<<endl;
	return 0;
}